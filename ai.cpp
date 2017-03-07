#include "ai.h"

int minScore(Card cards[],int n)
{
    int i, index;
    index = 0;
    int score = cardScore(cards[0]);
    for(i = 1; i < n; i++)
    {
        if(cardScore(cards[i]) < score)
        {
            index = i;
            score = cardScore(cards[i]);
        }
    }
    return index;
}

char getBestSuit(Card cards[])
{
    int i, max, index;
    int suits[4] = {0};
    for(i = 0; i < 4; i++)
    {
        if(cards[i].suit == 'd')
        {
            suits[0]++;
        }
        else if(cards[i].suit == 'c')
        {
            suits[1]++;
        }
        else if(cards[i].suit == 'h')
        {
            suits[2]++;
        }
        else if(cards[i].suit == 's')
        {
            suits[3]++;
        }
    }

    max = suits[0];
    index = 0;
    for(i = 1; i < 4; i++)
    {
        if(suits[i] > max)
        {
            max = suits[i];
            index = i;
        }
    }

    if(index == 0)
    {
        return 'd';
    }
    else if(index == 1)
    {
        return 'c';
    }
    else if(index == 2)
    {
        return 'h';
    }

    return 's';
}
