#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define box_length 15 //������ ����(�¿� ����)
#define box_height 15 //�ٴ��� ����(���� ����)

void intro_game(void); //���Ӽ���
void game_control(void); //���ӱ���
void gotoxy(int x, int y); //gotoxy ����
int left_right_move(void); //�¿��̵�����
void move_down(int x); //����� �������� ����
void draw_rectangle(int c, int r); //���ӿ�������
int max_block(void); //���Ѻ�ϼ���

int block_stack[box_length * 2 + 1] = { 0 }; //�ش� ��ġ�� ���� 0���� �ʱ�ȭ

int main(void){
	intro_game(); //���Ӽ����� �ҷ���
	game_control(); //���ӱ����� �ҷ���
	gotoxy(1, box_height + 3); //x��ǥ : 1, y��ǥ : 18
	printf("game�� ����Ǿ����ϴ�.                 \n"); //��� �Լ� ���� ��
	printf("�� %d���� �׾ҽ��ϴ�\n\n", max_block()); //�� ���� ���� ���
	return 0; //�Լ� ����
}

void intro_game(void){ //���Ӽ���
	system("cls"); //������ ����� �����ش�
	printf("******���ױ�****** \n\n");
	printf("����� �¿�� �����϶� �����̽�Ű�� ������\n");
	printf("����� ������ �ٴڿ� ���Դϴ�!\n\n");
	printf("�ƹ�Ű�� ������ ������ �����մϴ�\n");
	_getch(); //Ű�� ������ ������ ����
}

void game_control(void){ //���ӱ���
	int x, count = 0; //x, count ����(count �ʱⰪ 0)
	system("cls"); //������ ����� �����ش�
	draw_rectangle(box_length, box_height); //���ӿ����Լ� �ҷ�����
	gotoxy(box_length * 2 + 5, 3); //x��ǥ : 35, y��ǥ : 3
	printf("����� ���� : %2d", box_height); //15��
	gotoxy(1, box_height + 3); //���� printf���� ��ġ x��ǥ : 1, y��ǥ : 18
	printf("�����̽�Ű�� ������ ����� ��������\n");
	printf("�ٴڿ� ���Դϴ�. \n");

	while (count < box_height){ //count�� 15���� ��������
		gotoxy(box_length * 2 + 5, 4); //x��ǥ : 35, y��ǥ : 4
		printf("�õ��� Ƚ�� : %2d", count + 1); //����� ����߸������� count+1
		gotoxy(box_length * 2 + 5, 5); //���� printf���� ��ġ x��ǥ : 35, y��ǥ : 5
		printf("���� ��ϼ� : %2d", max_block()); //max_blocK()�Լ����� ���� ��� �� Ȯ��
		x = left_right_move(); //x�� �����̽��� ���� ��ġ, �Լ��� �θ���
		move_down(x); //����� �������� �Լ� �θ���
		count++; //����� ������������ count++
		_getch(); //Ű�� ���� �� ���� ����
	}
}

void gotoxy(int x, int y){ //gotoxy�� ���� ���� ����
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int left_right_move(void){ //�¿��̵�
	int x = 3, y = 2, temp = 2;

	do{
		x += temp;
		if (x > (box_length * 2)) //x���� �ִ밪 ����
			temp = -2;
		if (x < 3){ //x�� 3���� ������
			x = 3; //x�� 3
			temp = 2; //temp�� 2
		}
		gotoxy(x, y);
		printf("��");
		Sleep(50); //����� �¿�� �����̴� �ӵ��� ����
		gotoxy(x, y);
		printf(" ");
	} while (!_kbhit()); //Ű�� ���ȴ��� Ȯ��(Ű�� ������ ����������)
	block_stack[x] += 1; //block_stack �Լ��� +1
	
	return x;
}

void move_down(int x){ //����� �������� ����
	int y;
	for (y = 2; y < box_height + 2 - block_stack[x]; y += 1){
		gotoxy(x, y);
		printf("��");
		Sleep(20); //�������� �ӵ� ����
		gotoxy(x, y);
		printf(" ");
		Sleep(10);
	}
	gotoxy(x, box_height + 2 - block_stack[x]);
	printf("��");
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


int max_block(void){ //�ִ��ϰ���
	int i, max = 0;
	for (i = 1; i < box_height * 2 + 1; i++){ //1���� 31����
		if (max <= block_stack[i]) //���� max�� block_stack(����� ���μ�)���� ���ų� ������
			max = block_stack[i]; //max�� �� ���� �־��ش�
	}
	return max; //max�� ��ȯ
}

