#include "ticket.h" 


int main() {
	int timekey, Adnumber;// Adnumber => ���Ź�ȣ
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

		if (menucode == 0) { //�����ϱ�
			int datecode = dateprint(menucode);
			price = reservation(&datecode, &timekey, &datekey2, moviekey, &price); // �ð�,��¥,��ȭ Ű�� �޾� ��
		}

		if (menucode == 1) {   //Ƽ�Ͽ���  ���
			printf("���Ź�ȣ�� �Է��� �ֽʽÿ�.(ex2019111601):");
			scanf("%d", &Adnumber); 
			Ticket(moviekey, timekey, datekey2, price);

		}
		if (menucode == 2) {  //����
			system("cls");
			printf("�����մϴ�");
			break;
		}
	}
	return 0;

}


