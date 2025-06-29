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

	//string email = "whited3";
	//string password = "Tp8P!9Ls";

	//string email = "curiem";
	//string password = "Uz7V^5Mw";

	string email = "brooksm";
	string password = "qW9t@3zL";

	/*student* tempStud = new student();
	populate_student(DB, db_path, tempStud, "curiem");
	tempStud->show_all();

	insert_schedule(DB, 10002, 11357);
	insert_schedule(DB, 10002, 12674);
	insert_schedule(DB, 10002, 12847);

	tempStud->print_schedule(DB, db_path);*/

	/*delete_from_schedule(DB, 10002, 11357);
	delete_from_schedule(DB, 10002, 12674);
	delete_from_schedule(DB, 10002, 12847);

	tempStud->print_schedule(DB, db_path);*/

	if (get_role(DB, db_path, email) == "Admin") {
		admin* testUser = new admin();
		populate_admin(DB, db_path, testUser, email);
		cout << "Welcome " << testUser->show_first_name() << endl;

		print_welcome();
		print_admin();
		int user_in;
		cin >> user_in;
		while (logout(user_in) != 0) {
			if (user_in == 1) {
				testUser->add_courses(DB);
			}
			else if (user_in == 2) {
				testUser->remove_courses(DB);
			}
			else if (user_in == 3) {
				testUser->add_users(DB);
			}
			else if (user_in == 4) {
				testUser->remove_users(DB);
			}
			else if (user_in == 5) {
				testUser->add_student_course(DB);
			}
			else if (user_in == 6) {
				testUser->remove_student_course(DB);
			}
			else if (user_in == 7) {
				testUser->searchCourse_def(DB, db_path);
			}
			else if (user_in == 8) {
				testUser->searchCourse(DB, db_path);
			}
			else if (user_in == 9) {
				testUser->link_instructor(DB);
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
		int user_in;
		cin >> user_in;
		while (logout(user_in) != 0) {
			if (user_in == 1) {
				testUser->setSchedule(DB, db_path);
				testUser->print_class_list(DB, db_path);
			}
			else if (user_in == 2) {
				testUser->search_for_student();
			}
			else if (user_in == 3) {
				testUser->setSchedule(DB, db_path);
				testUser->print_schedule(DB, db_path);
			}
			else if (user_in == 4) {
				testUser->searchCourse_def(DB, db_path);
			}
			else if (user_in == 5) {
				testUser->searchCourse(DB, db_path);
			}
			else {
				cout << "Invalid input" << endl;
			}
			print_instructor();
			cin >> user_in;
		}
	} else if (get_role(DB, db_path, email) == "Student") {
		student* testUser = new student();
		populate_student(DB, db_path, testUser, email);
		testUser->setSchedule(DB, db_path);
		cout << "Welcome " << testUser->show_first_name() << endl;
		testUser->show_all();
		print_welcome();
		print_student();
		int user_in;
		cin >> user_in;
		while (logout(user_in) != 0) {
			if (user_in == 1) {
				testUser->add_course(DB, db_path);
			}
			else if (user_in == 2) {
				testUser->drop_course(DB);
			}
			else if (user_in == 3) {
				testUser->setSchedule(DB, db_path);
				testUser->print_schedule(DB, db_path);
			}
			else if (user_in == 4) {
				testUser->searchCourse_def(DB, db_path);
			}
			else if (user_in == 5) {
				testUser->searchCourse(DB, db_path);
			}
			else {
				cout << "Invalid input" << endl;
			}
			print_student();
			cin >> user_in;
		}
	}


	sqlite3_close(DB);

	return 0;
}