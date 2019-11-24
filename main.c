#include "main.h" 

int main() {
	int timekey, Adnumber;// Adnumber => 예매번호
	int datekey2;
	int price = 0;

	movieinformation();

	while (1)
	{
		init();
		titleDraw();
		int menucode = menuDraw();

		system("cls");

		int moviekey = movieselect(menucode);
		system("cls");

		if (menucode == 0) { //예매하기
			if (moviekey == 1) // 선택한 영화가 겨울왕국일때
			{
				int datecode = dateprint(menucode);
				price = reservation(&datecode, &timekey, &datekey2, moviekey, &price); // 시간,날짜,영화 키를 받아 옴
			}
			if (moviekey == 2) // 선택한 영화가 블랙머니일때
			{
				int datecode = dateprint(menucode);
				price = reservation(&datecode, &timekey, &datekey2, moviekey, &price); // 시간,날짜,영화 키를 받아 옴
			}
			if (moviekey == 3) // 선택한 영화가 신의한수일때
			{
				int datecode = dateprint(menucode);
				price = reservation(&datecode, &timekey, &datekey2, moviekey, &price); // 시간,날짜,영화 키를 받아 옴
			}
		}

		if (menucode == 1) {   //티켓예매  출력
			printf("예매번호를 입력해 주십시오.(ex2019111601):");;
			scanf("%d", &Adnumber);
			if (Adnumber == datekey2 * 100 + 1)
				Ticket(moviekey, timekey, datekey2, price);
			else
				printf("\n예매번호가 잘못되었습니다. 처음 화면으로 돌아갑니다.");
			_sleep(1000);

		}
		if (menucode == 2) {  //종료
			system("cls");
			printf("종료합니다");
			break;
		}
	}
	return 0;

}
