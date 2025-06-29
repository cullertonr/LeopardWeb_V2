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
	student* tempStud = new student();
	populate_student(DB, db_path, tempStud, "curiem");
	tempStud->show_all();

	insert_schedule(DB, 10002, 11357);
	insert_schedule(DB, 10002, 12674);
	insert_schedule(DB, 10002, 12847);

	tempStud->print_schedule(DB, db_path);

	if (get_role(DB, db_path, email) == "Admin") {
		admin* testUser = new admin();
		populate_admin(DB, db_path, testUser, email);
		/*course* testCourse = new course(12345, "Math", "BAMA", "8:00-9:15", "MWF", "Fall", 2025, 4);
		course* testCourse2 = new course();
		populate_admin(DB, db_path, testUser, email);
		insert_course(DB, testCourse);
		populate_course(DB, db_path, testCourse2, 12345);*/
		cout << "Welcome " << testUser->show_first_name() << endl;

		/*testUser->show_all();
		testCourse->show_all();
		delete_user(DB, 30004);
		delete_course(DB, 12345);*/
		//insert_user_admin(DB, "Nick", "Dos", 30004, "dosn2", "Dean", "Dobbs 202");
		
		/*admin* testUser2 = new admin();
		populate_admin(DB, db_path, testUser2, "dosn2");
		testUser2->show_all();*/

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
			else {
				cout << "Invalid input" << endl;
			}
			print_instructor();
			cin >> user_in;
		}
	} else {
		student* testUser = new student();
		populate_student(DB, db_path, testUser, email);
		cout << "Welcome " << testUser->show_first_name() << endl;
		testUser->show_all();
		print_welcome();
		print_student();
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