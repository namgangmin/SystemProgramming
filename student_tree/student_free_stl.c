#include <iostream>
#include <map>
#include <string>

struct Student {
	std::string name;
	int midterm;
	int final;
};

int main() {
	int numStudents;

	std::cout << "학생 수를 입력하세요 ";
	std::cin >> numStudents;

	std::map<std::string, Student> studentMap;

	for (int i = 0; i < numStudents; i++){
		Student student;
		std::cout << i + 1 <<"번째 학생의 이름을 입력하세요 : " ;
		std::cin >> student.name;
		std::cout << student.name << " 학생의 중간고사 성적을 입력하세요 : ";
		std::cin >> student.midterm;
		std::cout << student.name << " 학생의 기말고사 성적을 입력하세요 : ";
	        std::cin >> student.final;

		studentMap[student.name] = student;
	}

	std::cout << "\n학생 정보 : \n";
	for (const auto& pair : studentMap) {
		const Student& student = pair.second;
		std::cout << "이름 : " << student.name << ", 중간고사 성적 : " << student.midterm << ", 기말고사 성적 : " << student.final << std::endl ;
}

	std::string searchName;
	std::cout << "찾고자하는 학생의 이름을 입력하세요 : ";
	
	while (!std::cin.eof()){
		std::cin >> searchName;
		auto it = studentMap.find(searchName);
		if (it != studentMap.end()) {
		const Student& foundStudent = it->second;
		std::cout << "탐색 결과 > 이름 : " << foundStudent.name << ", 중간고사 성적 : " << foundStudent.midterm << ", 기말고사 성적 : " << foundStudent.final;
		std::cout << "\n 이름을 다시 입력해주세요 : " ;
		}

		else {
			std::cout << "탐색하지 못하였음 " << std::endl;
			std::cout << "\n 이름을 다시 입력해주세요 : " ;
		}
	}

	return 0;
}	
