#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

void draw_check02(int column, int row);
void gotoxy(int x, int y);

int main(void){
	int row, column;
	printf("확장된 바둑판 그리기\n\n");
	printf("가로 세로의 길이를 space로 분리하여 입력하고 Enter >> ");
	scanf("%d %d", &column, &row);
	system("cls");
	draw_check02(column, row);
	int i, j;
	for (i = 0; i < column; i++){
		for (j = 0; j < row; j++){
			gotoxy(3 + 4 * j, 2 + 2 * i);
			printf("♥");
		}
	}
	gotoxy(1, row * 2 + 2);

	return 0;
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 }; //좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check02(int c, int r){

	int i, j;

	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);

	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[8]);
	}

	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[2]);

		for (j = 0; j < c; j++){
			printf("  ");
			printf("%c%c", a, b[2]);
		}

		printf("\n");
		printf("%c%c", a, b[7]);

		for (j = 0; j < c - 1; j++){
			printf("%c%c", a, b[1]);
			printf("%c%c", a, b[11]);
		}

		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}

}