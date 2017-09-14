#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#define X_MAX 79  //가로(열) 방향의 최대값
#define Y_MAX 24  //세로(행) 방향의 최대값

void move_arrow_key(char chr, int *x, int *y, int x_b, int y_b);
void gotoxy(int x, int y);

int main(void){
	char key;
	int x = 10, y = 5;

	do{
		gotoxy(x, y);
		printf("▣");
		key = _getch();
		do{
			move_arrow_key(key, &x, &y, X_MAX, Y_MAX);
			gotoxy(x, y);
			printf("□");
			Sleep(50);  //이동 지연 시간
			system("cls");
		} while (!_kbhit());  //키를 눌렀는지 확인
		//kbhit() : 키가 눌러져 있는 상태(1)
		//안눌러져있는 상태(0)
	} while (key != 27);
	return 0;
}

//방향키 함수
//커서이동 함수
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

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}