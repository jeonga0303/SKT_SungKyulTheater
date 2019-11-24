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

int isyoon(int a);                     //달력 윤달세주는 함수(dateprint에 포함)
int dateprint();                       //달력출력 (main)
int movieselect(int);                 //영화 예매할때 출력되는 영화 (main.c에 선언)
int reservationtime(int);           //영화시간출력 (reservation에 포함)
void Ticket(int, int, int, int);        //티켓 영수증 출력함수 (reservarion포함)
int getYesNoKey(void);             //예,아니오값 (reservation,movieinformation에 포함)
int SeatsChange(int, int, int, int); //자리 0->1 바꿔주는것 (reservation에 포함)
int sprint2();                           //reservation  A,B,C값
int sprint3();                          //reservation   1,2,3값
int payprint_1(int, int, int);        //조조(시간)할인이랑 좌석할인 함수,reservation 포함
int payprint_2(int, int, int);        //좌석할인 함수,reservation 포함
int seatsprint();                      //좌석표전체출력 reservation 포함



