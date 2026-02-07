#include <stdio.h>
#include <stdlib.h>

/* -------- Structure Definition -------- */
struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

/* -------- Function Prototypes -------- */
void insertAtEnd(int value);
void deleteByValue(int value);
void traverseList();

/* -------- Insert at End -------- */
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/* -------- Delete a Node by Value -------- */
void deleteByValue(int value) {
    struct Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->data == value) {
        temp = head;
        head = head->next;
        free(temp);
        printf("Node deleted successfully.\n");
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found in list.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node deleted successfully.\n");
}

/* -------- Traverse the List -------- */
void traverseList() {
    struct Node *temp = head;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* -------- Main Function -------- */
int main() {
    int choice, value;

    do {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;

        case 2:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteByValue(value);
            break;

        case 3:
            traverseList();
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
