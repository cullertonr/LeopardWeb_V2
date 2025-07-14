#include "pch.h"
#include "../leb_web_test/my_func.h"
#include <gtest/gtest.h>
//#include "../leb_web_test/User.h"
//#include "../leb_web_test/student.h"


//extern int user_login(sqlite3* DB, const char* db_path, string in_email, string in_password);

//TEST(Login, ValidCredentials) {
//
//	sqlite3* DB;
//	const char* db_path = "assignment3.db";
//	sqlite3_open(db_path, &DB);
//
//	int result = user_login(DB, db_path, "whited3", "Tp8P!9Ls");
//	EXPECT_EQ(result, 1);
//	EXPECT_TRUE(true);
//
//	sqlite3_close(DB);
//}


TEST(testlogin, testintialAdmin) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "whited3", "Tp8P!9Ls");
	EXPECT_EQ(result, 1);

	sqlite3_close(DB);
}
TEST(testlogin, testnopass) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "whited3", "\n");
	EXPECT_EQ(result, 2);

	sqlite3_close(DB);
}
TEST(testlogin, testwrongpass) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "whited3", "1234");
	EXPECT_EQ(result, 2);

	sqlite3_close(DB);
}
TEST(testlogin, testwrongemail) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "white3", "Tp8P!9Ls");
	EXPECT_EQ(result, 3);

	sqlite3_close(DB);
}
TEST(testlogin, testnoemail) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "\n", "Tp8P!9Ls");
	EXPECT_EQ(result, 3);

	sqlite3_close(DB);
}
TEST(testlogin, testintialStud) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "curiem", "Uz7V^5Mw");
	EXPECT_EQ(result, 1);

	sqlite3_close(DB);
}
TEST(testlogin, testintialIns) {
	sqlite3* DB = nullptr;
	const char* db_path = "assignment3.db";
	sqlite3_open(db_path, &DB);

	//ASSERT_EQ(sqlite3_open(db_path, &DB), SQLITE_OK) << "Failed to open DB";
	int result = user_login(DB, db_path, "brooksm", "qW9t@3zL");
	EXPECT_EQ(result, 1);

	sqlite3_close(DB);
}
TEST(testlogout, testUserlogout) {

	EXPECT_EQ(logout(0), 0);

}
TEST(testlogout, testUserNOTlogout) {

	EXPECT_EQ(logout(1), 1);

}
TEST(testSearch, testDept) {
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	std::istringstream input("BSEE\n");
	std::ostringstream output;

	// Backup original streams
	auto* cin_buf = std::cin.rdbuf();
	auto* cout_buf = std::cout.rdbuf();

	// Redirect cin and cout
	std::cin.rdbuf(input.rdbuf());
	std::cout.rdbuf(output.rdbuf());

	// Call the function
	student* testUser = new student();

	testUser->searchCourse_def(DB, db_path);

	// Restore original streams
	std::cin.rdbuf(cin_buf);
	std::cout.rdbuf(cout_buf);

	string expected = 
		//"Enter course department: 
		"Courses in BSEE department:\n"
		"Course CRN: 11357\n"
		"Course Title: Control Systems\n"
		"Course Department: BSEE\n"
		"Course Meeting Time: 2:00-3:15\n"
		"Course Days of the Week: MWF\n"
		"Course Semester: Spring\n"
		"Course Year: 2026\n"
		"Course Credits: 3\n"
		"\n"
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

	//EXPECT_TRUE(true);
	sqlite3_close(DB);
}
TEST(testSearch, testSemDept) {
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	std::istringstream input("BSEE\nSpring\n");
	std::ostringstream output;

	// Backup original streams
	auto* cin_buf = std::cin.rdbuf();
	auto* cout_buf = std::cout.rdbuf();

	// Redirect cin and cout
	std::cin.rdbuf(input.rdbuf());
	std::cout.rdbuf(output.rdbuf());

	// Call the function
	student* testUser = new student();

	testUser->searchCourse(DB, db_path);

	// Restore original streams
	std::cin.rdbuf(cin_buf);
	std::cout.rdbuf(cout_buf);

	string expected =
		//"Enter course department: 
		"Courses in BSEE department and Spring semester:\n"
		"Course CRN: 11357\n"
		"Course Title: Control Systems\n"
		"Course Department: BSEE\n"
		"Course Meeting Time: 2:00-3:15\n"
		"Course Days of the Week: MWF\n"
		"Course Semester: Spring\n"
		"Course Year: 2026\n"
		"Course Credits: 3\n"
		"\n";

	EXPECT_EQ(output.str(), expected);

	//EXPECT_TRUE(true);
	sqlite3_close(DB);
}
TEST(testSearch, testFail) {
	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	std::istringstream input("BSEE\nFall\n");
	std::ostringstream output;

	// Backup original streams
	auto* cin_buf = std::cin.rdbuf();
	auto* cout_buf = std::cout.rdbuf();

	// Redirect cin and cout
	std::cin.rdbuf(input.rdbuf());
	std::cout.rdbuf(output.rdbuf());

	// Call the function
	student* testUser = new student();

	testUser->searchCourse(DB, db_path);

	// Restore original streams
	std::cin.rdbuf(cin_buf);
	std::cout.rdbuf(cout_buf);

	string expected =
		"Courses in BSEE department and Fall semester:\n";

	EXPECT_EQ(output.str(), expected);

	//EXPECT_TRUE(true);
	sqlite3_close(DB);
}

TEST(Add_Course1, Add_Course) {

	char* messageError;
	sqlite3* DB;
	const char* db_path = "assignment3.db";
	int exit = sqlite3_open(db_path, &DB);

	int course_id = 12847;
	int temp_course_id;

	student* testUser = new student();
	
	testUser->setID(10021);

	testUser->add_course(DB, db_path, course_id);
	testUser->setSchedule(DB, db_path);
	const char* sql = "SELECT COURSE_CRN FROM STUDENT_SCHEDULE WHERE STUDENT_ID = ?;";
	temp_course_id = query_db_int_w_int(DB, sql, db_path, 10021);

	EXPECT_EQ(temp_course_id, course_id);

	//EXPECT_TRUE(true);
	sqlite3_close(DB);
}