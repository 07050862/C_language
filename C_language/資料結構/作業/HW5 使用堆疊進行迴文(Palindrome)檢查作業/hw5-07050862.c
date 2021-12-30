/*
 * C Program to Identify whether the String is Palindrome or not using Stack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM	100
typedef struct tagStack
{
	char Item[MAX_ITEM];        /*資料欄位*/
	int	Top;
}Stack;
int Push(Stack *m,char X);
int IsFull(Stack *m);
int Pop(Stack *m,char *X);
int IsEmpty(Stack *m);
void PrintStack(Stack *m);
int main()
{
    int front = 0,i,half,YesNo=0,N,count,ans[MAX_ITEM];
	Stack m[MAX_ITEM];
	char test[MAX_ITEM];

	printf("輸入測試案例的個數T: ");
	scanf("%d",&N);
	for(count=1;count<=N;count++)
	{	YesNo=0;						//每次都歸零 
	
		scanf("%s",test);
		printf("\n");
		for(i=0;test[i]!=0;i++)
		{
			m->Top=i-1;					//最高項 
			Push(m,test[i]);
		}
    //	PrintStack(m);
   	 	half = (m->Top)/2;
		for(front=0;front<=half;front++)
		{
			if(m->Item[front]!=m->Item[m->Top])//比較迴文 
			{
				YesNo = -1;
				break;
			}
			Pop(m,m->Item-1);			
		}
		ans[count] = YesNo; 		//紀錄YESNO 
	}
	printf("\n----------------Sample Output-----------------\n");
	for(i=1;i<=N;i++)
	{
		if(ans[i]==-1)
			printf("\nNO\n");
		else
			printf("\nYES\n");
	}
    return 0;
}
void PrintStack( Stack *s)
{
   int i;
   if  ( IsEmpty(s) )
      return ;
   for (i=s->Top;i >= 0;i--)
      printf("%c ",s->Item[i]);
   printf("\n");
}
int Push(Stack *S,char X)
{
    if(IsFull(S))
		return(0);
    S->Top=S->Top+1;
    S->Item[S->Top]=X;
	return(1);
}
int IsFull(Stack *S)
{
    if (S->Top == (MAX_ITEM-1))
	return(1);
    else
	return(0);
}
int Pop(Stack *S,char *X)
{
    if(IsEmpty(S))
		return (0);
    *X=S->Item[S->Top];
    S->Top--;
	return(1);
}
int IsEmpty(Stack *S)
{
    if(S->Top == -1)
		return(1);
    else
		return(0);
}
