#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* next;
    struct node* prev;
};

struct node *start = NULL;
struct node *last = NULL;

void create_dll()
{
    int i, n, data;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("The number of nodes should be positive.\n");
        return;
    }

    struct node *newnode;
    newnode = malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    start = newnode;
    printf("Enter data for first node: ");
    scanf("%d", &data);
    start->info = data;
    start->prev = NULL;
    start->next = NULL;
    last = start;

    for (i = 2; i <= n; i++)
    {
        newnode = malloc(sizeof(struct node));
        if (newnode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        printf("Enter data for next node: ");
        scanf("%d", &data);
        newnode->info = data;
        newnode->prev = last;
        newnode->next = NULL;
        last->next = newnode;
        last = newnode;
    }
}

void display()
{
    struct node *temp = start;
    printf("List is: \n");
    while (temp != NULL)
    {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_frontdll()
{
    int data;
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter data for new node: ");
    scanf("%d", &data);
    new->info = data;
    new->next = start;
    new->prev = NULL;

    if (start != NULL) {
        start->prev = new;
    }
    start = new;

    if (last == NULL) {
        last = new;
    }
}

void insert_at_enddll()
{
    int data;
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter data for new node: ");
    scanf("%d", &data);
    new->info = data;
    new->next = NULL;

    if (last == NULL) {
        new->prev = NULL;
        start = new;
        last = new;
    } else {
        new->prev = last;
        last->next = new;
        last = new;
    }
}

void insert_at_anydll()
{
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    int data, pos, i = 1;
    if (start == NULL) {
        printf("List is empty.\n");
        free(new);
        return;
    }

    printf("Enter position and data: ");
    scanf("%d%d", &pos, &data);

    if (pos < 1) {
        printf("Position must be greater than 0.\n");
        free(new);
        return;
    }

    new->info = data;
    if (pos == 1) {
        new->next = start;
        new->prev = NULL;
        if (start != NULL) {
            start->prev = new;
        }
        start = new;
        if (last == NULL) {
            last = new;
        }
        return;
    }

    struct node *temp = start;
    while (temp != NULL && i < pos - 1) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        free(new);
        return;
    }

    new->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = new;
    }
    temp->next = new;
    new->prev = temp;

    if (new->next == NULL) {
        last = new;
    }
}

void delete_at_frontdll()
{
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = start;
    start = start->next;

    if (start != NULL) {
        start->prev = NULL;
    } else {
        last = NULL;
    }

    free(temp);
}

void delete_from_end_dll()
{
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct node *temp = last;
    last = last->prev;

    if (last != NULL) {
        last->next = NULL;
    } else {
        start = NULL;
    }

    free(temp);
}

void delete_at_anydll()
{
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    int pos, i = 1;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Position must be greater than 0.\n");
        return;
    }

    struct node *temp = start;
    if (pos == 1) {
        delete_at_frontdll();
        return;
    }

    while (temp != NULL && i < pos) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp == last) {
        last = temp->prev;
    }

    free(temp);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n ---- MENU ----\n");
        printf("\n Enter 1 to create list.");
        printf("\n Enter 2 to insert at beginning.");
        printf("\n Enter 3 to insert at end.");
        printf("\n Enter 4 to insert at middle.");
        printf("\n Enter 5 to delete front.");
        printf("\n Enter 6 to delete end.");
        printf("\n Enter 7 to delete middle.");
        printf("\n Enter 8 to display.");
        printf("\n Enter 9 to exit.");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create_dll();
            break;
        case 2:
            insert_at_frontdll();
            break;
        case 3:
            insert_at_enddll();
            break;
        case 4:
            insert_at_anydll();
            break;
        case 5:
            delete_at_frontdll();
            break;
        case 6:
            delete_from_end_dll();
            break;
        case 7:
            delete_at_anydll();
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("\nWrong Choice.\n");
        }
    }

    return 0;
}

