#include <stdio.h>
#include <stdlib.h>

int main(){

    struct node{

        int data;
        struct node* next;
    };

    struct node *head, *mid, *mid2, *mid3, *tail;

    head = (struct node*) malloc(sizeof(struct node));
    mid = (struct node*) malloc(sizeof(struct node));
    mid2 = (struct node*) malloc(sizeof(struct node));
    mid3 = (struct node*) malloc(sizeof(struct node));
    tail = (struct node*) malloc(sizeof(struct node));

    head->data = 10;
    head->next = mid;

    mid->data = 20;
    mid->next = mid2;

    mid2->data = 30;
    mid2->next = mid3;

    mid3->data = 40;
    mid3->next = tail;

    tail->data = 50;
    tail->next = NULL;

    struct node *temp;
    temp = head;

    printf("\nList before deletion : ");

    while(temp != NULL){
        printf(" %d ", temp->data);
        temp = temp->next;
    }

    printf("\nEnter a position to delete from : ");

    int x;
    scanf("%d", &x);

    struct node *temp1;

    temp = head;

    for(int i=1; i<x; i++){
        temp1 = temp;  //basically traverse till node before 
        temp = temp->next;
    }

    temp1->next = temp->next; //point temp1 to temp ka next where temp is the target node
    free(temp);

    struct node *ptr;
    ptr = head;

    printf("\nList after deletion : ");

    while(ptr != NULL){
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }

    return 0;
}