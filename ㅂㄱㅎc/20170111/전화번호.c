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
		puts("메모리 공간이 부족합니다.");
		return;
	}

	pData = (phoneData *)malloc(sizeof(phoneData));

	fputs("이름 입력 : ", stdout);

	gets(pData->name);

	fputs("전화번호 입력 : ", stdout);

	gets(pData->phoneNum);

	phoneList[numofData] = pData;

	numofData++;

	puts("입력이 완료되었습니다.");
	_getchar();
}

void SearchPhoneData(void){
	int i;
	char searchName[NAME_LEN];
	
	fputs("찾는 이름은? ", stdout);
	gets(searchName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, searchName)){
			ShowPhoneInfoByPtr(phoneList[i]);

			puts("검색이 완료되었습니다.");
			_getchar();
			return;
		}
	}


	puts("찾는 이름의 데이터가 존재하지 않습니다.");
	_getchar();
}

void DeletePhoneData(void){
	int i, j;
	char delName[NAME_LEN];

	fputs("찾는 이름은? ", stdout);
	gets(delName);

	for (i = 0; i < numofData; i++){
		if (!strcmp(phoneList[i]->name, delName)){
			free(phoneList[i]);

			for (j = 1; i < numofData - 1; j++){
				phoneList[j] = phoneList[j + 1];
			}

			numofData--;
			puts("삭제가 완료되었습니다\n");
			getchar();
			return;
		}
	}

	puts("찾는 이름의 데이터가 존재하지 않습니다");
	getchar();
}

void ShowMenu(void){
	system("cls");

	printf("------------메뉴------------\n");
	printf("1. 전화번호 입력\n");
	printf("2. 전체 정보 출력\n");
	printf("3. 전화번호 검색\n");
	printf("4. 전화번호 삭제\n");
	printf("5. 종료\n");
	printf("----------------------------\n");
	printf("선택 >> ");
}

void ShowPhoneInfo(phoneData phone){
	printf("------------------------------------\n");
	printf("|  ▶ 이름 : %s \n", phone.name);
	printf("|  ▶ 전화번호 : %s \n",phone.phoneNum);
	printf("------------------------------------\n");
}

void ShowPhoneInfoByPtr(phoneData * pPhone){
	printf("------------------------------------\n");
	printf("|  ▶ 이름 : %s \n", pPhone->name);
	printf("|  ▶ 전화번호 : %s \n", pPhone->phoneNum);
	printf("------------------------------------\n");
}