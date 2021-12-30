/*最小公倍數*/
#include <stdio.h>
int main(void)
{
	int a,b,i;
	
	scanf("%d%d",&a,&b);
	
	for(i=1;;i++)
	{
		if(i%a==0&&i%b==0)
		    break;
	}
	printf("%d",i);
	return 0;
}
