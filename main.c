#include "main.h" 

int main() {
	int timekey1_1, timekey2_2, timekey3_3;

	int ticketnumber;
	int movie_key;
	int count;
	int Adnumber;// Adnumber => 예매번호

	int price = 0;

	FILE *fp1, *fp2, *fp3, *fp4, *fp5, *fp6;

	movieinformation();


	while (1)
	{
		init();
		titleDraw();
		int menucode = menuDraw();

		system("cls");

		moviekey = movieselect(menucode);
		system("cls");


		if (menucode == 0) { //예매하기
			if (moviekey == 1) // 선택한 영화가 겨울왕국일때
			{
				price = reservation1(&timekey1_1);
			}
			if (moviekey == 2) // 선택한 영화가 블랙머니일때
			{
				price = reservation2(&timekey2_2);
			}
			if (moviekey == 3) // 선택한 영화가 신의한수일때
			{
				price = reservation3(&timekey3_3);
			}

			fp6 = fopen("count.txt", "r");
				fscanf(fp6, "%d", &count);
				fclose(fp6);
				count += 1;

				fp6 = fopen("count.txt", "w");
				fprintf(fp6, "%d", count);
				fclose(fp6);
		}

		if (menucode == 1) {   //티켓예매  출력
			fp5 = fopen("TicketNumber.txt", "r");
			fscanf(fp5, "%d", &ticketnumber);
			fclose(fp5);

			printf("예매번호를 입력해 주십시오.(ex2019111601):");;
			scanf("%d", &Adnumber);
			if (Adnumber == ticketnumber)
			{
				Ticket();
			}
		}
		if (menucode == 2) {  //종료
			system("cls");
			printf("종료합니다");
			break;
		}
	}
	return 0;

}
