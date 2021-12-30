/*
請輸入一個整數(最小為 2，若輸入 1 則印出請重新輸入)，並印出
該數的質因數分解式。*/ 
#include<stdio.h>

int main(void)
{
    int n,i;
    scanf("%d",&n);
    printf("請輸入一個整數\n");
    if(n==1)
        printf("請重新輸入\n");
    else
    {
     printf("%d=",n);
        for(i=2;i<=n;i++)   
        {
            for(;n>i;)
            {
                if(n%i==0)
                {   
                    printf("%d*",i);
                    n/=i;
                } 
                else
                break;
            }
        }
    printf("%d\n",i-1);
    }	
	return 0;
	
}
