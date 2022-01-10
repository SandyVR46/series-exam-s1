#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct TreeNode
{
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
};
typedef struct TreeNode TreeNode;
TreeNode *getnode();
main()
{
    int a[100],i,n,item;
    TreeNode *root;
    root=NULL;
    clrscr();
    printf("\nEnter the number of elements to be inserted : ");
      scanf("%d",&n);
    printf("\nEnter the elements : ");
    for(i=0;i<n;i++)
      scanf("%d",&a[i]);
    for(i=0;i<n;i++)
    TreeInsert(&root,a[i]);
    printf("\nBinary tree\n");
    TreeDisplay(root,1);
    getch();
}
TreeInsert(TreeNode **rt, int item)
{
    TreeNode *current=(*rt),*temp;
    if((*rt)==NULL)
    {
	(*rt)=getnode();
	(*rt)->data=item;
	(*rt)->lchild=NULL;
	(*rt)->rchild=NULL;
	return;

    }
    while(current!=NULL)
    {
	if(item<current->data)
	{
	    if(current->lchild!=NULL)
	      current=current->lchild;
	    else
            {
                temp=getnode();
                current->lchild=temp;
                temp->data=item;
                temp->rchild=NULL;
                temp->lchild=NULL;
                return;
            }
        }
    else
    {
        if(item>current->data)
        {
           if(current->rchild!=NULL)
           current=current->rchild;
        else
        {
            temp=getnode();
            current->rchild=temp;
            temp->data=item;
            temp->rchild=NULL;
            temp->lchild=NULL;
            return;
        }
    }
    else
    {
        printf("wrong data");
        exit(0);
    }
    }
    }
}
TreeDisplay(TreeNode * rt,int level)
{
    int i;
    if((rt)!=NULL)
    {
        TreeDisplay((rt)->rchild,level+1);
        printf("\n");
        for(i=0;i<level;i++)
        printf("  ");
        printf("%d",(rt)->data);
        TreeDisplay((rt)->lchild,level+1);
        
    }
}

TreeNode *getnode()
{
    TreeNode *t;
    t=(TreeNode *)malloc(sizeof(TreeNode));
    return t;
}