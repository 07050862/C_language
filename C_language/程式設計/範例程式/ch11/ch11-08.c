/* 
 * ch11-08.c
 * ¦Û­q«¬ºA 
 */
 
#include <stdio.h> 
#include <stdlib.h>

struct date_rec
{
	int year;
	int month;
	int day;
};
typedef struct date_rec DATE;

typedef enum bool
{
	false, 
	true 
} bool;

typedef char key;

void show_day(DATE d);

int main(void)
{
	DATE d1 = {2008,3,28};
	bool b1 = true;
	key k1;

	show_day(d1);
		
	printf("The answer is ");
	if (b1==true)
		printf("true");
	else
		printf("false");
	printf(".\n");

	printf("Press a key: ");
	scanf("%c",&k1);
	printf("The key you pressed is %c\n",k1);	

	system("pause");
	return 0;
}

void show_day(DATE d)
{
	printf("%d/%d/%d\n",d.year,d.month,d.day);
}
