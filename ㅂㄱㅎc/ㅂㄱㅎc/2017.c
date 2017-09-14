#include <stdio.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void) {
	gotoxy(2, 4);
	printf("hello");
	gotoxy(40, 20);
	printf("c");

	return 0;
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 }; //좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos); //커서이동
}