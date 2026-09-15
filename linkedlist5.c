//deletion from start

#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{
        int data;
        struct node *next;
    };

    struct node *head, *mid, *tail;
    head = (struct node *)malloc(sizeof(struct node));
    mid = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = mid;
    mid->data = 20;
    mid->next = tail;
    tail->data = 30;
    tail->next = NULL;

    struct node *temp = head;
    
    printf("Linked list before deletion: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    head = head->next;

    struct node *ptr = head;
    printf("\nLinked list after deletion from start: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }


    return 0;
}