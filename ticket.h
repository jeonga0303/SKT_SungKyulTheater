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
void init();                             //�ܼ�â ũ��
void titleDraw();                     // SKT�ΰ� ������
int menuDraw();                     //���� �޴�3�� ��� 1.�����ϱ� 2. ���Ź�ȣ��� 3.������
void gotoxy(int, int);               //����Ű
int reservation(int, int, int, int);  //��¥,�ڸ�����,����â
int reservationtime(int);           //��ȭ�ð���� (reservation�� ����)
int isyoon(int a);                    //�޷� ���޼��ִ� �Լ�(dateprint�� ����)
int dateprint();                        //�޷���� (main)
int movechart(int);                   //��ȭ ���� �˷��ִ� �ڵ� main
void Ticket(int, int, int, int);       //Ƽ�� ������ ����Լ� (reservarion����)
int getYesNoKey(void);             //reservation
int SeatsChange(int, int, int, int); //�ڸ� 0->1 �ٲ��ִ°� (reservation�� ����)
int sprint2();                           //reservation  A,B,C��
int sprint3();                          //reservation   1,2,3��
int payprint_1(int, int, int);        //reservation
int payprint_2(int, int, int);        //reservation
void setColor();                      //���� �ٲ��ִ� �Լ�
int seatsprint();                      //�¼�ǥ��ü��� reservation ����
void mselectprint();
int mselectDraw();
int selectDraw();
void infoprint(int);
void movieinformation();        


#endif
