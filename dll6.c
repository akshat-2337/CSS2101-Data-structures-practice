//deletion from end of dll

#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{
        int data;
        struct node* prev;
        struct node* next;
    };

    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *mid  = (struct node*)malloc(sizeof(struct node));
    struct node *mid2 = (struct node*)malloc(sizeof(struct node));
    struct node *mid3 = (struct node*)malloc(sizeof(struct node));
    struct node *tail = (struct node*)malloc(sizeof(struct node));

    head->data=10; head->prev=NULL; head->next=mid;
    mid->data=20;  mid->prev=head;  mid->next=mid2;
    mid2->data=23; mid2->prev=mid;  mid2->next=mid3;
    mid3->data=25; mid3->prev=mid2; mid3->next=tail;
    tail->data=30; tail->prev=mid3; tail->next=NULL;

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    printf("\n DLL before deletion : \n");
    ptr=head;
    while(ptr!=NULL){
        printf(" %d ", ptr->data);
        ptr=ptr->next;
    }

    struct node* ptr2 = (struct node*)malloc(sizeof(struct node));
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    ptr2=head;
    while(ptr2->next!=NULL){
        tmp=ptr2;
        ptr2=ptr2->next;
    }

    tmp->next=NULL;
    tail = tmp;
    free(ptr2);

    struct node* tmp2 = (struct node*)malloc(sizeof(struct node));
    tmp2=head;

    printf("\n DLL after deletion : \n");
    while(tmp2!=NULL){
        printf(" %d ", tmp2->data);
        tmp2=tmp2->next;
    }


}