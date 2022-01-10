#include<stdio.h>
#include<conio.h>
int stack[100],i,j,ch,n,top=-1;
void push();
void pop();
void display();
void topele();
void main()
   {
   clrscr();
   printf("Enter the no of elements:");
   scanf("%d",&n);
   printf("\nOperations on stack");
   while(ch!=5)
    {
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.TOP ELEMENT\n5.EXIT");
    printf("\nEnter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
     case 1:{
	     push();
	     break;
	     }
     case 2:{
	    pop();
	    break;
	    }
     case 3:{
	     display();
	     break;
	     }
     case 4:{
	    topele();
	    break;
	    }
     case 5:{
	    printf("\nExiting");
	    break;
	    }
     default:printf("Invalid Choice");
     }
     };
     getch();
     }
     void push()
      {
      int val;
      if(top==n-1)
      printf("\nOverflow");
      else
      {
      printf("\nEnter the element:");
      scanf("%d",&val);
      top++;
      stack[top]=val;
      }
      }
      void pop()
      {
      if(top==-1)
      printf("\nUnderflow");
      else
      {
      int val;
      val=stack[top];
      top--;
      printf("\nElement deleted");
      }
      }
      void display()
      {
      printf("\nThe elements are:");
      for(i=top;i>=0;i--)
      {
       printf("%d\t",stack[i]);
      }
      if(top==-1)
       printf("\nStack is empty");
       }
       void topele()
       {
       int val;
       if(top==-1)
	printf("\nStack empty");
       else
       {
       val=stack[top];
       printf("\nThe topmost element is: %d",val);
       }
       }