#include "main.h"
#include "findmovie.h"

void mselectprint() {
	while (1) {
		printf("\n");
		setColor(yellow, black);
		printf(":*:*:*:*:*:*:*:*:*:*:*:*:*:*:*\n*:");
		setColor(lightgray, black);
		printf("알아볼 영화를 선택해주세요");
		setColor(yellow, black);
		printf(":*\n:*:*:*:*:*:*:*:*:*:*:*:*:*:*:*\n");
		setColor(lightgray, black);
		int mselectcode = mselectDraw();
		printf("\n\n");
		int n;
		n = mselectcode;
		switch (n) {
		case 0:
			setColor(lightblue, white);
			infoprint(n);
			break;
		case 1:
			setColor(black, white);
			infoprint(n);
			break;
		case 2:
			setColor(lightred, white);
			infoprint(n);
			break;
		}

		printf("\n\n");
		int selectcode = selectDraw();
		if (selectcode == 0)
			continue;
		else {
			system("cls");
			setColor(lightgray, black);
			printf(" 영화 예매 시스템을 시작하겠습니다...잠시만 기다려주세요");
			break;
		}
	}
}

int selectDraw() {
	int x = 10;
	int y = 10;
	gotoxy(x - 2, y);
	setColor(lightgray, black);
	printf(">    더 알아보기");
	gotoxy(x, y + 1);
	printf("   끝내기");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 10) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 11) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 10;

		}
		}
	}
}

int mselectDraw() {
	int x = 5;
	int y = 5;
	gotoxy(x - 2, y);
	printf(">    겨울왕국2");
	gotoxy(x, y + 1);
	printf("   블랙머니");
	gotoxy(x, y + 2);
	printf("   신의 한수2");
	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 5) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 7) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y - 5;

		}
		}
	}
}

void infoprint(int n) {
	struct movie {
		char intro[1000]; //영화 소개
		char name[100]; //영화 이름
		int ranking; //영화 순위
		int mtime; //관람 시간
		char rate[100]; //관람 이용가 ex) 전체관람가,15세이상관람가 출력하기 위함
		char style[100]; //영화 장르
		double grade; //영화 평점
	} arr[3];
	//값 저장
	strcpy(arr[0].intro, "두려움을 깨고, 새로운 운명을 만나다.");
	strcpy(arr[0].name, "   Frozen2 = 겨울왕국2    ");
	arr[0].ranking = 1;
	arr[0].mtime = 108;
	strcpy(arr[0].rate, "전체관람가   ");
	strcpy(arr[0].style, "애니매이션 ");
	arr[0].grade = 4.06;
	strcpy(arr[1].intro, "나는 고발한다 !!!");
	strcpy(arr[1].name, "  BLACK MONEY = 블랙머니  ");
	arr[1].ranking = 2;
	arr[1].mtime = 113;
	strcpy(arr[1].rate, "12세이상관람가");
	strcpy(arr[1].style, "범죄,드라마");
	arr[1].grade = 9.11;
	strcpy(arr[2].intro, "귀신 같은 자들의 대결이 시작된다!");
	strcpy(arr[2].name, "The Divine Move2 = 신의 한수2");
	arr[2].ranking = 3;
	arr[2].mtime = 106;
	strcpy(arr[2].rate, "15세이상관람가");
	strcpy(arr[2].style, "범죄,액션 ");
	arr[2].grade = 8.94;
	printf(" [%s]\n", arr[n].name);
	printf("** %s\n", arr[n].intro);
	setColor(lightgray, black);
	printf("-------- 영화 순위 : %d위       \n", arr[n].ranking);
	printf("-------- 관람 시간 : %d분       \n", arr[n].mtime);
	printf("-------- 관람 이용가 : %s       \n", arr[n].rate);
	printf("-------- 영화 장르 : %s         \n", arr[n].style);
	printf("-------- 영화 평점 : %.2f       \n", arr[n].grade);
	printf("\n\n");
}

int movieinformation() {
	char ch;
	FILE * fp = fopen("무비차트.txt", "r");
	if (fp == NULL) {
		printf("파일 오픈 실패 !\n");
		return -1;
	}
	setColor(yellow, black);
	printf("*:*");
	setColor(lightred, black);
	printf("<이 달의 영화>");
	setColor(yellow, black);
	printf("*:*:*:*:*:*");
	setColor(lightred, black);
	printf("<예매율>\n");
	setColor(yellow, black);
	while (1) {
		ch = fgetc(fp);
		if (ch == EOF)
			break;
		putchar(ch);
	}
	setColor(white, black);
	printf("\n\n");
	setColor(lightgray, black);
	printf("영화의 정보를 알아보시겠습니까?(Y/N) ");
	if (getYesNoKey()) {
		system("cls");
		mselectprint();
	}
	else {
		printf("\n\n");
		printf("영화 예매 시스템을 시작하겠습니다...잠시만 기다려주세요");
	}
	fclose(fp);
	Sleep(1000);
	return 0;
}