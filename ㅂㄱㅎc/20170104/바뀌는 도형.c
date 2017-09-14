#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	char ch1[3] = "■", ch2[3] = "●";
	
	int i, check = 1;

	for (i = 1; i < 50; i += 2){
		gotoxy(5, i);

		if (check == 1){
			printf("%s", ch1);
			check = 0;
		}
		else{
			printf("%s", ch2);
			check = 1;
		}
		Sleep(150);
		gotoxy(5, i);
		printf("  "); //대상 지우기
	}
	
	printf("\n");
	return 0;
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}