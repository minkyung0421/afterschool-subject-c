#include <stdio.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	unsigned char a1 = 0xa1;
	unsigned char a2 = 0xe1;

	int i, j;

	for (i = 1; i <= 5; i++)
		printf("%c%c", a1, a2);

	gotoxy(9, 2);
	printf("%c%c", a1, a2);

	gotoxy(1, 3);
	for (i = 1; i <= 5; i++)
		printf("%c%c", a1, a2);

	gotoxy(1,4);
	printf("%c%c", a1, a2);

	gotoxy(1, 5);
	for (i = 1; i <= 5; i++)
		printf("%c%c", a1, a2);

	
	

	

	return 0;
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 }; //ÁÂÇ¥
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}