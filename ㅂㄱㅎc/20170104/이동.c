#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y);

int main(void){
	int x, y = 1;

	for (x = 1; x < 70; x += 2){
		system("cls");  //ȭ�� �����
		gotoxy(x, y);  //Ŀ���� ��ġ �̵�
		printf("��");  //��� ���
		Sleep(500);  //�����̴� �ӵ��� ����
	}
	printf("\n");
	return 0;
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}