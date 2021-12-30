/*
設計一個程式讀入兩個日期(yyyymmdd)，計算出兩個日期相距幾天。

檔名: 學號-hw07.c (例如：04051234-hw07.c)

程式必須符合下列要求：
1. 程式第一行必須加上含程式名稱,學號,姓名,及考試日期的註解
2. 程式之輸入及輸出結果必須符合範例執行結果

=== 範例執行結果(1) ===
19990102 19990110
DAY=8
=== 範例執行結果(2) ===
20000115 20000715
DAY=182
=== 範例執行結果(3) ===
20000310 20001202
DAY=267
=== 範例執行結果(4) ===
20020331 19991001 
DAY=912
=== 範例執行結果(5) ===
20040410 20080115
DAY=1375
=== 範例執行結果(6) ===
20040110 20080331
DAY=1542
*/
#include <stdio.h>
int main(void)
{
	int i,s1,s2,ans=0,a,b,year_a,year_b,mon_a,mon_b,day_a,day_b;
	
	scanf("%d%d",&a,&b);
	day_a = a % 100;
	day_b = b % 100;
	mon_a = a / 100 % 100;
	mon_b = b / 100 % 100;
	year_a = a / 10000;
	year_b = b / 10000;

    s1=sum(year_a,mon_a,day_a);
    s2=sum(year_b,mon_b,day_b);	
    
    if (s1 > s2)
        printf("DAY=%d",s1-s2);
    else
        printf("DAY=%d",s2-s1);
    
    
	return 0;
}

int sum(int y,int m,int d)
{
    char mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int i,s=0;
    
    for(i=1;i<y;i++)
    if(i%4==0 && i%100!=0 || i%400==0)
      s+=366;
    else
      s+=365;

    if(y%4==0 && y%100!=0 || y%400==0)
    mon[2]=29;

    for(i=1;i<m;i++)
    s+=mon[i];
    s+=d;

  return s;
}
