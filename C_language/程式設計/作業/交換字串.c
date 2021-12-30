/*
請輸入字串 : 0123456789
請輸入欲交換的區間 : 4 6
對調後的字串 : 0123654789

請輸入字串 : 0123456789
請輸入欲交換的區間 : 3 8
對調後的字串 : 0128765439
*/ 
#include <stdio.h>
void reverse(char a[],int x,int y,char b[]);
int main(void)
{   int x,y;
	char a[80],b[80];
	printf("請輸入字串 : ");
	scanf("%s",a);
	printf("請輸入欲交換的區間 : ");
	scanf("%d%d",&x,&y);
	reverse(a,x,y,b); 
	printf("對調後的字串 : %s\n",b);
	
	return 0;
 } 
void reverse(char a[],int x,int y,char b[])
{   
	int i,j=y,end;
	for(i=0;a[i]!=0;i++)
	;
	end = i;
	for(i=0;i<=end;i++)
	{
		if(i<x||i>y)
		    b[i]=a[i];
		else
			b[i]=a[j--];
	}
	return;
}
