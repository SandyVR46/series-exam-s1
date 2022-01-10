#include<stdio.h>
#include<conio.h>
#define maxsize 25
void insert();
void delete();
void display();
void fele();
void rele();
int front=-1,rear=-1;
int q[maxsize];
void main()
{
  int ch,n;
  clrscr();
  printf("\n          ********************QUEUE AS AN ARRAY********************");
  printf("\nOperations on queue:");
  while(ch!=6)
  {
   printf("\n\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.FRONT ELEMENT\n5.REAR ELEMENT\n6.EXIT");
   printf("\nEnter the choice: ");
   scanf("%d",&ch);
   switch(ch)
    {
    case 1:{
	    insert();
	    break;
	    }
    case 2:{
	    delete();
	    break;
	    }
    case 3:{
	    display();
	    break;
	    }
    case 4:{
	    fele();
	    break;
	    }
    case 5:{
	    rele();
	    break;
	    }
    case 6:{
	   printf("\nExiting");
	   break;
	   }
    default:printf("\nInvalid choice");
    }
    };
    getch();
    }
    void insert()
    {
     int item;
     printf("\n\Enter the element: ");
     scanf("%d",&item);
     if(rear==maxsize-1)
      {
      printf("\nOverflow");
      return;
      }
     if(front==-1 && rear==-1)
     {
     front=0;
     rear=0;
     }
     else
       rear++;
     q[rear]=item;
     printf("\nElement inserted");
     }
     void delete()
     {
      int item;
      if(front==-1 || front>rear)
      {
      printf("\nUnderflow");
      return;
      }
      else
      {
      item=q[front];
      if(front==rear)
      {
      front=-1;
      rear=-1;
      }
      else
       front++;
       }
      printf("\nElement deleted");
      }
      void display()
      {
       int i;
       if(rear==-1)
	printf("\nEmpty queue");
       else
	{
	 printf("\nThe elements are: ");
	 for(i=front;i<=rear;i++)
	 {
	  printf("\t%d\t",q[i]);
	  }
	 }
	 }
	void fele()
	{
	int item;
	if(front==-1)
	 printf("\nEmpty queue");
	else
	{
	item=q[front];
	printf("\nThe front element is %d ",item);
	}
	}
	void rele()
	{
	int item;
	if(rear==-1)
	printf("\nEmpty queue");
	else
	{
	item=q[rear];
	printf("\nThe rear element is %d",item);
	}
	}