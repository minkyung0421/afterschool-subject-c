#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void draw_check01(int column, int row);

int main(void){
	int row, column;

	printf("바둑판 그리기 >> ");
	scanf("%d %d", &column, &row);
	draw_check01(column, row);

	return 0;
}

void draw_check01(int c, int r){
	int i, j;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (i = 1; i < 12; i++){
		b[i] = 0xa0 + i;
	}

	printf("%c%c", a, b[3]);

	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[8]);
	}

	printf("%c%c", a, b[4]);
	printf("\n");
	
	//가운데 영역
	for (i = 0; i < r - 1; i++){
		printf("%c%c", a, b[7]);
		for (j = 0; j < c - 1; j++){
			printf("%c%c", a, b[11]);
		}
		printf("%c%c", a, b[9]);
		printf("\n");
	}

	//아래쪽 영역
	printf("%c%c", a, b[6]);

	for (i = 0; i < c - 1; i++){
		printf("%c%c", a, b[10]);
	}
	printf("%c%c", a, b[5]);
	printf("\n");
}