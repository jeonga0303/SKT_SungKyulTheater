#ifndef TICKET_H
#define TICKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <windows.h>

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define SUBMIT 4

#define PRICE 10000
#define TIMESALE 3000
#define SEATSALE 1000
#define TIMESIZE 5

int keyControl();
void init();                             //콘솔창 크기
void titleDraw();                     // SKT로고 디자인
int menuDraw();                     //시작 메뉴3개 출력 1.예매하기 2. 예매번호출력 3.끝내기
void gotoxy(int, int);               //방향키
int reservation(int, int, int, int);  //날짜,자리예약,결제창
int reservationtime(int);           //영화시간출력 (reservation에 포함)
int isyoon(int a);                    //달력 윤달세주는 함수(dateprint에 포함)
int dateprint();                        //달력출력 (main)
int movechart(int);                   //영화 순위 알려주는 코드 main
void Ticket(int, int, int, int);       //티켓 영수증 출력함수 (reservarion포함)
int getYesNoKey(void);             //reservation
int SeatsChange(int, int, int, int); //자리 0->1 바꿔주는것 (reservation에 포함)
int sprint2();                           //reservation  A,B,C값
int sprint3();                          //reservation   1,2,3값
int payprint_1(int, int, int);        //reservation
int payprint_2(int, int, int);        //reservation
void setColor();                      //배경색 바꿔주는 함수
int seatsprint();                      //좌석표전체출력 reservation 포함
void mselectprint();
int mselectDraw();
int selectDraw();
void infoprint(int);
void movieinformation();        


#endif
