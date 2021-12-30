/*最大公因數*/ 
#include <stdio.h>
int main(void)
{
	int a,b,i,ans;
	printf("請輸入兩個整數：");
	scanf("%d%d",&a,&b);
	
	for(i=1;i<=a&&i<=b;i++)
	{
		if(a%i==0&&b%i==0)
		    ans = i;
	}
	printf("最大公因數為：%d",ans);
	
	return 0;
}
