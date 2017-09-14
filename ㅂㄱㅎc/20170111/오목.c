#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b);
void gotoxy(int x, int y);
void draw_check01(int c, int r);
void game_control(void);
void display_stone(int matrix[][20][20]);
int judgement(int matrix[][20][20]);

int main(void){
	game_control();
	return 0;
}

void move_arrow_key(char key, int *x1, int *y1, int x_b, int y_b)
{
	switch (key){
	case 72:
		*y1 = *y1 - 1;  //����(��) ������ ȭ��ǥ Ű �Է�
		if (*y1 < 1) *y1 = 1;  //y��ǥ�� �ּڰ�
		break; 
	case 75:
		*x1 = *x1 - 2;  //����(��) ������ ȭ��ǥ Ű �Է�
		if (*x1 < 1) *x1 = 1;  //x��ǥ�� �ּڰ�
		break;
	case 77:
		*x1 = *x1 + 2;  //������(��) ������ ȭ��ǥ Ű �Է�
		if (*x1>x_b) *x1 = x_b; //x��ǥ�� �ִ�
		break;
	case 80:
		*y1 = *y1 + 1;  //�Ʒ���(��) ������ ȭ��ǥ Ű �Է�
		if (*y1 > y_b) *y1 = y_b;  //y��ǥ�� �ִ�
		break;
	default:
		return;
	}
}

void gotoxy(int x, int y){
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void draw_check01(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++)
		b[i] = 0xa0 + i;
	printf("%c%c", a, b[3]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[8]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[7]);
		for (j = 0; j < c; j++)
			printf("%c%c", a, b[11]);
		printf("%c%c", a, b[9]);
		printf("\n");
	}

	printf("%c%c", a, b[6]);
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[10]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

void display_stone(int matrix[][20][20]){
	int i, x, y;
	char *stone[2] = { "��", "��" };
	
	for (i = 0; i < 2;i++)
		for (x = 1; x < 20;x++)
			for (y = 1; y < 20; y++){
				if (matrix[i][x][y] == 1){
					gotoxy(x * 2 - 1, y);
					printf("%s", stone[i]);
				}
			}
}

void game_control(void){
	int x = 1, y = 1, other = 0;
	int matrix[2][20][20] = { 0 };
	char key, judge = 0;
	char *stone[2] = { "��", "��" };

	do{
		gotoxy(1, 1);
		draw_check01(18, 18);
		gotoxy(x, y);
		printf("%s", stone[other]);
		display_stone(matrix);
		gotoxy(1, 20);
		if (other)
			printf("�� �����Դϴ�.");
		else
			printf("�� �����Դϴ�.");
		gotoxy(1, 21);
		printf("����Ű�� �����̰� �����̽� Ű�� ��������.");

		key = _getch();
		if (key == 27)
			exit(0);
		else if (key == 32){
			matrix[other][(x + 1) / 2][y] = 1;
			judge = judgement(matrix);
			if (judge != 0){
				gotoxy(1, 20);
				printf("�ڡڡڡ������մϴ�!!! %s���� �¸��ϼ̽��ϴ�~!!�ڡڡڡ�\n", stone[other]);
				exit(0);
			}
			other = 1 - other;
		}
		else if (key >= 72)
			move_arrow_key(key, &x, &y, 37, 19);
	} while (1);
}

int judgement(int matrix[][20][20]){
	int i, x, y;
	int z, c[4] = { 0 };  
	for (i = 0; i < 2; i++){
		for (x = 0; x < 16; x++){
			for (y = 0; y < 16; y++){
				c[0] = 0, c[1] = 0, c[2] = 0, c[3] = 0;
				for (z = 0; z < 5; z++){
					if (matrix[i][x][y + z] == 1){
						c[0]++;
						if (c[0] == 5)
							return 1;
					}
					if (matrix[i][x + z][y] == 1){
						c[2]++;
						if (c[2] == 5)
							return 1;
					}
					if (matrix[i][x + z][y + 5 - z] == 1){
						c[3]++;
						if (c[3] == 5)
							return 1;
					}
				}
			}
		}
	}
	return 0;
}