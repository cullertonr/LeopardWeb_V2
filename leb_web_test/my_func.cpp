#include "my_func.h"

using namespace std;

static void print_welcome();
static void print_admin();
static void print_instructor();
static void print_student();
static string query_db_text(sqlite3* DB, const char* sql, const char* db_path, string in_email);
static string query_db_text_w_int(sqlite3* DB, const char* sql, const char* db_path, int in_int);
static int query_db_int(sqlite3* DB, const char* sql, const char* db_path, string in_email);
static int query_db_int_w_int(sqlite3* DB, const char* sql, const char* db_path, int in_int);
static int user_login(sqlite3* DB, const char* db_path, string in_email, string in_password);
static int logout(int input);
static string get_role(sqlite3* DB, const char* db_path, string in_email);

static void populate_student(sqlite3* DB, const char* db_path, student* user, string in_email);
static void populate_student_w_id(sqlite3* DB, const char* db_path, student* user, int in_id);

static void populate_instructor(sqlite3* DB, const char* db_path, instructor* user, string in_email);
static void populate_admin(sqlite3* DB, const char* db_path, admin* user, string in_email);
static void populate_course(sqlite3* DB, const char* db_path, course* course, int in_crn);

static void insert_user_admin(sqlite3* DB, string in_first_name, string in_last_name,
	int in_id, string in_email, string in_title, string in_office);
static void insert_user_instructor(sqlite3* DB, int in_id, string in_first_name, string in_last_name,
	string in_title, int in_hire_year, string in_dept, string in_email);
static void insert_user_student(sqlite3* DB, int in_id, string in_first_name, string in_last_name,
	int in_grad_year, string in_major, string in_email);

static void insert_course(sqlite3* DB, course* tempCourse);
static void insert_schedule(sqlite3* DB, int in_id, int in_crn);
static void delete_user(sqlite3* DB, int in_id);
static void delete_course(sqlite3* DB, int in_crn);
static void delete_from_schedule(sqlite3* DB, int in_id, int in_crn);

static void remove_student_course(sqlite3* DB, int in_id, int in_crn);

static vector<int> get_crn(sqlite3* db, const char* db_path, int in_id);
static vector<int> get_id(sqlite3* db, const char* db_path, int in_crn);


//static void check_time_conflict();
