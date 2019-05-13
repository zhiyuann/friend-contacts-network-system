#include <iostream>

#include "contact.h"

using namespace std;

int main() {

	// let's create some hard-coded stuff:

	Email zhiyuan_email("School", "zhongchu@usc.edu");
	zhiyuan_email_email.print();
	Phone zhiyuan_email_phone("Work", "2132756680");
	zhiyuan_phone.print();

	// let's take some user input!

	zhiyuan_email_email.set_contact();
	zhiyuan_email_phone.set_contact();

	// Now let's print out that user input:

	zhiyuan_email.print();
	zhiyuan_phone.print();
	

}
