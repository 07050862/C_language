#include <string.h>
#include <stdio.h>
#define MAXSIZE 10
typedef struct tagListNode
{
	char data[20]; //資料欄位
	int next; //鏈結欄位
} ListNode;

void ArrayListCreate(ListNode list[])
{
	int i,j;
	for(i=0;i<MAXSIZE;i++)
	list[i].next=-1;
	list[0].next=3;
	list[1].next=6;
	list[3].next=1;
	list[6].next=7;
	list[7].next=0;
	strcpy(list[1].data,"美國");
	strcpy(list[3].data,"中國");
	strcpy(list[6].data,"英國");
	strcpy(list[7].data,"蘇俄");
}
 
void ArrayListInsert(ListNode list[], int pos, const char *data)
{
	int i=0,j;
	for(i=0;i<=8;i++) //找到空位 
	{
		if(list[i].next== -1)
		break;
	}
	strcpy(list[i].data,data);//加入 義大利 
	list[pos].next =i;  //美國後面加入義大利 
	list[i].next = 6;
	
}
void ArraylistDelete(ListNode list[])
{
	int i=0;
	for(i=0;i<=8;i++)//找到list[i].next為中國 
	{
		if(list[i].next == 3)
		break;
	}
	list[i].next=1;//跳過中國 
	
}
void ArraylistDelete2(ListNode list[])
{
	int i=0;
	for(i=0;i<=8;i++)//找到list[i].next為英國 
	{
		if(list[i].next == 6)
		break;
	}
	list[i].next=7; //跳過英國 

}
void ArraylistInsert2(ListNode list[],int n1,const char *c1)
{
	int i=0,j;
	for(i=0;i<=8;i++)//找到空位 
	{
		if(list[i].next== -1)
		break;
	}
	strcpy(list[i].data,c1); //將空位設為德國 
	list[n1].next = i;//加入德國 
	list[i].next = 0;
}
void ArrayListTraverse(ListNode list[])
{
	int i;
	for(i=list[0].next;i!=0;i=list[i].next)
	{
		if(list[i].next==0)
		printf("%s",list[i].data);
		else
		printf("%s,",list[i].data);
	}
		printf("\n");
}
int main(int argc, char *argv[])
{
	ListNode table[MAXSIZE];
	ArrayListTraverse(table);
	ArrayListCreate(table);
	ArrayListTraverse(table);
	ArrayListInsert(table,1,"義大利");
	ArrayListTraverse(table); 
	ArraylistDelete(table);
	ArrayListTraverse(table);
	ArraylistInsert2(table,7,"德國");
	ArrayListTraverse(table);
	ArraylistDelete2(table);
	ArrayListTraverse(table);
	return 0;
}
