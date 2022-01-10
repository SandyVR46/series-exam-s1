#include <stdio.h>  
#include <stdlib.h>  
void push();  
void pop();  
void display();  
struct node   
{  
int val;  
struct node *next;  
};  
struct node *head;  
  
void main ()
{
    int choice=0;
    clrscr();
    printf("               **********STACK USING SINGLY LINKLIST**********               ");
    while(choice != 4)
    {
	printf("\n\nChose one from the below options...\n");
	printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");
	printf("\n Enter your choice \n");
	scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
	    {
		push();
		break;
	    }
	    case 2:
	    {
		pop();
		break;
	    }
	    case 3:
	    {
		display();
		break;
	    }
	    case 4:
	    {
		printf("Exiting....");
		break;
	    }
	    default:
	    {
		printf("Please Enter valid choice ");
	    }
    };
}
}
void push ()
{
    int val;
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)
    {
	printf("not able to push the element");
    }
    else
    {
	printf("\nEnter the value: ");
	scanf("%d",&val);
	if(head==NULL)
	{
	    ptr->val = val;
	    ptr -> next = NULL;
	    head=ptr;
	}
	else
	{
	    ptr->val = val;
	    ptr->next = head;
	    head=ptr;

	}
	printf("\nItem pushed");

    }
}

void pop()
{
    int item;
    struct node *ptr;
    if (head == NULL)
    {
	printf("\nUnderflow");
    }
    else
    {
	item = head->val;
	ptr = head;
	head = head->next;
	free(ptr);
	printf("\nItem popped");

    }
}
void display()
{
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr == NULL)
    {
	printf("\nStack is empty\n");
    }
    else
    {
	printf("\nPrinting Stack elements \n");
	while(ptr!=NULL)
	{
	    printf("\n%d\n",ptr->val);
	    ptr = ptr->next;
	}
    }
}