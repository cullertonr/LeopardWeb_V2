#pragma once
#include "User.h"
#include "sqlite3.h"
class admin :
    public user
{
protected:
    string title;
    string office;

public:

    // constructor
    admin();
    admin(string in_first_name, string in_last_name, int in_id, string in_email, string in_title, string in_office);

    // methods
    virtual string show_first_name();	// returns first name
    virtual string show_last_name();	// returns last name
    virtual int show_id();			// returns id number
    virtual void show_all();			// prints all attributes

    void setTitle(string in_title);
    void setOffice(string office);

    void add_courses(sqlite3* db);
    void remove_courses(sqlite3* db);
    void add_users(sqlite3* db);
    void remove_users(sqlite3* db);
    void remove_student_course(sqlite3* db);
    void add_student_course(sqlite3* db);
    void link_instructor(sqlite3* db);
    void unlink_instructor(sqlite3* db);

    // destructor
    virtual ~admin();
};

