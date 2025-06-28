#include "admin.h"
#include "student.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

admin::admin() {

}
admin::admin(string in_first_name, string in_last_name, int in_id, string in_email, string in_title, string in_office) : 
	user(in_first_name, in_last_name, in_id, in_email), title(in_title), office(in_office) {
	title = in_title;
	office = in_office;
}
string admin::show_first_name() {
	return first_name;
}
string admin::show_last_name() {
	return last_name;
}
int admin::show_id() {
	return id;
}
void admin::show_all() {
	cout << "Admin's first name: " << first_name << endl;
	cout << "Admin's last name: " << last_name << endl;
	cout << "Admin's id is: " << id << endl;
	cout << "Admin's email is: " << email << endl;
	cout << "Admin's title is: " << title << endl;
	cout << "Admin's office is: " << office << endl;
}

void admin::setTitle(string in_title) {
	title = in_title;
}
void admin::setOffice(string in_office) {
	office = in_office;
}

void admin::add_courses() {
	cout << "Adding Courses:" << endl;
}
void admin::remove_courses() {
	cout << "Remove Courses:" << endl;
}
void admin::add_users() {
	student* tempUser = new student();
	cout << "Adding users:" << endl;
}
void admin::remove_users() {
	cout << "Removing user:" << endl;
}
void admin::remove_student_course() {
	cout << "Removing Student Course:" << endl;
}
void admin::add_student_course() {
	cout << "Adding Student Course:" << endl;
}
void admin::search_print_roster() {
	cout << "Searching for Roster:" << endl;
	cout << "Printing Roser:" << endl;
}
admin::~admin() {

}
