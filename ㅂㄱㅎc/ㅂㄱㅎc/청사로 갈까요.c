#include <stdio.h>
#include <conio.h>

int main(void){
	int chr;
	do{
		chr = _getch();
		if (chr == 0 || chr == 0xe0){
			chr = _getch();
			printf("확장키 code=%d\n", chr);
		}
		else
			printf("아스키 code=%d\n", chr);
	} while (1);

	return 0;
}

void move_arrow_key(char key, int *x, int *y, int x_b, int y_b)
{
	switch (key)
	{
		//↑
	case 72:
		*y = *y - 1;
		if (*y < 1) *y = 1;
		break;
		//←
	case 75:
		*x = *x - 2;
		if (*x < 1)*x = 1;
		break;
		//→
	case 77:
		*x = *x + 2;
		if (*x > x_b)*x = x_b;
		break;
		//↓
	case 80:
		*y = *y + 1;
		if (*y > y_b) *y = y_b;
		break;
	case 71:
		*x = *x - 2;

		*y = *y - 1;
		if (*x < 1)*x = 1;
		if (*y < 1) *y = 1;
		break;
	case 73:
		*x = *x + 2;
		*y = *y - 1;
		if (*x > x_b)*x = x_b;
		if (*y < 1) *y = 1;
		break;
	case 79:
		*x = *x - 2;
		*y = *y + 1;
		if (*x < 1)*x = 1;
		if (*y > y_b) *y = y_b;
		break;
	case 81:
		*x = *x + 2;
		*y = *y + 1;
		if (*x > x_b)*x = x_b;
		if (*y > y_b) *y = y_b;
		break;
	}
}