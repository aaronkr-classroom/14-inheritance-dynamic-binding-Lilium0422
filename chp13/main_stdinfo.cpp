//main_stdinfo.cpp

#include <algorithm>

#include <ios>

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

#include "Student_info.h"

using namespace std;

int main() {
	vector<Student_info> students; 
	Student_info record;
	string::size_type maxlen = 0;

	//데이터를 읽고 저장
	while (record.read(cin)) {
		maxlen = max(maxlen, record.getName().size());
		students.push_back(record);
	}

	// 학생 기록을 알파벳 순으로 정렬
	sort(students.begin(), students.end(), Student_info::compare);

	//이름과 점수 출력
	for (vector<Core>::size_type i = 0; i != students.size(); i++) {
		cout << students[i].getName() << string(maxlen + 1 - students[i].getName().size(), ' ');
		try {
			double final_grade = students[i].grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
}