#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define box_length 15 //게임의 영역(좌우 길이)
#define box_height 15

void draw_rectangle(int c, int r);

void draw_rectangle(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[7];
	for (i = 1; i < 7; i++)
		b[i] = 0xa0 + i;

	printf("%c%c", a, b[3]); //위쪽영역
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[4]);
	printf("\n");
	for (i = 0; i < r; i++){
		printf("%c%c", a, b[2]);
		for (j = 0; j < c; j++)
			printf("  ");
		printf("%c%c", a, b[2]);
		printf("\n");
	}

	printf("%c%c", a, b[6]); //아래쪽영역
	for (i = 0; i < c; i++)
		printf("%c%c", a, b[1]);
	printf("%c%c", a, b[5]);
	printf("\n");
}

int main(void){
	draw_rectangle(box_height, box_length);
}