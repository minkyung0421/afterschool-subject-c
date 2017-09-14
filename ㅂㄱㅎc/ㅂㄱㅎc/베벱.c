#include <stdio.h>
#include <conio.h>

int main(void){
	char chr;
	do{
		printf("키 누르기");
		chr = getch();
		printf("\n 키: %c, ASCII(10): %d, (16진수):%x", chr, chr, chr);
	} while (chr != '0');

	return 0;
}