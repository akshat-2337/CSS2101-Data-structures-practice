//insertion at end with a tail pointer

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node*tail = NULL;

struct node*createnode(int val){
    struct node*tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data=val;
    tmp->next=NULL;
    return tmp;
}

void insertval(int val){
    struct node *tmp = createnode(val);
    if(tail==NULL){
        tail=tmp;
        tail->next=tail;
    }
    else{
        tmp->next=tail->next;
        tail->next=tmp;
        tail=tmp;
    }
}

void createlist(){
    int x;
    printf("Enter the number of elements in CLL \n");
    scanf("%d", &x);

    printf("Enter the data for each nodes of CLL : \n");
    for(int i=0; i<x; i++){
        int y;
        scanf("%d", &y);
        insertval(y);
    }

    printf("Final CLL : \n");
    struct node* ptr = tail;
    do{
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail);
}

int main(){
    createlist();
    return 0;
}