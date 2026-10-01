//sebastian solorano -- project 5 assigment 2

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

typedef struct STUDENT_DATA {
	string firstname;
	string lastname;
};

vector<STUDENT_DATA> parseStuDat() {
	vector<STUDENT_DATA> students;

	ifstream file("StudentData.txt");
	if (!file.is_open()) {
		return students;
		//error case
	}
	
	string buf;
	while (getline(file, buf)) {
		stringstream sbuf(buf);
		STUDENT_DATA stu;

		getline(sbuf, stu.lastname, ',');
		getline(sbuf, stu.firstname, ',');
		//I think the txt file is arranged in lastname firstname format? it's hard to tell

		students.push_back(stu);
	}
	return students;
 }

int main(void) {
	vector<STUDENT_DATA> v = parseStuDat();

	for (int i = 0; i < v.size();i++) {
		STUDENT_DATA s = v[i];
		printf("%s , %s\n", s.firstname.c_str(), s.lastname.c_str());
	}
	return 1;
}