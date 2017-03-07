#ifndef _BASIC_H_
#define _BASIC_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> 
#include <conio.h>


using namespace std;

typedef struct card
{
    int value;
    char suit;
} Card;

void cardColor(Card card);
void printCard(Card card);		//打印单张牌
void newGame(Card cards[]);		//生成新牌组 
void printCards(Card cards[], int n, char *name);  //打印牌组
int availableCards(Card card, Card playerCards[], int available[],int n); //当前可打的牌 
int cardScore(Card card);		// 返回牌对应的分值
void removeCard(Card cards[], int index);	//删除一张牌
void clearScr(int num);						//实时显示日期及界面 



#endif
