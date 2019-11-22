#include "first_screen_design.h"
#include "main.h"

int setColor(int forground, int back) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = forground + back * 16;
	SetConsoleTextAttribute(consoleHandle, code);
}

void init() {
	system("mode con cols=120 lines=40 | title SKT");
}

void titleDraw() {


	printf("\n\n\n\n");
	printf("                                       ");    setColor(lightred, white); printf("             ######   ##    ##  ########  .#  ");    setColor(yellow, white); printf("#.    \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("            ##    ##  ##   ##      ##     ");    setColor(lightred, white); printf("**#"); setColor(lightred, white); printf("#**    \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("            ##        ##  ##       ##     ");    setColor(yellow, white); printf("'# ");    setColor(lightred, white); printf("#'     \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("             ######   #####        ##               \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("                  ##  ##  ##       ##               \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("            ##    ##  ##   ##      ##               \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("             ######   ##    ##     ##               \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("                                                    \n");
	setColor(white, black); printf("                                       ");    setColor(lightred, white); printf("                 Sung Kyul Theatre                  \n");
	return 0;
}

int menuDraw() {
	setColor(white, black);
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

void gotoxy(int x, int y) {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}