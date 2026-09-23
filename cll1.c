#include <stdio.h>
#include <stdlib.h>

// Definition of the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the Circular Linked List
struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    // If the list is empty, point the new node to itself
    if (head == NULL) {
        head = newNode;
        head->next = head;
        return head;
    }

    // Traverse to the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Connect the last node to the new node and new node to head
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// Function to display the Circular Linked List
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    // Using do-while loop because the tail points back to head
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head: %d)\n", head->data);
}

int main() {
    struct Node* head = NULL;

    // Creating a circular linked list with 4 elements
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    // Display the list
    display(head);

    return 0;
}