/* 
 * ch10-02.c
 * 函數傳遞指標 
 */
 
#include <stdio.h> 
#include <stdlib.h>

void swap1(int a1,int a2);
void swap2(int *p1,int *p2);	//傳遞(整數)指標變數 

int main(void)
{
	int a=1, b=2;
	int *p1 = &a, *p2 = &b;

	printf("*p1=%d, *p2=%d\n",*p1,*p2);
	
	swap1(a,b);
	printf("a=%d, b=%d\n",a,b);
	
	swap2(&a,&b);				//傳入變數a和變數b的位址 
	printf("a=%d, b=%d\n",a,b);
	
	system("pause");
	return 0;
}

void swap1(int a1,int a2)
{
	int tmp;
	tmp = a1;
	a1 = a2;
	a2 = tmp;
}

void swap2(int *p1,int *p2)
{
	int tmp;
	tmp = *p1;					//令p1所指的內容存放於變數tmp中 
	*p1 = *p2;
	*p2 = tmp;
}
