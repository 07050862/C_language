/* 
 * ch10-08.c
 * 指標與二維陣列 
 */
 
#include <stdio.h> 
#include <stdlib.h>

void show4(char **p);
void show5(char **p);
void show6(char **p);

int main(void)
{
	char *p1[] = {"Hi","Hello","Welcome"};	// 指向(字元)指標的指標常數 
	char **pp1;								// 指向(字元)指標的指標變數 
	int i,j;
	char c; 
	
	pp1 = p1;
	show4(pp1);
	show5(pp1);
	show6(pp1);
	
	system("pause");
	return 0;
}

void show4(char **pp)
{
	int i;
	
	for (i=0;i<3;i++)
	{
		puts(*pp);	
		pp++;			//指向指標所指的下一個位址 
	}
	printf("\n");
}

void show5(char **pp)
{
	int i;
	
	for (i=0;i<3;i++)
	{
		puts(*(pp+i));	//取出pp指向位址起，向下i個位址的內容 
	}
	printf("\n");
}

void show6(char **pp)
{
	int i,j;
	char c;
	
	for (i=0;i<3;i++)
	{
		for (j=0;;j++)
		{
			c = *(*(pp+i)+j);//取出pp向下i個位址的內容(位址)，向後j個位址的內容 
			if (c!=0)
				printf("%c",c);
			else
			{
				printf("\n");
				break;
			}	
		}
	}
	printf("\n");
}
