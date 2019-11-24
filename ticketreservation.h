#ifndef RESERVATION_H
#define RESERVATION_H
 
#define PRICE 10000
#define TIMESALE 3000
#define SEATSALE 1000
#define TIMESIZE 5

#define TIMESALE_ORIGINAL_PRICE(x,y,z) ((x+y+z)*PRICE)
#define TIMESALE_SALEPRICE_PRICE(x,y,z) ((x*(TIMESALE+(2*SEATSALE)))+(y*(TIMESALE+SEATSALE))+(z*TIMESALE))
#define TIMESALE_FINALPRICE_PRICE(x,y,z) (((x+y+z)*PRICE)-((x*(TIMESALE+(2*SEATSALE)))+(y*(TIMESALE+SEATSALE))+(z*TIMESALE)))


#define SEATSALE_ORIGINAL_PRICE(x,y,z)  ((x + y +z) * (PRICE))
#define SEATSALE_SALEPRICE_PRICE(x,y,z) ((x*2*SEATSALE)+(y*SEATSALE))
#define SEATSALE_FINALPRICE_PRICE(x,y,z) (((x+y+z)*PRICE)-((x*2*SEATSALE)+(y*SEATSALE)))


#endif

int isyoon(int a);                     //�޷� ���޼��ִ� �Լ�(dateprint�� ����)
int dateprint();                       //�޷���� (main)
int movieselect(int);                 //��ȭ �����Ҷ� ��µǴ� ��ȭ (main.c�� ����)
int reservationtime(int);           //��ȭ�ð���� (reservation�� ����)
void Ticket(int, int, int, int);        //Ƽ�� ������ ����Լ� (reservarion����)
int getYesNoKey(void);             //��,�ƴϿ��� (reservation,movieinformation�� ����)
int SeatsChange(int, int, int, int); //�ڸ� 0->1 �ٲ��ִ°� (reservation�� ����)
int sprint2();                           //reservation  A,B,C��
int sprint3();                          //reservation   1,2,3��
int payprint_1(int, int, int);        //����(�ð�)�����̶� �¼����� �Լ�,reservation ����
int payprint_2(int, int, int);        //�¼����� �Լ�,reservation ����
int seatsprint();                      //�¼�ǥ��ü��� reservation ����



