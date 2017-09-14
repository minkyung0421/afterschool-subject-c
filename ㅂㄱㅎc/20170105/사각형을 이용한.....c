#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void draw_square(int size);
void draw_square_xy(int size, int x, int y);

int main(void){
	int square_size = 10;
	char key;
	printf("�簢���� ũ�⸦ ���������� �����ϴ� animation\n\n");
	printf("��� : Enter�� �����ּ���\n\n");
	_getch();
	system("cls");
	printf("�������� ȭ��ǥ Ű�� �簢�� ũ�� ����\n\n");
	printf("�������� ȭ��ǥ Ű�� �簢�� ũ�� ����\n\n");
	printf("animationó�� �߿� �ƹ�Ű�� ������ �����մϴ�\n\n");
	printf("�ƹ�Ű�� ������ �����մϴ�\n");
	_getch();
	system("cls");

	do{
		draw_square(square_size);
		key = _getch();

		do{
			system("cls");
			if (key == 75)
				draw_square(square_size--);
			if (key == 77)
				draw_square(square_size++);
			if (square_size < 1)
				square_size = 1;
			if (square_size>20)
				square_size = 20;
			printf("size = %d", square_size);
		} while (!_kbhit());
	} while (key != 27);
	return 0;
}

void draw_square(int size){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];

	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");

	for (i = 0; i < size; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < size; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}
	printf("%c%c", a, b[6]);
	for (i = 0; i < size; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}
