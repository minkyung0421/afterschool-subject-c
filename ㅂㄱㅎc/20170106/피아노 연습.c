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

void practice_piano(void); //건반 연습
void record_music(void); //메모리에 녹음(배열에 저장)
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
	printf("피아노 연습 프로그램\n\n");
	printf("1. 건반연습\n");
	printf("2. 연주녹음\n");
	printf("3. 연주재생\n");
	printf("0. 프로그램종료\n\n");
	printf("메뉴번호 선택 >> ");
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
		printf("저장된 음악이 없습니다\n");
	presskey();
}

void display_piano_keyboard(void){
	int i;
	char code[8][4] = { "도", "레", "미", "파", "솔", "라", "시", "도" };

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
	printf("키보드의 숫자를 누르면, 해당 건반에 음이 표시되고\n");
	printf("해당 음이 스피커로 출력됩니다\n");
	printf("프로그램 종료는 Esc 키 입니다\n");
}

void display_manual02(void){
	gotoxy(1, 6);
	printf("키보드의 숫자를 누르면, 메모리에 저장을 시작합니다.\n");
	printf("녹음 종료는 Esc 키 입니다\n");
}

void display_manual03(void){
	gotoxy(1, 6);
	printf("메모리에 저장된 음악을 재생합니다\n");
}

void presskey(void){
	gotoxy(1, 10);
	printf("아무키를 누르면 main으로 돌아갑니다");
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
	//윗부분
	printf("%c%c", a, b[3]);
	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[1]);
		printf("%c%c", a, b[8]);
	}
	printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	//확장된 바둑판 가운데부분
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

