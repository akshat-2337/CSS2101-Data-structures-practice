//insertion at end of linked list

#include <stdio.h>
#include <stdlib.h>

int main() {

    struct node {
        int data;
        struct node *next;
    };

    struct node *head, *mid, *tail;

    head = malloc(sizeof(struct node));
    mid = malloc(sizeof(struct node));
    tail = malloc(sizeof(struct node));

    head->data = 10;
    head->next = mid;

    mid->data = 20;
    mid->next = tail;

    tail->data = 30;
    tail->next = NULL;

    // Insertion at end

    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    newnode->data = 40;
    newnode->next = NULL;

    struct node *temp;

    temp = head;

    while (temp->next != NULL) { //basically this goes to the 2nd last node
        temp = temp->next;
    }

    temp->next = newnode;

    // Display linked list

    struct node *temp1;

    temp1 = head;

    while (temp1 != NULL) {
        printf("%d\n", temp1->data);
        temp1 = temp1->next;
    }

    free(newnode);
    free(tail);
    free(mid);
    free(head);

    return 0;
}