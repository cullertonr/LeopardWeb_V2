#pragma once
#include <string>
#include "sqlite3.h"
#include "course.h"
#include <vector>

using std::vector;
using std::string;

class user
{
protected:
	// attributes
	string first_name;
	string last_name;
	int id;
	string email;

public:

	// constructor
	user();
	user(string in_first_name, string in_last_name, int in_id, string in_email);

	// set functions
	void setFirst_Name(string in_first_name);
	void setLast_Name(string in_last_name);
	void setID(int in_id);
	void setEmail(string in_email);

	// method
	virtual string show_first_name();	// returns first name
	virtual string show_last_name();	// returns last name
	virtual int show_id();				// returns id number
	virtual string show_email();		//returns email
	virtual void show_all();			// prints all attributes
	virtual void searchCourse_def(sqlite3* db, const char* db_path);
	virtual void searchCourse(sqlite3* db, const char* db_path);
	// destructor
	~user();
};