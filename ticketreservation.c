#include "main.h"
#include "ticketreservation.h"

enum seats { A1, A2, A3, B1, B2, B3, C1, C2, C3 };

enum seats code;

int seats_num[3][3] = { 0 };
int count[5] = { 0, };

int reservation(int *datecode, int *timekey, int *date_key2, int movie_key) {

	int seat_key_a = 0;
	int seat_key_b = 0;
	int seat_key_c = 0;
	int code;
	int date;
	int cmpdate;
	int price;
	char pay;

	while (1)
	{
		setColor(yellow, black);
		printf("● 예매할 날짜를 입력해주세요. ex)20191101 : ");
		setColor(lightgray, black);
		scanf("%d", &date);
		cmpdate = date / 100;

		if (cmpdate == *datecode)
		{
			*date_key2 = date; // 예매날짜전체를 datekey값에 넣어줌
			system("cls");

			*timekey = reservationtime(count);
			_sleep(1000);
			switch (*timekey)
			{
			case 2:
				if (count[0] >= 9) {
					system("cls");
					printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
					Sleep(1000);
					continue;
				}
				count[0]++;
				printf("예매 완료.\n");
				Sleep(1000);
				break;

			case 4:
				if (count[1] >= 9) {
					system("cls");
					printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
					Sleep(1000);
					continue;
				}
				count[1]++;
				printf("예매 완료.\n");
				Sleep(1000);
				break;

			case 6:
				if (count[2] >= 9) {
					system("cls");
					printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
					Sleep(1000);
					continue;
				}
				count[2]++;
				printf("예매 완료.\n");
				Sleep(1000);
				break;

			case 8:
				if (count[3] >= 9) {
					system("cls");
					printf("매진되었습니다. 다시 예매해주세요.\n");
					Sleep(1000);
					continue;
				}
				count[3]++;
				printf("예매 완료.\n");
				Sleep(1000);
				break;

			case 10:
				if (count[4] >= 9) {
					system("cls");
					printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
					Sleep(1000);
					continue;
				}
				count[4]++;
				printf("예매 완료.\n");
				Sleep(1000);
				break;

			}
			setColor(lightred, black);
			printf("좌석번호\n");
			printf("a1 a2 a3\n");
			printf("b4 b5 b6\n");
			printf("c7 c8 c9\n\n");;
			setColor(lightgray, black);
			printf("잠시만 기다려주세요. 곧 예매 페이지로 넘어갑니다.");
			_sleep(1000);
			system("cls");

			while (1) {   // 자리 기능
				seatsprint();
				gotoxy(6, 5);
				printf("\n예약하시겠습니까?(Y/N): ");
				if (getYesNoKey())
					system("cls");
				else
					break;
				int a = sprint2(); //A,B,C 확인 키
				int b = sprint3(); //1,2,3 확인 키

				if (a == 2) {
					if (b == 2) {
						code = 0;
					}
					else if (b == 3) {
						code = 1;
					}
					else if (b == 4) {
						code = 2;
					}
				}
				else if (a == 3) {

					if (b == 2)
						code = 3;
					else if (b == 3)
						code = 4;
					else if (b == 4)
						code = 5;
				}
				else if (a == 4) {

					if (b == 2)
						code = 6;
					else if (b == 3)
						code = 7;
					else if (b == 4)
						code = 8;
				}
				_sleep(500);
				SeatsChange(code, &seat_key_a, &seat_key_b, &seat_key_c);
			}

			if ((*timekey == 2) || (*timekey == 10))// 오전이나 오후에 선택할 경우
				price = payprint_1(seat_key_a, seat_key_b, seat_key_c); // 시간할인 받을 때 결제 함수
			else
				price = payprint_2(seat_key_a, seat_key_b, seat_key_c); // 시간할인 안 받을 때 결제 함수

			printf("\n결제 하시겠습니까?(Y/N):");
			scanf(" %c", &pay);
			if (pay == 'Y' || pay == 'y')
			{
				printf("\n\t<결 제 완 료>\n");
				Ticket(movie_key, *timekey, *date_key2, price);
				printf("\n\t처음 화면으로 돌아갑니다.");
				_sleep(1500);
				system("cls");
				return price;
			}
			else if (pay == 'N' || pay == 'n')
			{
				printf(" 날짜입력으로 돌아갑니다.\n");
				_sleep(1200);
				system("cls");
			}
			else
			{
				printf("잘못된 입력값입니다. 날짜입력으로 돌아갑니다.\n");
				_sleep(1200);
				system("cls");
			}
		}
		else
		{
			printf("잘못된 날짜입니다. 다시 입력해주세요.\n");
			_sleep(1000);
			system("cls");
		}
	}

}

int SeatsChange(int code, int *seatkey_a, int *seatkey_b, int *seatkey_c) {

	if (code == 0) {
		if (seats_num[0][0] == 0) {
			seats_num[0][0] = 1;
			printf("A1좌석의 예약이 완료되었습니다.");
			(*seatkey_a)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 1) {
		if (seats_num[0][1] == 0) {
			seats_num[0][1] = 1;
			printf("A2좌석의 예약이 완료되었습니다.");
			(*seatkey_a)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 2) {
		if (seats_num[0][2] == 0) {
			seats_num[0][2] = 1;
			printf("A3좌석의 예약이 완료되었습니다.");
			(*seatkey_a)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 3) {
		if (seats_num[1][0] == 0) {
			seats_num[1][0] = 1;
			printf("B1좌석의 예약이 완료되었습니다.");
			(*seatkey_b)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 4) {
		if (seats_num[1][1] == 0) {
			seats_num[1][1] = 1;
			printf("B2좌석의 예약이 완료되었습니다.");
			(*seatkey_b)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 5) {
		if (seats_num[1][2] == 0) {
			seats_num[1][2] = 1;
			printf("B3좌석의 예약이 완료되었습니다.");
			(*seatkey_b)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 6) {
		if (seats_num[2][0] == 0) {
			seats_num[2][0] = 1;
			printf("C1좌석의 예약이 완료되었습니다.");
			(*seatkey_c)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 7) {
		if (seats_num[2][1] == 0) {
			seats_num[2][1] = 1;
			printf("C2좌석의 예약이 완료되었습니다.");
			(*seatkey_c)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
	else if (code == 8) {
		if (seats_num[2][2] == 0) {
			seats_num[2][2] = 1;
			printf("C3좌석의 예약이 완료되었습니다.");
			(*seatkey_c)++;
		}
		else
			printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
	}
}

int payprint_1(int seatnum_a, int seatnum_b, int seatnum_c)
{
	int originalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE);
	int saleprice = seatnum_a * (TIMESALE + 2 * SEATSALE) + seatnum_b * (TIMESALE + SEATSALE) + seatnum_c * TIMESALE;
	int finalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE)-((seatnum_a * (TIMESALE + 2 * SEATSALE)) + seatnum_b * (TIMESALE + SEATSALE) + seatnum_c * TIMESALE);
	system("cls");
	gotoxy(2, 2);
	printf("<결제 내용>");
	gotoxy(2, 4);
	printf("원래 금액: %d", originalprice);
	gotoxy(2, 5);
	printf("할인 금액: %d", saleprice);
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("최종 금액: %d", finalprice);

	return finalprice;
}

int payprint_2(int seatnum_a, int seatnum_b, int seatnum_c)
{
	int originalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE);
	int saleprice = seatnum_a * 2 * SEATSALE + seatnum_b * SEATSALE;
	int finalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE)-(seatnum_a * 2 * SEATSALE + seatnum_b * SEATSALE);
	system("cls");
	gotoxy(2, 2);
	printf("<결제 내용>");
	gotoxy(2, 4);
	printf("원래 금액: %d", originalprice);
	gotoxy(2, 5);
	printf("할인 금액: %d", saleprice);
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("최종 금액: %d", finalprice);

	return finalprice;
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
	setColor(yellow, black);
	printf("● 예매할 년도와 달을 입력해주세요. ex)2019 11 : ");
	setColor(lightgray, black);
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

int reservationtime(int count[])
{
	int x = 2;
	int y = 2;

	gotoxy(x, y - 2);
	setColor(yellow, black);
	printf("● 관람하실 시간대를 선택해주세요.\n");
	setColor(lightgray, black);;
	gotoxy(x, y);
	printf("> *8:30 (%d/9)", count[0]);
	gotoxy(x, y + 2);
	printf("   11:30(%d/9)", count[1]);
	gotoxy(x, y + 4);
	printf("   15:30(%d/9)", count[2]);
	gotoxy(x, y + 6);
	printf("   18:30(%d/9)", count[3]);
	gotoxy(x, y + 8);
	printf("  *22:00(%d/9)", count[4]);

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, y -= 2);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 10) {
				gotoxy(x - 1, y);
				printf("  ");
				gotoxy(x, y += 2);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y;
		}
		}

		switch (y)
		{
		case 2:
			count[0]++;
			break;
		case 4:
			count[1]++;
			break;
		case 6:
			count[2]++;
			break;
		case 8:
			count[3]++;
			break;
		case 10:
			count[4]++;
			break;
		default:
			break;
		}

	}

}

int movieselect(int i)
{

	if (i == 0)
	{
		int x = 2;
		int y = 0;

		system("cls");
		gotoxy(x, y);
		setColor(yellow, black);
		printf(":*:*:*:*:*:예매할 영화를 선택해주세요*:*:*:*:*:\n");
		setColor(lightgray, black);
		gotoxy(x, y + 1);
		printf(">1.겨울왕국\n");
		gotoxy(x, y + 2);
		printf(" 2. 블랙머니\n");
		gotoxy(x, y + 3);
		printf(" 3. 신의한수2\n");

		while (1) {
			int n = keyControl();
			switch (n) {
			case UP: {
				if (y > 1) {
					gotoxy(x - 1, y);
					printf("  ");
					gotoxy(x, --y);
					printf(">");
				}
				break;
			}

			case DOWN: {
				if (y < 6) {
					gotoxy(x - 1, y);
					printf("  ");
					gotoxy(x, ++y);
					printf(">");
				}
				break;
			}
			case SUBMIT: {
				return y;
			}
			}
		}
	}

}

int getYesNoKey(void) {
	int key;

	while ((key = getch()) != NULL) {
		if (key == 'y' || key == 'Y') {
			printf("Y");
			return 1; // 참을 반환
		}
		else if (key == 'n' || key == 'N') {
			printf("N");
			return 0; // 거짓을 반환
		}
	}
	return -1;
}

int sprint2() {

	int x = 16;
	int y = 2;

	gotoxy(x - 2, y);
	printf("> A");
	gotoxy(x, y + 1);
	printf("B");
	gotoxy(x, y + 2);
	printf("C");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 4) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {

			return y;

		}
		}
	}
}

int sprint3() {
	int x = 19;
	int y = 2;
	gotoxy(x - 2, y);
	printf("> 1");
	gotoxy(x, y + 1);
	printf("2");
	gotoxy(x, y + 2);
	printf("3");

	while (1) {
		int n = keyControl();
		switch (n) {
		case UP: {
			if (y > 2) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, --y);
				printf(">");
			}
			break;
		}

		case DOWN: {
			if (y < 4) {
				gotoxy(x - 2, y);
				printf(" ");
				gotoxy(x - 2, ++y);
				printf(">");
			}
			break;
		}

		case SUBMIT: {
			return y;

		}
		}
	}

}

int seatsprint() {
	char A[3] = { 'A','B','C' }; //알파펫 출력
	int d[3] = { 1,2,3 };         //숫자 출력
	int x = 3;
	int y = 2;
	gotoxy(x, y);
	int i;
	i = 0;
	setColor(lightred, white);
	for (int j = 0; j < 3; j++) {
		printf("%d ", seats_num[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(green, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(purple, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num[i][j]);
	}
	setColor(white, black);
	printf("\n   ");


	gotoxy(x - 2, y);
	for (int p = 0; p < 3; p++)
		printf("%c\n ", A[p]);

	gotoxy(x, y - 1);
	for (int q = 0; q < 3; q++)
		printf("%d ", d[q]);


}

void Ticket(int moviekey, int timekey, int date, int price)
{
	system("cls");
	printf("\n\t<※티켓정보※> \n\n");
	printf("\t●영화정보●\n");
	switch (moviekey)
	{
	case 1:
		printf("▶예매영화:Frozen 2\n");
		break;
	case 2:
		printf("▶예매영화: BLACK MONEY\n");
		break;
	case 3:
		printf("▶예매영화: The Divine Move 2 \n");
		break;
	default:
		break;
	}
	printf("▶관람일: %d\n", date); // 날짜 ( 20191120 처럼 8자리로 표시)
	switch (timekey)
	{
	case 0:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	case 2:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	case 4:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	case 6:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	case 8:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	case 10:
		printf("▶관람시간: 8:30 - 10:30\n");
		break;
	default:
		break;
	} // 선택한 영화와 관람일, 관람시간표시! ( 추가적으로 자리표시 필요!)

	printf("\n\t●결제 정보●\n\n");
	printf("▶결제 금액: %d", price);

	printf("\n\t●예매번호●\n\n");
	printf("▶%d", date * 100 + 1);
	_sleep(4000);


}
