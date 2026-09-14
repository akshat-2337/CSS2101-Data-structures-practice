//insertion at start


#include <stdio.h>
#include <stdlib.h>

int main(){

    struct node{
        int data;
        struct node *next;
    };

    struct node *head, *mid, *tail;

    head = (struct node *)malloc(sizeof(struct node));
    mid = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));
    
    head->data = 1;
    head->next = mid;

    mid->data = 2;
    mid->next = tail;

    tail->data = 3;
    tail->next = NULL;

    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = 7;

    newnode->next = head;
    head = newnode;

    struct node *temp = head;
    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    free(head);
    free(mid);
    free(tail);
    free(newnode);
    free(temp);

    return 0;
}