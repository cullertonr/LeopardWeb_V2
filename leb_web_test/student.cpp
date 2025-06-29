#include "student.h"
#include "course.h"
#include "my_func.h"
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
void student::setSchedule(sqlite3* db, const char* db_path) {
	schedule = get_crn(db, db_path, id);
}

void student::print_schedule(sqlite3* db, const char* db_path) {
	cout << schedule.size() << endl;
	if (schedule.empty()) {
		cout << first_name << " has no registered courses." << endl;
	}
	else {
		for (int i = 0; i < schedule.size(); i++) {
			course* tempCourse = new course();
			populate_course(db, db_path, tempCourse, schedule[i]);
			tempCourse->show_all();
			cout << endl;
		}
	}
	//cout << "Printing " << first_name << " " << last_name << "'s schedule." << endl;
}
void student::search_course() {
	cout << "Searching for Courses: " << endl;
}
void student::add_course(sqlite3* db, const char* db_path) {
	int in_crn;
	cout << "Add Course:" << endl;
	cout << "Enter CRN: ";
	cin >> in_crn;
	const char* sql = "SELECT CRN FROM COURSE WHERE CRN = ?;";
	if (query_db_int_w_int(db, sql, db_path, in_crn) == -1) {
		cout << "Invalid CRN" << endl;
	}
	else {
		insert_schedule(db, id, in_crn);
	}

}
void student::drop_course(sqlite3* db) {
	cout << "----- Drop Course -----" << endl;
	int course_crn;
	cout << "Enter the Course CRN that you Want to Drop (5-digit Number): ";
	cin >> course_crn;
	remove_student_course(db, id, course_crn);
}
student::~student() {

}

