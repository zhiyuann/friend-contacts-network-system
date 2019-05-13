# EE355 Spring 2019 - Programming Assignment 1

## Targets: 
- Learning how to change the already implemented code, going back and forth!
- OOP, protected and private, friend
- OOP, dependency of implementation for different classes 
- Virtual functions
- Main menu design
- Running commands from C++ code
- Getting feedback from OS, if file exists
- Default argument 
- Using complicated codes as blackboxes. 
- Connecting to USC Viterbi servers
- Copying files between local machine and server

## Important note: 
- You are given the prompts (what you code is supposed to print, when asking for input, confirming an action is done wrong or right, or when options are provided for the user. Please do not change these strings! Of course, you may need to change the location of the prompts or write code in between different prompts. 
- Follow the TODO and NOTE tags in your code. We believe comments will help you a lot. 

## Class Date:
Already completed and the correct version is uploaded. 

## Class Contact
**TODO**: Write a test-file for Contact
- Look at the declaration of class Contact in contact.h. The class Contact does not have any functionality itself, but is the parent of two other classes, Email and Phone.
- The *type* string is representing the name-tag you want to give to this contact. "Work", "Home" and "Office" are good examples as type of a Phone. Remember the difference between **private and protected** attributes in inheritance and determine which one is the correct choice for type (you may need to see the other methods of Phone and Email to make this decision).
- There are three virtual functions defined for class Contact. You need to define them for each subclass of Contact, Phone and Email. You should also add other attributes to each subclass. 
- **get_contact()**: returns the contact information in the format of string. This method has one argument, style, with default value as "full". You need to pay attention to this default argument when you declare this method for children of Contact (in contact.h), and also when you implement its definition (in contact.cpp). As a hint, get_contact has been completed for Email. 
- **set_contact()**: it has no arguments, but prompts the user to enter the information, like phone number or email address. The prompt messages are shown for you in the code. You need to think about how you want to store the raw-data information of your object, for example, email address seems to be a string, however, the choice for phone-number is a bit more complicated. While phone-number seems like an integer value, it may not be possible to store it in a simple-integer value. 
- **print()**: here are examples, you can also look at test:
    - Email::print() example: "Email (USC): tommytrojan@usc.edu"
    - Phone::print() example: "Phone (Office): 310-192-2847"
- **Email(string type, string email_addr)** & Phone(string type, string phone_number): both constructors get the type and the raw-data in the format of string. 
- Test your code with test_contact.cpp

## Class Connection
- You are given a new template for Connection class (connection.cpp and connection.h), for most of the methods you will copy and paste the complete method or some parts of it from your previous imnplementation of Connection in Lab5. Follow these steps
- We added phone and email to Connection. Rewrite both set_connection methods, one which prompts user for the information and get them from the terminal, and the other one which reads a Connection from a file. Look at the structure of connection_template files given to you. 
- The new constructor for Connection gets 5 string values (instead of 3 in Lab5). Complete it. 
- From now on the combination of fname and lname will determine a unique connection, and checking birthdate is not necessary. Update your == and != operators for Connection. 
- Update the destructor. 

## Class Network
- Add a new search method that only checks for fname and lname
- Even though the Connection class has been changed, the Network methods like push_back, push_from, printDB, destructor, and remove are not required to be modified. This is a feature of OOP, classes are supposed to take care of themselves! Intentionally, we did not follow this approach for saveDB and loadDB, so you can observe how wrong-coding can make things complicated, even when your code works fine.
- **TODO**: Test your network code with test-cases
- Modify saveDB, notice the disadvantage we mentioend earlier, test your code
- Modify loadDB, notice the disadvantage we mentioned earlier, test your code

## Interaction with operating system
- You can run a command (which is simply a string sent to OS using an interface like terminal) from your code. Take a look into sample_msg.cpp and understand how it works. Then comeback Implement sendEmail method, take a look into sample_msg.cpp as an example. 
- Complete Network::sendEmail, notice that sendEmail has attachment as default argument. 
- C++ code can also get some information from operating system, for example the list of content of a directory (like ls command in linux). Take a look into sample_file.cpp. You will use almost the same code later in main menu method. 

## Main Menu 
- Look at the misc.cpp and misc.h to see how we are printing the banner to our Trojan-Book! 
- Start with Main Menu (showMenu), here is our suggestion for the sequence of implementation, based on how you can debug your code. Try to test your code after each implementation, this means your code should be bug free in those options. 
    - Option 8, printing the database. We implement the print first so you can debug your code. Test your code before going to the next step! 
    - Option 3, adding a new connection, only if it does not exist 
    - Option 1, save network
    - Option 2, load network. When load network is selected, you need to print all the files in this same directory that have .db format. You need to check if the file exists or not, if not, prompt the warning, if it is a valid file, prompt as shown in the code mentioning the number of the connections loaded.  
    - Option 4 and 5: searching a connection and removing it. 
    - Option 6: send an email option has been already implemented for you. You need to run the code from a server, like viterbi servers. Instructions are given at the end of this instruction.  
    - Option 7: *Optional!* if you have macbook you are welcomed to implement this method. We will send out the solution for this part after the deadline. 


## Running code on viterbi servers:
By default, you all have a user in viterbi servers. Follow these steps to connect to viterbi-scf1 (or viterbi-scf2) servers:
- Make sure you are connected to internet with USC Secure Wireless (for wifi) or Lan (inside USC domain). 
- If you are not in USC domain, use VPN (instructions are here: https://itservices.usc.edu/vpn/)
- From your terminal create a secure shell to connect to the server: 
    - *$> ssh TommyTrojan@viterbi-scf1.usc.edu* (TommyTrojan is your own USC user)
- You can transfer your files from local machine (your laptop) to the server and in the opposite direction using secure copy *scp* command: 
    - From local machine to server: *$> scp fileName TommyTrojan@viterbi-scf1.usc.edu:<addres-in-server>*
    - From server to local machine: *$> scp TommyTrojan@viterbi-scf1.usc.edu:~/folderName/folderName/fileName <address-in-local-machine>*
    - As an example, I copy my network.cpp file to the server with this command: 
    - *scp \~/Documents/Courses/EE355/PA1/network.cpp abri442@viterbi-scf1.usc.edu:\~/workspace/PA1_in_server/*
    - Or you can copy the folder completely like this: 
    - *scp -r \~/Documents/Courses/EE355/PA/ abri442@viterbi-scf1.usc.edu:\~/workspace/* 

