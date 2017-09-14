#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define box_length 15 //게임의 영역(좌우 길이)
#define box_height 15 //바닥의 높이(상하 길이)

void intro_game(void); //게임설명
void game_control(void); //게임구성
void gotoxy(int x, int y); //gotoxy 정의
int left_right_move(void); //좌우이동설정
void move_down(int x); //블록이 떨어지는 설정
void draw_rectangle(int c, int r); //게임영역설정
int max_block(void); //제한블록설정

int block_stack[box_length * 2 + 1] = { 0 }; //해당 위치의 값을 0으로 초기화

int main(void){
	intro_game(); //게임설명을 불러옴
	game_control(); //게임구성을 불러옴
	gotoxy(1, box_height + 3); //x좌표 : 1, y좌표 : 18
	printf("game이 종료되었습니다.                 \n"); //모든 함수 종료 후
	printf("총 %d개를 쌓았습니다\n\n", max_block()); //총 쌓은 갯수 출력
	return 0; //함수 종료
}

void intro_game(void){ //게임설명
	system("cls"); //이전의 결과를 지워준다
	printf("******블럭쌓기****** \n\n");
	printf("블록이 좌우로 움직일때 스페이스키를 누르면\n");
	printf("블록이 떨어져 바닥에 쌓입니다!\n\n");
	printf("아무키나 누르면 게임을 시작합니다\n");
	_getch(); //키를 누르기 전까지 멈춤
}

void game_control(void){ //게임구성
	int x, count = 0; //x, count 선언(count 초기값 0)
	system("cls"); //이전의 결과를 지워준다
	draw_rectangle(box_length, box_height); //게임영역함수 불러오기
	gotoxy(box_length * 2 + 5, 3); //x좌표 : 35, y좌표 : 3
	printf("블록의 갯수 : %2d", box_height); //15개
	gotoxy(1, box_height + 3); //위의 printf문의 위치 x좌표 : 1, y좌표 : 18
	printf("스페이스키를 누르면 블록이 떨어지고\n");
	printf("바닥에 쌓입니다. \n");

	while (count < box_height){ //count가 15보다 작을때만
		gotoxy(box_length * 2 + 5, 4); //x좌표 : 35, y좌표 : 4
		printf("시도한 횟수 : %2d", count + 1); //블록을 떨어뜨릴때마다 count+1
		gotoxy(box_length * 2 + 5, 5); //위의 printf문의 위치 x좌표 : 35, y좌표 : 5
		printf("쌓인 블록수 : %2d", max_block()); //max_blocK()함수에서 쌓인 블록 수 확인
		x = left_right_move(); //x는 스페이스를 누른 위치, 함수를 부른다
		move_down(x); //블록이 떨어지는 함수 부른다
		count++; //블록이 떨어질때마다 count++
		_getch(); //키를 누를 때 까지 멈춤
	}
}

void gotoxy(int x, int y){ //gotoxy를 쓰기 위한 정의
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int left_right_move(void){ //좌우이동
	int x = 3, y = 2, temp = 2;

	do{
		x += temp;
		if (x > (box_length * 2)) //x방향 최대값 설정
			temp = -2;
		if (x < 3){ //x가 3보다 작으면
			x = 3; //x는 3
			temp = 2; //temp는 2
		}
		gotoxy(x, y);
		printf("□");
		Sleep(50); //블록이 좌우로 움직이는 속도를 조절
		gotoxy(x, y);
		printf(" ");
	} while (!_kbhit()); //키가 눌렸는지 확인(키가 눌리지 않을때까지)
	block_stack[x] += 1; //block_stack 함수에 +1
	
	return x;
}

void move_down(int x){ //블록이 떨어지는 설정
	int y;
	for (y = 2; y < box_height + 2 - block_stack[x]; y += 1){
		gotoxy(x, y);
		printf("□");
		Sleep(20); //떨어지는 속도 조절
		gotoxy(x, y);
		printf(" ");
		Sleep(10);
	}
	gotoxy(x, box_height + 2 - block_stack[x]);
	printf("□");
}

void draw_rectangle(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}


int max_block(void){ //최대블록갯수
	int i, max = 0;
	for (i = 1; i < box_height * 2 + 1; i++){ //1부터 31까지
		if (max <= block_stack[i]) //만약 max가 block_stack(블록이 쌓인수)보다 적거나 같으면
			max = block_stack[i]; //max에 그 수를 넣어준다
	}
	return max; //max값 반환
}

