#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

void intro_game(void);
void keyboard_practice(void);
void display_keyboard(void);
void practice_result(char output[], char input[], char check[], int total);
void gotoxy(int x, int y);

int main(void){
	intro_game();
	keyboard_practice();
	return 0;
}

void intro_game(void){
	printf("���� �ҹ����� ���� �����Դϴ�! \n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�!!");
	_getch();
}

//���� ���� ���
void practice_result(char output[], char input[], char check[], int total){
	int i;
	system("cls");
	printf("  ���� �ҹ��� ���� ���� ���! \n\n");
	printf("   ��¹���  �Է¹���    OX\n");
	printf("--------------------------------------\n");
	for (i = 0; i < 15; i++){
		printf("%2d:   %c         %c", i + 1, output[i], input[i]);
		if (check[i] == 0)
			printf("         X\n");
		else
			printf("         O\n");
	}
	printf("\n");
	printf("���� ���� : %d(�� 15��)\n", total);
}

void display_keyboard(void){
	printf("  ����  �ҹ���  ����  ��ġ\n");
	printf("------------------------------\n");
	printf(" q  w  e  r  t  y  u  i  o  p\n");
	printf("  a  s  d  f  g  h  j  k  l\n");
	printf("   z  x  c  v  b  n  m\n");
	printf("------------------------------\n");
}

void keyboard_practice(void){
	int i, total = 0;
	char output[15], check[15], input[15];
	srand(time(NULL));
	system("cls");
	display_keyboard();  //Ű���� ǥ��
	for (i = 0; i < 15; i++){
		output[i] = rand() % 26 + 97;
		gotoxy(4, 9);
		printf("%2d�� ���� : %c", i + 1, output[i]);
		input[i] = _getch();
		if (output[i] == input[i]){
			total++;
			check[i] = 1;
		}
		else
			check[i] = 0;
	}
	gotoxy(4, 10);
	printf("���� ������ �������ϴ�");
	gotoxy(4, 11);
	printf("����� ������ �ƹ�Ű�� ��������\n");
	_getch();
	practice_result(output, input, check, total);
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}