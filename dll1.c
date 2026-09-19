#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{
        int data;
        struct node* next;
        struct node* prev;
    };

    struct node *head, *mid, *tail;

    head =  (struct node*)malloc(sizeof(struct node));
    mid = (struct node*)malloc(sizeof(struct node));
    tail = (struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->prev=NULL;
    head->next=mid;

    mid->data=20;
    mid->prev=head;
    mid->next=tail;

    tail->data=30;
    tail->prev=mid;
    tail->next=NULL;

    struct node* temp = (struct node*) malloc (sizeof(struct node));
    temp = head;
    while(temp!=NULL){
        printf(" %d ", temp->data);
        temp=temp->next;
    }
    free(temp);

    printf("\n");

    struct node* temp2 = (struct node *) malloc (sizeof(struct node));
    temp2 = tail;
    while(temp2!=NULL){
        printf(" %d ", temp2->data);
        temp2=temp2->prev;
    }
    free(temp2);

    return 0;
}