#include "basic.h"
#include "ai.h"

int main()
{
    srand((unsigned)time(NULL));
    int i, n, mode, playerScore1, index = 0, playerScore2, choose, valid, 
	meWins = 0, player2Wins1 = 0,player2Wins2 = 0, player1Wins = 0,rest1,
	rest2,prev_value,enter,flag;
    char suit;
    Card cards[52];
    Card player1[5];
    int available1[5];
    Card player2[5];
    int available2[5];
    Card card;  
	Card preCard; 
	  
	
    while(1)
    { 
        newGame(cards);
        card.value = -1;
        playerScore1 = 0;
        playerScore2 = 0;

        // 记录发牌位置
        index = 0;
        //控制回车量 
        enter = 7;
        rest1 = 5;
        rest2 = 5;
    	clearScr(index);
    	printf("\t\t\t\t  请选择游戏菜单\n\n\n");
    	printf("\t\t\t\t   1、人机对战\n\n");
    	printf("\t\t\t\t   2、机机对战\n\n"); 
    	printf("\t\t\t\t   3、游戏帮助\n\n"); 
    	printf("\t\t\t\t   4、退出游戏\n\n\n"); 
		printf("(请输入1/2/3/4):"); 
		scanf("%d",&mode);
		
		if(mode == 4) break;
		
		if(mode != 1 && mode != 2 && mode != 3 && mode != 4) continue;
		
        for(i = 0; i < 5; i++)
        {
            player1[i] = cards[index++];
            player2[i] = cards[index++];
        }
        
    	clearScr(index);

        while((index < 52 || rest1 !=0 || rest2 !=0)  && mode != 3)
        {
            if(mode == 1)
            {
                // 人机对战
                n = availableCards(card, player1, available1,rest1);
                valid = 0;
                if(n > 0)
                {
                    // 用户选择一张牌打出
                    while(!valid)
                    {
                    	flag = 0;
                    	for(i = 0;i < enter;i++) printf("\n");
            			printCards(player1, rest1, "您的手牌");
                        printf("请选择一张牌打出（输入牌序号,当前可出  ");
                        for(i = 0; i < n; i++)
                        {
                        	if(i != n - 1) printf("%d/",available1[i] + 1);
                        	else printf("%d",available1[i] + 1);
                        }
                        printf(",选择其他为弃牌）：");
                        scanf("%d", &choose);
                        choose -= 1;
                        enter = 7;
                        // 检查打出的牌是否在合法区间内
                        for(i = 0; i < n; i++)
                        {
                            if(choose == available1[i])
                            {
                            	flag = 1;
                                valid = 1;
                                prev_value = card.value;
                                card = player1[choose];
                                preCard = card;
                                removeCard(player1, choose);
                                if(index < 52)
                                {
                                	player1[4] = cards[index++];	
                                }
								else rest1--;
								if(index < 52) clearScr(index + 1);
                                else clearScr(index);
                                if(card.value == 11 || prev_value == card.value)
                                {
                                    while(1)
                                    {
                                    	clearScr(index - 1);
                                    	enter = 7;
    									for(i = 0;i < enter;i++) printf("\n");
    									printCards(player1, rest1, "您的手牌");
                                        printf("请输入改变的花色:1.方块 2.梅花 3.红桃 4.黑桃:");
                                        scanf("%d", &choose);
                                    	if(index < 52) clearScr(index + 1);
                                		else clearScr(index);
                                        choose -=1; 
                                        if(0 <= choose && choose <= 3)
                                        {
                                            if(choose == 0)
                                            {
                                                suit = 'd';
                                            }
                                            else if(choose == 1)
                                            {
                                                suit = 'c';
                                            }
                                            else if(choose == 2)
                                            {
                                                suit = 'h';
                                            }
                                            else if(choose == 3)
                                            {
                                                suit = 's';
                                            }

                                            break;
                                        }
                                        else continue;
                                    }
									card.suit = suit;
									
									printf("您将花色改变为 ");
									cardColor(card);
									enter--;
									printf("\n");
								}
								printf("您打出：");
                                printCard(preCard);
    							printf("\n");
    							enter--;
                                break;
                            }
                        }
                    	if(flag == 0)
                    	{
                    		preCard = player1[choose];
                        	if(0 <= choose && choose < rest1)
                        	{
                            	valid = 1;
                            	// 加分
                            	playerScore2 += cardScore(player1[choose]);
                            	removeCard(player1, choose);
 								if(index < 52)
                            	{
                                	player1[4] = cards[index++];	
                            	}
								else rest1--;
								enter = 7;
                            	if(index < 52) clearScr(index + 1);
                            	else clearScr(index);
                            	printf("您丢弃：");
                            	printCard(preCard);
    							printf("\n");
                            	enter--;
                        	}
                        	else
                        	{
                        		clearScr(index);
                    			printf("该牌不可出，请重新出牌!\n");
                        		enter--;
                        	}
                    	}
                    }
                }
                else
                {
                    // 选择一张牌丢弃
                    while(!valid)
                    {
                    	for(i = 0;i < enter;i++) printf("\n");
            			printCards(player1, rest1, "您的手牌");
                        printf("请选择一张牌丢弃：");
                        scanf("%d", &choose);
                        choose -= 1;
                        preCard = player1[choose];
                        if(0 <= choose && choose < rest1)
                        {
                            valid = 1;
                            // 加分
                            playerScore2 += cardScore(player1[choose]);
                            removeCard(player1, choose);
 							if(index < 52)
                            {
                                player1[4] = cards[index++];	
                            }
							else rest1--;
							enter = 7;
                            if(index < 52) clearScr(index + 1);
                            else clearScr(index);
                            printf("您丢弃：");
                            printCard(preCard);
    						printf("\n");
                            enter--;
                        }
                        else
                        {
                        	enter = 7;
                        	clearScr(index);
                        	printf("该牌不存在，请重新丢弃！\n");
                        	enter--;
						}
					}
				}
            }
            else if(mode == 2)
            {
            	for(i = 0;i < enter;i++) printf("\n");
            	printCards(player1, rest1, "张三手牌");
            	Sleep(2000);
                n = availableCards(card, player1, available1,rest1);
				if(index < 52) clearScr(index + 2);
                else clearScr(index);
				enter = 7; 
				
                if(n > 0)
                {
                    choose = rand() % n;
					prev_value = card.value;
                    card = player1[available1[choose]];
                    preCard = card;
					removeCard(player1, available1[choose]);
 					if(index < 52)
                    {
                        player1[4] = cards[index++];	
                    }
					else rest1--;
					printf("张三打出: ");
					printCard(preCard);
    				printf("\n");
    				enter--;
                    if(card.value == 11 || prev_value == card.value)
                    {
                        card.suit = getBestSuit(player1);
						printf("张三将花色变为 ");
						cardColor(card);
						printf("\n");
						enter--;
					}
                }
                else
                {
                    choose = minScore(player1,rest1);
                    printf("张三丢弃：");
                    playerScore2 += cardScore(player1[choose]);
                    preCard = player1[choose];
 					if(index < 52)
                    {
                        player1[4] = cards[index++];	
                    }
					else rest1--;
                    printCard(preCard);
    				printf("\n");
    				enter--;
                }
                
            }

            // 电脑选择
            n = availableCards(card, player2, available2,rest2);

            if(n > 0)
            {
                choose = rand() % n;
                printf("李四打出: ");
				prev_value = card.value;
                card = player2[available2[choose]];
                preCard = card;
				removeCard(player2, available2[choose]);
 				if(index < 52)
                {
                    player2[4] = cards[index++];	
                }
				else rest2--;
				printCard(preCard);
    			printf("\n");
				enter--; 
                if(card.value == 11 || prev_value == card.value)
                {
                    card.suit = getBestSuit(player2);
					printf("李四将花色变为 ");
					cardColor(card);
					printf("\n"); 
					enter--;
                }

            }
            else
            {
                choose = minScore(player2,rest2);
                printf("李四丢弃: ");
                //加分
                playerScore1 += cardScore(player2[choose]);
                preCard = player2[choose];
                removeCard(player2, choose);
 				if(index < 52)
                {
                	player2[4] = cards[index++];	
                }
				else rest2--;
                printCard(preCard);
    			printf("\n");
                enter--;
            }
        }

		
		if(mode != 3)
		{
			clearScr(index);
			printf("\n\n游戏结果:\n\n");
        	if(mode == 1)
        	{
        		printf("您的得分：%d\n\n", playerScore1);
        		printf("李四得分: %d\n\n", playerScore2);
        		if(playerScore1 > playerScore2)
        		{
            		printf("恭喜您，您获得了胜利  ^_^Y\n");
            		meWins++;
        		}
        		else if(playerScore2 > playerScore1)
        		{
            		printf("很遗憾，您输给了电脑  T_T!\n");
            		player2Wins1++;
        		}
       	 	else
        		{
            		printf("这局为平局!     =_=\n");
        		}
        	}
        	else
			{
        		printf("张三得分：%d\n", playerScore1);
        		printf("李四得分: %d\n", playerScore2);	
				if(playerScore1 > playerScore2)
        		{
            		printf("张三获胜\n");
            		player1Wins++;
        		}
        		else if(playerScore2 > playerScore1)
        		{
            		printf("李四获胜\n");
            		player2Wins2++;
        		}
       	 	else
        		{
            		printf("平局\n");
        		}		
			} 

        	valid = 0;
        	while(!valid)
        	{
            	printf("\n\n\n\n1.继续游戏 2.退出：");
            	scanf("%d", &choose);
            	if(choose == 1 || choose == 2)
            	{
                	valid = 1;
            	}
        	}

        	// 选择退出
        	if(choose == 2)
        	{
            	break;
        	}
    	}
		else
		{
			clearScr(index - 10);
			printf("\t\t\t\t游戏规则如下：\n\n");
			printf("[1] 使用一副扑克牌，共52张牌，不要大小王。 两位玩家。\n\n");
			printf("[2] 游戏开始后，两位玩家交错摸一张牌，直至每位玩家手中都有4张牌。此后，玩家1摸\n");
			printf("一张牌，手中有5张牌，然后从手中选择一张牌打出。玩家2再摸一张牌，手中有5张牌，从\n");
			printf("手中选择一张牌打出。一般情况下，每位玩家在出牌时手中有5张牌。\n\n");
			printf("[3] 出牌时，玩家三种选择：不变色、变色和放弃。\n\n");
			printf("[4] 花色。花色是指黑桃、红桃、梅花、方块。整个打牌过程中都必须有当前花色。例如\n");
			printf("游戏开始后第一张牌的花色就是当前花色。如果没有玩家进行变色，当前花色将保持不变\n\n");
			printf("[5] 不变色。例如，玩家1出一张黑桃3，玩家2需要从手中牌中也出一张黑桃的牌，例如黑\n");
			printf("桃Q。这样一来，当前的花色仍然是黑桃。\n\n");
			printf("[6] 变色。 例如，玩家1出一张黑桃3，玩家2需要从手中牌中也出一张黑桃的牌。但是玩\n");
			printf("家2手中没有黑桃的牌，她/他在满足以下条件的情况下可以变色：\n");
			printf("\t（a）打出任意花色的J；\n");
			printf("\t（b）与对方出的最后一张牌同样数字的牌。\n\n");
			printf("[7] 放弃。如果玩家2既没有黑桃，也无法变色，必须从手中选一张牌放弃，其数值作为玩\n");
			printf("家1的得分。玩家2放弃的牌对玩家1不可见，反之亦然。游戏结束后可公布双方放弃牌。\n\n");
			printf("[8] 牌的数值。2至10的数值分别是2至10，Q是12分，K是0分，A是1分。J是变色牌。\n\n");
			printf("[9] 胜负条件。52张牌都必须摸完并出完。玩家1放弃牌的总分值即玩家2本次游戏的得\n");
			printf("分，反之亦然。得分多者胜。\n\n");
			printf("\n按任意键返回");
     		COORD coord;
			coord.X=0;
			coord.Y=0;
    		HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
     		SetConsoleCursorPosition(hout,coord);
			while(!kbhit());  //当没有键按下 
			getch(); 
		}		
	}
	
	clearScr(index);
	
	if(meWins != 0 || player2Wins1 !=0 || player2Wins2 !=0 ||player1Wins !=0)
	{
   		printf("战绩统计:\n\n\n");
    	if(meWins != 0 || player2Wins1 !=0)
    	{
        	printf("您胜利李四%d次\n", meWins);
    		printf("李四赢了您%d次\n\n\n", player2Wins1);	
    	}
    	if(player2Wins2 !=0 ||player1Wins !=0)
    	{
        	printf("张三赢了李四%d次\n", player1Wins);
    		printf("李四赢了张三%d次\n", player2Wins2);	
    	}			
	}
	Sleep(5000);
    return 0;
}
