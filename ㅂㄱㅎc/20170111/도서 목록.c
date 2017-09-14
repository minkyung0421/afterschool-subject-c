#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct book_info{
	int year;
	char title[12];
};

typedef struct book_info BOOK;

int main(){
	BOOK *books;
	int size, i;

	do{
		printf("������ �Է��� ���� �Ǽ� : "); scanf("%d", &size);
		if (size <= 0)
			printf("���� : �Ǽ��� �߸� �Է��Ͽ����ϴ�. �ٽ� �Է��ϼ���");
	} while (size <= 0);

	books = (BOOK *)malloc(sizeof(BOOK)*size);
	if (books == NULL){
		printf("���� ������ �Ҵ翡 �����Ͽ����ϴ�\n");
		exit(1);
	}

	for (i = 0; i < size; i++){
		printf("%d) �����̸� : ", i + 1);
		fflush(stdin);
		scanf("%s", books[i].title);

		printf(" ���ǳ⵵ : ");
		scanf("%d", &(books[i].year));
	}

	printf("\n >> ���� ���� ��� <<\n");
	printf("\n ���� ������ ���ǳ⵵ ");
	printf("==================\n");
	for (i = 0; i < size; i++){
		printf("%3d %-12s %4d\n", i + 1, books[i].title, books[i].year);
	}
	printf("==================\n");

	free(books);

	return 0;
}