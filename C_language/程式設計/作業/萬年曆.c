/*設計一個程式讀入年份和月份兩個整數，在畫面上顯示該月份的月曆。
(已知1900年1月1日為星期一)

程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及考試日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
2018 4 <-- 從鍵盤輸入2018 4[Enter]

2018 4
Sun Mon Tue Wed Thu Fri Sat
  1   2   3   4   5   6   7
  8   9  10  11  12  13  14
 15  16  17  18  19  20  21
 22  23  24  25  26  27  28
 29  30*/
#include <stdio.h>
int main(void) 
{ 
    int i,Init_day,year,month;    
    int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    
    scanf("%d%d",&year,&month);
    printf("Sun Mon Tue Wed Thu Fri Sat\n");    
    
    if ((year%4 == 0 )) 
    { 
        day[1]=29;
        Init_day = (((year-1900)/4)*366 + ( (year-1900)-((year-1900)/4) )*365)%7;//取得該年 1 月 1 日的日期 
    } 
    else
    {
    	Init_day = (((year-1900)/4)*366 + ( (year-1900)-((year-1900)/4) )*365+1)%7;
	}
    for(i=0;i<month-1;i++)  //加總到輸入月份的天數 
        Init_day += day[i];	  
    for(i=0;i<(Init_day %= 7);i++)//輸出上個月的空白日期 
        printf("    ");
         
    for(i=1;i<=day[month-1];i++)//輸出該月日期 
    {
    	printf("%3d ",i);
    	Init_day++;
    	if(Init_day>=7)
    	{
    		printf("\n");
		    Init_day=0;
		}
	}
    return 0; 
}
