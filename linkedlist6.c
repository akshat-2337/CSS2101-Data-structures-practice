#include <stdio.h>
#include <stdlib.h>

int main() {

    struct node {
        int data;
        struct node *next;
    };

    struct node *head, *mid, *tail;

    head = (struct node*)malloc(sizeof(struct node));
    mid = (struct node*)malloc(sizeof(struct node));
    tail = (struct node*)malloc(sizeof(struct node));

    head->data = 10;
    head->next = mid;

    mid->data = 20;
    mid->next = tail;

    tail->data = 30;
    tail->next = NULL;

    struct node *temp, *temp1;

    temp = head;

    while(temp->next != NULL) {
        temp1 = temp;
        temp = temp->next;
    }

    temp1->next = NULL;
    free(temp);

    struct node *tem;
    tem = head;

    while(tem != NULL) {
        printf(" %d ", tem->data);
        tem = tem->next;
    }

    return 0;
}