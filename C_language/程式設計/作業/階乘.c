#include <stdio.h>
int main(void)
{
    int n,i,ans=1;
	
	printf("請輸入N值:");
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
	    ans = ans * i;
	}    
	printf("%d!=%d",n,ans);
    
    return 0;
} 
