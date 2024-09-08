#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *start = NULL;

void createlist() {
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    struct node *new_node, *temp;
    new_node = malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }

    start = new_node;
    temp = start;
    
    printf("Enter data for first node: ");
    scanf("%d", &data);
    new_node->info = data;
    new_node->next = NULL;

    for (i = 2; i <= n; i++) {
        new_node = malloc(sizeof(struct node));
        if (!new_node) {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for next node: ");
        scanf("%d", &data);
        new_node->info = data;
        new_node->next = NULL;
        temp->next = new_node;
        temp = temp->next;
    }
}

void display() {
    struct node *temp = start;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List is: \n");
    while (temp != NULL) {
        printf("%d\t", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_front() {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    int data;
    printf("Enter data for new node: ");
    scanf("%d", &data);
    new_node->info = data;
    new_node->next = start;
    start = new_node;
}

void insert_at_end() {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    int data;
    printf("Enter data for new node: ");
    scanf("%d", &data);
    new_node->info = data;
    new_node->next = NULL;

    if (start == NULL) {
        start = new_node;
    } else {
        struct node *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_at_any() {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        printf("Memory allocation failed.\n");
        return;
    }
    int data, pos, i = 1;
    printf("Enter position and data: ");
    scanf("%d %d", &pos, &data);
    
    if (pos < 1) {
        printf("Invalid position.\n");
        free(new_node);
        return;
    }

    new_node->info = data;

    if (pos == 1) {
        new_node->next = start;
        start = new_node;
    } else {
        struct node *temp = start;
        while (temp != NULL && i < pos - 1) {
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
            free(new_node);
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void delete_at_front() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = start;
    start = start->next;
    free(temp);
}

void delete_at_end() {
    if (start == NULL) {
        printf("The list is empty.\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
    } else {
        struct node *temp = start;
        struct node *last = NULL;
        while (temp->next != NULL) {
            last = temp;
            temp = temp->next;
        }
        free(temp);
        last->next = NULL;
    }
}

void delete_at_any() {
    int pos, i = 1;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (start == NULL || pos < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }

    if (pos == 1) {
        struct node *temp = start;
        start = start->next;
        free(temp);
    } else {
        struct node *temp = start;
        struct node *prev = NULL;
        while (temp != NULL && i < pos) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (temp == NULL) {
            printf("Position out of bounds.\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n ---- MENU ----\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at middle\n");
        printf("5. Delete from front\n");
        printf("6. Delete from end\n");
        printf("7. Delete from middle\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createlist(); break;
            case 2: insert_at_front(); break;
            case 3: insert_at_end(); break;
            case 4: insert_at_any(); break;
            case 5: delete_at_front(); break;
            case 6: delete_at_end(); break;
            case 7: delete_at_any(); break;
            case 8: display(); break;
            case 9: return 0;
            default: printf("Wrong choice.\n");
        }
    }
}

