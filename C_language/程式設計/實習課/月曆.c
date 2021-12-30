/*
輸入一個數字代表月份，在輸入該月的 1 號為星期幾，及該月有
機天。輸入完成後會印出"X 月份日曆"及月曆結果。(日期寬度為
2，日期與日期中間空格為 tab，若該月的第一天為星期日則輸輸入
7，且完成後的月曆星期日在左邊)。
*/ 
#include<stdio.h>
int main(void)
{
    int first_day,total_day,month,i,j;
    scanf("%d%d%d",&month,&first_day,&total_day);
	printf("請輸入月份： ");
	
	
	printf("請輸入1號為星期幾？本月份幾天？");
	
	
	printf("%d月份日曆\n",month);
	
    printf("日	一	二	三	四	五	六	\n");
	
	if(first_day == 7)
	    first_day = 0;
	
	for(i=1;i<=first_day;i++)
	    {
	        printf("  	");
	    }
	for(j=1;j<=total_day;j++)
	{
	    if( (first_day+j) % 7 ==0 )
	    {
	        printf("%2d	\n",j);
	    }
	    else
	        printf("%2d	",j);
	}
	
	return 0;
}
