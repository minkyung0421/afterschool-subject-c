#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void draw_check01(int column, int row);
void gotoxy(int x, int y);


int main(void){
	int count = 0;
	int score = 0;
	printf("�ڡڡڡھ��ĺ� ���߱�ڡڡڡ�\n");
	printf("ȭ�鿡 ��Ÿ���� �ܾ �Է��ϼ���!\n");

	//�ٵ��� �׸���
	draw_check01(4, 4);
	printf("�ƹ�Ű�� �����ּ���(Enter����� Enter����� Enter�����...)");
	_getch();

	do{
		int x, y, alpha, check, user;
		system("cls");
		srand(time(NULL));
		draw_check01(4, 4);
		x = rand() % 4 + 1; //1~4������ �� �����ϰ�
		y = rand() % 4 + 1;
		//���ĺ� ���� �����ϰ� �������ϱ�
		alpha = rand() % 26;
		//��ҹ��� �����ϴ� ���� �����ϰ�
		check = rand() % 2;  //0 : �빮��, 1 : �ҹ���
		//����� ���ĺ��� �־��ֱ�
		alpha = 65 + 32 * check + alpha;

		x = x * 4; //���� ��ġ
		y = y * 2; //���� ��ġ

		gotoxy(x, y);
		printf("%c", alpha);
		//���Ƿ� ������ ������ Ŀ�� �̵�
		//���� ���
		gotoxy(1, 10);
		printf("���� >> ");

		Sleep(1000);
		//����ڰ� Ű���忡 �Էµ� ���� ���ĺ��� ������ ��
		gotoxy(1, 15);
		user = _getch();
		if (user == alpha){
			//���� ����� ������ 1����
			//score++;
			//printf("������� Exactly!");
		}
		count++;
	} while (count < 5);
	printf("���� ���� : %d", score++);
	gotoxy(1, 15);
}

void draw_check01(int c, int r){
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


void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 }; //��ǥ
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}