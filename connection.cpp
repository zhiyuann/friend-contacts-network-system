#include "connection.h"

using namespace std;

Connection::Connection(){
    // I'm already done! 
    set_connection();
}


Connection::~Connection(){
    // TODO: Complete me!
    delete birthdate;
    delete email;
    delete phone;
}


Connection::Connection(string fname, string lname, string bdate, string email, string phone){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = fname;
    this->l_name = lname;
    this->birthdate = new Date(bdate);

    string emailType = email.substr(email.find("(")+1,email.find(")")-1);
    string emailAddress = email.substr(email.find(")")+2);
    this->email = new Email(emailType, emailAddress);

    string phoneType = phone.substr(phone.find("(")+1,phone.find(")")-1);
    string phoneNumber = phone.substr(phone.find(")")+2);
    this->phone = new Phone(phoneType, phoneNumber);
}


Connection::Connection(string filename){
    // TODO: Complete this method!
    set_connection(filename);
}


void Connection::set_connection(){
    // prompts for the information of the user
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    string temp;
    string type;

    cout << "First Name: ";
    // code here
    getline(cin, f_name);
	cout << "Last Name: ";
    // code here
    getline(cin, l_name);
    cout << "Birthdate (M/D/YYYY): ";
    // code here
    getline(cin, temp);
    this->birthdate = new Date(temp);
    cout << "Type of email address: ";
    // code here
    cin >> type;
    cout << "Email address: ";
    // code here
    cin >> temp;
    this->email = new Email(type, temp);
    cout << "Type of phone number: ";
    // code here
    cin >> type;
    cout << "Phone number: ";
    // code here
    // code here
    cin >> temp;
    this->phone = new Phone(type, temp);
}


void Connection::set_connection(string filename){
    // TODO: Complete this method!
    // Look at connection_template files as examples.     
    // Phone number in files can have '-' or not.
    ifstream input;
    input.open(filename.c_str());
    string temp;
    string type;
    getline(input, f_name);
    getline(input, l_name);
    getline(input, temp);
    this->birthdate = new Date(temp);
    getline(input, temp);
    type = temp.substr(temp.find("(")+1,temp.find(")")-1);
    string phoneNumber = temp.substr(temp.find(")")+2);
    this->phone = new Phone(type, phoneNumber);
    getline(input, temp);
    type = temp.substr(temp.find("(")+1,temp.find(")")-1);
    string emailAddress = temp.substr(temp.find(")")+2);
    this->email = new Email(type, emailAddress);
}


bool Connection::operator==(const Connection& rhs){
    // TODO: Complete this method!
    // Note: Difference to Lab is that from now on the combination of fname-lname is unique for any connection
    return (this->f_name == rhs.f_name && this->l_name == rhs.l_name);
}


bool Connection::operator!=(const Connection& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}

string codeName(string str1, string str2){
string res = str1 +str2;
transform(res.begin(), res.end(), res.begin(), ::tolower);
res.erase(remove(res.begin(), res.end(), ' '), res.end());
return res;
}



void Connection::print_connection(){
    // Already implemented for you! Do not change!
	cout << l_name <<"," << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    email->print();
    phone->print();
    for (int i=0; i < myfriends.size(); i++){
// friends[i]
    cout << codeName(myfriends[i]->f_name, myfriends[i]->l_name) << endl;
    }
}

void Connection::makefriends(Connection* newFriend){
    
    myfriends.push_back(newFriend);
}

void Connection::write_connection(ofstream &output){
    output<<f_name<<", "<<l_name<<endl;
    output<<birthdate->get_date()<<endl;
    output<<email->get_contact()<<endl;
    output<<phone->get_contact()<<endl;
    for(int i=0;i < myfriends.size(); i++){
        output<<codeName(myfriends[i]->f_name, myfriends[i]->l_name) << endl;
    }
    output<<"--------------"<<endl;
}