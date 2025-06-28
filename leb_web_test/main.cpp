#include "my_func.h"

int main(int argc, char** argv)
{
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";

	int exit = sqlite3_open(db_path, &DB);


	//string email;
	//cout << "Enter email: ";
	//cin >> email;
	//string password;
	//cout << "Enter password: ";
	//cin >> password;
	//while (user_login(DB, db_path, email, password) == 0) {
	//	cout << "Incorrect Email or Password" << endl;
	//	cout << "Enter email: ";
	//	cin >> email;
	//	cout << "Enter password: ";
	//	cin >> password;
	//}
	string email = "whited3";
	string password = "Tp8P!9Ls";

	if (get_role(DB, db_path, email) == "Admin") {
		admin* testUser = new admin();
		populate_admin(DB, db_path, testUser, email);
		cout << "Welcome " << testUser->show_first_name() << endl;
		testUser->show_all();
		print_welcome();
		print_admin();
		int user_in;
		cin >> user_in;
		while (logout(user_in) != 0) {
			if (user_in == 1) {
				testUser->add_courses();
			}
			else if (user_in == 2) {
				testUser->remove_courses();
			}
			else if (user_in == 3) {
				testUser->add_users();
			}
			else if (user_in == 4) {
				testUser->remove_users();
			}
			else if (user_in == 5) {
				testUser->add_student_course();
			}
			else if (user_in == 6) {
				testUser->remove_student_course();
			}
			else if (user_in == 7) {
				testUser->search_print_roster();
			}
			else {
				cout << "Invalid input" << endl;
			}
			print_admin();
			cin >> user_in;
		}
	} else if (get_role(DB, db_path, email) == "Instructor") {
		instructor* testUser = new instructor();
		populate_instructor(DB, db_path, testUser, email);
		cout << "Welcome " << testUser ->show_first_name() << endl;
		testUser->show_all();
		print_welcome();
		print_instructor();

	} else {
		student* testUser = new student();
		populate_student(DB, db_path, testUser, email);
		cout << "Welcome " << testUser->show_first_name() << endl;
		testUser->show_all();
		print_welcome();
		print_student();

	}


	sqlite3_close(DB);

	return 0;
}