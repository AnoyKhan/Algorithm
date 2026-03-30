#include <stdio.h>
#define NULL -1
#define SIZE 10


int INFO[SIZE];
int LINK[SIZE];
int START, AVAIL;


void initializeList();
int getNode();
void freeNode(int);
void insertAtBeginning(int item);
void insertAtEnd(int item);
void insertAfter(int item, int after);
void deleteNode(int item);
void traverse();
int search(int item);

int main() {
    int choice, item, after, pos;
    initializeList();

    do {
        printf("\n--- LINKED LIST USING ARRAYS ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After\n");
        printf("4. Delete Node\n");
        printf("5. Display List\n");
        printf("6. Search Element\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                insertAtBeginning(item);
                traverse();
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &item);
                insertAtEnd(item);
                traverse();
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &item);
                printf("Insert %d after which element? ", item);
                scanf("%d", &after);
                insertAfter(item, after);
                traverse();
                break;

            case 4:
                printf("Enter element to delete: ");
                scanf("%d", &item);
                deleteNode(item);
                traverse();
                break;

            case 5:
                traverse();
                break;

            case 6:
                printf("Enter element to search: ");
                scanf("%d", &item);
                pos = search(item);
                if (pos != NULL)
                    printf("Element %d found at position %d.\n", item, pos);
                else
                    printf("Element %d not found in the list.\n", item);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);

    return 0;
}


void initializeList() {
    for (int i = 0; i < SIZE - 1; i++) {
        LINK[i] = i + 1;   // Link free nodes
    }
    LINK[SIZE - 1] = NULL; // End of free list
    START = NULL;
    AVAIL = 0;
    printf("List initialized.\n");
}


int getNode() {
    if (AVAIL == NULL) {
        printf("Overflow! No more free nodes.\n");
        return NULL;
    }
    int newNode = AVAIL;
    AVAIL = LINK[AVAIL];
    return newNode;
}


void freeNode(int node) {
    LINK[node] = AVAIL;
    AVAIL = node;
}


void insertAtBeginning(int item) {
    int newNode = getNode();
    if (newNode == NULL) return;
    INFO[newNode] = item;
    LINK[newNode] = START;
    START = newNode;
}


void insertAtEnd(int item) {
    int newNode = getNode();
    if (newNode == NULL) return;
    INFO[newNode] = item;
    LINK[newNode] = NULL;

    if (START == NULL)
        START = newNode;
    else {
        int ptr = START;
        while (LINK[ptr] != NULL)
            ptr = LINK[ptr];
        LINK[ptr] = newNode;
    }
}


void insertAfter(int item, int after) {
    int ptr = START;
    while (ptr != NULL && INFO[ptr] != after)
        ptr = LINK[ptr];

    if (ptr == NULL) {
        printf("Element %d not found.\n", after);
        return;
    }

    int newNode = getNode();
    if (newNode == NULL) return;
    INFO[newNode] = item;
    LINK[newNode] = LINK[ptr];
    LINK[ptr] = newNode;
}


void deleteNode(int item) {
    if (START == NULL) {
        printf("Underflow! List is empty.\n");
        return;
    }

    int ptr = START, prev = NULL;

    while (ptr != NULL && INFO[ptr] != item) {
        prev = ptr;
        ptr = LINK[ptr];
    }

    if (ptr == NULL) {
        printf("Element %d not found.\n", item);
        return;
    }

    if (ptr == START)
        START = LINK[START];
    else
        LINK[prev] = LINK[ptr];

    freeNode(ptr);
    printf("Element %d deleted successfully.\n", item);
}


void traverse() {
    if (START == NULL) {
        printf("List is empty.\n");
        return;
    }

    int ptr = START;
    printf("List: ");
    while (ptr != NULL) {
        printf("%d", INFO[ptr]);
        ptr = LINK[ptr];
        if (ptr != NULL) printf(" -> ");
    }
    printf("\n");
}


int search(int item) {
    int ptr = START, pos = 1;
    while (ptr != NULL) {
        if (INFO[ptr] == item)
            return pos;
        ptr = LINK[ptr];
        pos++;
    }
    return NULL;
}