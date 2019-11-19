#include <stdio.h>
#include <windows.h>
#include<stdlib.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4


int keyControl();
void init();
void titleDraw();
int menuDraw();
void gotoxy(int, int);
void reservation();
void reservationtime(int, int);
int isyoon(int a);
int dateprint();
int sprint();


int main() {

	init();
	titleDraw();
	int ans1;
	int menucode = menuDraw();


	system("cls");

	int datecode = dateprint();


	if (menucode == 0) { //예매
	   //시작
		while (1) {
			reservation(&datecode);
		}
	
	}

	if (menucode == 1) {   //티켓예매  출력
		printf("예매번호를 입력해 주십시오. (ex2019111601)");

	}
	if (menucode == 2) {  //종료
		system("cls");
		printf("종료합니다");
	}

}

int keyControl() {
	int temp = getch();

	if (temp == 72) {
		return UP;
	}
	else if (temp == 75) {
		return LEFT;
	}
	else if (temp == 80) {
		return DOWN;
	}
	else if (temp == 77) {
		return RIGHT;
	}
	else if (temp == 13) {
		system("cls");
		return SUBMIT;
	}
}

void init() {
	system("mode con cols=130 lines=40 | title SKT");
}

void titleDraw() {
	system("COLOR FC");
	printf("\n\n\n\n");
	printf("                                       :::::::::::::######::'##:::'##:'########:::#::#:::::\n");
	printf("                                       :::::::::::'##... ##: ##::'##::... ##..:::**##**::::\n");
	printf("                                       ::::::::::: ##:::..:: ##:'##:::::: ##::::::#::#:::::\n");
	printf("                                       :::::::::::. ######:: #####::::::: ##:::::::::::::::\n");
	printf("                                       ::::::::::::..... ##: ##. ##:::::: ##:::::::::::::::\n");
	printf("                                       :::::::::::'##::: ##: ##:. ##::::: ##:::::::::::::::\n");
	printf("                                       :::::::::::. ######:: ##::. ##:::: ##:::::::::::::::\n");
	printf("                                       ::::::::::::......:::..::::..:::::..::::::::::::::::\n");
	printf("                                       ::::::::::::::::::Sung Kyul Theatre:::::::::::::::::\n");
	return 0;
}

int menuDraw() {
	int x = 50;
	int y = 25;
	gotoxy(x - 2, y);
	printf(">    예매하기");
	gotoxy(x, y + 1);
	printf("   예매된 티켓 출력하기");
	gotoxy(x, y + 2);
	printf("   종료하기");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 25) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 27) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 25;

		}
		}
	}
}

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

void reservation(int *code) {
	int ans2;
	int date;
	int num1, num2, num3, num4;
	int ans_1[3][3];
	int sprintcode = sprint();
	ans_1[3][3] = ans2;
	
	while (1)
	{
		printf("날짜를 입력해주십시오.(ex 20191101) ");
		scanf("%d", &date);
		date /= 100;

		if (date == *code)
		{
			system("cls");

			system("cls");
			reservationtime(&num3, &num4);
			printf("좌석번호\n");
			printf("a1 a2 a3\n");
			printf("b4 b5 b6\n");
			printf("c7 c8 c9\n\n");
			printf("잠시만 기다려주세요. 곧 예매 페이지로 넘어갑니다.");
			_sleep(4000);
			system("cls");

			sprint(&ans_1);
			if (sprintcode == 0) {
				if (ans_1== 0)
					ans2= 1;
				printf("예약이 완료되었습니다.\n");

				return ans2;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 골라주세요.\n");
		}
		
		
		
		
		
		else
		{
			printf("잘못된 날짜입니다. 다시 입력해주세요.\n");
			_sleep(1000);
			system("cls");
		}
	}

}

int dateprint()
{
	int year;
	int month;
	int code;
	int i;
	int j;
	int k;
	int sum = 0;
	int chk = 0;
	int basicyear[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	printf("출력할 년,달 입력 ex)2019 11 : ");
	scanf("%d %d", &year, &month);


	if (isyoon(year)) {
		chk = 1;
		basicyear[1]++;
	}
	else
		chk = 0;

	sum = 365;
	for (i = 1; i < year; i++) {
		if (isyoon(i))
			sum += 366;
		else
			sum += 365;
	}


	for (i = 0; i < month - 1; i++) {
		sum += basicyear[i];
	}

	k = sum % 7;


	printf("SUN\tMON\tTUS\tWED\tTHU\tFRI\tSAT\n");
	printf("===================================================\n");


	for (j = 0; j < k; j++) {
		printf("\t");
	}

	for (i = 1; i <= basicyear[month - 1]; i++) {

		printf("%d\t", i);
		if (k == 6) {
			k = -1;
			printf("\n");
		}
		k++;
	}
	printf("\n");
	code = year * 100 + month;

	return code;

}

int isyoon(int a) {
	if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int mchkdraw() {
	int x = 50;
	int y = 25;
	gotoxy(x - 2, y);
	printf(">    예매하기");
	gotoxy(x, y + 1);
	printf("   예매된 티켓 출력하기");
	gotoxy(x, y + 2);
	printf("   종료하기");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 25) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 27) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 25;

		}
		}
	}
}

int sprint() {
	int x = 6;
	int y = 2;
	int a[3][3] = { 0 };
	int *p = a[3][3];

	gotoxy(x - 2, y);
	printf("A");
	gotoxy(x - 2, y + 1);
	printf("B");
	gotoxy(x - 2, y + 2);
	printf("C");
	gotoxy(x + 1, y - 1);
	printf("1");
	gotoxy(x + 4, y - 1);
	printf("2");
	gotoxy(x + 7, y - 1);
	printf("3");
	gotoxy(x, y);
	printf(">%d", a[0][0]);
	gotoxy(x, y + 1);
	printf(" %d", a[1][0]);
	gotoxy(x, y + 2);
	printf(" %d", a[2][0]);
	gotoxy(x + 3, y);
	printf(" %d", a[0][1]);
	gotoxy(x + 3, y + 1);
	printf(" %d", a[1][1]);
	gotoxy(x + 3, y + 2);
	printf(" %d", a[2][1]);
	gotoxy(x + 6, y);
	printf(" %d", a[0][2]);
	gotoxy(x + 6, y + 1);
	printf(" %d", a[1][2]);
	gotoxy(x + 6, y + 2);
	printf(" %d", a[2][2]);

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 4) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, ++y);
				printf(">");
			}
			break;
		}
		case LEFT: {
			if (x > 6) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x -= 3, y);
				printf(">");
			}
			break;
		}
		case RIGHT: {
			if (x < 12) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x += 3, y);
				printf(">");
			}

			break;
		}

		case SUBMIT: {
			
			return *p;
		}
		}
	}
}


void reservationtime(int *c, int *d)
{
	int x = 8;
	int y = 4;
	gotoxy(x, y - 2);
	printf("[영 화 시 간 대]");
	gotoxy(x, y);
	printf("> *8:30 (5/9)");
	gotoxy(x, y + 2);
	printf("   11:30(1/9)");
	gotoxy(x, y + 4);
	printf("   15:30(2/9)");
	gotoxy(x, y + 6);
	printf("   18:30(8/9)");
	gotoxy(x, y + 8);
	printf("  *22:00(4/9)");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 4) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, y -= 2);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 12) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, y += 2);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			*c = x;
			*d = y;
			return y - 4;
		}
		}
	}
}



