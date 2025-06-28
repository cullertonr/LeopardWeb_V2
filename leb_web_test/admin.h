#pragma once
#include "User.h"
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

    void add_courses();
    void remove_courses();
    void add_users();
    void remove_users();
    void remove_student_course();
    void add_student_course();
    void search_print_roster();

    // destructor
    virtual ~admin();
};

