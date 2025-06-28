#include "student.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;


student::student() {

}
student::student(string in_first_name, string in_last_name, int in_id, string in_email, int in_grad_year, string in_major) : 
	user(in_first_name, in_last_name, in_id, in_email), grad_year(in_grad_year), major(in_major) {
	grad_year = in_grad_year;
	major = in_major;
}
string student::show_first_name() {
	return first_name;
}
string student::show_last_name() {
	return last_name;
}
int student::show_id() {
	return id;
}
void student::show_all() {
	cout << "Student's first name is: " << first_name << endl;
	cout << "Student's last name is: " << last_name << endl;
	cout << "Student's id is: " << id << endl;
	cout << "Student's email is: " << email << endl;
	cout << "Student's grad year is: " << grad_year << endl;
	cout << "Student's major is: " << major << endl;
}

void student::setGrad_year(int in_grad_year) {
	grad_year = in_grad_year;
}
void student::setMajor(string in_major) {
	major = in_major;
}

void student::print_schedule() {
	cout << "Printing " << first_name << " " << last_name << "'s schedule." << endl;
}
void student::search_course() {
	cout << "Searching for Courses: " << endl;
}
void student::add_course() {
	cout << "Add Course:" << endl;
}
void student::drop_course() {
	cout << "Drop Course:" << endl;
}
student::~student() {

}

