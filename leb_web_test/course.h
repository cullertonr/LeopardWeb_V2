#pragma once
#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

class course
{
protected:
	int crn;
	string title;
	string dept;
	string time;
	string dow;
	string semester;
	int year;
	int credits;

public:
	course();
	course(int in_crn, string in_title, string in_dept,
		string in_time, string in_dow, string in_semester, int in_year, int in_credits);

	void show_all();

	int getCRN();
	string getTitle();
	string getDept();
	string getTime();
	string getDow();
	string getSemester();
	int getYear();
	int getCredits();

	void setCRN(int in_crn);
	void setTitle(string in_title);
	void setDept(string in_dept);
	void setTime(string in_time);
	void setDow(string in_dow);
	void setSemester(string in_semester);
	void setYear(int in_year);
	void setCredits(int in_credits);


	~course();
};

