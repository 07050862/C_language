/*程そ计*/ 
#include <stdio.h>
int main(void)
{
	int a,b,i,ans;
	printf("叫块进俱计");
	scanf("%d%d",&a,&b);
	
	for(i=1;i<=a&&i<=b;i++)
	{
		if(a%i==0&&b%i==0)
		    ans = i;
	}
	printf("程そ计%d",ans);
	
	return 0;
}
