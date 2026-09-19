//insertion at the end of DLL

#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{
        int data;
        struct node* prev;
        struct node* next;
    };

    struct node *head, *mid, *tail;
    head = (struct node*) malloc (sizeof(struct node));
    mid = (struct node*) malloc (sizeof(struct node));
    tail = (struct node*) malloc(sizeof(struct node));

    head->data=10;
    head->next=mid;
    head->prev=NULL;
    
    mid->data=20;
    mid->next=tail;
    mid->prev=head;
    
    tail->data=30;
    tail->next=NULL;
    tail->prev=mid;

    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data=40;
    newnode->next=NULL;
    newnode->prev=NULL;

    //insertion at end beginsl
    //tail ka next will point to new node;
    tail->next=newnode;
    //basically new node ka prev will point to tail
    newnode->prev=tail;
    //update tail as newnode
    tail=newnode;

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;

    while(ptr!=NULL){
        printf(" %d ", ptr->data);
        ptr=ptr->next;
    }
    free(ptr);

    return 0;
}
