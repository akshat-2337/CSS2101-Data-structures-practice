//insertion at the start

#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{

        int data;
        struct node* prev;
        struct node* next;

    };

    struct node *head, *mid, *tail;
    head =  (struct node*)malloc(sizeof(struct node));
    mid = (struct node*)malloc(sizeof(struct node));
    tail = (struct node*)malloc(sizeof(struct node));

    
    head->data=10;
    head->next=mid;
    head->prev=NULL;
    
    mid->data=20;
    mid->next=tail;
    mid->prev=head;
    
    tail->data=30;
    tail->next=NULL;
    tail->prev=mid;

    struct node *newnode = (struct node*) malloc (sizeof(struct node));
    newnode->data=0;
    newnode->next=NULL;
    head->prev=NULL;

    //insertion at start
    //basically head ka prev will point to new node
    head->prev=newnode;
    //newnode ka next will point to head
    newnode->next=head;
    //finally head update hoga
    head=newnode;

    //printing of dll

    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr = head;
    while(ptr!=NULL){
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }

    free(ptr);
    return 0;
}