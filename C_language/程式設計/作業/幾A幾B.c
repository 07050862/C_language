/*
猜數字，幾A幾B!

請設計一個程式，由電腦產生由4個不重複數字(0-9)所組成的密碼，之後由玩家來猜測這個密碼。

將猜測密碼的4個數字逐一與實際密碼的4個數字進行比較，如果有猜測密碼的某個數字與組成密碼的某個數字相同，且位置相同，則計算為1A；如果數字相同，但位置不同則計算為1B。將比較的結果合併計算後提供給玩家，作為玩家進行下一次猜測的參考。

當計算結果為4A0B，則表示玩家已經猜中密碼。玩家輸入0000表示放棄，程式會顯示密碼。

檔名: 學號-hw11.c (例如：04051234-hw11.c)

提示：

srand(time(NULL)); // 設定亂數種子，執行一次即可
n = rand()%10; // 產生一個 0 - 9 的整數
程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
Ready! Go:
1234
=0A2B
1111
Incorrect input, try again!
5678
=1A0B
1290
=1A1B
5294
=1A1B
3692
=2A0B
4691
=4A0B
MAGIC=4691
*/
#include <stdio.h>
int main()
{
    int o[4],en[4],i,j=0,A=0,B=0,n,count=0,y=0,m;
    srand(time(NULL)); // 設定亂數種子，執行一次即可

    
    for(i=0;i<4;i++)
	{
	    o[i] = rand()%10;
	    for(j=0;j<=3;j++)
	    {
	    	
			    if(o[i]==o[j]&&i!=j)
			        for(count=0;count<=9;count++)
			        {
			        	if(count!=o[0]&&count!=o[1]&&count!=o[2]&&count!=o[3])
			        	    o[i] = count;
					}
		}
	} 
	
    
    
    while(A!=4)
    {
        for(j=0;j<4;j++)
        {y=0;
            scanf("%1d",&en[j]);
        }
     
        
    for(m=0;m<4;m++)
	{
	    for(n=0;n<=3;n++)
	    {
	    	if(en[m]==en[n]&&m!=n)
	    	{
	    		y=-1;
	    		printf("Incorrect input, try again!");
	    		break;
			}
	    	   
		}
		if(y==-1)
		break;
	} 
    if(y!=-1)
    {
         
        A=0,B=0;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(en[i]==o[j])
                {
                    B+=1;
                }
            }
        }
            for(i=0;i<4;i++)
            {
                if(en[i]==o[i])
                {
                    A+=1;
                }
            }
    B=B-A;
            printf("=%dA%dB\n",A,B);

        }
    } 
    printf("MAGIC=");
    for(i=0;i<=3;i++)
	    printf("%d",o[i]);
    return 0;
    }
