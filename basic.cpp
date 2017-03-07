#include "basic.h"

void cardColor(Card card)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	
    switch(card.suit)
	{
		case 'h':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED);
			printf("红桃");
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 's':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN);
			printf("黑桃");
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 'd':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
			FOREGROUND_RED|FOREGROUND_INTENSITY);
		 	printf("方块");
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 'c':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_INTENSITY);
			printf("梅花");
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
	}	
}

void printCard(Card card)
{	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);	
    char *value;
    switch(card.value)
    {
    	case 1:
        	value = "A";
        	break;
    	case 2:
        	value = "2";
        	break;
    	case 3:
        	value = "3";
       		break;
    	case 4:
        	value = "4";
        	break;
    	case 5:
        	value = "5";
        	break;
    	case 6:
        	value = "6";
        	break;
    	case 7:
        	value = "7";
        	break;
    	case 8:
        	value = "8";
        	break;
    	case 9:
        	value = "9";
        	break;
    	case 10:
        	value = "10";
        	break;
    	case 11:
        	value = "J";
        	break;
    	case 12:
        	value = "Q";
        	break;
    	case 13:
        	value = "K";
        	break;
    }
    switch(card.suit)
	{
		case 'h':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED);
			printf("红桃%s ", value);
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 's':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN);
			printf("黑桃%s ", value);
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 'd':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
			FOREGROUND_RED|FOREGROUND_INTENSITY);
		 	printf("方块%s ", value);
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
		case 'c':
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_INTENSITY);
			printf("梅花%s ", value);
			SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|FOREGROUND_RED|
			FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
			break;
	}
}

//生成新牌组 
void newGame(Card cards[])
{
    int i, j;
    Card tmp;

    for(i = 0; i < 52; i++)
    {
        cards[i].value = i % 13 + 1;

        if(i / 13 == 0)
        {
            cards[i].suit = 'd';
        }
        else if(i / 13 == 1)
        {
            cards[i].suit = 'c';
        }
        else if(i / 13 == 2)
        {
            cards[i].suit = 'h';
        }
        else
        {
            cards[i].suit = 's';
        }
    }

    // 洗牌
    for(i = 0; i < 52; i++)
    {
        j = rand() % 52;
        tmp = cards[i];
        cards[i] = cards[j];
        cards[j] = tmp;
    }
}

void printCards(Card cards[], int n, char *name)
{
    int i;
    printf("\t\t\t           %s: ", name);
    printf("\n\n\n");
    printf("\t\t");   
    for(i = 0; i < n; i++)
    {
    	printf("%d：",i + 1);
        printCard(cards[i]);
    }
    printf("\n\n\n");
}

int availableCards(Card card, Card playerCards[], int available[],int n)
{
    int i, count;
    if(card.value == -1)
    {
        for(i = 0; i < 5; i++)
        {
            available[i] = i;
        }
        return 5;
    }

    count = 0;

    for(i = 0; i < n; i++)
    {
        // J
        if(playerCards[i].value == 11)
        {
            available[count++] = i;
            continue;
        }

        // 同数字
        if(playerCards[i].value == card.value)
        {
            available[count++] = i;
            continue;
        }

        // 同花色
        if(playerCards[i].suit == card.suit)
        {
            available[count++] = i;
            continue;
        }
    }

    return count;
}

int cardScore(Card card)
{
    if(card.value == 13)
    {
        return 0;
    }

    return card.value;
}

void removeCard(Card cards[], int index)
{
    int i;
    for(i = 0; i < 4; i++)
    {
        if(i >= index)
        {
            cards[i] = cards[i + 1];
        }
    }
}

void clearScr(int num)
{	
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	system("color 2e");
	system("cls");
	int i = 0;
	
	printf("\t\t\t  ");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("============================\n"); 
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN);
	printf("\t\t\t  ");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("||");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("*********");		
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
	printf("变色龙"); 
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("*********");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("||\n");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN);
	printf("\t\t\t  ");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("============================\n");
	
	struct tm *current_date;
   	time_t seconds;
	time(&seconds);
	current_date = localtime(&seconds);
	SetConsoleTextAttribute(hOut,BACKGROUND_BLUE|
	FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY);
 	printf("日期：%d-%d-%d\n", current_date->tm_year + 1900,
	current_date->tm_mon+1,current_date->tm_mday);

	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|BACKGROUND_RED|
	FOREGROUND_BLUE|FOREGROUND_INTENSITY|BACKGROUND_INTENSITY);	
	printf("   小提示：游戏前请仔细阅读游戏规则，游戏中遵循提示，每次操作完成请按回车确认   \n");
	
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_INTENSITY);
	printf("\t\t\t   ");
	printf("**************************\n");	
	printf("\t\t\t   *");
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_BLUE|FOREGROUND_INTENSITY);	
	printf("      牌堆剩余：%d张",52 - num);	
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_INTENSITY);	
	printf("    *\n");	
	printf("\t\t\t   ");
	printf("**************************\n\n");			
	SetConsoleTextAttribute(hOut,BACKGROUND_GREEN|
	FOREGROUND_RED|FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY);
}

