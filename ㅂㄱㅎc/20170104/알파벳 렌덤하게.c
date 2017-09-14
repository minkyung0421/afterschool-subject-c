#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void draw_check01(int column, int row);
void gotoxy(int x, int y);


int main(void){
	int count = 0;
	int score = 0;
	printf("★★★★알파벳 맞추기★★★★\n");
	printf("화면에 나타나는 단어를 입력하세요!\n");

	//바둑판 그리기
	draw_check01(4, 4);
	printf("아무키나 눌러주세요(Enter라던지 Enter라던지 Enter라던지...)");
	_getch();

	do{
		int x, y, alpha, check, user;
		system("cls");
		srand(time(NULL));
		draw_check01(4, 4);
		x = rand() % 4 + 1; //1~4사이의 값 랜덤하게
		y = rand() % 4 + 1;
		//알파벳 값을 랜덤하게 나오게하기
		alpha = rand() % 26;
		//대소문자 구분하는 값을 랜덤하게
		check = rand() % 2;  //0 : 대문자, 1 : 소문자
		//출력할 알파벳값 넣어주기
		alpha = 65 + 32 * check + alpha;

		x = x * 4; //열의 위치
		y = y * 2; //행의 위치

		gotoxy(x, y);
		printf("%c", alpha);
		//임의로 점수를 계산공간 커서 이동
		//점수 출력
		gotoxy(1, 10);
		printf("점수 >> ");

		Sleep(1000);
		//사용자가 키보드에 입력된 값과 알파벳이 같은지 비교
		gotoxy(1, 15);
		user = _getch();
		if (user == alpha){
			//점수 계산할 변수에 1점씩
			//score++;
			//printf("빰빠라밤 Exactly!");
		}
		count++;
	} while (count < 5);
	printf("현재 점수 : %d", score++);
	gotoxy(1, 15);
}

void draw_check01(int c, int r){
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


void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 }; //좌표
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}