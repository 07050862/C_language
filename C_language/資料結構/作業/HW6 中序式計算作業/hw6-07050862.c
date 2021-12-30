/*=========================================================
	4.4節 
     堆疊的應用:運算式轉換及求值
	    中序轉後序
	    後序式求值

	  in_to_post()	中序轉後序
	  priority()	判斷運算元的優先順序
	  post_evaluate()後序式求值
	  evaluate()	一指定運算元計算
	  Push()	推入堆疊
	  Pop() 	自堆疊彈出資料

  =========================================================
*/
#include	<stdio.h>
#include	<stdlib.h>

#define MAX_OP 6
#define operator(c) ((c=='+')||(c=='-')||(c=='*')||(c=='/')||(c=='^'))?1:0
#define operands(c) ((c)>='a' && (c)<='z'||(c)>='A' && (c)<='Z'||(c)>='0' && (c)<='9')?1:0
#define MAX_ITEM 100
typedef struct tagStack
	{
		int item [MAX_ITEM];
		int top;
	}Stack;
Stack S;

char op[MAX_OP]={'(','+','-','*','/','^'};
char prio[MAX_OP]={0,1,1,2,2,3};
int numtable[10]={0,1,2,3,4,5,6,7,8,9};
int op_value[26]={10,30,6,9,8,11,12,13,7,8,22,56,77,76,
		   55,56,43,40,13,19,18,16,46,52,61,63};
int 	post_evaluate(char *,char *);
void	in_to_post(char *,char *);
void	Push(int);
void	Pop(int *);
int powermynum(int,int);
int		priority(int );
int 	power(int,int);
int evaluate(char,int,int);
int main(int argc, char *argv[])
{
    int i,T,count,j=0,m=0,ans_evaluate[80];
    char powtimes[80],infix[MAX_ITEM],ans[80][80]={0},Title[80][80]={0};
    char postfix[MAX_ITEM];

    S.top=-1;
	printf("輸入測試案例的個數T:");
	scanf("%d",&T);
	for(count=1;count<=T;count++)
	{
		
		printf("請輸入中序式, 例如 (a+b)*c-d/e :");
    scanf("%s",infix);	
	
    in_to_post(infix,postfix);
    
    for(m=0;postfix[m]!=0;m++)
			ans[count-1][m] = postfix[m];	
	for(m=0;infix[m]!=0;m++)
			Title[count-1][m] = infix[m];
	
	ans[count-1][m] = '?';
	Title[count-1][m] = '`';

	ans_evaluate[count-1] = post_evaluate(postfix,infix);
   
	}
	printf("\n-------------Sample Output-------------\n");
	for(i=0;i<T;i++)
	{
		printf("中序式=>");
		for(j=0;Title[i][j]!='`';j++)
			{
				printf("%c",Title[i][j]);
			}
			printf("\n後序式=>");
		for(j=0;ans[i][j]!='?';j++)
			{
				printf("%c",ans[i][j]);	
			}
			printf("\n上式之結果= %d\n",ans_evaluate[i],i+1);
			printf("\n");
	}
	return 0;
}
void in_to_post(char *infix,char *postfix)
{
    int i,j,element;
    char token;
    
    i=j=0;
    while((token=infix[i]) != '\0')
    {
	i=i+1;
	if(operands(token))
		postfix [j++]=token;
	else if(token == '(')
		Push(token);
	else if(token == ')')
		while (S.top >= 0)
		{
			Pop(&element);
			if(element == '(')
				break;
			postfix [j++]=element;
		}
	else if(operator(token))
	{
		while(S.top >= 0)
		{
			element=S.item[S.top];
			if(priority(token) <= priority (element))
			{
				Pop(&element);
				postfix[j++]=element;
			}
			else
				break;
		}
		Push(token);
	}
    }
    while(S.top >= 0)
    {
		Pop(& element);
		postfix[j++]=element;
    }
    postfix[j]='\0';
}

void Push(int x)
{
    if (S.top < MAX_ITEM-1)
    {
		S.top++;
		S.item[S.top]=x;
    }
}
void Pop(int *x)
{
    if (S.top >= 0)
    {
		*x=S.item[S.top];
		S.top--;
    }
}

int priority(int c)
{
    int i=0;
	for(;i < MAX_OP;i++)
		if(op[i] == c)
			return(prio [i]);
    return(-1);
}


int post_evaluate(char *postfix,char *infix)
{
    char token;
    int op1,op2,result,i=0,j=0,k=0;




	k=0;
    while((token=postfix[i]) != '\0')
    {
		
		if(operands(token))
		{
		    if('a'<=postfix[i]&&postfix[i]<='z') 
		    	Push(op_value[token-'a']);
		    else if('A'<=postfix[i]&&postfix[i]<='Z')
		    	Push(op_value[token-'A']);
		    else if('0'<=postfix[i]&&postfix[i]<='9')
		    	Push(numtable[token-'0']);
		} 
		else if(operator(token))
		{
			Pop(&op2);
			Pop(&op1);
			
			
			result=evaluate(token,op1,op2);
			Push(result);
		}
		i=i+1;
    }
    Pop (&result);
    return(result);
}

int evaluate(char optr,int op1,int op2)
{ 
    int result;

    switch(optr)
    {
    	case '^':result=powermynum(op1,op2);
		 	break;
		case '+':result=op1+op2;
		 	break;
		case '-':result=op1-op2;
		 	break;
		case '*':result=op1*op2;
			 break;
		case '/':result=op1/op2;
			break;
    }
    return(result);
}


int powermynum(int a,int b)
{
	int ans=1,i;
	ans =a;
	for(i=1;i<b;i++)
	{
		ans = ans * a;
	}
	return ans;
}
