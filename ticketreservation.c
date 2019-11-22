#include "main.h"
#include "ticketreservation.h"

enum seats { A1, A2, A3, B1, B2, B3, C1, C2, C3 };

enum seats code;

int seats_num[3][3] = { 0 };

int reservation(int *datecode, int *timekey, int *date_key2, int movie_key) {
	int count[5] = { 0, };
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
		printf("��¥�� �Է����ֽʽÿ�.(ex 20191101) ");
		scanf("%d", &date);
		cmpdate = date / 100;

		if (cmpdate == *datecode)
		{
			*date_key2 = date; // ���ų�¥��ü�� datekey���� �־���
			system("cls");

			*timekey = reservationtime(count);
			printf("�¼���ȣ\n");
			printf("a1 a2 a3\n");
			printf("b4 b5 b6\n");
			printf("c7 c8 c9\n\n");
			printf("��ø� ��ٷ��ּ���. �� ���� �������� �Ѿ�ϴ�.");
			_sleep(1000);
			system("cls");

			while (1) {   // �ڸ� ���
				seatsprint();
				gotoxy(6, 5);
				printf("\n�����Ͻðڽ��ϱ�?(Y/N): ");
				if (getYesNoKey())
					system("cls");
				else
					break;
				int a = sprint2(); //A,B,C Ȯ�� Ű
				int b = sprint3(); //1,2,3 Ȯ�� Ű

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

			if ((*timekey == 2) || (*timekey == 10))// �����̳� ���Ŀ� ������ ���
				price = payprint_1(seat_key_a, seat_key_b, seat_key_c); // �ð����� ���� �� ���� �Լ�
			else
				price = payprint_2(seat_key_a, seat_key_b, seat_key_c); // �ð����� �� ���� �� ���� �Լ�

			printf("\n���� �Ͻðڽ��ϱ�?(Y/N):");
			scanf(" %c", &pay);
			if (pay == 'Y' || pay == 'y')
			{
				printf("\n\t<�� �� �� ��>\n");
				Ticket(movie_key, *timekey, *date_key2, price);
				printf("\n\tó�� ȭ������ ���ư��ϴ�.");
				_sleep(1500);
				system("cls");
				return price;
			}
			else if (pay == 'N' || pay == 'n')
			{
				printf(" ��¥�Է����� ���ư��ϴ�.\n");
				_sleep(1200);
				system("cls");
			}
			else
			{
				printf("�߸��� �Է°��Դϴ�. ��¥�Է����� ���ư��ϴ�.\n");
				_sleep(1200);
				system("cls");
			}
		}
		else
		{
			printf("�߸��� ��¥�Դϴ�. �ٽ� �Է����ּ���.\n");
			_sleep(1000);
			system("cls");
		}
	}

}

int SeatsChange(int code, int *seatkey_a, int *seatkey_b, int *seatkey_c) {

	if (code == 0) {
		if (seats_num[0][0] == 0) {
			seats_num[0][0] = 1;
			printf("A1�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_a)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 1) {
		if (seats_num[0][1] == 0) {
			seats_num[0][1] = 1;
			printf("A2�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_a)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 2) {
		if (seats_num[0][2] == 0) {
			seats_num[0][2] = 1;
			printf("A3�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_a)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 3) {
		if (seats_num[1][0] == 0) {
			seats_num[1][0] = 1;
			printf("B1�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_b)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 4) {
		if (seats_num[1][1] == 0) {
			seats_num[1][1] = 1;
			printf("B2�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_b)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 5) {
		if (seats_num[1][2] == 0) {
			seats_num[1][2] = 1;
			printf("B3�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_b)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 6) {
		if (seats_num[2][0] == 0) {
			seats_num[2][0] = 1;
			printf("C1�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_c)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 7) {
		if (seats_num[2][1] == 0) {
			seats_num[2][1] = 1;
			printf("C2�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_c)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
	else if (code == 8) {
		if (seats_num[2][2] == 0) {
			seats_num[2][2] = 1;
			printf("C3�¼��� ������ �Ϸ�Ǿ����ϴ�.");
			(*seatkey_c)++;
		}
		else
			printf("�̹̿���� �¼��Դϴ�. �ٽ� ������ �ֽʽÿ�.");
	}
}

int payprint_1(int seatnum_a, int seatnum_b, int seatnum_c)
{
	int originalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE);
	int saleprice = seatnum_a * (TIMESALE + 2 * SEATSALE) + seatnum_b * (TIMESALE + SEATSALE) + seatnum_c * TIMESALE;
	int finalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE)-((seatnum_a * (TIMESALE + 2 * SEATSALE)) + seatnum_b * (TIMESALE + SEATSALE) + seatnum_c * TIMESALE);
	system("cls");
	gotoxy(2, 2);
	printf("<���� ����>");
	gotoxy(2, 4);
	printf("���� �ݾ�: %d", originalprice);
	gotoxy(2, 5);
	printf("���� �ݾ�: %d", saleprice);
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("���� �ݾ�: %d", finalprice);

	return finalprice;
}

int payprint_2(int seatnum_a, int seatnum_b, int seatnum_c)
{
	int originalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE);
	int saleprice = seatnum_a * 2 * SEATSALE + seatnum_b * SEATSALE;
	int finalprice = (seatnum_a + seatnum_b + seatnum_c) * (PRICE)-(seatnum_a * 2 * SEATSALE + seatnum_b * SEATSALE + seatnum_c);
	system("cls");
	gotoxy(2, 2);
	printf("<���� ����>");
	gotoxy(2, 4);
	printf("���� �ݾ�: %d", originalprice);
	gotoxy(2, 5);
	printf("���� �ݾ�: %d", saleprice);
	gotoxy(2, 6);
	printf("-----------------");
	gotoxy(2, 7);
	printf("���� �ݾ�: %d", finalprice);

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
	printf("����� ��,�� �Է� ex)2019 11 : ");
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
	printf(" [��ȭ�ð���]");
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
		printf(" <�̹����� ��ȭ>");
		gotoxy(x, y + 1);
		printf(">1.�ܿ�ձ�\n");
		gotoxy(x, y + 2);
		printf(" 2. ���Ӵ�\n");
		gotoxy(x, y + 3);
		printf(" 3. �����Ѽ�2\n");

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
			return 1; // ���� ��ȯ
		}
		else if (key == 'n' || key == 'N') {
			printf("N");
			return 0; // ������ ��ȯ
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
	char A[3] = { 'A','B','C' }; //������ ���
	int d[3] = { 1,2,3 };         //���� ���
	int x = 3;
	int y = 2;
	gotoxy(x, y);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {

			printf("%d ", seats_num[i][j]);
		}
		printf("\n   ");
	}


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
	printf("\n\t<��Ƽ��������> \n\n");
	printf("\t�ܿ�ȭ������\n");
	switch (moviekey)
	{
	case 1:
		printf("�����ſ�ȭ:Frozen 2\n");
		break;
	case 2:
		printf("�����ſ�ȭ: BLACK MONEY\n");
		break;
	case 3:
		printf("�����ſ�ȭ: The Divine Move 2 \n");
		break;
	default:
		break;
	}
	printf("��������: %d\n", date); // ��¥ ( 20191120 ó�� 8�ڸ��� ǥ��)
	switch (timekey)
	{
	case 0:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	case 2:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	case 4:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	case 6:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	case 8:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	case 10:
		printf("�������ð�: 8:30 - 10:30\n");
		break;
	default:
		break;
	} // ������ ��ȭ�� ������, �����ð�ǥ��! ( �߰������� �ڸ�ǥ�� �ʿ�!)

	printf("\n\t�ܰ��� ������\n\n");
	printf("������ �ݾ�: %d", price);
	_sleep(4000);
}
