#include<stdio.h>
#include<stdlib.h>

struct node
{
int info;
struct node *next;
};
struct node *top=NULL;

void push()
{
int data;
struct node *new;
new=malloc(sizeof(struct node));
printf("Enter data : ");
scanf("%d",&data);
new->info=data;
if(top==NULL)
{
new->next=NULL;
top=new;
}
else
{
new->next=top;
top=new;
}
}

void pop()
{
struct node *temp;
if(top==NULL)
printf("UNDERFLOW");
else
{
temp=top;
printf("\nPoped element is: %d\n",temp->info);
top=top->next;
free(temp);
}
}

void peek()
{
struct node *temp;
if(top==NULL)
printf("\nSTACK UNDERFLOW\n");
else
{
printf("\nThe PEEKED element is : %d\n",top->info);
}
}

void display()
{
struct node *temp;
temp=top;
while(temp!=NULL)
{
printf("%d\n",temp->info);
temp=temp->next;
}
}

int main()
{
int choice;
while(1)
{
printf("\n----MENU----\n");
printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d",&choice);
switch(choice)
{
case 1: push();
        break;
case 2: pop();
        break;
case 3: display();
        break;
case 4: peek();
        break;
case 5: exit(1); 
default: printf("Wrong choice");
}
}
}

