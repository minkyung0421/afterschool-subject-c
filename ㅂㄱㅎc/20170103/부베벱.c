#include <stdio.h>
#include <Windows.h>

void draw_basic_square(void);
void gotoxy(int x, int y);

int main(void){
	draw_basic_square();
	return 0;
}

void draw_basic_square(void){
	unsigned char a = 0xa6, b[7], i;
	
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;
	for (i = 1; i <= 5; i++){
		printf("%c%c", a, b[3]);
		printf("%c%c", a, b[4]);
		printf("\n");
		printf("%c%c", a, b[6]);
		printf("%c%c", a, b[5]);
		printf("\n");
	}

	
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 }; //ÁÂÇ¥
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}