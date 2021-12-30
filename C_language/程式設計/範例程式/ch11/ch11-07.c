/* 
 * ch11-07.c
 * 羭篈 
 */
 
#include <stdio.h> 
#include <stdlib.h>

enum color
{
	green,	//讽盽计 0 
	yellow,	//讽盽计 1 
	red		//讽盽计 2 
};

enum model
{
	first,		//讽盽计 0 
	five = 5,	//讽盽计 5 
	six,		//讽盽计 6 
	ten = 10	//讽盽计 10 
};

void show_color(enum color c);
void show_model(enum model m);

int main(void)
{

	enum color light = green;
	enum model car = six;
	
	printf("sizeof(light)=%d\n",sizeof(light));

	if (light == green)
		printf("Go!\n");
	else if (light == yellow)
		printf("Causion!\n");
	else if (light == red)
		printf("Stop!\n");
	
	show_color(light);
	
	show_model(car);
	
	system("pause");
	return 0;
}

void show_color(enum color c)
{
	printf("The color of the light is %d\n",c);
}

void show_model(enum model m)
{
	printf("The model of the car is %d\n",m);
}
