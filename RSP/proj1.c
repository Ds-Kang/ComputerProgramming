#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int i = 0;
int cash = 1000000, win = 0, lose = 0;
int num, bet;

void home(void);
void state(int, int, int);
void game();
void RSP(void);

int main(void) {
	home();
	return 0;
}

void click(void) {
	int click = 0;
	while (click == 0) { click = _kbhit(); }
	_getch();
}

void home(void) {
	printf("\t--------------------------------------");
	printf("\n\t\t1. My State\n");
	printf("\t\t2. RSP\n");
	printf("\t\t3. End\n");
	printf("\t--------------------------------------");
	printf("\n\t\tEnter the number: ");
	scanf_s("%d", &num);
	switch (num) {
	case 1:
		system("cls");
		state(cash, win, lose);
		break;
	case 2:
		system("cls");
		RSP();
		break;
	case 3:
		return;
	default:
		printf("\t\tPlease reenter: ");
		scanf_s("%d", &num);
	}
}

void state(int cash, int win, int lose) {
	printf("\t--------------------------------------");
	printf("\n\t\tUser's State\n");
	printf("\t\tCash: %d won\n",cash);
	printf("\t\tWin: %d\n",win);
	printf("\t\tLose: %d\n", lose);
	printf("\t--------------------------------------");
	printf("\n\t\tPlease Enter any key to return\n");
	click();
	system("cls");
	home();
}

void game() {
	int rock = 0, scissor = 1, paper = 2;
	int user, com;
	printf("\t--------------------------------------");
	printf("\n\t\tRock Scissors Paper\n\n");
	printf("\t\tStart?\n");
	printf("\t--------------------------------------");
	click();
	printf("\n\t\t3...\n"); Sleep(1000);
	printf("\t\t2..\n"); Sleep(1000);
	printf("\t\t1.\n"); Sleep(1000);
	printf("\t\trock, "); Sleep(500);
	printf("scissors, "); Sleep(500);
	printf("paper!\n\n");
	if (_kbhit()) {
		switch (_getch()) {
		case 'q':
			user = rock;
			break;
		case 'w':
			user = scissor;
			break;
		case 'e':
			user = paper;
			break;
		}
	}
	else {
		printf("\t\tDo not Enter any key\n");
		printf("\t\tLose!\n");
		printf("\t\t%d\n", -bet);
		cash -= bet;
		printf("\t\t%d\n", cash);
	}
	srand(time(NULL));
	com = rand() % 3;
	if (user == 0) printf("\n\t\tUser: Rock");
	else if (user == 1) printf("\n\t\tUser: Scissors");
	else printf("\n\t\tUser: Paper");
	if (com == 0) printf("\n\t\tCom: Rock\n");
	else if (com == 1) printf("\n\t\tCom: Scissors\n");
	else printf("\n\t\tCom: Paper\n");
	int result = user - com;
	if (result == -1 || result == 2) {
		printf("\t\tWin!\n");
		printf("\t\t+%d\n\n", bet);
		cash += bet;
		win++;
	}
	else if (result == 0) {
		printf("\t\tDraw!\n");
		printf("\t\tRestart\n\n");
		click();
		game();
	}
	else {
		printf("\t\tLose!\n");
		printf("\t\t-%d\n\n", bet);
		cash -= bet;
		lose++;
	}
	printf("\t\tCash: %d\n", cash);
	printf("\t\tOne more?\n");
	printf("\t\t1. Yes\n");
	printf("\t\t2. No\n");
	num = 0;
	while (!(num == 1 || num == 2)) {
		scanf_s("%d", &num);
	}
	if (num == 1) {
		system("cls");
		game();
	}
	else if (num == 2) {
		system("cls");
		home();
	}
}

void RSP(void) {
	printf("\t--------------------------------------");
	printf("\n\t\tRock Scissors Paper\n");
	printf("\t--------------------------------------");
	printf("\n\t\tCash: %d\t\n", cash);
	printf("\t\tHow much do you want to bet?\n\t\t: ");
	scanf_s("%d", &bet);
	while (bet > cash) {
		printf("\t\tNot enough money!\n");
		printf("\t\tReenter please: ");
		scanf_s("%d", &bet);
	}
	printf("\t\tOK\n\t\t..then Now start!\n");
	click();
	system("cls");
	game();
}
