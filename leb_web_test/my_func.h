#pragma once
#include <iostream>
#include "sqlite3.h"
#include <string>
#include <stdio.h>
#include "User.h"
#include "student.h"
#include "instructor.h"
#include "admin.h"
#include "course.h"

using namespace std;

static void print_welcome() {
	cout << "-----------------------------------------------------" << endl;
	cout << "*****************Lepeord Web v1**********************" << endl;
	cout << "-----------------------------------------------------" << endl;
}
static void print_admin() {
	cout << "Choose an Option" << endl;
}
static void print_instructor() {
	cout << "Choose an Option" << endl;
}
static void print_student() {
	cout << "Choose an Option" << endl;
}
static string query_db_text(sqlite3* DB, const char* sql, const char* db_path, string in_email) {

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr);

	const char* email = in_email.c_str();
	sqlite3_bind_text(stmt, 1, email, -1, SQLITE_TRANSIENT);

	string info;
	int rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW) {
		const unsigned char* raw = sqlite3_column_text(stmt, 0);
		info = reinterpret_cast<const char*>(raw);
	}
	else if (rc == SQLITE_DONE) {
		cout << "No user found with id = " << in_email << "\n";
	}
	else {
		cerr << "Query failed: " << sqlite3_errmsg(DB) << "\n";
	}

	sqlite3_finalize(stmt);

	return info;
}

static int query_db_int(sqlite3* DB, const char* sql, const char* db_path, string in_email) {

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr);

	const char* email = in_email.c_str();
	sqlite3_bind_text(stmt, 1, email, -1, SQLITE_TRANSIENT);

	int info = -1;
	int rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW) {
		info = sqlite3_column_int(stmt, 0);
	}
	else if (rc == SQLITE_DONE) {
		cout << "No user found with id = " << in_email << "\n";
	}
	else {
		cerr << "Query failed: " << sqlite3_errmsg(DB) << "\n";
	}

	sqlite3_finalize(stmt);

	return info;
}

static int user_login(sqlite3* DB, const char* db_path, string in_email, string in_password) {
	const char* sql[] = {
		"SELECT PASSWORD FROM LOGIN WHERE EMAIL = ?; ",
	};

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(DB, sql[0], -1, &stmt, nullptr);

	const char* email = in_email.c_str();
	sqlite3_bind_text(stmt, 1, email, -1, SQLITE_TRANSIENT);

	string info = "NULL";
	int rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW) {
		const unsigned char* raw = sqlite3_column_text(stmt, 0);
		info = reinterpret_cast<const char*>(raw);
		//cout << info << endl;
		if (in_password == info) {
			sqlite3_finalize(stmt);
			return 1;
		}
		else 
			sqlite3_finalize(stmt);
			return 0;
	}
	else if (rc == SQLITE_DONE) {
		cout << "No user found with email = " << in_email << "\n";
		sqlite3_finalize(stmt);
		return 0;
	}
	else {
		cerr << "Query failed: " << sqlite3_errmsg(DB) << "\n";
		sqlite3_finalize(stmt);
		return 0;
	}

	sqlite3_finalize(stmt);
}
static int logout(int input) {
	if (input == 0){
		cout << "logout successful" << endl;
		return 0;
	} else {
		return 1;
	}
}
static string get_role(sqlite3* DB, const char* db_path, string in_email) {
	const char* sql[] = {
		"SELECT ROLE FROM LOGIN WHERE EMAIL = ?; ",
	};

	sqlite3_stmt* stmt;

	sqlite3_prepare_v2(DB, sql[0], -1, &stmt, nullptr);

	const char* email = in_email.c_str();
	sqlite3_bind_text(stmt, 1, email, -1, SQLITE_TRANSIENT);

	string info = "NULL";
	int rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW) {
		const unsigned char* raw = sqlite3_column_text(stmt, 0);
		info = reinterpret_cast<const char*>(raw);

	}
	else if (rc == SQLITE_DONE) {
		cout << "No user found with email = " << in_email << "\n";

	}
	else {
		cerr << "Query failed: " << sqlite3_errmsg(DB) << "\n";
	}

	sqlite3_finalize(stmt);
	return info;
}

static void populate_student(sqlite3* DB, const char* db_path, student* user, string in_email) {

	const char* sql[] = {
		"SELECT NAME FROM STUDENT WHERE EMAIL = ?; ",
		"SELECT SURNAME FROM STUDENT WHERE EMAIL = ?; ",
		"SELECT ID FROM STUDENT WHERE EMAIL = ?; ",
		"SELECT EMAIL FROM STUDENT WHERE EMAIL = ?; ",
		"SELECT GRADYEAR FROM STUDENT WHERE EMAIL = ?; ",
		"SELECT MAJOR FROM STUDENT WHERE EMAIL = ?; "
	};

	user->setFirst_Name(query_db_text(DB, sql[0], db_path, in_email));
	user->setLast_Name(query_db_text(DB, sql[1], db_path, in_email));
	user->setID(query_db_int(DB, sql[2], db_path, in_email));
	user->setEmail(query_db_text(DB, sql[3], db_path, in_email));
	user->setGrad_year(query_db_int(DB, sql[4], db_path, in_email));
	user->setMajor(query_db_text(DB, sql[5], db_path, in_email));
}
static void populate_instructor(sqlite3* DB, const char* db_path, instructor* user, string in_email) {

	const char* sql[] = {
		"SELECT NAME FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT SURNAME FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT ID FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT EMAIL FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT HIREYEAR FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT DEPT FROM INSTRUCTOR WHERE EMAIL = ?; ",
		"SELECT TITLE FROM INSTRUCTOR WHERE EMAIL = ?; "
	};

	user->setFirst_Name(query_db_text(DB, sql[0], db_path, in_email));
	user->setLast_Name(query_db_text(DB, sql[1], db_path, in_email));
	user->setID(query_db_int(DB, sql[2], db_path, in_email));
	user->setEmail(query_db_text(DB, sql[3], db_path, in_email));
	user->setHire_year(query_db_int(DB, sql[4], db_path, in_email));
	user->setDept(query_db_text(DB, sql[5], db_path, in_email));
	user->setTitle(query_db_text(DB, sql[6], db_path, in_email));
}
static void populate_admin(sqlite3* DB, const char* db_path, admin* user, string in_email) {

	const char* sql[] = {
		"SELECT NAME FROM ADMIN WHERE EMAIL = ?; ",
		"SELECT SURNAME FROM ADMIN WHERE EMAIL = ?; ",
		"SELECT ID FROM ADMIN WHERE EMAIL = ?; ",
		"SELECT EMAIL FROM ADMIN WHERE EMAIL = ?; ",
		"SELECT TITLE FROM ADMIN WHERE EMAIL = ?; ",
		"SELECT OFFICE FROM ADMIN WHERE EMAIL = ?; "
	};

	user->setFirst_Name(query_db_text(DB, sql[0], db_path, in_email));
	user->setLast_Name(query_db_text(DB, sql[1], db_path, in_email));
	user->setID(query_db_int(DB, sql[2], db_path, in_email));
	user->setEmail(query_db_text(DB, sql[3], db_path, in_email));
	user->setTitle(query_db_text(DB, sql[4], db_path, in_email));
	user->setOffice(query_db_text(DB, sql[5], db_path, in_email));
}
static void populate_course(sqlite3* DB, const char* db_path, course* course, int in_crn) {


}