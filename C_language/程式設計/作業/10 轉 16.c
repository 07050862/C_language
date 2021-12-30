/*10 轉 16*/
#include <stdio.h>
int main(void)
{
	int a[80],i,n,end;
	
	scanf("%d",&n);
	
	for(i=0;;i++)
	{
		a[i] = n % 16;
		if(a[i]>=10)
		   a[i] = a[i] - 10 + 'A';
		n /= 16;
		if(n==0)
		    break; 
	}
	end = i;
	for(i=end;i>=0;i--)
	{
		if(a[i]<10)
		    printf("%d",a[i]);
		else
		    printf("%c",a[i]);
	}
	
	return 0;
}
