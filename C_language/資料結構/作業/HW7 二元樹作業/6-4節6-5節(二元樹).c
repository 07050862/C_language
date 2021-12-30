/*=========================================================

    6.4節    二元樹的建立
    6.5節    二元樹的走訪

          *crt_bt()             二元樹建立函式
          preorder()            前序走訪函式
          inorder()             中序走訪函式
          postorder()           後序走訪函式
          visit()               拜訪節點
          visit2()              拜訪節點順便將記億體釋回
                                本例利用後序拜訪時一一將
                                子樹所占之記億體釋回,以免
                                當機

       備註:執行時一一輸入節點結構資料,不用按<ENTER>
            也不能更正資料!!!

  =========================================================
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<conio.h>

typedef struct tagTNode
        {
                struct tagTNode *left_c;
                char    data;
                struct tagTNode *right_c;
        }TNode;
  
TNode *CreateBinaryTree(void);
void visit(TNode *);
void visit2(TNode  *);
void PreOrder(TNode  *);
void InOrder(TNode  *p);
void PostOrder(TNode  *p);
int countHeight(TNode *);
int countNodes(TNode *); 
void MirrorBT(TNode *);
int main(int argc, char *argv[])
{
    TNode *tree;

    printf("輸入節點資料,不用按<ENTER>\n");
    tree=CreateBinaryTree();

 
    printf("\n中序走訪結果=> ");
    InOrder(tree);
    printf("\n二元樹節點數: %d",countNodes(tree));
    printf("\n二元樹的高度: %d",countHeight(tree));
    MirrorBT(tree);
	printf("\n二元樹鏡像對調後中序走訪結果=> ");
    InOrder(tree);
	return 0;
}

TNode *CreateBinaryTree(void)
{
    TNode  *ptr;
    char data;
    data=getche();
    if(data == '0')
        return (NULL);
    ptr=(TNode *)malloc(sizeof(TNode));
    ptr->data=data;
    ptr->left_c = CreateBinaryTree();
    ptr->right_c = CreateBinaryTree();
    return(ptr);
}

void visit(TNode  *p)
{
    printf("%c",p->data);
}

/*後序走訪時*/
void visit2(TNode  *p)
{
    printf("%c",p->data);
    free(p);
}



void InOrder(TNode  *p)
{
    if(p != NULL)
    {
        InOrder(p->left_c);
        visit(p);
        InOrder(p->right_c);
    }
}
int countHeight(TNode *p)
{
	int leftHeight,rightHeight;
	
	if(p != NULL)
	{
		leftHeight = countHeight(p->left_c);
		rightHeight= countHeight(p->right_c);
		return (leftHeight >= rightHeight? leftHeight+1 : rightHeight+1);
	}
	else
		return 0;
}
int countNodes(TNode *p)
{
	int leftNodes,rightNodes;
	
	if(p != NULL)
	{
		leftNodes = countNodes(p->left_c);
		rightNodes = countNodes(p->right_c);
		return (leftNodes + rightNodes + 1);
	}
	else
		return 0;
}
void MirrorBT(TNode *p)
{
	TNode *tmpPtr;
	
	if(p != NULL)
	{
		tmpPtr = p->right_c;
		MirrorBT(p->left_c);
		MirrorBT(p->right_c);
		p->right_c = p->left_c;
		p->left_c = tmpPtr;
		return;
	}
	else
		return ;
}
/*
void PreOrder(TNode  *p)
{
    if(p != NULL)
    {
        visit(p);
        PreOrder(p->left_c);
        PreOrder(p->right_c);
    }
}*/
/*void PostOrder(TNode  *p)
{
   if(p != NULL)
   {
        PostOrder(p->left_c);
        PostOrder(p->right_c);
        visit2(p);
   }
}*/
