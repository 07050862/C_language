/* 
 * ch10-04.c
 * 指向陣列的指標 
 */
 
#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	int a[] = {11,22,33,44,55};		// a是(整數)指標常數, 常數不可變動 
	int *p1;
	int i;

	p1 = a;							// 令p1指向a所指的位址 
	
	printf("address of a[] = %p\n\n",a);
	
	for (i=0;i<5;i++)
		printf("address of a[%d] = %p\n",i,&a[i]);	// 各元素所在的位址 
	printf("\n");

	for (i=0;i<5;i++)
		printf("address of p1+%d = %p\n",i,p1+i);
	printf("\n");
	
	for (i=0;i<5;i++)
		printf("p1[%d] = %d\n",i,*(p1+i));			// 取出各位址的內容(值) 
	
	system("pause");
	return 0;
}
