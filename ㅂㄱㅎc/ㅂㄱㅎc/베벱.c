#include <stdio.h>
#include <conio.h>

int main(void){
	char chr;
	do{
		printf("Ű ������");
		chr = getch();
		printf("\n Ű: %c, ASCII(10): %d, (16����):%x", chr, chr, chr);
	} while (chr != '0');

	return 0;
}