#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int num;
};

typedef struct node NODE;

int main()
{
	int cnt,i;
	NODE *p;
	scanf("%d",&cnt);
	p = (NODE *)malloc(cnt*sizeof(NODE));
	
	for (i=0;i<cnt;i++)
		scanf("%d",&(p+i)->num);
		
	for (i=0;i<cnt;i++)
		printf("%d=%d\n",i,(p+i)->num);
	
	free(p);
	
	system("PAUSE");
	return 0;
}
