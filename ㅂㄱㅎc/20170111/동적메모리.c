#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int size, sum, i;  //�л���, �迭�� ���Ҽ�
	int *score; //�������� �Ҵ���� �����Ҹ� ����ų ������ ���� �� �迭��

	//���� �Ҵ� �������� ũ�⸦ �����ϱ� ���� �л� ���� �Է¹ޱ�
	printf("�л� ����? "); scanf("%d", &size);

	//size������ int�� ���� ������ ���� ������ �Ҵ� �� score�� ����Ű��
	score = (int *)malloc(sizeof(int)*size);

	//���� �Ҵ��� ���� ���ߴٸ� ���α׷��� ������ ������.
	if (score == NULL){
		printf("���� ������ �Ҵ翡 �����Ͽ����ϴ�\n");
		exit(1);		//���α׷� ���� �ߴ�
	}
}