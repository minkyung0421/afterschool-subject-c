#include <stdio.h>

int main(void){
	unsigned char a1 = 0xa1;
	unsigned char a2 = 0xe1;

	int i, j;

	for (i = 1; i <= 5; i++)
		printf("%c%c", a1, a2);
	printf("\n");
	for (i = 1; i <= 2; i++){
		printf("%c%c", a1, a2);
		for (j = 1; j <= 6; j++)
			printf(" ");
		printf("%c%c\n", a1, a2);
	}

	for (i = 1; i <= 5; i++)
		printf("%c%c", a1, a2);
	printf("\n");
	
	return 0;
		
}