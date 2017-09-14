#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_NUM 100
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct ___phoneData{
	char name[NAME_LEN];
	char phoneNum[PHONE_LEN];
}phoneData;

void InputPhoneData(void);
void ShowAllData(void);
void SearchPhoneData(void);
void DeletePhoneData(void);

void ShowMenu(void);
void ShowPhoneInfo(phoneData phone);

int numofData = 0;
phoneData * phoneList[LIST_NUM];

enum{ INPUT = 1, SHOWALL, SEARCH, DELETE, QUIT };

void InputPhoneData(void){
	phoneData *pData;

	if (numofData >= LIST_NUM){
		puts("�޸� ������ �����մϴ�.");
		return;
	}

	pData = (phoneData *)malloc(sizeof(phoneData));

	fputs("�̸� �Է� : ", stdout);

	gets(pData->name);

	fputs("��ȭ��ȣ �Է� : ", stdout);

	gets(pData->phoneNum);

	phoneList[numofData] = pData;

	numofData++;

	puts("�Է��� �Ϸ�Ǿ����ϴ�.");
	_getchar();
}

void SearchPhoneData(void){
	int i;
	char searchName[NAME_LEN];
	
	fputs("ã�� �̸���? ", stdout);
	gets(searchName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, searchName)){
			ShowPhoneInfoByPtr(phoneList[i]);

			puts("�˻��� �Ϸ�Ǿ����ϴ�.");
			_getchar();
			return;
		}
	}


	puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�.");
	_getchar();
}

void DeletePhoneData(void){
	int i, j;
	char delName[NAME_LEN];

	fputs("ã�� �̸���? ", stdout);
	gets(delName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, delName)){
			free(phoneList[i]);

			for (j = 1; i < numofData - 1; j++){
				phoneList[j] = phoneList[j + 1];
			}

			numofData--;
			puts("������ �Ϸ�Ǿ����ϴ�\n");
			getchar();
			return;
		}
	}

	puts("ã�� �̸��� �����Ͱ� �������� �ʽ��ϴ�");
	getchar();
}

void ShowMenu(void){
	system("cls");

	printf("------------�޴�------------\n");
	printf("1. ��ȭ��ȣ �Է�\n");
	printf("2. ��ü ���� ���\n");
	printf("3. ��ȭ��ȣ �˻�\n");
	printf("4. ��ȭ��ȣ ����\n");
	printf("5. ����\n");
	printf("----------------------------\n");
	printf("���� >> ");
}

void ShowPhoneInfo(phoneData phone){
	printf("------------------------------------\n");
	printf("|  �� �̸� : %s \n", phone.name);
	printf("|  �� ��ȭ��ȣ : %s \n",phone.phoneNum);
	printf("------------------------------------\n");
}

void ShowPhoneInfoByPtr(phoneData * pPhone){
	printf("------------------------------------\n");
	printf("|  �� �̸� : %s \n", pPhone->name);
	printf("|  �� ��ȭ��ȣ : %s \n", pPhone->phoneNum);
	printf("------------------------------------\n");
}