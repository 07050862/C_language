/*�̤j���]��*/ 
#include <stdio.h>
int main(void)
{
	int a,b,i,ans;
	printf("�п�J���Ӿ�ơG");
	scanf("%d%d",&a,&b);
	
	for(i=1;i<=a&&i<=b;i++)
	{
		if(a%i==0&&b%i==0)
		    ans = i;
	}
	printf("�̤j���]�Ƭ��G%d",ans);
	
	return 0;
}
