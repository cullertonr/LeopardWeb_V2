#include "course.h"
#include <iostream>

course::course() {

}
course::course(int in_crn, string in_title, string in_dept,
	string in_time, string in_dow, string in_semester, int in_year, int in_credits) {
	crn = in_crn;
	title = in_title;
	dept = in_dept;
	time = in_time;
	dow = in_dow;
	semester = in_semester;
	year = in_year;
	credits = in_credits;
}

void course::show_all() {
	cout << "Course CRN: " << crn << endl;
	cout << "Course Title: " << title << endl;
	cout << "Course Department: " << dept << endl;
	cout << "Course Meeting Time: " << time << endl;
	cout << "Course Days of the Week: " << dow << endl;
	cout << "Course Semester: " << semester << endl;
	cout << "Course Year: " << year << endl;
	cout << "Course Credits: " << credits << endl;
}

int course::getCRN() {
	return crn;
}
string course::getTitle() {
	return title;
}
string course::getDept() {
	return dept;
}
string course::getTime() {
	return time;
}
string course::getDow() {
	return dow;
}
string course::getSemester() {
	return semester;
}
int course::getYear() {
	return year;
}
int course::getCredits() {
	return credits;
}


void course::setCRN(int in_crn) {
	crn = in_crn;
}
void course::setTitle(string in_title) {
	title = in_title;
}
void course::setDept(string in_dept) {
	dept = in_dept;
}
void course::setTime(string in_time) {
	time = in_time;
}
void course::setDow(string in_dow) {
	dow = in_dow;
}
void course::setSemester(string in_semester) {
	semester = in_semester;
}
void course::setYear(int in_year) {
	year = in_year;
}
void course::setCredits(int in_credits) {
	credits = in_credits;
}

course::~course() {

}