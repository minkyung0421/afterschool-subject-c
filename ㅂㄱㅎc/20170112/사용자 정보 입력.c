#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct person{
	char name[7], gender[3];
	int age;
};

void input(struct person ptr[]);
void print(struct person *ptr);

int count;

int main(){
	struct person user[SIZE];

	printf("최대 %d명의 사용자 정보를 입력받고 출력합니다\n", SIZE);
	input(user);
	print(user);

	return 0;
}

void print(struct person *ptr){
	int i;

	printf("\n 이름 성별 나이 \n");
	printf("===================\n");
	for (i = 0; i < count; i++){
		printf("%s\t %s\t %d\t", (ptr + i)->name, (ptr + i)->gender, (ptr + i)->age);
	}
	printf("==================\n");
}