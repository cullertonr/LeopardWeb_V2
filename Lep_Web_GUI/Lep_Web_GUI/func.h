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
#include <vector>

using std::string;


//using namespace std;

static int user_login(sqlite3* DB, const char* db_path, string in_email, string in_password) {
	const char* sql = "SELECT PASSWORD FROM LOGIN WHERE EMAIL = ?;";

	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(DB, sql, -1, &stmt, nullptr) != SQLITE_OK) {
		sqlite3_finalize(stmt);
		return 5; // query failed
	}

	sqlite3_bind_text(stmt, 1, in_email.c_str(), -1, SQLITE_TRANSIENT);

	std::string db_password;
	int rc = sqlite3_step(stmt);

	if (rc == SQLITE_ROW) {
		const unsigned char* raw = sqlite3_column_text(stmt, 0);
		db_password = reinterpret_cast<const char*>(raw);
		sqlite3_finalize(stmt);

		// Compare passwords as strings
		if (db_password == in_password)
			return 1; // login success
		else
			return 0; // wrong password
	}
	else if (rc == SQLITE_DONE) {
		sqlite3_finalize(stmt);
		return 3; // no user found
	}
	else {
		sqlite3_finalize(stmt);
		return 4; // other query failure
	}
}

