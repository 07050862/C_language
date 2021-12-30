/*
請設計一個九宮格程式，輸入1~9的整數，繪製一個九宮格，
在對應的位置顯示輸入的數字(數字依序由左至右，由上而下排列)。
*/ 
#include <stdio.h>
int main(void)
{
    int n,i,j,l,o,r;
	
	printf("請輸入欲顯示的數字 : ");
	
	scanf("%d",&n);
	
	r = n % 3;
	if(r == 0)
	r = r+3;
	
	if(n%3==0)
	l = n / 3;
	else
	l = n / 3 + 1;
	
	for(j=1;j<=7;j++)
	{
		if(j%2==0)
		{
			if(l*2==j)
			{
				for(o=1;o<=3;o++)
			    {
			        if(r == o)
			            printf("*%d",n);
			        else
			        printf("* ");
			    }
			}
			else
			{
			printf("* * * ");
	        }
		
		printf("*\n");
		}
		else
		{
		    for(i=1;i<=7;i++)
		    {
		        printf("*"); 
		    }
		printf("\n");
        }
    }
    return 0;
} 
