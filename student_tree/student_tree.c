#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <search.h>

typedef struct Student{
	char name[50];
	int midterm;
	int final;
} Student;

int compareNodes(const void* a, const void* b) {
	return strcmp (((Student*)a)->name, ((Student*)b)->name);
}

void printStudentInfo(const void* node, VISIT visit, int level){
	if (visit == leaf || visit == preorder || visit == endorder){
		Student* student = *(Student**)node;
		printf("이름 : %s, 중간고사 성적: %d, 기말고사 성적: %d\n", student->name, student->midterm, student->final);
	}
}



int main() {
	int numStudents;

	printf("학생 수를 입력하세요: ");
	scanf("%d", &numStudents);

	void* root = NULL;

	for(int i = 0; i < numStudents; i++){
		Student* student = (Student*)malloc(sizeof(Student));
		if (student == NULL) {
			fprintf(stderr, "메모리 할당 실패 ");
			return 1;
		}
	
		printf("\n%d번째 학생의 이름을 입력해주세요 :", i+1);
		scanf("%s", student->name);
	
		printf("%s 학생의 중간고사 성적을 입력해주세요 :", student->name);
		scanf("%d", &student->midterm);
	
		printf("%s 학생의 기말고사 성적을 입력해주세요 :", student->name);
		scanf("%d", &student->final);

		void* result;
		result = tsearch(student, &root, compareNodes);

		if (result == NULL) {
			fprintf(stderr, "메모리 할당 실패");
			return 1;
		}
	}

	printf("학생 정보 (twalk) : \n ");
	twalk(root, printStudentInfo);

	char searchName[50];
	printf("찾을 학생의 이름을 입력해주세요: ");

	while(scanf("%s",searchName) != EOF){
		Student searchStudent;
		strcpy(searchStudent.name, searchName);
		void* result = tfind(&searchStudent, &root, compareNodes);
		if (result != NULL) {
			Student* foundStudent = *(Student**)result;
			printf("탐색 결과 > 이름 : %s, 중간고사 성적 : %d. 기말고사 성적 : %d\n", foundStudent->name, foundStudent->midterm, foundStudent->final);
			printf("찾을 학생의 이름을 입력해주세요: ");
		}
		else{

			printf("%s 학생을 찾지 못하였습니다\n",searchName);
			printf("다시 입력 해주세요 : ");
		}
	}
	
	tdestroy(root, free);
	return 0;
}
	
