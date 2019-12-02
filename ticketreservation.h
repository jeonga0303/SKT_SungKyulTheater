#ifndef TICKETPRICE
#define TICKETPRICE

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

int payprint_1(int, int, int);        //조조(시간)할인이랑 좌석할인 함수,reservation 포함
int payprint_2(int, int, int);        //좌석할인 함수,reservation 포함
#endif

#ifndef FROZEN2
#define FROZEN2
#define SIZE 5

int count1[SIZE] = { 0 };
int seats_num1[3][3] = { 0 };
int ticket1;
int date1;

int reservation1(int *timekey1); //예약함수
int reservationtime1();                                                                            //영화시간출력
int seatsprint1();                                                                                  //좌석표전체출력 
int seattotal1(int *seatkey_a, int *seatkey_b, int *seatkey_c);                             //좌석변환
int dateprint1();                       //달력출력 
#endif

#ifndef BLACKMONEY
#define BLACKMONEY

int count2[SIZE] = { 0 };
int seats_num2[3][3] = { 0 };
int ticket2;
int date2;

int reservation2(int *timekey2);
int reservationtime2();
int seatsprint2();
int seattotal2(int *seatkey_a, int *seatkey_b, int *seatkey_c);
int dateprint2();                       //달력출력 
#endif

#ifndef THEDIVINEMOVE2
#define THEDIVINEMOVE2

int count3[SIZE] = { 0 };
int seats_num3[3][3] = { 0 };
int ticket3;
int date3;

int reservation3(int *timekey3);
int reservationtime3();
int seattotal3(int *seatkey_a, int *seatkey_b, int *seatkey_c);
int seatsprint3();
int dateprint3();                       //달력출력 
#endif

#ifndef SEAT_HAMSU
#define SEAT_HAMSU

enum seats { A1, A2, A3, B1, B2, B3, C1, C2, C3 };
enum seats code;
int sprint1();                           //A,B,C 입력
int sprint2();                          //1,2,3 입력
#endif


int yoon(int a);                       //달력 윤달세주는 함수


void Ticket();
int movieselect(int);                   //영화 예매할때 출력되는 영화 
int getYesNoKey(void);             //예,아니오값
