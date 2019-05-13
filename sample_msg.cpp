

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


void send_email(string addr, string content, 
        string subject){

    // Add quotations to the strings
    addr = "\"" + addr + "\"";
    content = "\"" + content + "\"";
    subject = "\"" + subject + "\"";
    string cmd;
    cmd = "echo " + content + " | mailx -s " + subject + " " + addr;
    cout << cmd << endl;
    system(cmd.c_str());
}


int main(){
    // Funny practice: add main arguments (argv and argc) to make this an email app!
    // You can pass email addr, subject, content and attachment as argv to main
    send_email("tommyTrojan@usc.edu", "content of msg", "subject of msg");

    return 0;
}
