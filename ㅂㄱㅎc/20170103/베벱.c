#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw_square(int size);

int main(void){
	int n = 0;
	int num = 0;
	printf("★★★★★정사각형 그리기★★★★★\n\n");
	printf("아무 키를 누르면 시작합니다~ ♬ \n\n");
	_getch();
	printf("정사각형의 길이(최대 37) 를 입력하고 Enter를 눌러주세yo♥♥♥ >> ");
	scanf("%d", &n);
	if (n <= 0 || n > 37){
		printf("\n");
		printf("정사각형을 만들 수 없는 숫자 입니다...^p^");
		printf("\n\n");
		exit(1);
	}
	draw_square(n);

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