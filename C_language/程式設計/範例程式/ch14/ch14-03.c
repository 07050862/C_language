#include <stdlib.h>
#include <stdio.h>

void print_node(int *p);
void del_node(int *p,int n);
void add_node(int *p,int idx,int n);
int find_node(int *p,int n);

int main()
{
	int a[10] = {11,22,33,44,55,0}; /* use 0 to indicate end of array */
	int ask,idx,found;
	
	print_node(a);
	
	printf("(DELETE)Enter a index: ");
	scanf("%d",&ask);
	del_node(a,ask);
	print_node(a);

	printf("(ADD)Enter a index and a number: ");
	scanf("%d %d",&idx,&ask);	
	add_node(a,idx,ask);
	print_node(a);
	
	printf("(FIND)Enter a number: ");
	scanf("%d",&ask);
	if ((found=find_node(a,ask))>=0)
		printf("%d is FOUND at index %d\n",ask,found);
	else
		printf("%d is NOT FOUND\n",ask);
	
	system("PAUSE");
	return 0;
}

void del_node(int *p,int idx)
{
	int i;
	for (i=idx;p[i]!=0;i++)
		p[i] = p[i+1];	
}

void add_node(int *p,int idx,int n)
{
	int i,end;
	
	for (end=0;p[end]!=0;end++);
	for (i=end;i>=idx;i--)
		p[i+1] = p[i];
	p[idx] = n;
}

int find_node(int *p,int n)
{
	int i;
	for (i=0;p[i]!=0;i++)
	{
		if (p[i]==n)
			return i;
	}
	return -1;
}

void print_node(int *p)
{
	int i;
	for (i=0;p[i]!=0;i++)
		printf("[%d]%d ",i,p[i]);
	printf("\n");
	
}
