#include "pch.h"
#include "../leb_web_test/my_func.h"
#include <gtest/gtest.h>

//TEST(Add_Course1, Add_Course_Student) {
//	/*  Test function created by Robbie to test the add student course to student's schedule
//		This test function will add a course to a temp students schedule, and then it will query to see if
//		the Student ID is linked to the course that was added to the schedule. This will confirm that the course was added
//		correctly. This test is fully automated.
//	*/
//  char* messageError;
//  sqlite3* DB;
//  const char* db_path = "assignment3.db";
//  int exit = sqlite3_open(db_path, &DB);
//
//  int course_id = 12847;
//  int temp_course_id;
//
//  student* testUser = new student();
//
//  testUser->setID(10021);
//
//  testUser->add_course(DB, db_path, course_id);	// adding existing course to students schedule (solid state devices)
//  testUser->setSchedule(DB, db_path);
//  const char* sql = "SELECT COURSE_CRN FROM STUDENT_SCHEDULE WHERE STUDENT_ID = ?;";	// querying the database for the student linked to the course
//  temp_course_id = query_db_int_w_int(DB, sql, db_path, 10021);
//  EXPECT_EQ(temp_course_id, course_id);
//  sqlite3_close(DB);
//}
//
//TEST(Add_Course2, Add_Course_Student) {
//	/*  Test function created by Robbie to test the add student course to student's schedule and see
//		what happens when you add a course that does not exist in the database. The expected result of the test should fail.
//		This test is fully automated, so the user will not have to input anything.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int course_id = 99999;
//	int temp_course_id;
//
//	student* testUser = new student();
//
//	testUser->setID(10021);
//
//	testUser->add_course(DB, db_path, course_id);	// adding existing course to students schedule (solid state devices)
//	testUser->setSchedule(DB, db_path);
//	const char* sql = "SELECT COURSE_CRN FROM STUDENT_SCHEDULE WHERE STUDENT_ID = ?;";	// querying the database for the student linked to the course
//	temp_course_id = query_db_int_w_int(DB, sql, db_path, 10021);
//	EXPECT_EQ(temp_course_id, course_id);
//	sqlite3_close(DB);
//}




//TEST(Delete_Course1, Delete_Course) {
//	/*  Test function created by Robbie to test the delete a student course from a student's schedule.
//		This particular test case is designed to delete the course that was added in the first function (solid state devices).
//		This test is fully automated and is meant for the test to pass.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int course_id = 12847;
//	int temp_course_id;
//
//	student* testUser = new student();
//
//	// Backup original streams
//	std::ostringstream output;
//	auto* cout_buf = std::cout.rdbuf();
//
//	// Redirect cout
//	std::cout.rdbuf(output.rdbuf());
//
//	testUser->setID(10021);
//
//	testUser->drop_course(DB, db_path, course_id);
//
//	string expected =
//		"Row deleted successfully.\nCourse Deleted Success\n";
//
//	EXPECT_EQ(output.str(), expected);
//	sqlite3_close(DB);
//}
//
//
//
//
//TEST(Delete_Course2, Delete_Course) {
//	/*  Test function created by Robbie to test the delete a student course from a student's schedule. The output of this particular function
//		should be a fail, because I am trying to delete a course that is not in the database already with the CRN 99999.
//		This test is fully automated.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int course_id = 99999;
//	int temp_course_id;
//
//
//	// Backup original streams
//	std::ostringstream output;
//	auto* cout_buf = std::cout.rdbuf();
//
//	// Redirect cout
//	std::cout.rdbuf(output.rdbuf());
//
//	student* testUser = new student();
//
//	testUser->setID(10021);
//
//	testUser->drop_course(DB, db_path, course_id);
//
//	string expected =
//		"Course Not In Schedule\n";
//
//	EXPECT_EQ(output.str(), expected);
//	sqlite3_close(DB);
//}





//TEST(Add_Course1, Add_Course_Admin) {
//	/*  Test function created by Robbie to test the add course to system admin function
//		This test function will add a course that does not already exist and then query the database to see if it was added correctly
//		This will mean that the add admin works as intented and the test passed. This test is fully automated.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int temp_course_id;
//
//	admin* testUser = new admin();
//
//	testUser->add_courses(DB, 55555, 2025, 4, "Optics", "PHYS", "3:30-4:45", "TR", "Spring");
//	const char* sql = "SELECT CRN FROM COURSE WHERE CRN = ?;";
//	temp_course_id = query_db_int_w_int(DB, sql, db_path, 55555);
//	EXPECT_EQ(temp_course_id, 55555);
//	sqlite3_close(DB);
//}
//
//
//TEST(Add_Course2, Add_Course_Admin) {
//	/*  Test function created by Robbie to test the add course to system admin function
//		This test function will add a course that already exists and then query the database to see to see 
//		This will mean that the add admin works as intented and the test passed. This test is fully automated.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int temp_course_id;
//
//	admin* testUser = new admin();
//
//	std::ostringstream output;
//	auto* cout_buf = std::cout.rdbuf();
//	std::cout.rdbuf(output.rdbuf());
//
//	string expected = "Course Already Exists\n";
//
//
//	testUser->add_courses(DB, 11111, 2025, 3, "Statistics", "BSAS", "8:30-9:45", "TRF", "Summer");
//	//const char* sql = "SELECT CRN FROM COURSE WHERE CRN = ?;";	
//	//temp_course_id = query_db_int_w_int(DB, sql, db_path, 11111);
//	EXPECT_EQ(output.str(), expected);
//	sqlite3_close(DB);
//}




//TEST(Delete_Course1, Delete_Course_Admin) {
//	/*  Test function created by Robbie to test the delete course from system admin function.
//		In this particular function I want to delete the course that I just added from the add course admin function
//		which is optics. This test should pass and is fully automated.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	int temp_course_id;
//
//	admin* testUser = new admin();
//
//	testUser->remove_courses(DB, 55555);
//	const char* sql = "SELECT CRN FROM COURSE WHERE CRN = ?;";
//	temp_course_id = query_db_int_w_int(DB, sql, db_path, 55555);
//	EXPECT_NE(temp_course_id, 55555);
//	sqlite3_close(DB);
//}




TEST(Delete_Course2, Delete_Course_Admin) {
	//	/*  Test function created by Robbie to test the delete course from system admin function.
	//		In this particular function I want to delete a course that does not exist in the course table.
	//		This test should pass and is fully automated.
	//	*/
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	int temp_course_id;

	admin* testUser = new admin();

	testUser->remove_courses(DB, 12125);
	const char* sql = "SELECT CRN FROM COURSE WHERE CRN = ?;";
	temp_course_id = query_db_int_w_int(DB, sql, db_path, 12125);
	EXPECT_NE(temp_course_id, 12125);
	sqlite3_close(DB);
}



//
//TEST(testPrint1, Instructor_schedule) {
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	string email = "brooksm";
//	string password = "qW9t@3zL";
//	instructor* testUser = new instructor();
//	populate_instructor(DB, db_path, testUser, email);
//
//
//	// Backup original streams
//	std::ostringstream output;
//	auto* cout_buf = std::cout.rdbuf();
//
//	// Redirect cout
//	std::cout.rdbuf(output.rdbuf());
//
//	testUser->setSchedule(DB, db_path);
//	testUser->print_schedule(DB, db_path);
//
//	string expected =
//		"Course CRN: 11357\n"
//		"Course Title: Control Systems\n"
//		"Course Department: BSEE\n"
//		"Course Meeting Time: 2:00-3:15\n"
//		"Course Days of the Week: MWF\n"
//		"Course Semester: Spring\n"
//		"Course Year: 2026\n"
//		"Course Credits: 3\n"
//		"\n";
//
//	EXPECT_EQ(output.str(), expected);
//
//	sqlite3_close(DB);
//}
//
//
TEST(testPrint2, Instructor_schedule) {
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	string email = "reynoldsd";
	string password = "Hq1Z@4Ls";
	instructor* testUser = new instructor();
	populate_instructor(DB, db_path, testUser, email);


	// Backup original streams
	std::ostringstream output;
	auto* cout_buf = std::cout.rdbuf();

	// Redirect cout
	std::cout.rdbuf(output.rdbuf());

	testUser->setSchedule(DB, db_path);
	testUser->print_schedule(DB, db_path);

	string expected =
		"Course CRN: 12847\n"
		"Course Title: Solid State Devices\n"
		"Course Department: BSEE\n"
		"Course Meeting Time: 09:30-10:45\n"
		"Course Days of the Week: WF\n"
		"Course Semester: Summer\n"
		"Course Year: 2025\n"
		"Course Credits: 4\n"
		"\n"
		"Course CRN: 25001\n"
		"Course Title: NETWORK THEORY 1\n"
		"Course Department: BSEE\n"
		"Course Meeting Time: 3:00-4:15\n"
		"Course Days of the Week: TR\n"
		"Course Semester: SPRING\n"
		"Course Year: 2026\n"
		"Course Credits: 3\n"
		"\n";

	EXPECT_EQ(output.str(), expected);

	sqlite3_close(DB);
}





//TEST(testList1, Instructor_classlist) {
//	/*	Robbie - This is the second test case for printing the instructor class list. All it does is compare the output string from the
//	main and compare it to the intended string that we are expected to see. This test is fully automated and will run by itself.
//	*/
//	char* messageError;
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	int exit = sqlite3_open(db_path, &DB);
//
//	string email = "brooksm";
//	string password = "qW9t@3zL";
//	instructor* testUser = new instructor();
//	populate_instructor(DB, db_path, testUser, email);
//
//
//	// Backup original streams
//	std::ostringstream output;
//	auto* cout_buf = std::cout.rdbuf();
//
//	// Redirect cout
//	std::cout.rdbuf(output.rdbuf());
//
//	testUser->setSchedule(DB, db_path);
//	testUser->print_class_list(DB, db_path);
//
//	string expected =
//		"Course Roster for: Control Systems\n"
//		"Marie Curie\n"
//		"Michael Johnson\n"
//		"David Collins\n"
//		"Sarah Bennett\n"
//		"\n";
//
//	EXPECT_EQ(output.str(), expected);
//
//	sqlite3_close(DB);
//}
//
TEST(testList2, Instructor_classlist) {
	/*	Robbie - This is the second test case for printing the instructor class list. All it does is compare the output string from the
		main and compare it to the intended string that we are expected to see. The difference from the first test and this one
		is that I changed the name of the instructor to see the classlist that they have. This test is fully automated and will run by itself.
	*/
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	string email = "reynoldsd";
	string password = "Hq1Z@4Ls";
	instructor* testUser = new instructor();
	populate_instructor(DB, db_path, testUser, email);


	// Backup original streams
	std::ostringstream output;
	auto* cout_buf = std::cout.rdbuf();

	// Redirect cout
	std::cout.rdbuf(output.rdbuf());

	testUser->setSchedule(DB, db_path);
	testUser->print_class_list(DB, db_path);

	string expected =
		"Course Roster for: Solid State Devices\n"
		"Nikola Tesla\n"
		"Laura Davis\n"
		"Steven Smith\n"
		"\n"
		"Course Roster for: NETWORK THEORY 1\n"
		"Laura Davis\n"
		"Thomas Edison\n"
		"\n";

	EXPECT_EQ(output.str(), expected);

	sqlite3_close(DB);
}