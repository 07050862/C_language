/*
請設計一個程式，劃出座位表每排10人共有4排，請輸入座位號碼，在那個座位旁邊標上*字號(請將座位對其)。

舉例1:18->18*

舉例2:39->39*
*/
#include <stdio.h>

int main(void)
{
 int n,i,j;
 char c = c;
 c = '*' ;
 
 printf("請輸入學生座號\n");
 
 scanf("%d",&n);
 
 for(i=1;i<=40;i++)
 {	
 	if(i%10==0)
 	{
 		if(i == n)
 		printf("%.2d%-4c\n",i,c);
 		
 		else
 		printf("%d\n",i);
	}
	else if(i==n)
	{
		printf("%.2d%-4c",i,c);
	}
	else
	{	
	    printf("%-5.2d ",i);
	}
	
 }
 
 
  return 0;
} 
