/*遞迴印星星*/
#include <stdio.h>
void afunc(int n);
void bfunc(int n);
int main(void) 
{ 
    int n;	
	scanf("%d",&n);	
	afunc(n);	    
    return 0; 
}
void afunc(int n)
{
	if(n==1)
	    bfunc(n);
	else
	{
	    bfunc(n);
		printf("\n");
		afunc(n-1);    	
	}
}
void bfunc(int n)
{
	if(n==1)
	    printf("*");
	else
	{
		printf("*");
		bfunc(n-1);
	}
}
