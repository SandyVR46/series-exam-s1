#include<stdio.h>
#include<conio.h>
#define max 10
void enqueue(int );
void dequeue();
void display();
int cq[max];
int front = -1, rear = -1;
void main()
{
 int ele,ch;
 clrscr();
 while(1){
 printf("\n MENU\n");
 printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d",&ch);
 switch(ch)
{
case 1: printf("\nEnter the element to be insert: ");
scanf("%d",&ele);
enqueue(ele);
break;
case 2: dequeue();
break;
case 3: display();
break;
case 4: exit(0);
default: printf("\n INVALID CHOICE..\n");
 }
 }
getch();
}
void enqueue(int ele)
{
 if((front == 0 && rear == max - 1) || (front == rear+1))
 printf("\nCircular Queue is Full...\n");
 else{
 if(rear == max-1 && front != 0)
 rear = -1;
 cq[++rear] = ele;
 printf("\nElement %d inserted at %d position \n",ele,rear);
 if(front == -1)
 front = 0;
}
}
void dequeue()
{
 if(front == -1 && rear == -1)
 printf("\nCircular Queue is Empty....\n");
 else
{
 printf("\nElement %d is deleted\n",cq[front++]);
 if(front == max)
	front = 0;
 if(front-1 == rear)
	front = rear = -1;
 }
}
void display()
{
 if(front == -1)
 printf("\nCircular Queue is Empty...\n");
 else
{
 int i = front;
 printf("\nCircular Queue elements are : \n");
 if(front <= rear){
 while(i <= rear)
 printf("%d\t",cq[i++]);
}
 else
{
while(i <= max - 1)
printf("%d\t", cq[i++]);
i = 0;
while(i <= rear)
printf("%d\t",cq[i++]);
}
}
}