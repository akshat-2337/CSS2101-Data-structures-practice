//searching in LL
#include<stdio.h>
#include<stdlib.h>

int main(){

    struct node{
        int data;
        struct node* next;
    };

    struct node *head, *mid, *tail;
    head = (struct node *) malloc (sizeof(struct node));
    mid = (struct node *) malloc (sizeof(struct node));
    tail = (struct node *) malloc (sizeof(struct node));

    head->data = 10;
    head->next = mid;

    mid->data=11;
    mid->next=tail;

    tail->data=12;
    tail->next=NULL;

    struct node *temp = (struct node *) malloc (sizeof(struct node));
    temp=head;

    while(temp!=NULL){
        int x = temp->data;
        if(x==12){
            printf("\n FOUND");
            break;
        }
        temp=temp->next;
    }

    free(temp);
    return 0;
}