/*
块ㄢタ俱计
凱 狦材计单材计玥ㄌ酚パ抖
   ┮Τ单材计材计计计
凱 狦材计材计玥ㄌ酚パ抖
   ┮Τ单材计材计计计
   EX:Please enter two numbers:2 10
      The sequence is 2 4 6 8 10
   EX:Please enter two numbers:30 4
      The sequence is 28 24 20 16 12 8 4 
 
*/ 
#include <stdio.h>
int main(void)
{
	int a,b,i;
	
	printf("Please enter two numbers:");
	
	scanf("%d%d",&a,&b);
	printf("The sequence is ");
	if(a<=b)
	{
		for(i=1;a*i<=b;i++)
		{
			printf("%d ",a*i);
		}
	}
	else
	{
		i = a / b;
		for(i;i>0;i--)
		{
			printf("%d ",b*i);
		}
	}
	
	return 0; 
 } 
