#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int menu_display(void);
int sub_menu_display01(void); //��Ģ����
int sub_menu_display02(void); //�α� ����
void sub_main01(void); //��Ģ���� �޴�
void sub_main02(void); //�α׿��� �޴�

void add(void);
void subtraction(void);
void press_any_key(void);

int main(void){
	int c;
	while ((c = menu_display()) != 3){
		switch (c){
		case 1: sub_menu_display01();
			break;
		case 2: sub_menu_display02();
			break;
		default :	break;
		}
	}
	return 0;
}

int menu_display(void){
	int select;
	system("cls");
	printf("��� ���α׷�\n\n");
	printf("1. ��Ģ����\n");
	printf("2. �α׿���\n");
	printf("3. ���α׷� ����\n\n");
	printf("�޴���ȣ �Է� >> ");
	select = _getch() - 48;
	
}

int sub_menu_display01(void){
	int select;
	system("cls");
	printf("��Ģ����\n\n");
	printf("1. ����(+) ����\n");
	printf("2. ����(-) ����\n");
	printf("3. ������(/) ����\n");
	printf("4. ����(*) ����\n");
	printf("5. ������(%) ����\n");
	printf("6. ���θ޴��� �̵�\n\n");
	printf("�޴���ȣ �Է� >> ");
	select = _getch() - 48;
	return select;
}

void add(void){
	double num1, num2;
	printf("��Ģ���� ����\n\n");
	printf("�� �� x�� y�� �Է��� �ּ��� >> ");
	scanf("%d %d", &num1, &num2);
	printf("���� ����� %d �Դϴ�.", num1 + num2);
	press_any_key();
}

void subtraction(void){
	double num1, num2;
	printf("��Ģ���� ����\n\n");
	printf("�� �� x�� y�� �Է��� �ּ��� >> ");
	scanf("%d %d", &num1, &num2);
	printf("���� ����� %d �Դϴ�.", num1 - num2);
	press_any_key();
}


int sub_menu_display02(void){
	system("cls");
	printf("�α� ����");
}

void press_any_key(void){
	printf("\n\n");
	printf("�ƹ� Ű�� ������ ���θ޴���....\n");
	_getch();
}

