//sebastian solorano -- project 5 assigment 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

//#define PRE_RELEASE 

using namespace std;


typedef struct STUDENT_DATA {
	string firstname;
	string lastname;
#ifdef PRE_RELEASE
	string email;
#endif // PRE_RELEASE

};

vector<STUDENT_DATA> parseStuDat() {
	vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
	ifstream file("StudentData_Emails.txt");
#else
	ifstream file("StudentData.txt");
#endif // PRE_RELEASE

	if (!file.is_open()) {
		printf("error reading file\n");
		return students;
		//error case
	}
	
	string buf;
	while (getline(file, buf)) {
		stringstream sbuf(buf);
		STUDENT_DATA stu;

		getline(sbuf, stu.lastname, ',');
		getline(sbuf, stu.firstname, ',');

#ifdef PRE_RELEASE
		getline(sbuf, stu.email, ',');
#endif // PRE_RELEASE

		//I think the txt file is arranged in lastname firstname format? it's hard to tell

		students.push_back(stu);
	}

	#ifdef _DEBUG
	for (int i = 0; i < students.size();i++) {
		STUDENT_DATA s = students[i];

		#ifdef PRE_RELEASE
			printf("%s , %s, %s\n", s.firstname.c_str(), s.lastname.c_str(),s.email.c_str());
		#else
		printf("%s , %s\n", s.firstname.c_str(), s.lastname.c_str());
		#endif // PRE_RELEASE

	}
	#endif // DEBUG

	return students;
 }

int main(void) {

#ifdef PRE_RELEASE
	printf("running prerelease\n");
#else
	printf("running standard\n");
#endif // PRE_RELEASE

	vector<STUDENT_DATA> v = parseStuDat();



	return 1;
}