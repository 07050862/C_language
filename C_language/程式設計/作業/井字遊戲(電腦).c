/*
井字遊戲，人腦和電腦對弈!
請設計一個程式，讓使用者(O)和電腦(X)玩井字遊戲，由使用者開始，電腦要盡力取勝和防守，並判斷誰贏了。
檔名: 學號-hw10.c (例如：04051234-hw0.c)
程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果
=== 範例執行結果(1) ===
 | |
-+-+-
 | |
-+-+-
 | |
Player put O:0 0
O| |
-+-+-
 | |
-+-+-
 | |
Computer put X: 0 1
O|X|
-+-+-
 | |
-+-+-
 | |
Player put O:1 0
O|X|
-+-+-
O| |
-+-+-
 | |
Computer put X: 2 0
O|X|
-+-+-
O| |
-+-+-
X| |
Player put O:2 2
O|X|
-+-+-
O| |
-+-+-
X| |O
Computer put X: 1 1
O|X|
-+-+-
O|X|
-+-+-
X| |O
Player put O:0 2
O|X|O
-+-+-
O|X|
-+-+-
X| |O
Computer put X: 2 1
O|X|O
-+-+-
O|X|
-+-+-
X|X|O
Player X win!
*/
#include <stdio.h>
int main(void)
{
   int player = 0, winner = 0, choice = 0, row = 0, column = 0, line = 0, i, j, k, dd = 0;
   char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
   int math[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
   for (i = 0; i < 9 && winner == 0; i++)
   {
      printf("%c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
      printf("-+-+-\n");
      printf("%c|%c|%c\n\n", board[2][0], board[2][1], board[2][2]);
      player = i % 2 + 1;
      do
      {
         if (player == 1)
         {
            printf("Player put O:");
            scanf("%d %d", &row, &column);
         }
         else
         {
            printf("Computer put X:");
         }
      } while (board[row][column] == 'X');
      if (player == 1)
      {
         board[row][column] = 'O';
         math[row][column] = 1;
      }
      else
      {
         dd = 0;
         if (math[0][0] + math[1][1] + math[2][2] == 2)
         {
            for (j = 0; j <= 2; j++)
            {
               if (math[j][j] == 0)
               {
                  //	printf("斜排有威脅\n");
                  board[j][j] = 'X';
                  math[j][j] = -1;
                  printf("%d %d\n", j, j);
                  break;
               }
            }
         }
         else if (math[0][2] + math[1][1] + math[2][0] == 2)
         {
            if (math[0][2] == 0)
            {
               board[0][2] = 'X';
               math[0][2] = -1;
               printf("0 2\n");
            }
            else if (math[1][1] == 0)
            {
               board[1][1] = 'X';
               math[1][1] = -1;
               printf("1 1\n");
            }
            else
            {
               board[2][0] = 'X';
               math[2][0] = -1;
               printf("2 0\n");
            }
         }
         else
         {

            for (k = 0; k <= 2; k++)
            {
               if (math[k][0] + math[k][1] + math[k][2] == 2)
               {
                  for (j = 0; j <= 2; j++)
                     if (math[k][j] == 0)
                     {
                        //  printf("橫排有威脅\n");
                        board[k][j] = 'X';
                        math[k][j] = -1;
                        printf("%d %d\n", k, j);
                        dd = -1;
                        break;
                     }
               }
               else if (math[0][k] + math[1][k] + math[2][k] == 2)
               {
                  for (j = 0; j <= 2 && dd != -1; j++)
                     if (math[j][k] == 0)
                     {
                        // printf("縱排有威脅\n");
                        board[j][k] = 'X';
                        math[j][k] = -1;
                        printf("%d %d\n", j, k);
                        dd = -1;
                        break;
                     }
               }
            }

            for (j = 0; j <= 2 && dd != -1; j++)
            { //  printf("沒威脅\n");
               if (math[0][j] == 0 && dd != -1)
               {
                  board[0][j] = 'X';
                  math[0][j] = -1;
                  printf("0 %d\n", j);
                  dd = 0;
                  break;
               }
               else if (math[1][j] == 0 && dd != -1)
               {
                  board[1][j] = 'X';
                  math[1][j] = -1;
                  printf("1 %d\n", j);
                  dd = 0;
                  break;
               }
               else if (math[2][j] == 0 && dd != -1)
               {
                  board[2][j] = 'X';
                  math[2][j] = -1;
                  printf("2 %d\n", j);
                  dd = 0;
                  break;
               }
            }
         }
      }

      if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) && board[1][1] != ' ' || (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != ' '))
         winner = player;

      for (line = 0; line <= 2; line++)
         if (((board[line][0] == board[line][1] && board[line][0] == board[line][2] && board[line][0] != ' ') || (board[0][line] == board[1][line] && board[0][line] == board[2][line] && board[0][line] != ' ')))
            winner = player;
   }

   printf("\n\n");
   printf("%c|%c|%c\n", board[0][0], board[0][1], board[0][2]);
   printf("-+-+-\n");
   printf("%c|%c|%c\n", board[1][0], board[1][1], board[1][2]);
   printf("-+-+-\n");
   printf("%c|%c|%c\n", board[2][0], board[2][1], board[2][2]);

   if (winner == 1)
      printf("Player O win!");
   else if (winner == 2)
      printf("Player X win!");
   else
      printf("\n平手");
   return 0;
}
