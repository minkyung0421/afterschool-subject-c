#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define X_MAX 30
#define Y_MAX 15;

void draw_square(int size);
void move_ball(int size);
void gotoxy(int x, int y);

int main(void){
	int n;
	printf("★★★상자안에 공★★★\n\n");
	printf("사각형의 길이를 입력해 주세요 >>");
	scanf("%d", &n);
	system("cls");
	//사각형 그리기
	draw_square(n);
	//공 움직이기
	move_ball(n);

	gotoxy(1, 20);
	printf("아무키나 누르면 종료합니다...");

	return 0;
}

void draw_square(int size){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < size; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < size; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void move_ball(int size){
	int x = 3, y = size / 2 + 1;
	int inc_x = 2, inc_y = -2;

	do{
		gotoxy(x, y);
		printf("●");
		Sleep(50);
		gotoxy(x, y);
		printf("  ");

		//x의 이동범위
		if (x > (2 * size))
			inc_x = -2;

		else if (x < 4)
			inc_x = 2;

		//y의 이동범위
		if (y>size)
			inc_y = -1;

		else if (y < 3)
			inc_y = 1;

		x += inc_x;
		y += inc_y;
	} while (1);
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}