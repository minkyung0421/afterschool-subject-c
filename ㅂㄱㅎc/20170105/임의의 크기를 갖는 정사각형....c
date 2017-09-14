#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void draw_square_xy(int size, int x, int y);
void gotox(int x, int y);

int main(void){
	int move = 1, y = 0, size;
	printf("�簢���� �¿�� �����̴� animation\n\n");
	printf("���� �߿� �ƹ�Ű�� ������ ����\n\n");
	printf("�簢���� ũ�⸦ �Է��ϰ� Enter(�ִ� 20) >> ");
	scanf("%d", &size);
	printf("�ƹ�Ű�� ������ �����մϴ�\n");
	_getch();

	do{
		y += move;
		if (y > 23 - size)  //���簢���� ũ�⿡ ���� ������ �� x��ǥ ���
			move = -1;
		if (y < 3)  //���簢�� ���� �� ��ǥ
			move = 1;
		system("cls");
		draw_square_xy(size, y, 1);
	} while (!_kbhit());
	_getch();
	return 0;
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_square_xy(int size, int x, int y){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	gotoxy(x, y);
	printf("%c%c", a, b[3]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);

	for (i = 0; i < size; i++){
		gotoxy(x, y + i + 1);
		printf("%c%c", a, b[2]);
		for (j = 0; j < size; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
	}

	gotoxy(x, y + i + 1);
	printf("%c%c", a, b[6]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
}