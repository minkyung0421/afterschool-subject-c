#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void display_piano_keyboard(void);
void touch_keyboard(int code);
void display_manual01(void);
void display_manual02(void);
void display_manual03(void);

void practice_piano(void); //�ǹ� ����
void record_music(void); //�޸𸮿� ����(�迭�� ����)
void play_piano(void);

void draw_check02(int c, int r);
void gotoxy(int x, int y);
int menu_display(void);
void presskey(void);

char touch[100];
char rec_check = 0;
unsigned long time_check[100];

int main(void){
	int c;
	while (c = menu_display()){
		switch (c){
		case 1: practice_piano();
			break;
		case 2: record_music();
			break;
		case 3: play_piano();
			break;
		default: break;
		}
	}
	return 0;
}

int menu_display(void){
	char select;
	system("cls");
	printf("�ǾƳ� ���� ���α׷�\n\n");
	printf("1. �ǹݿ���\n");
	printf("2. ���ֳ���\n");
	printf("3. �������\n");
	printf("0. ���α׷�����\n\n");
	printf("�޴���ȣ ���� >> ");
	select = _getch();
	return select - '0';
}

void practice_piano(void){
	int freq[] = { 523, 587, 659, 698, 784, 880, 988, 1046 };
	int code;
	system("cls");
	draw_check02(8, 2);
	display_piano_keyboard();
	display_manual01();

	do{
		code = _getch();
		if ('1' <= code && code <= '8'){
			code = '0';
			touch_keyboard(code - 1);
			Beep(freq[code - 1], 300);
		}
		display_piano_keyboard();
	} while (code != 27);
	presskey();
}

void record_music(void){
	int freq[] = { 523, 587, 659, 698, 784, 880, 988, 1046 };
	int code, count = 0;
	clock_t start, end;
	system("cls");
	draw_check02(8, 2);
	display_piano_keyboard();
	display_manual02();

	do{
		code = _getch();
		touch[count] = code;
		start = clock();
		if ('1' <= code && code <= '8'){
			code -= '0';
			touch_keyboard(code - 1);
			touch[count] = code;
			Beep(freq[code - 1], 300);

			while (!_kbhit())
				end = clock();
		}
		end = clock();
		time_check[count] = end - start;
		count++;
		display_piano_keyboard();
	} while (code != 27);
	if (count == 0)
		rec_check = 0;
	else
		rec_check = 1;
	presskey();
}

void play_piano(void){
	int freq[] = { 523, 587, 659, 698, 784, 880, 988, 1046 };
	int code, count = 0;
	system("cls");
	if (rec_check){
		draw_check02(8, 2);
		display_piano_keyboard();
		display_manual03();

		do{
			code = touch[count];
			if (1 <= code && code <= 8){
				touch_keyboard(code - 1);
				Beep(freq[code - 1], time_check[count]);
			}
			count++;
			display_piano_keyboard();
		} while (code != 27);
	}
	else
		printf("����� ������ �����ϴ�\n");
	presskey();
}

void display_piano_keyboard(void){
	int i;
	char code[8][4] = { "��", "��", "��", "��", "��", "��", "��", "��" };

	for (i = 0; i < 8; i++){
		gotoxy(3 + i * 4, 2);
		printf("%2d", i + 1);
	}

	for (i = 0; i < 8; i++){
		gotoxy(3 + i * 4, 4);
		printf("%s", code[i]);
	}
}

void touch_keyboard(int code){
	gotoxy(3 + code * 4, 8);
	printf("%c%c", 0xa1, 0xe3);
}

void display_manual01(void){
	gotoxy(1, 6);
	printf("Ű������ ���ڸ� ������, �ش� �ǹݿ� ���� ǥ�õǰ�\n");
	printf("�ش� ���� ����Ŀ�� ��µ˴ϴ�\n");
	printf("���α׷� ����� Esc Ű �Դϴ�\n");
}

void display_manual02(void){
	gotoxy(1, 6);
	printf("Ű������ ���ڸ� ������, �޸𸮿� ������ �����մϴ�.\n");
	printf("���� ����� Esc Ű �Դϴ�\n");
}

void display_manual03(void){
	gotoxy(1, 6);
	printf("�޸𸮿� ����� ������ ����մϴ�\n");
}

void presskey(void){
	gotoxy(1, 10);
	printf("�ƹ�Ű�� ������ main���� ���ư��ϴ�");
	_getch();
}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check02(int c, int r){
	int i, j;
	unsigned char a = 0xa6, b[12];

	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;
	//���κ�
	printf("%c%c", a, b[3]);
	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[8]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	//Ȯ��� �ٵ��� ����κ�
	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++){
			printf("  ");
			printf("%c%c", a, b[2]);
		}
		printf("\n");
		printf("%c%c", a, b[7]);
		for (j = 0; j < c - 1; j++){
			printf("%c%c", a, b[1]);
			printf("%c%c", a, b[11]);
		}
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}
	printf("%c%c", a, b[2]);
	for (j = 0; j < c; j++){
		printf("  ");
		printf("%c%c", a, b[2]);
	}
	printf("\n");
	printf("%c%c", a, b[6]);
	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[10]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
	printf("\n");
}

