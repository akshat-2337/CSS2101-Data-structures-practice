#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char ch){
    if(top == MAX-1){
        printf("PUSH UNSUCCESSFUL - STACK FULL\n");
    }
    else{
        stack[++top] = ch;
    }
}

char pop(){
    if(top == -1){
        return '\0';
    }
    return stack[top--];
}

int main(){
    char exp[100];
    int flag = 0;

    printf("Enter an expression to check for duplicate parentheses:\n");
    scanf("%s", exp);

    for(int i = 0; i < strlen(exp); i++){
        char ch = exp[i];

        if(ch == '('){
            push(ch);
        }
        else if(ch == ')'){
            if(top != -1 && stack[top] == '('){
                flag = 1;
                break;
            }

            while(top != -1 && stack[top] != '('){
                pop();
            }

            if(top != -1){
                pop();
            }
        }
    }

    if(flag == 1){
        printf("Duplicate parenthesis detected\n");
    }
    else{
        printf("No duplicate parenthesis\n");
    }

    return 0;
}