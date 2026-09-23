#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertEnd(int val){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    if(head==NULL){
        newnode->next=newnode;
        head=newnode;
    }
    else{
        struct node*tmp = (struct node*)malloc(sizeof(struct node));
        tmp=head;
        while(tmp->next!=head){
            tmp=tmp->next;
        }
        newnode->next=head;
        tmp->next=newnode;
    }
}

int main(){

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    struct node *t = head;

    do
    {
        printf("%d ", t->data);
        t = t->next;
    } while(t != head);

    return 0;
}