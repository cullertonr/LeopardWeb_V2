#include "user.h"
#include "my_func.h"
#include <iostream>
#include <string>


using std::cout;
using std::endl;

// This is the base CPP Class for assignment 1

// constructor
user::user() {

}
user::user(string in_first_name, string in_last_name, int in_id, string in_email) {
	first_name = in_first_name;
	last_name = in_last_name;
	id = in_id;
	email = in_email;
}

// set functions
void user::setFirst_Name(string in_first_name) {
	first_name = in_first_name;
}
void user::setLast_Name(string in_last_name) {
	last_name = in_last_name;
}
void user::setID(int in_id) {
	id = in_id;
}
void user::setEmail(string in_email) {
	email = in_email;
}

// methods
string user::show_first_name() {
	return first_name;
}
string user::show_last_name() {
	return last_name;
}
int user::show_id() {
	return id;
}
string user::show_email() {
	return email;
}
void user::show_all() {
	cout << "first name: " << first_name << endl;
	cout << "last name: " << last_name << endl;
	cout << "id number: " << id << endl;
	cout << "email: " << email << endl;
}
void user::searchCourse_def(sqlite3* db, const char* db_path) {

	vector<course*> courses;

	sqlite3_stmt* stmt;

	const char* sql = "SELECT CRN FROM COURSE;";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Failed to prepare statement\n";
	}

	// Bind user input (department) to the query
	//sqlite3_bind_text(stmt, 1, dept.c_str(), -1, SQLITE_TRANSIENT);

	// Execute and print results
	//cout << "Courses in " << dept << " department:\n/n";
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		course* tempCourse = new course();
		int code = sqlite3_column_int(stmt, 0);
		populate_course(db, db_path, tempCourse, code);
		tempCourse->show_all();
		cout << endl;
		//courses.push_back(tempCourse);
	}

	/*for (int i = 0; i < courses.size(); i++) {
		courses[i]->show_all();
		cout << endl;
	}*/


	// Clean up
	sqlite3_finalize(stmt);

}
void user::searchCourse(sqlite3* db, const char* db_path) {
	string dept;
	cout << "Enter course department: ";
	cin >> dept;

	vector<course*> courses;

	sqlite3_stmt* stmt;

	const char* sql = "SELECT CRN FROM COURSE WHERE DEPARTMENT = ?";
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		std::cerr << "Failed to prepare statement\n";
	}

	// Bind user input (department) to the query
	sqlite3_bind_text(stmt, 1, dept.c_str(), -1, SQLITE_TRANSIENT);

	// Execute and print results
	cout << "Courses in " << dept << " department:\n/n";
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		course* tempCourse = new course();
		int code = sqlite3_column_int(stmt, 0);
		populate_course(db, db_path, tempCourse, code);
		tempCourse->show_all();
		cout << endl;
		//courses.push_back(tempCourse);
	}

	/*for (int i = 0; i < courses.size(); i++) {
		courses[i]->show_all();
		cout << endl;
	}*/


	// Clean up
	sqlite3_finalize(stmt);
}
// deconstructor
user::~user() {

}
