#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

void questions(void);
void gotoxy(int x, int y);

int main(void){
	printf("�ڡڡڡ�Ÿ �� �� �� �� �� �� ���ڡڡڡ�\n\n");
	printf(">>������ ��Ÿ���� �ش� �ܾ �Է��մϴ�.\n");
	printf(">>ó�� ������ 100���̸� Ʋ�� ������ 10���� �����մϴ�.\n\n");
	printf(">>Press Enter to get started.");
	_getch();
	questions();
	return 0;
}

void questions(void){
	char *quest1[] = { "People in zone 20-30 km from plant encouraged to leave.",
		"More than 10,000 dead, 17,500 missing after quake, tsunami.",
	"We're blood. Run without clogging. Turn the oxygen on. Brain can rotate normally.",
	"Do not look down, volleyball is a sport to see the stomach",
	"Only one block. Only one point out of 25 points. At best, club activity",
	"Because there is no wing, people is looking for the how to fly"};
	char input;
	int count, length, i, j, sumsu =100;
	system("cls");

	for (i = 0; i < 5; i++){
		system("cls");
		count = 0;
		printf("���� %d: >", i + 1);
		printf("%s\n", quest1[i]);
		length = strlen(quest1[i]);
		gotoxy(1, 2);
		printf("�� ��   >    ");
		gotoxy(1, 3);
		printf("�� ��   >    ");

		gotoxy(1, 5);
		printf("Ʋ�� �ܾ� : ");

		for (j = 1; j < length; j++){
			gotoxy(9 + j, 2);
			input = _getch();
			gotoxy(9 + j, 2);
			printf("%c", input);

			if (input == quest1[i][j - 1]){
				gotoxy(9 + j, 3);
				printf("  ");
			}
			else{
				gotoxy(9 + j, 3);
				printf("X");
				count++;
				gotoxy(9 + count, 5);
				printf("%c", quest1[i][j - 1]);
				sumsu -= 10;
			}
		}
			gotoxy(1, 9);
			printf("�Է� ���� : %dgȸ", count);
			gotoxy(1, 10);
			printf("�ƹ�Ű�� ������ ���� ������ ����մϴ�.");
			_getch();
		}
	printf("���� Ÿ�� ������ �������ϴ�.\n\n");
	printf("����� ������ %d�� �Դϴ�!", sumsu);

}

void gotoxy(int x, int y){

	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}