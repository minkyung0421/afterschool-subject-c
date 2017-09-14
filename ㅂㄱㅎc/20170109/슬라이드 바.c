#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void draw_vertical_slide(int x, int y, int length, char *s);
void draw_horizontal_slide(int x, int y, int length, char *s);
void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void draw_rectangle(int c, int r);
void gotoxy(int x, int y);

int main(void){
	char *slide = "■", key;
	int x = 1, y = 1;
	int h_slide_length, v_slide_length;
	printf("슬라이드 바 표시\n\n");
	printf("수평 슬라이드바의 길이(최대 70)를 입력하고 Enter >> \n");
	scanf("%d", &h_slide_length);
	printf("수직 슬라이드바의 길이(최대 19)를 입력하고 Enter >> \n");
	scanf("%d", &v_slide_length);
	system("cls");

	do{
		draw_vertical_slide(1, y, v_slide_length, slide);
		draw_horizontal_slide(x, v_slide_length + 3, h_slide_length, slide);
		key = _getch();
		move_arrow_key(key, &x, &y, h_slide_length, v_slide_length);
	} while (key != 27);
	return 0;
}

void draw_vertical_slide(int x, int y, int length, char *s){
	gotoxy(x, 1);
	draw_rectangle(1, length);
	gotoxy(x + 2, y + 1);
	printf("%s", s);
	gotoxy(x + 6, length + 1);
	printf("%2d", y);
}

void draw_horizontal_slide(int x, int y, int length, char *s){
	int real_length = length / 2;
	gotoxy(1, y);
	draw_rectangle(real_length + 1, 1);
	gotoxy(x + 2, y + 1);
	printf("%s", s);
	gotoxy(real_length * 2 + 2, y - 1);
	printf("%2d", x);
}

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b)
{
	switch (key)
	{
		//↑
	case 72:
		*y = *y - 1;
		if (*y < 1) *y = 1;
		break;
		//←
	case 75:
		*x = *x - 2;
		if (*x < 1)*x = 1;
		break;
		//→
	case 77:
		*x = *x + 2;
		if (*x > x_b)*x = x_b;
		break;
		//↓
	case 80:
		*y = *y + 1;
		if (*y > y_b) *y = y_b;
		break;
	case 71:
		*x = *x - 2;

		*y = *y - 1;
		if (*x < 1)*x = 1;
		if (*y < 1) *y = 1;
		break;
	case 73:
		*x = *x + 2;
		*y = *y - 1;
		if (*x > x_b)*x = x_b;
		if (*y < 1) *y = 1;
		break;
	case 79:
		*x = *x - 2;
		*y = *y + 1;
		if (*x < 1)*x = 1;
		if (*y > y_b) *y = y_b;
		break;
	case 81:
		*x = *x + 2;
		*y = *y + 1;
		if (*x > x_b)*x = x_b;
		if (*y > y_b) *y = y_b;
		break;
	}
}

void draw_rectangle(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}