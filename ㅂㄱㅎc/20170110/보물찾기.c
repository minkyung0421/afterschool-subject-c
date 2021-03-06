#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void intro_game(void);
void gotoxy(int x, int y);
void display_matrix(int x, int y, int matrix[][10], int height);
int treasure_x[2], treasure_y[2], count;

int main(void){
	char key;
	int x = 10, y = 5;
	int i, map[10][10] = { 0 };
	clock_t start, end;
	double pst;

	srand(time(NULL));

	for (i = 0; i < 2; i++){
		do{
			treasure_x[i] = rand() % 10;
			treasure_y[i] = rand() % 10;
		} while ((treasure_x[i] == 0) || (treasure_y[i] == 0));
	}

	intro_game();
	system("cls");
	start = clock();
	do{
		gotoxy(2, 2);
		printf("찾은 보물(★)의 개수 : %d", count);
		gotoxy(2, 3);
		end = clock();
		pst = (double)(end - start) / CLK_TCK;
		printf("경과 시간 : %.1f 초", pst);
		display_matrix(x, y, map, 5);

		while (!_kbhit());
		key = _getch();
		switch (key){
		case 72:
			y--;
			break;
		case 75:
			x -= 2;
			break;
		case 77:
			x += 2;
			break;
		case 80:
			y++;
			break;
		default:
			break;
		}
		if (y > 14)
			y = 14;
		else if (y < 5)
			y = 5;
		if (x > 38)
			x = 38;
		else if (x < 10)
			x = 10;
	} while (count < 2);
	gotoxy(2, 2);
	printf("찾은 보물(★)의 개수 : %d", count);
	gotoxy(1, 19);
	printf("경과 시간 : %.1f 초", pst);
	gotoxy(1, 20);
	printf("Enter키를 누르시면 여행이 종료됩니다!\n");
	scanf("%c", &key);
	return 0;
}

void intro_game(void){
	char key;
	int x = 10, y = 5;
	int map[10][10] = { 0 };
	system("cls");
	gotoxy(1, 1);
	printf("★★★★보 물 찾 기★★★★");
	gotoxy(1, 3);
	printf("옛날 옛적의 신비한 지도에는.....(아무거나 눌러주세요)");
	_getch();
	gotoxy(1, 4);
	printf("보물이 숨겨져 있습니다!!!!\n");
	gotoxy(1, 5);
	printf("화살표(↑ ↓ ← →)키를 움직여서 여행에서 보물을 찾아주세요!\n");
	gotoxy(1, 7);
	printf("Enter키를 누르면 보물을 찾으러 여행을 떠납니다! \n");
	display_matrix(x, y, map, 10);
	gotoxy(1, 8);
	_getch();
}

void display_matrix(int x, int y, int matrix[][10], int h){
	int i, j;
	for (i = 0; i < 10; i++){
		gotoxy(10, h + i);
		for (j = 0; j < 10; j++)
			printf("■");
	}
	gotoxy(x, y);
	printf("□");

	matrix[(x - 10) / 2][y - h] = 1;

	for (i = 0; i < 2; i++){
		if ((((x - 10) / 2) == treasure_x[i]) && ((y - h) == treasure_y[i]))
			matrix[(x - 10) / 2][y - h] = 2;
	}
	count = 0;
	for (i = 0; i < 10;i++)
		for (j = 0; j < 10;j++)
			if (matrix[i][j] == 1){
				gotoxy(10 + 2 * i, h + j);
				printf("□");
			}
			else if (matrix[i][j] == 2){
				gotoxy(10 + 2 * i, h + j);
				printf("★");
				count++;
			}
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}