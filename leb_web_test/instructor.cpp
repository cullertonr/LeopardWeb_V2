#include "instructor.h"
#include "my_func.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

instructor::instructor() {

}
instructor::instructor(string in_first_name, string in_last_name, int in_id, string in_email, int in_hire_year, string in_dept, string in_title) 
	: user(in_first_name, in_last_name, in_id, in_email), hire_year(in_hire_year), dept(in_dept), title(in_title){
	hire_year = in_hire_year;
	dept = in_dept;
	title = in_title;
}

string instructor::show_first_name() {
	return first_name;
}
string instructor::show_last_name() {
	return last_name;
}
int instructor::show_id() {
	return id;
}
void instructor::show_all() {
	cout << "Instructor's first name is: " << first_name << endl;
	cout << "Instructor's last name is: " << last_name << endl;
	cout << "Instructor's id is: " << id << endl;
	cout << "Instructor's email is: " << email << endl;
	cout << "Instructor's hire year is: " << hire_year << endl;
	cout << "Instructor's department is: " << dept << endl;
	cout << "Instructor's title is: " << title << endl;
}

void instructor::setHire_year(int in_hire_year) {
	hire_year = in_hire_year;
}
void instructor::setDept(string in_dept) {
	dept = in_dept;
}
void instructor::setTitle(string in_title) {
	title = in_title;
}
void instructor::setSchedule(sqlite3* db, const char* db_path) {
	schedule = get_crn(db, db_path, id);
}
void instructor::print_schedule(sqlite3* db, const char* db_path) {
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
}
void instructor::print_class_list(sqlite3* db, const char* db_path) {
	if (schedule.empty()) {
		cout << first_name << " has no registered courses." << endl;
	}
	else {
		for (int i = 0; i < schedule.size(); i++) {
			course* tempCourse = new course();
			populate_course(db, db_path, tempCourse, schedule[i]);
			vector<int> roster = get_id(db, db_path, schedule[i]);
			cout << "Course Roster for: " << tempCourse->getTitle() << endl;
			for (int j = 0; j < roster.size(); j++) {
				student* tempStud = new student();
				populate_student_w_id(db, db_path, tempStud, roster[j]);
				cout << tempStud->show_first_name() << " " << tempStud->show_last_name() << endl;
			}
			cout << endl;
		}
	}
}
void instructor::search_for_student() {
	cout << "----- Searching for Student ------" << endl;
}
instructor::~instructor() {

}
