#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int stack[MAX], choice, top = -1, data, i;
void push()
{
if(top == MAX-1)
    printf("Stack overflow\n");
else
{
printf("Enter a value: ");
scanf("%d",&data);
top++;
stack[top] = data;
}
}

void pop()
{
if(top <= -1)
    printf("Stack Underflow");
else{
printf("The popped element is %d",stack[top]);
top--;
}
}

void peek()
{
printf("Peek element is: %d\n",stack[top]);
}

void display()
{
if(top == -1)
{
printf("Stack underflow\n");
}
else
{
printf("Elements present: \n");
for(i = top; i >= 0; i--)
{
printf("%d\n", stack[i]);
}
printf("\n");
}
}



int main()
{
int choice;
while(1)
{
printf("\n----MENU----\n");
printf("1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
printf("Enter your choice:\n");
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
