#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	int x = 0, y = 1, temp = 2, count = 0;

	while (count < 3){
		x += temp;
		if (x > 20)  //x의 최대값
			temp *= -1;
		if (x < 2){ //x의 최소값
			temp = 2;
			count++;
		}
		
		system("cls");
		gotoxy(x, y);
		printf("□");
		Sleep(500);

	}

	printf("\n");
	return 0;
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}