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
NODE* insert_node(NODE *h,int n);

int main()
{
	NODE *head,*target;
	int n = 9, ask;
	
	head = create_list(n);
	print_node(head);
			
	printf("(INSERT)Enter a number: ");
	scanf("%d",&ask);	
	head = insert_node(head,ask);
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

NODE* find_node(NODE *h,int n)
{
	while (h!=NULL)
	{
		if (h->data == n)
			return h;
		else
			h = h->next;
	}
	return h;
}

// 依數字大小順序插入一個node	
NODE* insert_node(NODE *h,int n)
{
	NODE *t = h;
	
	if (h==NULL)
		return h;
	
	if (n < h->data)
	{
		h = new_node(n,h);
		return h;
	}
		
	while (t->next!=NULL && t->next->data < n)
		t = t->next;
	t->next = new_node(n,t->next);
	return h;
}
