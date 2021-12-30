/* 
 * ch10-1.c
 * 指標變數 
 */
 
#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	int a=5;
	double b=3.14;
	int *p1;	//指向int的指標變數 
	double *p2;	//指向double的指標變數 
	int *p3;
   
	p1 = &a;	//取出變數a的位址 
	p2 = &b;	//取出變數b的位址 
   
	printf("  a=%8d, size=%d, address=%p\n",a,sizeof(a),&a);
	printf("  b=%8.2f, size=%d, address=%p\n",b,sizeof(b),&b);

	printf(" p1=%p, size=%d, address=%p\n",p1,sizeof(p1),&p1);
	printf(" p2=%p, size=%d, address=%p\n",p2,sizeof(p2),&p2);

	printf("*p1=%8d\n",*p1);
	printf("*p2=%8.2f\n",*p2);
	
	*p1 = 10;	//設定p1所指位址的內容(值) 
	*p2 = 6.28;	//設定p2所指位址的內容(值) 
	
	printf("  a=%8d\n",a);
	printf("  b=%8.2f\n",b);
	
	p3 = p1;	//令指標p3指向p1所指的位址 
	
	printf("*p3=%8d\n",*p3);
	
	system("pause");
	return 0;
}
