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
		printf("정보를 입력할 도서 권수 : "); scanf("%d", &size);
		if (size <= 0)
			printf("에러 : 권수를 잘못 입력하였습니다. 다시 입력하세요");
	} while (size <= 0);

	books = (BOOK *)malloc(sizeof(BOOK)*size);
	if (books == NULL){
		printf("동적 기억장소 할당에 실패하였습니다\n");
		exit(1);
	}

	for (i = 0; i < size; i++){
		printf("%d) 도서이름 : ", i + 1);
		fflush(stdin);
		scanf("%s", books[i].title);

		printf(" 출판년도 : ");
		scanf("%d", &(books[i].year));
	}

	printf("\n >> 도서 정보 목록 <<\n");
	printf("\n 순번 도서명 출판년도 ");
	printf("==================\n");
	for (i = 0; i < size; i++){
		printf("%3d %-12s %4d\n", i + 1, books[i].title, books[i].year);
	}
	printf("==================\n");

	free(books);

	return 0;
}