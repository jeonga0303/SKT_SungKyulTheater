#include "main.h"
#include "ticketreservation.h"




int reservation1(int *timekey1) {

	int seat_key_a1 = 0;
	int seat_key_b1 = 0;
	int seat_key_c1 = 0;
	int ticketnumber;
	int price;
	int count;
	char pay;
	char *name;

	rescode = timekey1;

	FILE *fp6 = fopen("count.txt", "r");
	fscanf(fp6, "%d", &count);
	fclose(fp6);

	while (1)
	{
		dateprint1();
		ticketnumber = date1 *100 + count;
		system("cls");
		Sleep(1000);
		int timekey1 = reservationtime1();
		seatscount1();
		system("cls");
		Sleep(1000);
		setColor(lightred, black);
		printf("좌석번호\n");
		printf("a1 a2 a3\n");
		printf("b4 b5 b6\n");
		printf("c7 c8 c9\n\n");;
		setColor(lightgray, black);
		printf("잠시만 기다려주세요. 곧 예매 페이지로 넘어갑니다.");
		Sleep(1000);
		system("cls");

		seattotal1(&seat_key_a1, &seat_key_b1, &seat_key_c1);
		Sleep(1000);
		if ((timekey1 == 2) || (timekey1 == 10))// 오전이나 오후에 선택할 경우
			price = payprint_1(seat_key_a1, seat_key_b1, seat_key_c1); // 시간할인 받을 때 결제 함수
		else
			price = payprint_2(seat_key_a1, seat_key_b1, seat_key_c1); // 시간할인 안 받을 때 결제 함수

		printf("\n결제 하시겠습니까?(Y/N):");
		scanf(" %c", &pay);
		if (pay == 'Y' || pay == 'y')
		{
			FILE *fp1, *fp2, *fp3, *fp4, *fp5;
			name = "Frozen2";
			fp1 = fopen("movie.txt", "w");
			fwrite(name, strlen(name), 1, fp1);
			fclose(fp1);

			// 관람 날짜
			fp2 = fopen("date.txt", "w");
			fprintf(fp2, "%d", date1);
			fclose(fp2);

			// 관람 시간대
			switch (timekey)
			{
			case 0:
				timekey1 = "8:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey1, strlen(timekey1), 1, fp3);
				fclose(fp3);
				break;
			case 2:
				timekey1 = "11:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey1, strlen(timekey1), 1, fp3);
				fclose(fp3);
				break;
			case 4:
				timekey1 = "15:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey1, strlen(timekey1), 1, fp3);
				fclose(fp3);
				break;
			case 8:
				timekey1 = "18:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey1, strlen(timekey1), 1, fp3);
				fclose(fp3);
				break;
			case 10:
				timekey1 = "22:00";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey1, strlen(timekey1), 1, fp3);
				fclose(fp3);
				break;
			default:
				break;
			}

			// 최종 금액
			fp4 = fopen("price.txt", "w");
			fprintf(fp4, "%d", price);
			fclose(fp4);

			// 예매 번호
			fp5 = fopen("TicketNumber.txt", "w");
			fprintf(fp5, "%d", ticketnumber);
			fclose(fp5);
			Ticket();
			break;
		}
		else if (pay == 'N' || pay == 'n')
		{
			printf(" 날짜입력으로 돌아갑니다.\n");
			Sleep(1000);
			system("cls");
		}
		else
		{
			printf("잘못된 입력값입니다. 날짜입력으로 돌아갑니다.\n");
			Sleep(1000);
			system("cls");
		}
	}

	return price;
}

int reservation2(int *timekey2) {

	int seat_key_a2 = 0;
	int seat_key_b2 = 0;
	int seat_key_c2 = 0;
	int price;
	int ticketnumber;
	int count;
	char *name;
	char pay;  //yes,no
	int seats_num2[3][3];
	rescode = timekey2;

	FILE *fp6 = fopen("count.txt", "r");
	fscanf(fp6, "%d", &count);
	fclose(fp6);

	while (1)
	{
		dateprint2();

		ticketnumber = date2 * 100 + count;
		system("cls");

		int timekey2 = reservationtime2();
		seatscount2();

		setColor(lightred, black);
		printf("좌석번호\n");
		printf("a1 a2 a3\n");
		printf("b4 b5 b6\n");
		printf("c7 c8 c9\n\n");;
		setColor(lightgray, black);
		printf("잠시만 기다려주세요. 곧 예매 페이지로 넘어갑니다.");
		_sleep(1000);
		system("cls");

		seattotal2(&seat_key_a2, &seat_key_b2, &seat_key_c2);

		if ((timekey2 == 2) || (timekey2 == 10))// 오전이나 오후에 선택할 경우
			price = payprint_1(seat_key_a2, seat_key_b2, seat_key_c2); // 시간할인 받을 때 결제 함수
		else
			price = payprint_2(seat_key_a2, seat_key_b2, seat_key_c2); // 시간할인 안 받을 때 결제 함수

		printf("\n결제 하시겠습니까?(Y/N):");
		scanf(" %c", &pay);
		if (pay == 'Y' || pay == 'y')
		{
			FILE *fp1, *fp2, *fp3, *fp4, *fp5;
			name = "BLACK MONEY"; // 영화 이름
			fp1 = fopen("movie.txt", "w");
			fwrite(name, strlen(name), 1, fp1);
			fclose(fp1);

			// 관람 날짜
			fp2 = fopen("date.txt", "w");
			fprintf(fp2, "%d", date2);
			fclose(fp2);

			// 관람 시간대
			switch (timekey)
			{
			case 0:
				timekey2 = "8:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey2, strlen(timekey2), 1, fp3);
				fclose(fp3);
				break;
			case 2:
				timekey2 = "11:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey2, strlen(timekey2), 1, fp3);
				fclose(fp3);
				break;
			case 4:
				timekey2 = "15:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey2, strlen(timekey2), 1, fp3);
				fclose(fp3);
				break;
			case 8:
				timekey2 = "18:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey2, strlen(timekey2), 1, fp3);
				fclose(fp3);
				break;
			case 10:
				timekey2 = "22:00";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey2, strlen(timekey2), 1, fp3);
				fclose(fp3);
				break;
			default:
				break;
			}

			// 최종 금액
			fp4 = fopen("price.txt", "w");
			fprintf(fp4, "%d", price);
			fclose(fp4);

			 // 예매 번호
			fp5 = fopen("TicketNumber.txt", "w");
			fprintf(fp5, "%d", ticketnumber);
			fclose(fp5);

			Ticket();
			break;
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

	return price;
}

int reservation3(int *timekey3) {

	int seat_key_a3 = 0;
	int seat_key_b3 = 0;
	int seat_key_c3 = 0;
	int price;
	int ticketnumber;
	int count;
	char *name;
	char pay; 

	rescode = timekey3;

	FILE *fp6 = fopen("count.txt", "r");
	fscanf(fp6, "%d", &count);
	fclose(fp6);

	while (1)
	{
		dateprint3();

		ticketnumber = date3 * 100 + count;
		system("cls");

		int timekey3 = reservationtime3();
		seatscount3();

		setColor(lightred, black);
		printf("좌석번호\n");
		printf("a1 a2 a3\n");
		printf("b4 b5 b6\n");
		printf("c7 c8 c9\n\n");;
		setColor(lightgray, black);
		printf("잠시만 기다려주세요. 곧 예매 페이지로 넘어갑니다.");
		_sleep(1000);
		system("cls");

		seattotal3(&seat_key_a3, &seat_key_b3, &seat_key_c3);

		if ((timekey3 == 2) || (timekey3 == 10))// 오전이나 오후에 선택할 경우
			price = payprint_1(seat_key_a3, seat_key_b3, seat_key_c3); // 시간할인 받을 때 결제 함수
		else
			price = payprint_2(seat_key_a3, seat_key_b3, seat_key_c3); // 시간할인 안 받을 때 결제 함수

		printf("\n결제 하시겠습니까?(Y/N):");
		scanf(" %c", &pay);
		if (pay == 'Y' || pay == 'y')
		{
			FILE *fp1, *fp2, *fp3, *fp4, *fp5;

			name = "The Divine Move2"; // 영화 이름
			fp1 = fopen("movie.txt", "w");
			fwrite(name, strlen(name), 1, fp1);
			fclose(fp1);

			// 관람 날짜
			fp2 = fopen("date.txt", "w");
			fprintf(fp2, "%d", date3);
			fclose(fp2);

			// 관람 시간대
			switch (timekey)
			{
			case 0:
				timekey3 = "8:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey3, strlen(timekey3), 1, fp3);
				fclose(fp3);
				break;
			case 2:
				timekey3 = "11:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey3, strlen(timekey3), 1, fp3);
				fclose(fp3);
				break;
			case 4:
				timekey3 = "15:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey3, strlen(timekey3), 1, fp3);
				fclose(fp3);
				break;
			case 8:
				timekey3 = "18:30";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey3, strlen(timekey3), 1, fp3);
				fclose(fp3);
				break;
			case 10:
				timekey3 = "22:00";
				fp3 = fopen("time.txt", "w");
				fwrite(timekey3, strlen(timekey3), 1, fp3);
				fclose(fp3);
				break;
			default:
				break;
			}

			// 최종 금액
			fp4 = fopen("price.txt", "w");
			fprintf(fp4, "%d", price);
			fclose(fp4);

			// 예매 번호
			fp5 = fopen("TicketNumber.txt", "w");
			fprintf(fp5, "%d", ticketnumber);
			fclose(fp5);

			Ticket();
			break;
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

	return price;
}

int payprint_1(int seatnum_a, int seatnum_b, int seatnum_c)
{
	TIMESALE_ORIGINAL_PRICE(seatnum_a, seatnum_b, seatnum_c);
	TIMESALE_SALEPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);
	TIMESALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);

	system("cls");
	gotoxy(2, 2);
	printf("<결제 내용>");
	gotoxy(2, 4);
	printf("원래 금액: %d", TIMESALE_ORIGINAL_PRICE(seatnum_a, seatnum_b, seatnum_c));
	gotoxy(2, 5);
	printf("할인 금액: %d", TIMESALE_SALEPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c));
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("최종 금액: %d", TIMESALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c));

	return TIMESALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);
}

int payprint_2(int seatnum_a, int seatnum_b, int seatnum_c)
{
	SEATSALE_ORIGINAL_PRICE(seatnum_a, seatnum_b, seatnum_c);
	SEATSALE_SALEPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);
	SEATSALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);

	system("cls");
	gotoxy(2, 2);
	printf("<결제 내용>");
	gotoxy(2, 4);
	printf("원래 금액: %d", SEATSALE_ORIGINAL_PRICE(seatnum_a, seatnum_b, seatnum_c));
	gotoxy(2, 5);
	printf("할인 금액: %d", SEATSALE_SALEPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c));
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("최종 금액: %d", SEATSALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c));

	return SEATSALE_FINALPRICE_PRICE(seatnum_a, seatnum_b, seatnum_c);
}

int dateprint1() {
	int year;
	int month;
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

	if (yoon(year)) {
		chk = 1;
		basicyear[1]++;
	}
	else
		chk = 0;

	sum = 365;
	for (i = 1; i < year; i++) {
		if (yoon(i))
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

	setColor(yellow, black);
	printf("날짜를 입력해주십시오.(ex 20191101) ");
	setColor(lightgray, black);
	scanf("%d", &date1);

	return date1;

}

int dateprint2() {
	int year;
	int month;
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

	if (yoon(year)) {
		chk = 1;
		basicyear[1]++;
	}
	else
		chk = 0;

	sum = 365;
	for (i = 1; i < year; i++) {
		if (yoon(i))
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

	setColor(yellow, black);
	printf("날짜를 입력해주십시오.(ex 20191101) ");
	setColor(lightgray, black);
	scanf("%d", &date2);

	return date2;

}

int dateprint3() {
	int year;
	int month;
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

	if (yoon(year)) {
		chk = 1;
		basicyear[1]++;
	}
	else
		chk = 0;

	sum = 365;
	for (i = 1; i < year; i++) {
		if (yoon(i))
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

	setColor(yellow, black);
	printf("날짜를 입력해주십시오.(ex 20191101) ");
	setColor(lightgray, black);
	scanf("%d", &date3);

	return date3;

}

int yoon(int a) {
	if ((a % 4 == 0) && !(a % 100 == 0) || (a % 400 == 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int reservationtime1()
{
	int x = 2;
	int y = 2;


	gotoxy(x, y - 2);
	setColor(yellow, black);
	printf("● 관람하실 시간대를 선택해주세요.\n");
	setColor(lightgray, black);
	gotoxy(x, y);
	printf("> *8:30 (%d/9)", count1[0]);
	gotoxy(x, y + 2);
	printf("   11:30(%d/9)", count1[1]);
	gotoxy(x, y + 4);
	printf("   15:30(%d/9)", count1[2]);
	gotoxy(x, y + 6);
	printf("   18:30(%d/9)", count1[3]);
	gotoxy(x, y + 8);
	printf("  *22:00(%d/9)", count1[4]);

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
	}

}

int reservationtime2()
{
	int x = 2;
	int y = 2;

	gotoxy(x, y - 2);
	setColor(yellow, black);
	printf("● 관람하실 시간대를 선택해주세요.\n");
	setColor(lightgray, black);
	gotoxy(x, y);
	printf("> *8:30 (%d/9)", count2[0]);
	gotoxy(x, y + 2);
	printf("   11:30(%d/9)", count2[1]);
	gotoxy(x, y + 4);
	printf("   15:30(%d/9)", count2[2]);
	gotoxy(x, y + 6);
	printf("   18:30(%d/9)", count2[3]);
	gotoxy(x, y + 8);
	printf("  *22:00(%d/9)", count2[4]);

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
	}

}

int reservationtime3()
{
	int x = 2;
	int y = 2;

	gotoxy(x, y - 2);
	setColor(yellow, black);
	printf("● 관람하실 시간대를 선택해주세요.\n");
	setColor(lightgray, black);
	gotoxy(x, y);
	printf("> *8:30 (%d/9)", count3[0]);
	gotoxy(x, y + 2);
	printf("   11:30(%d/9)", count3[1]);
	gotoxy(x, y + 4);
	printf("   15:30(%d/9)", count3[2]);
	gotoxy(x, y + 6);
	printf("   18:30(%d/9)", count3[3]);
	gotoxy(x, y + 8);
	printf("  *22:00(%d/9)", count3[4]);

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

	}

}

int seatscount1() {
	while (1) {

		int rescode = reservationtime1();
		_sleep(1000);
		switch (rescode)
		{
		case 2:
			if (count1[0] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count1[0]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 4:
			if (count1[1] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count1[1]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 6:
			if (count1[2] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count1[2]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 8:
			if (count1[3] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count1[3]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 10:
			if (count1[4] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count1[4]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		}
		break;
	}

}

int seatscount2() {
	while (1) {

		int rescode = reservationtime2();
		_sleep(1000);
		switch (rescode)
		{
		case 2:
			if (count2[0] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count2[0]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 4:
			if (count2[1] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count2[1]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 6:
			if (count2[2] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count2[2]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 8:
			if (count2[3] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count2[3]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 10:
			if (count2[4] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count2[4]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		}
		break;
	}

}

int seatscount3() {
	while (1) {

		int rescode = reservationtime3();
		_sleep(1000);
		switch (rescode)
		{
		case 2:
			if (count3[0] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count3[0]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 4:
			if (count3[1] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count3[1]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 6:
			if (count3[2] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count3[2]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 8:
			if (count3[3] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count3[3]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		case 10:
			if (count3[4] >= 9) {
				system("cls");
				printf("좌석이 매진되었습니다. 다시 예매해주세요.\n");
				Sleep(1000);
				continue;
			}
			count3[4]++;
			printf("예매가 진행됩니다.\n");
			Sleep(1000);
			break;

		}
		break;
	}

}

int movieselect(int menucode)
{
	int x = 2;
	int y = 0;
	if (menucode == 0)
	{
		system("cls");
		gotoxy(x, y);
		setColor(yellow, black);
		printf(":*:*:*:*:*:예매할 영화를 선택해주세요*:*:*:*:*:\n");
		setColor(lightgray, black);
		gotoxy(x, y + 1);
		printf(">1. 겨울왕국\n");
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
				if (y < 3) {
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

int sprint1() {

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

int sprint2() {
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

int seatsprint1() {
	char A[3] = { 'A','B','C' }; //알파펫 출력
	int d[3] = { 1,2,3 };         //숫자 출력
	int x = 3;
	int y = 2;
	gotoxy(x, y);
	int i;
	i = 0;
	setColor(lightred, white);
	for (int j = 0; j < 3; j++) {
		printf("%d ", seats_num1[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(green, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num1[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(purple, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num1[i][j]);
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

int seatsprint2() {
	char A[3] = { 'A','B','C' }; //알파펫 출력
	int d[3] = { 1,2,3 };         //숫자 출력
	int x = 3;
	int y = 2;
	gotoxy(x, y);
	int i;
	i = 0;
	setColor(lightred, white);
	for (int j = 0; j < 3; j++) {
		printf("%d ", seats_num2[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(green, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num2[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(purple, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num2[i][j]);
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

int seatsprint3() {
	char A[3] = { 'A','B','C' }; //알파펫 출력
	int d[3] = { 1,2,3 };         //숫자 출력
	int x = 3;
	int y = 2;
	gotoxy(x, y);
	int i;
	i = 0;
	setColor(lightred, white);
	for (int j = 0; j < 3; j++) {
		printf("%d ", seats_num3[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(green, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num3[i][j]);
	}      setColor(white, black);
	printf("\n   ");
	i++;
	setColor(purple, white);
	for (int j = 0; j < 3; j++) {

		printf("%d ", seats_num3[i][j]);
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

int seattotal1(int *seatkey_a1, int *seatkey_b1, int *seatkey_c1) {
	while (1) {
		seatsprint1();
		gotoxy(6, 5);
		printf("\n예약하시겠습니까?(Y/N): ");
		if (getYesNoKey())
			system("cls");
		else
			break;

		int a = sprint1(); //A,B,C 확인 키
		int b = sprint2(); //1,2,3 확인 키

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
		if (code == 0) {
			if (seats_num1[0][0] == 0) {
				seats_num1[0][0] = 1;
				printf("A1좌석의 예약이 완료되었습니다.");
				(*seatkey_a1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 1) {
			if (seats_num1[0][1] == 0) {
				seats_num1[0][1] = 1;
				printf("A2좌석의 예약이 완료되었습니다.");
				(*seatkey_a1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 2) {
			if (seats_num1[0][2] == 0) {
				seats_num1[0][2] = 1;
				printf("A3좌석의 예약이 완료되었습니다.");
				(*seatkey_a1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 3) {
			if (seats_num1[1][0] == 0) {
				seats_num1[1][0] = 1;
				printf("B1좌석의 예약이 완료되었습니다.");
				(*seatkey_b1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 4) {
			if (seats_num1[1][1] == 0) {
				seats_num1[1][1] = 1;
				printf("B2좌석의 예약이 완료되었습니다.");
				(*seatkey_b1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 5) {
			if (seats_num1[1][2] == 0) {
				seats_num1[1][2] = 1;
				printf("B3좌석의 예약이 완료되었습니다.");
				(*seatkey_b1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 6) {
			if (seats_num1[2][0] == 0) {
				seats_num1[2][0] = 1;
				printf("C1좌석의 예약이 완료되었습니다.");
				(*seatkey_c1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 7) {
			if (seats_num1[2][1] == 0) {
				seats_num1[2][1] = 1;
				printf("C2좌석의 예약이 완료되었습니다.");
				(*seatkey_c1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 8) {
			if (seats_num1[2][2] == 0) {
				seats_num1[2][2] = 1;
				printf("C3좌석의 예약이 완료되었습니다.");
				(*seatkey_c1)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
	}
}

int seattotal2(int *seatkey_a2, int *seatkey_b2, int *seatkey_c2) {
	while (1) {
		seatsprint2();
		gotoxy(6, 5);
		printf("\n예약하시겠습니까?(Y/N): ");
		if (getYesNoKey())
			system("cls");
		else
			break;

		int a = sprint1(); //A,B,C 확인 키
		int b = sprint2(); //1,2,3 확인 키

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
		if (code == 0) {
			if (seats_num2[0][0] == 0) {
				seats_num2[0][0] = 1;
				printf("A1좌석의 예약이 완료되었습니다.");
				(*seatkey_a2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 1) {
			if (seats_num2[0][1] == 0) {
				seats_num2[0][1] = 1;
				printf("A2좌석의 예약이 완료되었습니다.");
				(*seatkey_a2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 2) {
			if (seats_num2[0][2] == 0) {
				seats_num2[0][2] = 1;
				printf("A3좌석의 예약이 완료되었습니다.");
				(*seatkey_a2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 3) {
			if (seats_num2[1][0] == 0) {
				seats_num2[1][0] = 1;
				printf("B1좌석의 예약이 완료되었습니다.");
				(*seatkey_b2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 4) {
			if (seats_num2[1][1] == 0) {
				seats_num2[1][1] = 1;
				printf("B2좌석의 예약이 완료되었습니다.");
				(*seatkey_b2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 5) {
			if (seats_num2[1][2] == 0) {
				seats_num2[1][2] = 1;
				printf("B3좌석의 예약이 완료되었습니다.");
				(*seatkey_b2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 6) {
			if (seats_num2[2][0] == 0) {
				seats_num2[2][0] = 1;
				printf("C1좌석의 예약이 완료되었습니다.");
				(*seatkey_c2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 7) {
			if (seats_num2[2][1] == 0) {
				seats_num2[2][1] = 1;
				printf("C2좌석의 예약이 완료되었습니다.");
				(*seatkey_c2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 8) {
			if (seats_num2[2][2] == 0) {
				seats_num2[2][2] = 1;
				printf("C3좌석의 예약이 완료되었습니다.");
				(*seatkey_c2)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
	}
}

int seattotal3(int *seatkey_a3, int *seatkey_b3, int *seatkey_c3) {
	while (1) {
		seatsprint3();
		gotoxy(6, 5);
		printf("\n예약하시겠습니까?(Y/N): ");
		if (getYesNoKey())
			system("cls");
		else
			break;

		int a = sprint1(); //A,B,C 확인 키
		int b = sprint2(); //1,2,3 확인 키

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
		if (code == 0) {
			if (seats_num3[0][0] == 0) {
				seats_num3[0][0] = 1;
				printf("A1좌석의 예약이 완료되었습니다.");
				(*seatkey_a3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 1) {
			if (seats_num3[0][1] == 0) {
				seats_num3[0][1] = 1;
				printf("A2좌석의 예약이 완료되었습니다.");
				(*seatkey_a3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 2) {
			if (seats_num3[0][2] == 0) {
				seats_num3[0][2] = 1;
				printf("A3좌석의 예약이 완료되었습니다.");
				(*seatkey_a3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 3) {
			if (seats_num3[1][0] == 0) {
				seats_num3[1][0] = 1;
				printf("B1좌석의 예약이 완료되었습니다.");
				(*seatkey_b3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 4) {
			if (seats_num3[1][1] == 0) {
				seats_num3[1][1] = 1;
				printf("B2좌석의 예약이 완료되었습니다.");
				(*seatkey_b3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 5) {
			if (seats_num3[1][2] == 0) {
				seats_num3[1][2] = 1;
				printf("B3좌석의 예약이 완료되었습니다.");
				(*seatkey_b3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 6) {
			if (seats_num3[2][0] == 0) {
				seats_num3[2][0] = 1;
				printf("C1좌석의 예약이 완료되었습니다.");
				(*seatkey_c3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 7) {
			if (seats_num3[2][1] == 0) {
				seats_num3[2][1] = 1;
				printf("C2좌석의 예약이 완료되었습니다.");
				(*seatkey_c3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
		else if (code == 8) {
			if (seats_num3[2][2] == 0) {
				seats_num3[2][2] = 1;
				printf("C3좌석의 예약이 완료되었습니다.");
				(*seatkey_c3)++;
			}
			else
				printf("이미 예약된 좌석입니다. 다시 선택해 주십시오.");
		}
	}
}

void Ticket()
{
	char buffer1[20] = { 0, };
	char buffer2[20] = { 0, };
	char *time;
	char *name;
	int date;
	int price;
	int ticketnumber; // 예매 번호 변수 선언

	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp3 = NULL;
	FILE *fp4 = NULL;
	FILE *fp5 = NULL;


	printf("\n\t<※티켓정보※> \n\n");    // 영수증 출력 부분
	printf("\t●영화정보●\n");

	fp1 = fopen("movie.txt", "r");
	fgets(buffer1, sizeof(buffer1), fp1);
	printf("▶예매영화: %s\n", buffer1);
	fclose(fp1);

	fp2 = fopen("date.txt", "r");
	fscanf(fp2, "%d", &date);
	fclose(fp2);
	printf("▶관람일: %d\n", date);

	fp3 = fopen("time.txt", "r");
	fgets(buffer2, sizeof(buffer2), fp3);
	printf("▶관람시작시간: %s\n", buffer2);
	fclose(fp3);

	printf("\n\t●결제 정보●\n\n");

	fp4 = fopen("price.txt", "r");
	fscanf(fp4, "%d", &price);
	fclose(fp4);
	printf("▶결제 금액: %d", price);

	printf("\n\t●예매번호●\n\n");

	fp5 = fopen("TicketNumber.txt", "r");
	fscanf(fp5, "%d", &ticketnumber);
	fclose(fp5);
	printf("▶예매번호: %d", ticketnumber);

	_sleep(4000);
}
