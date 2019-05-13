
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){
    // Copy from lab5
    Connection* temp = head;
    while(head != NULL){
        temp = head->next;
        delete head;
        head = temp;
    }
}


void Network::push_front(Connection* newEntry){
    // Adds a new Connection (newEntry) to the front of LL
    // TA completed me in lab5 and since then I've not been changed! 
    newEntry->prev = NULL;
    newEntry->next = head;
    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    head = newEntry;
    count++;
}


void Network::push_back(Connection* newEntry){
    // Adds a new Connection (newEntry) to the back of LL
    // Copy from your lab5
    newEntry->next = NULL;
    newEntry->prev = tail;
    if(tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;
    tail = newEntry;
    count++;
}


Connection* Network::search(Connection* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // Copy from lab5
    Connection *newEntry = head;
    while(newEntry != NULL){ 
        if(*newEntry == *searchEntry){
            return newEntry;
        }
        else{
            newEntry = newEntry->next;
        } 
    }
    return NULL;
}


Connection* Network::search(string fname, string lname){
    // New == for Connection, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Connection with fname and lname and and using search(Connection*), 2nd using fname and lname directly.
    Connection *newEntry = head;
    while(newEntry != NULL){ 
        if(newEntry->f_name == fname && newEntry->l_name == lname){
            return newEntry;
        }
        else{
            newEntry = newEntry->next;
        } 
    }
    return NULL;
}

Connection* Network::search (string code){
 Connection* point = head;
    while (point != NULL){
       if(code == codeName(point->f_name, point->l_name)){
           return point;
       }
       else{
           point = point->next;
       }
    }
    return NULL;
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Connection attributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of connections: " << count << endl;
    cout << "------------------------------" << endl;
    Connection* ptr = head;
    while(ptr != NULL){
        ptr->print_connection();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}


void Network::saveDB(string filename){
    // Saves the netwrok in file <filename>
    // Note: The format of the output file is very abstract, just raw data
    // Look at studentDB.txt as a template
    // TODO: Update this method with new requirements
    // Note: notice the intentional flaw in this code, as compared to the note mentioned in printDB, now the one who is responsible for implementing Network should be aware of implementation of Connection, not good! You will fix this in PA2.
    ofstream output(filename.c_str());
    Connection* ptr = head;
    while(ptr != NULL){
        // output << ptr->l_name << ", " << ptr->f_name << endl;
        // output << ptr->birthdate->get_date() << endl;
        // output << ptr->email->get_contact() << endl;
        // output << ptr->phone->get_contact() << endl;
        // output << "------------------" << endl;
        ptr->write_connection(output);
        ptr = ptr->next;
    }
}


void Network::loadDB(string filename){
    // Loads the netwrok from file <filename>
    // The format of the input file is similar to saveDB
    // Look at network studentDB.txt as a template
    // Phone number can be with dashes or without them
    // TODO: Now you will notice you need to go back and make a new constructor to the Connection class,  
    // Connection::Connection(fname, lname, bdate, email, phone)
    // TODO: Update this method with new requirements
    Connection* ptr = head;
    while(head != NULL){
        ptr = head->next;
        delete head;
        head = ptr;
        count--;
    }
    head = NULL;
    tail = NULL;
    ifstream infile;
    infile.open(filename.c_str());
    string buff, fname, lname, bdate, phone, email;
    vector < vector<string> > friendCode;
    vector <string> temp0;
    
    while(getline(infile, buff)){
        lname = buff.substr(0, buff.find(','));
        fname = buff.substr(buff.find(',') + 2);
        getline(infile, bdate);
        getline(infile, email);
        getline(infile, phone);
        getline(infile, buff);
        Connection* newEntry = new Connection(fname, lname, bdate, email, phone);
        this->push_back(newEntry);
        temp0.clear();
       
        while(buff.compare(0,5,"-----")!=0){

            temp0.push_back(buff);
            getline(infile,buff);
        }

        friendCode.push_back(temp0);
        
    }
    // infile.close();
    //cout<<friendCode.size()<<endl;
    Connection* temp1=head;
    Connection* now=head;
    for(int i=0;i<friendCode.size();i++){
        for(int j=0;j<friendCode[i].size();j++){
            //cout<<friendCode[i][j]<<endl;
            // cout<<temp1<<endl;
            Connection* temp1=head;
            while(temp1!=NULL){
            if(codeName (temp1->l_name,temp1->f_name)==friendCode[i][j]){
                cout<<temp1->f_name;
                cout<<temp1->l_name;
                now->makefriends(temp1);
                break;
            }
          //cout<<codeName (temp1->l_name,temp1->f_name)<<endl;
            temp1=temp1->next;
            }
        }
        now=now->next;
    }

   
}
//     infile.open(filename.c_str());
//     while(getline(infile, buff)){
//         lname = buff.substr(0, buff.find(','));
//         fname = buff.substr(buff.find(',') + 2);
//         getline(infile, bdate);
//         getline(infile, email);
//         getline(infile, phone);
//         getline(infile, buff);
//         Connection* newEntry=this->search(fname,lname);
       
//         while(buff.compare(0,5,"-----")!=0){
//             Connection* result=this->search(buff);
//             if (result!=NULL){
//                 newEntry->makefriends(result);
//             }
//             getline(infile,buff);
//         }
       
    
//     }
//     infile.close();
// }


bool Network::remove(string fname, string lname){
    // We modified the definition of == for Connection in Connection definition itself, 
    // So we should not be worried about changes we made in Connection to modify this method!
    // Copy from lab5
    bool ret = true;
    Connection* newEntry = new Connection(fname, lname, "7/20/1997", "tempEmail", "tempPhone"); 
    Connection* ptr = search(fname,lname);
    if (ptr == NULL) {
        ret = false;
    }
    else if ((ptr->next == NULL) && (ptr->prev == NULL)) {
        ptr = NULL;
        head = NULL;
        tail = NULL;
        count--;
    }

    else if (ptr->next == NULL) {
        Connection* ptrPrev = ptr->prev;
        ptrPrev->next = NULL;
        ptr->prev = NULL;
        tail = ptrPrev;
        count--;
    }

    else if (ptr->prev == NULL) {
        Connection* ptrNext = ptr->next;
        ptrNext->prev = NULL;
        ptr->next = NULL;
        head = ptrNext;
        count--;
    }
    else {
        Connection* ptrPrev = ptr->prev;
        Connection* ptrNext = ptr->next;
        ptrPrev->next = ptrNext;
        ptrNext->prev = ptrPrev;
        newEntry->prev = NULL;
        newEntry->next = NULL;
        count--;
    }
    delete newEntry;
    delete ptr;
    return ret;
}


void Network::sendEmail(string addr, string subject, string content, string attachment=""){
    // Sending a command looks like:
    // echo "content" | mailx -s "subject" -a "attachment" addr;
    // TODO: Search how you can run a unix command in C++
    // TODO: You need to add double quotation character (") to both sides of strings for this command. Adding other characters (like ? in code below) should be easy, but double quotation says: I'm a character but not a typical character! 
    // string new_str = '?' + old_str + '?'
    // TODO: Complete this method
    
    subject = "\"" + subject + "\"";
    content = "\"" + content + "\"";
    attachment = "\"" + attachment + "\"";
    string command;
    command = "echo " + content + " | mailx -s " + subject + " -a " + attachment + " " + addr;
    cout << command << endl;
    system(command.c_str());
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new connection \n";
        cout << "4. Remove a connection \n";
        cout << "5. Search \n";
        cout << "6. Send an email \n";
        cout << "7. Send an iMessage \n";
        cout << "8. Print database \n";
        cout<< "9. Connect\n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate, candidateFile;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have ".db" format
            // Take a look into sample_files.cpp
            DIR *dir;
            struct dirent *ent;
            char targetFolderAddr[] = "./";
            if ((dir = opendir ("./")) != NULL) {
                  while ((ent = readdir (dir)) != NULL) {
                    candidateFile = ent->d_name;
                    candidateFile = candidateFile.substr(candidateFile.find(".")+1);
                    if (candidateFile == "db") {
                        cout << ent->d_name << endl;
                    }
                  }
                  closedir (dir);
            } 
            else {
                  /* could not open directory */
                  perror ("No directory!");
            }
            cout << "Enter the name of the load file: ";
            // If file with name FILENAME does not exist:
            cin >> fileName;
            bool exist = false;
            if ((dir = opendir ("./")) != NULL) {
                while ((ent = readdir (dir)) != NULL) {
                    if (fileName == ent->d_name) {    
                        loadDB(fileName);
                        cout << "Network loaded from " << fileName << " with " << count << " connections." << endl;
                        exist = true;
                    }
                }
                closedir (dir);
            } 
            if (exist == false) {
                cout << "File " << fileName << "does not exist!" << endl;
            }
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Connection ONLY if it does not exists!
            cout << "Adding a new connection \n";
            Connection* toAdd = new Connection();
            if (!(search(toAdd))) {
                push_front(toAdd);
            }
            else{
                cout << "Connection already exists!" << endl;
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a connection \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            // if found, cout << "Remove Successful! \n";
            if (remove(fname, lname)) {
                cout << "Remove Successful! \n";
            }
            // if not found: cout << "Connection not found! \n";
            else {
                cout << "Connection not found! \n";
            }
        }
        else if (opt==5){
            // TODO: Complete me!
            cout << "Searching: \n";
            cout << "First Name: ";
            cin >> fname;
            cout << "Last Name: ";
            cin >> lname;
            Connection* toPrint = search(fname,lname);
            // if found: print connection
            if(toPrint != NULL){
                toPrint->print_connection();
            }
            // if not, cout << "Not found! \n";
            else {
                cout << "Not found! \n";
            }
        }
        else if (opt==6){
            // Note: Completed!
            cout << "Sending email to: \n";
            cout << "First Name: ";
            std::getline (std::cin, fname);
            cout << "Last Name: ";
            std::getline (std::cin, lname);
            Connection* ptr = search(fname, lname);
            if (ptr){
                string subject, content, attachment;
                cout << "Sending email to: \n";
                ptr->print_connection();
                cout << "Subject: ";
                std::getline (std::cin, subject);
                cout << "Content: ";
                std::getline (std::cin, content);
                cout << "Attachment: ";
                std::getline (std::cin, attachment);
                string addr = ptr->email->get_contact("1");
                sendEmail(addr, subject, content, attachment);
            }
            else 
                cout << "Contact not found! \n";
        }
        else if (opt==7){
            cout << "Option currently not available\n";
        }
        else if (opt==8){
            // TODO: Complete me!
            cout << "Network Database: \n";
            printDB();
        }
        else if(opt==9){
            string f1name;
            string f2name;
            string l1name;
            string l2name;
            cout<<"Make Friends: \n";
            cout<<"Connection1\n";
            cout<<"First Name: ";
            getline(cin,f1name);
            cout<<"Last Name: ";
            getline(cin,l1name);
            Connection* toPrint=search(f1name,l1name);
            if(toPrint== NULL){
                cout<<"Connection Not Found!\n";
            }
            else{
                cout<<"Connection2\n";
                cout<<"First Name:";
                getline(cin,f2name);
                cout<<"Last Name:";
                getline(cin,l2name);
                Connection* toPrint1=search(f2name,l2name);
                if(toPrint1==NULL){
                    cout<<"Connection Not Found!\n";
                }
                else{
                   toPrint->print_connection();
                  cout<<"------"<<endl;
                   toPrint1->print_connection();
                toPrint->makefriends( toPrint1);
                toPrint1->makefriends(toPrint);
                }
            }
        }
        else{
            cout << "Nothing matched!\n";
        }
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}



