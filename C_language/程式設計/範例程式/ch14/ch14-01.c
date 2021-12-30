#include <stdio.h>
#include <stdlib.h>

int main()
{
	int cnt,i,*p;
	scanf("%d",&cnt);
	p = (int *)malloc(cnt*sizeof(int));
	
	for (i=0;i<cnt;i++)
		scanf("%d",&p[i]);
		
	for (i=0;i<cnt;i++)
		printf("%d=%d\n",i,*(p+i));
	
	free(p);
	
	system("PAUSE");
	return 0;
}
