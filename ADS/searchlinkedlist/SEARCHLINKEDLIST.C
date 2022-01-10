
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;          
    struct node *next; 
} * head;
void createList(int n);
void displayList();
int  search(int key);
int main()
{
    int n, keyToSearch, index;
    clrscr();
    printf("Enter number of node to create: ");
    scanf("%d", &n);
    createList(n);
    printf("\nData in list: \n");
    displayList();
    printf("\nEnter element to search: ");
    scanf("%d", &keyToSearch);
    index = search(keyToSearch); 
    if (index >= 0)
        printf("%d found in the list at position %d\n", keyToSearch, index + 1);
    else
	printf("%d not found in the list.\n", keyToSearch);
    getch();
    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Unable to allocate memory. Exiting from app.");
        exit(0);
    }  
    printf("Enter data of node 1: ");
    scanf("%d", &data);
    head->data = data; 
    head->next = NULL; 
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct node)); 
        if (newNode == NULL)
        {
            printf("Unable to allocate memory. Exiting from app.");
            exit(0);
        }

        printf("Enter data of node %d: ", i);
        scanf("%d", &data);

        newNode->data = data; 
        newNode->next = NULL; 

        temp->next = newNode; 
        temp = temp->next;
    }
    
}

void displayList()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
	printf("%d ", temp->data);
        temp = temp->next;  
    }
    printf("\n");
}

int search(int key)
{
    int index;
    struct node *curNode;
    index = 0;
    curNode = head;
    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }
    return (curNode != NULL) ? index : -1;
}
