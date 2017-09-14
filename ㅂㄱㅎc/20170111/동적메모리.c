#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int size, sum, i;  //학생수, 배열의 원소수
	int *score; //동적으로 할당받은 기억장소를 가리킬 포인터 변수 즉 배열명

	//동적 할당 기억장소의 크기를 결정하기 위해 학생 수를 입력받기
	printf("학생 수는? "); scanf("%d", &size);

	//size개수의 int형 값을 저장할 동적 기억장소 할당 후 score가 가리키기
	score = (int *)malloc(sizeof(int)*size);

	//동적 할당을 받지 못했다면 프로그램을 강제로 끝낸다.
	if (score == NULL){
		printf("동적 기억장소 할당에 실패하였습니다\n");
		exit(1);		//프로그램 실행 중단
	}
}