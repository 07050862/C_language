/*
井字遊戲，誰贏了?

請設計一個程式，讓兩個使用者完井字遊戲，依序放入O和X，程式可以判斷誰贏了。

檔名: 學號-hw09.c (例如：04051234-hw09.c)

程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
 | |
-+-+-
 | |
-+-+-
 | |

Place to put O:0 0
O| |
-+-+-
 | |
-+-+-
 | |

Place to put X:1 0
O| |
-+-+-
X| |
-+-+-
 | |

Place to put O:0 1
O|O|
-+-+-
X| |
-+-+-
 | |

Place to put X:1 2
O|O|
-+-+-
X| |X
-+-+-
 | |

Place to put O:0 2
O|O|O
-+-+-
X| |X
-+-+-
 | |

Player O win!
*/
#include <stdio.h>
int* trans(int *n);
int main(void)
{
	int player = 0,winner = 0,choice = 0,row = 0,column = 0,line = 0,i;
	char board[3][3] = 	{ {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
	for(i = 0;i<9 && winner==0;i++)
	{
		    printf("%c|%c|%c\n",board[0][0],board[0][1],board[0][2]);
		    printf("-+-+-\n");
		    printf("%c|%c|%c\n",board[1][0],board[1][1],board[1][2]);
		    printf("-+-+-\n");
		    printf("%c|%c|%c\n\n",board[2][0],board[2][1],board[2][2]);
		    player = i%2+1;
	    do
	    {
		    if(player==1)
		        printf("Place to put O:");
		    else
		        printf("Place to put X:");
		        
		trans(&choice);
		row = --choice/3;
		column = choice%3;
	    }
	    while(choice<0 || choice>9 || board[row][column]>'9');
		    if(player==1)
		    board[row][column] ='O';
		    else
		    board[row][column] ='X';
	
		if((board[0][0]==board[1][1] && board[0][0]==board[2][2]) &&board[1][1]!=' '||(board[0][2]==board[1][1] && board[0][2]==board[2][0]&&board[1][1]!=' '))
			winner = player;
		else
	
			for(line = 0;line <= 2;line++)
				if(((board[line][0]==board[line][1] &&board[line][0]==board[line][2]&&board[line][0]!=' ')||(board[0][line]==board[1][line]&&board[0][line]==board[2][line]&&board[0][line]!=' ')) )
					winner = player;
	}
	
	
	    printf("\n\n");
	    printf("%c|%c|%c\n",board[0][0],board[0][1],board[0][2]);
		printf("-+-+-\n");
		printf("%c|%c|%c\n",board[1][0],board[1][1],board[1][2]);
		printf("-+-+-\n");
		printf("%c|%c|%c\n",board[2][0],board[2][1],board[2][2]);
	
    
		if(winner==1)
            printf("Player O win!");
        else if(winner==2)
            printf("Player X win!");
        else
            printf("draw");
	
	return 0;
}
int* trans(int *choice)
{
	int a,b;
	scanf("%d %d",&a,&b);

	if(a==0)
	    *choice = b+1;
	else if(a%2==1)
	    *choice = (a*2+2+b);
	else
	    *choice = (a*4-1+b);
	
	return choice;
}
