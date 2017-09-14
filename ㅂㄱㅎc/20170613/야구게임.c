#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>


void mainmenu(void){ //게임설명
	
	printf("*********베이스볼 게임********\n");
	printf("*                            *\n");
	printf("*                            *\n");
	printf("*       1. 초      급        *\n");
	printf("*                            *\n");
	printf("*       2. 중      급        *\n");
	printf("*                            *\n");
	printf("*       3. 고      급        *\n");
	printf("*                            *\n");
	printf("*                            *\n");
	printf("******************************\n");
	
}

void easymode(void){ //초급
	srand((unsigned)time(NULL)); //랜덤함수를 쓰기 위함
	int c1 = 0, c2 = 0, c3 = 0; //컴퓨터의 값(랜덤값)
	int h1 = 0, h2 = 0, h3 = 0; //사용자가 입력한 값
	int S = 0, B = 0; //맞췄을 경우 S, 자리만 다를 경우 B 
	int count = 0; //몇 번만에 맞췄는지 세기 위함

		c1 = rand() % 9 + 1; //c1에 0부터 9까지의 랜덤값을 넣겠다

		//중복 제거를 위함
		do{
			c2 = rand() % 9 + 1; //c2에 0부터 9까지의 랜덤값을 넣겠다.
		} while (c1 == c2); //c1의 랜덤값과 c2의 랜덤값이 같게 될 경우 반복 그만

		do{
			c3 = rand() % 9 + 1; //c3에 0부터 9까지의 랜덤값을 넣겠다
		} while (c3 == c1 || c3 == c2); //c3와 c1이 같거나, c3와 c2가 같게 될 경우 반복 그만

		//printf("%d %d %d\n", c1, c2, c3);

		for (count = 0; S != 3; count++){ //count = 0부터 스트라이크가 3번이 아닐 때까지 count를 +1한다
			S = 0, B = 0; //초기값 0

			printf("숫자 3개를 입력하세요(ex 1 2 3) >> ");
			scanf_s("%d%d%d", &h1, &h2, &h3);

			if (c1 == h1) S++; //만약 첫번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
			else if (h1 == c2 || h1 == c3) B++; //만약 입력받은 첫번째 수가 두번째 세번째 랜덤값과 같을 경우 B + 1

			if (c2 == h2) S++; //두번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
			else if (h2 == c1 || h2 == c3) B++;

			if (c3 == h3) S++;
			else if (h3 == c1 || h3 == c2) B++;

			printf("[%dS %dB]\n", S, B); //S의 갯수와 B의 갯수 표시
		}

		if (count < 10){
			printf("정말 빠르네요! 중급 도전?\n");
			printf("당신은 %d번째만에 맞췄습니다!!\n", count);
		}
		else if (count > 10){
			printf("좀 더 연습이 필요할 것 같네요.. ㅠ\n");
			printf("당신은 %d번째만에 맞췄습니다!! \n", count);
		}
	}//end of easymode

void normalmode(void){
	srand((unsigned)time(NULL)); //랜덤함수를 쓰기 위함
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
	int h1 = 0, h2 = 0, h3 = 0, h4 = 0;
	int S = 0, B = 0; //맞췄을 경우 S, 자리만 다를 경우 B 
	int count = 0; //몇 번만에 맞췄는지 세기 위함

	c1 = rand() % 9 + 1; //c1에 0부터 9까지의 랜덤값을 넣겠다

	//중복 제거를 위함
	do{
		c2 = rand() % 9 + 1; //c2에 0부터 9까지의 랜덤값을 넣겠다.
	} while (c1 == c2); //c1의 랜덤값과 c2의 랜덤값이 같게 될 경우 반복 그만

	do{
		c3 = rand() % 9 + 1; //c3에 0부터 9까지의 랜덤값을 넣겠다
	} while (c3 == c1 || c3 == c2); //c3와 c1이 같거나, c3와 c2가 같게 될 경우 반복 그만

	do{
		c4 = rand() % 9 + 1;
	} while (c4 == c1 || c4 == c2 || c4 == c3);

	printf("%d %d %d %d\n", c1, c2, c3, c4);

	for (count = 0; S != 4; count++){ //count = 0부터 스트라이크가 3번이 아닐 때까지 count를 +1한다
		S = 0, B = 0; //초기값 0

		printf("숫자 4개를 입력하세요(ex 1 2 3 4) >> ");
		scanf_s("%d%d%d%d", &h1, &h2, &h3, &h4);

		if (c1 == h1) S++; //만약 첫번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
		else if (h1 == c2 || h1 == c3 || h1 == c4) B++; //만약 입력받은 첫번째 수가 두번째 세번째 랜덤값과 같을 경우 B + 1

		if (c2 == h2) S++; //두번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
		else if (h2 == c1 || h2 == c3 || h2 == c4) B++;

		if (c3 == h3) S++;
		else if (h3 == c1 || h3 == c2 || h3 == c4) B++;

		if (c4 == h4) S++;
		else if (h4 == c1 || h4 == c2 || h4 == c3) B++;

		printf("[%dS %dB]\n", S, B); //S의 갯수와 B의 갯수 표시
	}

	if (count < 15){
		printf("정말 빠르네요! 고급 도전?\n");
		printf("당신은 %d번째만에 맞췄습니다!!\n", count);
	}
	else if (count > 15){
		printf("좀 더 연습이 필요할 것 같네요.. ㅠ\n");
		printf("당신은 %d번째만에 맞췄습니다!! \n", count);
	}

}//end of normalmode

void hardmode(void){
	srand((unsigned)time(NULL)); //랜덤함수를 쓰기 위함
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0; //컴퓨터의 값(랜덤값)
	int h1 = 0, h2 = 0, h3 = 0, h4 = 0, h5 = 0; //사용자가 입력한 값
	int S = 0, B = 0; //맞췄을 경우 S, 자리만 다를 경우 B 
	int count = 0; //몇 번만에 맞췄는지 세기 위함

	c1 = rand() % 9 + 1; //c1에 0부터 9까지의 랜덤값을 넣겠다

	//중복 제거를 위함
	do{
		c2 = rand() % 9 + 1; 
	} while (c1 == c2); 

	do{
		c3 = rand() % 9 + 1; 
	} while (c3 == c1 || c3 == c2); 

	do{
		c4 = rand() % 9 + 1;
	} while (c4 == c1 || c4 == c2 || c4 == c3);

	do{
		c5 = rand() % 9 + 1;
	} while (c5 == c1 || c5 == c2 || c5 == c3 || c5 == c4);

	//printf("%d %d %d %d %d\n", c1, c2, c3, c4, c5);

	for (count = 0; S != 5; count++){ 
		S = 0, B = 0; //초기값 0
		printf("숫자 5개를 입력하세요(ex 1 2 3 4 5) >> ");
		scanf_s("%d%d%d%d%d", &h1, &h2, &h3, &h4, &h5);

		if (c1 == h1) S++; //만약 첫번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
		else if (h1 == c2 || h1 == c3 || h1 == c4 || h1 == c5) B++; //만약 입력받은 첫번째 수가 두번째 세번째 랜덤값과 같을 경우 B + 1

		if (c2 == h2) S++; //두번째 수의 랜덤값과 입력받은 수가 같으면 S + 1
		else if (h2 == c1 || h2 == c3 || h2 == c4 || h2 == c5) B++;

		if (c3 == h3) S++;
		else if (h3 == c1 || h3 == c2 || h3 == c4 || h2 == c5) B++;

		if (c4 == h4) S++;
		else if (h4 == c1 || h4 == c2 || h4 == c3 || h2 == c5) B++;

		if (c5 == h5) S++;
		else if (h5 == c1 || h5 == c2 || h5 == c3 || h5 == c4) B++;

		printf("[%dS %dB]\n", S, B); //S의 갯수와 B의 갯수 표시
	}

	if (count < 20){
		printf("정말 빠르네요! 최고난이도 도전?\n");
		printf("당신은 %d번째만에 맞췄습니다!!\n", count);
	}
	else if (count > 20){
		printf("좀 더 연습이 필요할 것 같네요.. ㅠ\n");
		printf("당신은 %d번째만에 맞췄습니다!! \n", count);
	}

}

void endgame(void){
	int choice;
	printf("\n");
	printf("메인메뉴로 돌아가려면 4번 누르고 \n끝내려면 ctrl + c를 입력해주세요!\n");
	printf(">> ");
	scanf_s("%d", &choice);
	if (choice == 4){
		system("cls");
		mainmenu();
	}
	
}//end of endgame


int main(void){
	int choice; //난이도 선택
	mainmenu();
	
	for (;;){
		printf("\n");
		printf("당신의 선택은? >> ");
		scanf_s("%d", &choice);
		system("cls"); //이전의 결과를 지워준다


		//초급부분
		if (choice == 1){
			printf("\n");
			printf("★★★베이스볼 게임 초급입니다!★★★\n\n");
			printf("3개의 숫자를 가지고 게임을 합니다.\n");
			printf("숫자를 입력할 때 한칸씩 띄고 입력해주세요!\n");
			printf("행운을 빌어요!\n\n");
			printf("아무키나 누르면 게임을 시작합니다!");
			_getch(); //키를 누를 때 까지 잠시 멈춤
			system("cls"); //이전결과를 지워줌
			easymode(); //easymode() 메소드 호출
			endgame(); //endgame() 메소드 호출
		}

		//중급부분
		if (choice == 2){
			printf("\n");
			printf("☆☆☆☆베이스볼 게임 중급입니다!☆☆☆☆\n\n");
			printf("4개의 숫자를 가지고 게임을 합니다.\n");
			printf("숫자를 입력할 때 한칸씩 띄고 입력해주세요!\n");
			printf("행운을 빌어요~~\n\n");
			printf("아무키나 누르면 게임을 시작합니다!");
			_getch();
			system("cls");
			normalmode();
			endgame();
		}

		//고급부분
		if (choice == 3){
			printf("\n");
			printf("♥♥♥♥♥베이스볼 게임 고급입니다!♥♥♥♥♥\n\n");
			printf("5개의 숫자를 가지고 게임을 합니다.\n");
			printf("숫자를 입력할 때 한칸씩 띄고 입력해주세요!\n");
			printf("마지막 단계입니다! 행운을 빌어요~~\n\n");
			printf("아무키나 누르면 게임을 시작합니다!");
			_getch(); //키를 누를 때 까지 잠시 멈춤
			system("cls"); //이전결과를 지워줌
			hardmode(); //hardmode() 메소드 호출
			endgame(); //endgame() 메소드 호출
		}
	}

}//end of main

