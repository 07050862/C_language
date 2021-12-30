#include <stdio.h>
int main(void)
{
	int i=0,j=0,n=0,t=0,Times=1;
	int board[4][4] = {0};
	int Test[5]={0,0,0,0,0};
	scanf("%d",&t);
	for(Times=1;Times<=t;Times++)
	{
		printf("N = ");
		scanf("%d",&n);
		
		for(i = 0;i < n;i++)
		{	
			for(j = 0;j < n;j++)
			{
				scanf("%d",&board[i][j]); 	
			}
		}
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(board[i][j]!=board[n-i-1][n-j-1]) 
					{
						Test[Times]=-1;
					}
			}
		}
		printf("\n");
    }
    for(Times=1;Times<=t;Times++)
    {
    	if(Test[Times]==-1)
    		printf("Test #%d:Non-symmetric\n",Times);
    	else
    		printf("Test #%d:Symmetric\n",Times);
	}
	return 0;
}
