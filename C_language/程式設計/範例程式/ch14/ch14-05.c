#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node* next;
};
typedef struct node NODE;

NODE* new_node(int n,NODE* p);
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

NODE* new_node(int n,NODE* p)
{
	NODE *t;
	t = (NODE *)malloc(sizeof(NODE));
	t->data = n;
	t->next = p;
	return t;
}

NODE* create_list(int n)
{
	int i,ask;
	NODE *head,*p,*tail;
	
	if (n==0)
		return NULL;

	tail = new_node(11,NULL);
	head = tail;
	
	for (i=2;i<=n;i++)
	{
		p = new_node(i*11,NULL);
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
