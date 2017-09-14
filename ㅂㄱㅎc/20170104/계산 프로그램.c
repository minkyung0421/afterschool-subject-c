#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
int sub_menu_display01(void); //사칙연산
int sub_menu_display02(void); //로그 연산
void sub_main01(void); //사칙연산 메뉴
void sub_main02(void); //로그연산 메뉴

void add(void);
void subtraction(void);
void press_any_key(void);

int main(void){
	int c;
	while ((c = menu_display()) != 3){
		switch (c){
		case 1: sub_menu_display01();
			break;
		case 2: sub_menu_display02();
			break;
		default :	break;
		}
	}
	return 0;
}

int menu_display(void){
	int select;
	system("cls");
	printf("계산 프로그램\n\n");
	printf("1. 사칙연산\n");
	printf("2. 로그연산\n");
	printf("3. 프로그램 종료\n\n");
	printf("메뉴번호 입력 >> ");
	select = _getch() - 48;
	
}

int sub_menu_display01(void){
	int select;
	system("cls");
	printf("사칙연산\n\n");
	printf("1. 덧셈(+) 연산\n");
	printf("2. 뺄셈(-) 연산\n");
	printf("3. 나눗셈(/) 연산\n");
	printf("4. 곱셈(*) 연산\n");
	printf("5. 나머지(%) 연산\n");
	printf("6. 메인메뉴로 이동\n\n");
	printf("메뉴번호 입력 >> ");
	select = _getch() - 48;
	return select;
}

void add(void){
	double num1, num2;
	printf("사칙연산 덧셈\n\n");
	printf("두 수 x와 y를 입력해 주세요 >> ");
	scanf("%d %d", &num1, &num2);
	printf("계산된 결과는 %d 입니다.", num1 + num2);
	press_any_key();
}

void subtraction(void){
	double num1, num2;
	printf("사칙연산 뺄셈\n\n");
	printf("두 수 x와 y를 입력해 주세요 >> ");
	scanf("%d %d", &num1, &num2);
	printf("계산된 결과는 %d 입니다.", num1 - num2);
	press_any_key();
}


int sub_menu_display02(void){
	system("cls");
	printf("로그 연산");
}

void press_any_key(void){
	printf("\n\n");
	printf("아무 키나 누르면 메인메뉴로....\n");
	_getch();
}

