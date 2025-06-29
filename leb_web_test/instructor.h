#pragma once
#include "User.h"
class instructor :
    public user
{
protected:
    int hire_year;
    string dept;
    string title;
    vector<int> schedule;

public:

    // constructor
    instructor();
    instructor(string in_first_name, string in_last_name, int in_id, string in_email, int in_hire_year, string in_dept, string in_title);

    // methods
    virtual string show_first_name();	// returns first name
    virtual string show_last_name();	// returns last name
    virtual int show_id();			// returns id number
    virtual void show_all();			// prints all attributes

    void setHire_year(int in_hire_year);
    void setDept(string in_dept);
    void setTitle(string in_title);

    void setSchedule(sqlite3* db, const char* db_path);

    void print_schedule(sqlite3* db, const char* db_path);
    void print_class_list(sqlite3* db, const char* db_path);
    void search_for_student();

    // destructor
    virtual ~instructor();
};

