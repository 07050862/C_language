/* 
 * ch10-06.c
 * 指標陣列 
 */
 
#include <stdio.h> 
#include <stdlib.h>

void show1(char a[][10]);
void show2(char* p[]);
void show3(char* p[]);

int main(void)
{
	char a[][10] = {"Hi","Hello","Welcome"};//字串陣列(二維字元陣列) 
	char *p1[] = {"Hi","Hello","Welcome"}; 	//指標陣列(每個指標指向字串) 
	
	show1(a);
	show2(p1);
	show3(p1);
	
	system("pause");
	return 0;
}

void show1(char a[][10])
{
	int i;

	for (i=0;i<3;i++)
		puts(a[i]);
	printf("\n");
}

void show2(char* p[])
{
	int i;
	
	for (i=0;i<3;i++)
		puts(p[i]);
	printf("\n");
}

void show3(char *p[])
{
	int i;
	
	for (i=0;i<3;i++)
		puts(*(p+i));	//*(p+i)相當於p[i]，即取出第i個元素的內容 
	printf("\n");
}
