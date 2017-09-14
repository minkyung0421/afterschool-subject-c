#include <stdio.h>
int main(void){
	unsigned char a1 = 0xa2;
	unsigned char a2 = 0xbe;

	int i, j;

	for (i = 1; i <= 5; i++){
		for (j = 1; j <= i; j++)
			printf("%c%c", a1, a2);
		printf("\n");
	}

	return 0;
}