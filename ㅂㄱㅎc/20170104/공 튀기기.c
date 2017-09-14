#include <stdio.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	char ch1[3] = "♥";
	int y, check = 24;

	do{
		for (y = 25 - check; y < 24; y += 1){
			gotoxy(20, y);
			printf("%s", ch1);
			Sleep(50); //공이 바닥으로 내려오는 시간조절
			gotoxy(20, y);
			printf("  ");
		}
		
		for (y = 24; y>24 - check; y -= 1){
			gotoxy(20, y);
			printf("%s", ch1);
			Sleep(70); //공이 바닥에서 튀어 오르는 시간
			gotoxy(20, y);
			printf("  ");
		}
	} while (check != 1);
	printf("\n");
	return 0;
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}