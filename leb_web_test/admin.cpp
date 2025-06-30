#include "admin.h"
#include "student.h"
#include "instructor.h"
#include "course.h"
#include <iostream>
#include "sqlite3.h"
#include "my_func.h"
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::cerr;
using namespace std;

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

void admin::add_courses(sqlite3* db) {
    cout << "----- Adding a New Course to LeopardWeb -----" << endl;
    int crn, year, credits;
    string title, dept, time, dow, semester;

    course* tempCourse = new course();

    // Entering all of the inserts (database) with an input into a temporary class named tempCourse
    cout << "Enter the Course CRN: ";
    cin >> crn;
    tempCourse->setCRN(crn);

    cout << "Enter the Course Title: ";
    cin >> title;
    tempCourse->setTitle(title);

    cout << "Enter the Course Department: ";
    cin >> dept;
    tempCourse->setDept(dept);

    cout << "Enter the Course Time (i.e. 8:00-9:00): ";
    cin >> time;
    tempCourse->setTime(time);

    cout << "Enter the Course Days of the Week: ";
    cin >> dow;
    tempCourse->setDow(dow);

    cout << "Enter the Course Semester: ";
    cin >> semester;
    tempCourse->setSemester(semester);

    cout << "Enter the Course Year: ";
    cin >> year;
    tempCourse->setYear(year);

    cout << "Enter the Course Credits: ";
    cin >> credits;
    tempCourse->setCredits(credits);

    insert_course(db, tempCourse);

    //delete tempCourse;
}
void admin::remove_courses(sqlite3* db) {
    int remove_crn;
    cout << "Remove Courses:" << endl;
    cout << "Enter ID of User to be Removed: ";
    cin >> remove_crn;
    // display information of the course we are removing
    delete_course(db, remove_crn);
}
void admin::add_users(sqlite3* db) {
	string role_inp;
	cout << "Adding a New User to LeopardWeb..." << endl;
	cout << "----- Please Enter New-User Credentials ------" << endl;
	cout << "Enter New-User Role (Admin, Instructor, or Student): ";
	cin >> role_inp;
	while ((role_inp != "Instructor") && (role_inp != "Admin") && (role_inp != "Student")) {
		cout << "Incorrect Role. Please Try again." << endl;
		cout << "New User Role (Admin, Instructor, or Student): ";
		cin >> role_inp;
	}
    if (role_inp == "Admin") {
        admin* tempUser = new admin();
        int admin_id;
        string admin_name, admin_surname, admin_title, admin_office, admin_email;

        cout << "Enter New Admin's ID (5 Digit Integer): ";
        cin >> admin_id;
        tempUser->setID(admin_id);

        cout << "Enter New Admin's Name: ";
        cin >> admin_name;
        tempUser->setFirst_Name(admin_name);

        cout << "Enter New Admin's Surname: ";
        cin >> admin_surname;
        tempUser->setLast_Name(admin_surname);

        cout << "Enter New Admin's Title: ";
        cin >> admin_title;
        tempUser->setTitle(admin_title);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter New Admin's Office: ";
        getline(cin, admin_office);
        tempUser->setOffice(admin_office);

        cout << "Enter New Admin's Email: ";
        cin >> admin_email;
        tempUser->setEmail(admin_email);

        insert_user_admin(db, admin_name, admin_surname, admin_id,  admin_email, admin_title, admin_office);

        delete tempUser;
    }
    else if (role_inp == "Instructor") {
        instructor* tempUser = new instructor();
        int ins_id, ins_hire_year;
        string ins_name, ins_surname, ins_title, ins_dept, ins_email;

        cout << "Enter New Instructor's ID (5 Digit Integer): ";
        cin >> ins_id;
        tempUser->setID(ins_id);

        cout << "Enter New Instructor's Name: ";
        cin >> ins_name;
        tempUser->setFirst_Name(ins_name);

        cout << "Enter New Instructor's Surname: ";
        cin >> ins_surname;
        tempUser->setLast_Name(ins_surname);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter New Instructor's Title: ";
        getline(cin, ins_title);
        tempUser->setTitle(ins_title);

        cout << "Enter New Instructor's Hire Year: ";
        cin >> ins_hire_year;
        tempUser->setHire_year(ins_hire_year);

        cout << "Enter New Instructor's Department: (BS...): ";
        cin >> ins_dept;
        tempUser->setDept(ins_dept);

        cout << "Enter New Instructor's Email: ";
        cin >> ins_email;
        tempUser->setEmail(ins_email);

        insert_user_instructor(db, ins_id, ins_name, ins_surname, ins_title, ins_hire_year, ins_dept, ins_email);

        delete tempUser;
    }
    else if (role_inp == "Student") {
        student* tempUser = new student();
        int stu_id, stu_grad_year;
        string stu_name, stu_surname, stu_major, stu_email;

        cout << "Enter New Student's ID (5 Digit Integer): ";
        cin >> stu_id;
        tempUser->setID(stu_id);

        cout << "Enter New Student's Name: ";
        cin >> stu_name;
        tempUser->setFirst_Name(stu_name);

        cout << "Enter New Student's Surname: ";
        cin >> stu_surname;
        tempUser->setLast_Name(stu_name);

        cout << "Enter New Student's Graduation Year: ";
        cin >> stu_grad_year;
        tempUser->setGrad_year(stu_grad_year);

        cout << "Enter New Student's Major (BS...): ";
        cin >> stu_major;
        tempUser->setMajor(stu_major);

        cout << "Enter New Student's Email: ";
        cin >> stu_email;
        tempUser->setEmail(stu_email);

        insert_user_student(db, stu_id, stu_name,  stu_surname, stu_grad_year, stu_major, stu_email);

        delete tempUser;
    }
}
void admin::remove_users(sqlite3* db) {
    int remove_id;
	cout << "----- Removing user -----" << endl;
    cout << "Enter ID of User to be Removed: ";
    cin >> remove_id;
    // display information of the user we are removing
    delete_user(db, remove_id);
}
void admin::remove_student_course(sqlite3* db) {
	cout << "----- Removing Student From Course -----" << endl;
    int stu_id, course_crn;
    cout << "Enter the Student ID to be Unlinked: ";
    cin >> stu_id;
    cout << "Enter the Course CRN Pertaining to the Student: ";
    cin >> course_crn;
    delete_from_schedule(db, stu_id, course_crn);
}
void admin::add_student_course(sqlite3* db) {
	cout << "----- Adding Student to Course -----" << endl;
    int in_id, in_crn;
    cout << "Enter the Student ID: ";
    cin >> in_id;
    cout << "Enter the Course CRN: ";
    cin >> in_crn;
    insert_schedule(db, in_id, in_crn);
}
void admin::link_instructor(sqlite3* db) {
    cout << "----- Linking Instructor to Course -----" << endl;
    int in_id, in_crn;
    cout << "Enter the Instructor ID: ";
    cin >> in_id;
    cout << "Enter the Course CRN: ";
    cin >> in_crn;
    insert_schedule(db, in_id, in_crn);
}
void admin::unlink_instructor(sqlite3* db) {
    int ins_id, course_crn;
    cout << "----- Unlinking Instructor From Course -----" << endl;
    cout << "Enter the Instructor ID to be Unlinked: ";
    cin >> ins_id;
    cout << "Enter the Course CRN Pertaining to the Instructor: ";
    cin >> course_crn;
    delete_from_schedule(db, ins_id, course_crn);
}
admin::~admin() {

}
