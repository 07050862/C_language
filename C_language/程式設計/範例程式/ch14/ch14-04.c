#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

NODE* create_list(int n);
void print_node(NODE* h);
void free_list(NODE *h);

int main()
{
	NODE *head,*target;
	int ask;	
	
	printf("(CREATE)Enter node numbers: ");
	scanf("%d",&ask);
	head = create_list(ask);
	print_node(head);
	free_list(head);
	
	system("PAUSE");
	return 0;
}

NODE* create_list(int n)
{
	int i,ask;
	NODE *head,*p,*tail;
	
	if (n==0)
		return NULL;

	printf("Enter %d numbers: ",n);	
	
	// 第一個 node 
	scanf("%d",&ask);
	tail = (NODE *)malloc(sizeof(NODE));
	tail->data = ask;
	tail->next = NULL;
	head = tail;
	
	// 後續 n-1 個  
	for (i=1;i<n;i++)
	{
		scanf("%d",&ask);
		p = (NODE *)malloc(sizeof(NODE));
		p->data = ask;
		p->next = NULL;	
		tail->next = p;
		tail = p;
	}
	return head;
}

void print_node(NODE* h)
{
	while (h!=NULL)
	{
		printf("%d->",h->data);
		h = h->next;
	}
	printf("NULL\n");
}

void free_list(NODE* h)
{
	NODE *p;
	while (h!=NULL)
	{
		p = h->next;
		free(h);
		h = p;
	}
}
