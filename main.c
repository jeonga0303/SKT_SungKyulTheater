#include "ticket.h" 


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

		int moviekey = movechart(menucode);
		system("cls");

		if (menucode == 0) { //예매하기
			int datecode = dateprint(menucode);
			price = reservation(&datecode, &timekey, &datekey2, moviekey, &price); // 시간,날짜,영화 키를 받아 옴
		}

		if (menucode == 1) {   //티켓예매  출력
			printf("예매번호를 입력해 주십시오.(ex2019111601):");
			scanf("%d", &Adnumber); 
			Ticket(moviekey, timekey, datekey2, price);

		}
		if (menucode == 2) {  //종료
			system("cls");
			printf("종료합니다");
			break;
		}
	}
	return 0;

}


