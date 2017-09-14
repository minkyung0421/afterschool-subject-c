#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	int x, y = 1;

	for (x = 1; x < 70; x += 2){
		system("cls");  //화면 지우기
		gotoxy(x, y);  //커서의 위치 이동
		printf("□");  //대상 출력
		Sleep(500);  //움직이는 속도를 조절
	}
	printf("\n");
	return 0;
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}