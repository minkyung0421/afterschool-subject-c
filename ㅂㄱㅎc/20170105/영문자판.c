#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void intro_game(void);
void keyboard_practice(void);
void display_keyboard(void);
void practice_result(char output[], char input[], char check[], int total);
void gotoxy(int x, int y);

int main(void){
	intro_game();
	keyboard_practice();
	return 0;
}

void intro_game(void){
	printf("영문 소문자의 자판 연습입니다! \n\n");
	printf("아무키나 누르면 시작합니다!!");
	_getch();
}

//자판 연습 결과
void practice_result(char output[], char input[], char check[], int total){
	int i;
	system("cls");
	printf("  영문 소문자 자판 연습 결과! \n\n");
	printf("   출력문자  입력문자    OX\n");
	printf("--------------------------------------\n");
	for (i = 0; i < 15; i++){
		printf("%2d:   %c         %c", i + 1, output[i], input[i]);
		if (check[i] == 0)
			printf("         X\n");
		else
			printf("         O\n");
	}
	printf("\n");
	printf("맞은 개수 : %d(총 15개)\n", total);
}

void display_keyboard(void){
	printf("  영문  소문자  자판  위치\n");
	printf("------------------------------\n");
	printf(" q  w  e  r  t  y  u  i  o  p\n");
	printf("  a  s  d  f  g  h  j  k  l\n");
	printf("   z  x  c  v  b  n  m\n");
	printf("------------------------------\n");
}

void keyboard_practice(void){
	int i, total = 0;
	char output[15], check[15], input[15];
	srand(time(NULL));
	system("cls");
	display_keyboard();  //키보드 표시
	for (i = 0; i < 15; i++){
		output[i] = rand() % 26 + 97;
		gotoxy(4, 9);
		printf("%2d번 문자 : %c", i + 1, output[i]);
		input[i] = _getch();
		if (output[i] == input[i]){
			total++;
			check[i] = 1;
		}
		else
			check[i] = 0;
	}
	gotoxy(4, 10);
	printf("자판 연습이 끝났습니다");
	gotoxy(4, 11);
	printf("결과를 보려면 아무키나 누르세요\n");
	_getch();
	practice_result(output, input, check, total);
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}