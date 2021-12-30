#include <stdio.h>
int afunc(int n);
int main()
{
	int n;
	scanf("%d",&n);
	printf("==%d",afunc(n));
} 
int afunc(int n)
{
	if(n==0)
	    return 0;
	else
	    return 1+afunc(n/10);
}
