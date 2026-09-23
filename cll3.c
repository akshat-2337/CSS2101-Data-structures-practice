//insertion at end with a start pointer

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

struct node*head = NULL;

struct node* createnode(int val){
    struct node * newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertend(int val){
    struct node*tmp = createnode(val);
    if(head==NULL){
        head=tmp;
        head->next=head;
    }
    else{
        struct node *ptr = head;
        while(ptr->next!=head){
            ptr=ptr->next; 
        }
        ptr->next=tmp;
        tmp->next=head;
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
        insertend(y);
    }

    printf("Final CLL : \n");
    struct node* ptr = head;
    do{
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}

int main(){
    createlist();
    return 0;
}

