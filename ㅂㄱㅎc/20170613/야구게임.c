#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


void mainmenu(void){ //���Ӽ���
	
	printf("*********���̽��� ����********\n");
	printf("*                            *\n");
	printf("*                            *\n");
	printf("*       1. ��      ��        *\n");
	printf("*                            *\n");
	printf("*       2. ��      ��        *\n");
	printf("*                            *\n");
	printf("*       3. ��      ��        *\n");
	printf("*                            *\n");
	printf("*                            *\n");
	printf("******************************\n");
	
}

void easymode(void){ //�ʱ�
	srand((unsigned)time(NULL)); //�����Լ��� ���� ����
	int c1 = 0, c2 = 0, c3 = 0; //��ǻ���� ��(������)
	int h1 = 0, h2 = 0, h3 = 0; //����ڰ� �Է��� ��
	int S = 0, B = 0; //������ ��� S, �ڸ��� �ٸ� ��� B 
	int count = 0; //�� ������ ������� ���� ����

		c1 = rand() % 9 + 1; //c1�� 0���� 9������ �������� �ְڴ�

		//�ߺ� ���Ÿ� ����
		do{
			c2 = rand() % 9 + 1; //c2�� 0���� 9������ �������� �ְڴ�.
		} while (c1 == c2); //c1�� �������� c2�� �������� ���� �� ��� �ݺ� �׸�

		do{
			c3 = rand() % 9 + 1; //c3�� 0���� 9������ �������� �ְڴ�
		} while (c3 == c1 || c3 == c2); //c3�� c1�� ���ų�, c3�� c2�� ���� �� ��� �ݺ� �׸�

		//printf("%d %d %d\n", c1, c2, c3);

		for (count = 0; S != 3; count++){ //count = 0���� ��Ʈ����ũ�� 3���� �ƴ� ������ count�� +1�Ѵ�
			S = 0, B = 0; //�ʱⰪ 0

			printf("���� 3���� �Է��ϼ���(ex 1 2 3) >> ");
			scanf_s("%d%d%d", &h1, &h2, &h3);

			if (c1 == h1) S++; //���� ù��° ���� �������� �Է¹��� ���� ������ S + 1
			else if (h1 == c2 || h1 == c3) B++; //���� �Է¹��� ù��° ���� �ι�° ����° �������� ���� ��� B + 1

			if (c2 == h2) S++; //�ι�° ���� �������� �Է¹��� ���� ������ S + 1
			else if (h2 == c1 || h2 == c3) B++;

			if (c3 == h3) S++;
			else if (h3 == c1 || h3 == c2) B++;

			printf("[%dS %dB]\n", S, B); //S�� ������ B�� ���� ǥ��
		}

		if (count < 10){
			printf("���� �����׿�! �߱� ����?\n");
			printf("����� %d��°���� ������ϴ�!!\n", count);
		}
		else if (count > 10){
			printf("�� �� ������ �ʿ��� �� ���׿�.. ��\n");
			printf("����� %d��°���� ������ϴ�!! \n", count);
		}
	}//end of easymode

void normalmode(void){
	srand((unsigned)time(NULL)); //�����Լ��� ���� ����
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
	int S = 0, B = 0; //������ ��� S, �ڸ��� �ٸ� ��� B 
	int count = 0; //�� ������ ������� ���� ����

	c1 = rand() % 9 + 1; //c1�� 0���� 9������ �������� �ְڴ�

	//�ߺ� ���Ÿ� ����
	do{
		c2 = rand() % 9 + 1; //c2�� 0���� 9������ �������� �ְڴ�.
	} while (c1 == c2); //c1�� �������� c2�� �������� ���� �� ��� �ݺ� �׸�

	do{
		c3 = rand() % 9 + 1; //c3�� 0���� 9������ �������� �ְڴ�
	} while (c3 == c1 || c3 == c2); //c3�� c1�� ���ų�, c3�� c2�� ���� �� ��� �ݺ� �׸�

	do{
		c4 = rand() % 9 + 1;
	} while (c4 == c1 || c4 == c2 || c4 == c3);

	printf("%d %d %d %d\n", c1, c2, c3, c4);

	for (count = 0; S != 4; count++){ //count = 0���� ��Ʈ����ũ�� 3���� �ƴ� ������ count�� +1�Ѵ�
		S = 0, B = 0; //�ʱⰪ 0

		printf("���� 4���� �Է��ϼ���(ex 1 2 3 4) >> ");
		scanf_s("%d%d%d%d", &h1, &h2, &h3, &h4);

		if (c1 == h1) S++; //���� ù��° ���� �������� �Է¹��� ���� ������ S + 1
		else if (h1 == c2 || h1 == c3 || h1 == c4) B++; //���� �Է¹��� ù��° ���� �ι�° ����° �������� ���� ��� B + 1

		if (c2 == h2) S++; //�ι�° ���� �������� �Է¹��� ���� ������ S + 1
		else if (h2 == c1 || h2 == c3 || h2 == c4) B++;

		if (c3 == h3) S++;
		else if (h3 == c1 || h3 == c2 || h3 == c4) B++;

		if (c4 == h4) S++;
		else if (h4 == c1 || h4 == c2 || h4 == c3) B++;

		printf("[%dS %dB]\n", S, B); //S�� ������ B�� ���� ǥ��
	}

	if (count < 15){
		printf("���� �����׿�! ��� ����?\n");
		printf("����� %d��°���� ������ϴ�!!\n", count);
	}
	else if (count > 15){
		printf("�� �� ������ �ʿ��� �� ���׿�.. ��\n");
		printf("����� %d��°���� ������ϴ�!! \n", count);
	}

}//end of normalmode

void hardmode(void){
	srand((unsigned)time(NULL)); //�����Լ��� ���� ����
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0; //��ǻ���� ��(������)
	int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0; //����ڰ� �Է��� ��
	int S = 0, B = 0; //������ ��� S, �ڸ��� �ٸ� ��� B 
	int count = 0; //�� ������ ������� ���� ����

	c1 = rand() % 9 + 1; //c1�� 0���� 9������ �������� �ְڴ�

	//�ߺ� ���Ÿ� ����
	do{
		c2 = rand() % 9 + 1; 
	} while (c1 == c2); 

	do{
		c3 = rand() % 9 + 1; 
	} while (c3 == c1 || c3 == c2); 

	do{
		c4 = rand() % 9 + 1;
	} while (c4 == c1 || c4 == c2 || c4 == c3);

	do{
		c5 = rand() % 9 + 1;
	} while (c5 == c1 || c5 == c2 || c5 == c3 || c5 == c4);

	//printf("%d %d %d %d %d\n", c1, c2, c3, c4, c5);

	for (count = 0; S != 5; count++){ 
		S = 0, B = 0; //�ʱⰪ 0
		printf("���� 5���� �Է��ϼ���(ex 1 2 3 4 5) >> ");
		scanf_s("%d%d%d%d%d", &h1, &h2, &h3, &h4, &h5);

		if (c1 == h1) S++; //���� ù��° ���� �������� �Է¹��� ���� ������ S + 1
		else if (h1 == c2 || h1 == c3 || h1 == c4 || h1 == c5) B++; //���� �Է¹��� ù��° ���� �ι�° ����° �������� ���� ��� B + 1

		if (c2 == h2) S++; //�ι�° ���� �������� �Է¹��� ���� ������ S + 1
		else if (h2 == c1 || h2 == c3 || h2 == c4 || h2 == c5) B++;

		if (c3 == h3) S++;
		else if (h3 == c1 || h3 == c2 || h3 == c4 || h2 == c5) B++;

		if (c4 == h4) S++;
		else if (h4 == c1 || h4 == c2 || h4 == c3 || h2 == c5) B++;

		if (c5 == h5) S++;
		else if (h5 == c1 || h5 == c2 || h5 == c3 || h5 == c4) B++;

		printf("[%dS %dB]\n", S, B); //S�� ������ B�� ���� ǥ��
	}

	if (count < 20){
		printf("���� �����׿�! �ְ��̵� ����?\n");
		printf("����� %d��°���� ������ϴ�!!\n", count);
	}
	else if (count > 20){
		printf("�� �� ������ �ʿ��� �� ���׿�.. ��\n");
		printf("����� %d��°���� ������ϴ�!! \n", count);
	}

}

void endgame(void){
	int choice;
	printf("\n");
	printf("���θ޴��� ���ư����� 4�� ������ \n�������� ctrl + c�� �Է����ּ���!\n");
	printf(">> ");
	scanf_s("%d", &choice);
	if (choice == 4){
		system("cls");
		mainmenu();
	}
	
}//end of endgame


int main(void){
	int choice; //���̵� ����
	mainmenu();
	
	for (;;){
		printf("\n");
		printf("����� ������? >> ");
		scanf_s("%d", &choice);
		system("cls"); //������ ����� �����ش�


		//�ʱ޺κ�
		if (choice == 1){
			printf("\n");
			printf("�ڡڡں��̽��� ���� �ʱ��Դϴ�!�ڡڡ�\n\n");
			printf("3���� ���ڸ� ������ ������ �մϴ�.\n");
			printf("���ڸ� �Է��� �� ��ĭ�� ��� �Է����ּ���!\n");
			printf("����� �����!\n\n");
			printf("�ƹ�Ű�� ������ ������ �����մϴ�!");
			_getch(); //Ű�� ���� �� ���� ��� ����
			system("cls"); //��������� ������
			easymode(); //easymode() �޼ҵ� ȣ��
			endgame(); //endgame() �޼ҵ� ȣ��
		}

		//�߱޺κ�
		if (choice == 2){
			printf("\n");
			printf("�١١١ٺ��̽��� ���� �߱��Դϴ�!�١١١�\n\n");
			printf("4���� ���ڸ� ������ ������ �մϴ�.\n");
			printf("���ڸ� �Է��� �� ��ĭ�� ��� �Է����ּ���!\n");
			printf("����� �����~~\n\n");
			printf("�ƹ�Ű�� ������ ������ �����մϴ�!");
			_getch();
			system("cls");
			normalmode();
			endgame();
		}

		//��޺κ�
		if (choice == 3){
			printf("\n");
			printf("�������������̽��� ���� ����Դϴ�!����������\n\n");
			printf("5���� ���ڸ� ������ ������ �մϴ�.\n");
			printf("���ڸ� �Է��� �� ��ĭ�� ��� �Է����ּ���!\n");
			printf("������ �ܰ��Դϴ�! ����� �����~~\n\n");
			printf("�ƹ�Ű�� ������ ������ �����մϴ�!");
			_getch(); //Ű�� ���� �� ���� ��� ����
			system("cls"); //��������� ������
			hardmode(); //hardmode() �޼ҵ� ȣ��
			endgame(); //endgame() �޼ҵ� ȣ��
		}
	}

}//end of main

