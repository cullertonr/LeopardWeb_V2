#pragma once
#include "User.h"
class student :
    public user
{
protected:
    int grad_year;
    string major;
    vector<int> schedule;

public:

    // constructor
    student();
    student(string in_first_name, string in_last_name, int in_id, string in_email, int in_grad_year, string in_major);

    // methods
    virtual string show_first_name();	// returns first name
    virtual string show_last_name();	// returns last name
    virtual int show_id();			    // returns id number
    virtual void show_all();			// prints all attributes
    void setGrad_year(int in_grad_year);
    void setMajor(string in_major);
    void setSchedule(sqlite3* db, const char* db_path);

    void print_schedule(sqlite3* db, const char* db_path);
    void search_course();
    void add_course(sqlite3* db, const char* db_path);
    void drop_course(sqlite3* db);

    // destructor
    virtual ~student();
};

