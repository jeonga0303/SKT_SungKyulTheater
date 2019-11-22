#include "main.h"
#include "findmovie.h"

void mselectprint() {
	while (1) {
		printf("\n");
		setColor(yellow, black);
		printf(":*:*:*:*:*:*:*:*:*:*:*:*:*:*:*\n*:");
		setColor(lightgray, black);
		printf("�˾ƺ� ��ȭ�� �������ּ���");
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
			printf(" ��ȭ ���� �ý����� �����ϰڽ��ϴ�...��ø� ��ٷ��ּ���");
			break;
		}
	}
}

int selectDraw() {
	int x = 10;
	int y = 10;
	gotoxy(x - 2, y);
	setColor(lightgray, black);
	printf(">    �� �˾ƺ���");
	gotoxy(x, y + 1);
	printf("   ������");
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
	printf(">    �ܿ�ձ�2");
	gotoxy(x, y + 1);
	printf("   ���Ӵ�");
	gotoxy(x, y + 2);
	printf("   ���� �Ѽ�2");
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
		char intro[1000]; //��ȭ �Ұ�
		char name[100]; //��ȭ �̸�
		int ranking; //��ȭ ����
		int mtime; //���� �ð�
		char rate[100]; //���� �̿밡 ex) ��ü������,15���̻������ ����ϱ� ����
		char style[100]; //��ȭ �帣
		double grade; //��ȭ ����
	} arr[3];
	//�� ����
	strcpy(arr[0].intro, "�η����� ����, ���ο� ����� ������.");
	strcpy(arr[0].name, "   Frozen2 = �ܿ�ձ�2    ");
	arr[0].ranking = 1;
	arr[0].mtime = 108;
	strcpy(arr[0].rate, "��ü������   ");
	strcpy(arr[0].style, "�ִϸ��̼� ");
	arr[0].grade = 4.06;
	strcpy(arr[1].intro, "���� ����Ѵ� !!!");
	strcpy(arr[1].name, "  BLACK MONEY = ���Ӵ�  ");
	arr[1].ranking = 2;
	arr[1].mtime = 113;
	strcpy(arr[1].rate, "12���̻������");
	strcpy(arr[1].style, "����,���");
	arr[1].grade = 9.11;
	strcpy(arr[2].intro, "�ͽ� ���� �ڵ��� ����� ���۵ȴ�!");
	strcpy(arr[2].name, "The Divine Move2 = ���� �Ѽ�2");
	arr[2].ranking = 3;
	arr[2].mtime = 106;
	strcpy(arr[2].rate, "15���̻������");
	strcpy(arr[2].style, "����,�׼� ");
	arr[2].grade = 8.94;
	printf(" [%s]\n", arr[n].name);
	printf("** %s\n", arr[n].intro);
	setColor(lightgray, black);
	printf("-------- ��ȭ ���� : %d��       \n", arr[n].ranking);
	printf("-------- ���� �ð� : %d��       \n", arr[n].mtime);
	printf("-------- ���� �̿밡 : %s       \n", arr[n].rate);
	printf("-------- ��ȭ �帣 : %s         \n", arr[n].style);
	printf("-------- ��ȭ ���� : %.2f       \n", arr[n].grade);
	printf("\n\n");
}

int movieinformation() {
	char ch;
	FILE * fp = fopen("������Ʈ.txt", "r");
	if (fp == NULL) {
		printf("���� ���� ���� !\n");
		return -1;
	}
	setColor(yellow, black);
	printf("*:*");
	setColor(lightred, black);
	printf("<�� ���� ��ȭ>");
	setColor(yellow, black);
	printf("*:*:*:*:*:*");
	setColor(lightred, black);
	printf("<������>\n");
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
	printf("��ȭ�� ������ �˾ƺ��ðڽ��ϱ�?(Y/N) ");
	if (getYesNoKey()) {
		system("cls");
		mselectprint();
	}
	else {
		printf("\n\n");
		printf("��ȭ ���� �ý����� �����ϰڽ��ϴ�...��ø� ��ٷ��ּ���");
	}
	fclose(fp);
	Sleep(1000);
	return 0;
}