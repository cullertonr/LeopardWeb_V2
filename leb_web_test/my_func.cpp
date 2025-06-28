#include "my_func.h"

using namespace std;

static void print_welcome();
static void print_admin();
static void print_instructor();
static void print_student();
static string query_db_text(sqlite3* DB, const char* sql, const char* db_path, string in_email);
static int query_db_int(sqlite3* DB, const char* sql, const char* db_path, string in_email);
static int user_login(sqlite3* DB, const char* db_path, string in_email, string in_password);
static int logout(int input);
static string get_role(sqlite3* DB, const char* db_path, string in_email);
static void populate_student(sqlite3* DB, const char* db_path, student* user, string in_email);
static void populate_instructor(sqlite3* DB, const char* db_path, instructor* user, string in_email);
static void populate_admin(sqlite3* DB, const char* db_path, admin* user, string in_email);
//static void insert_user_instructor();
//static void insert_user_student();
//static void remove_user_instructor();
//static void remove_user_student();
//static void insert_course();
//static void remove_course();
