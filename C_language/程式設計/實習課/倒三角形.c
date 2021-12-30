/*讀入數字m，在畫面上顯示高度為m的倒三角形。*/ 
#include <stdio.h>
int main(void)
{
	int n,i,j;
	
	printf("Please enter n: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<=i-1)
			{
			    printf(" ");
		    }
			else
			{
			    printf("*");
		    }
		}
    printf("\n");
	}
	
	return 0;
}
