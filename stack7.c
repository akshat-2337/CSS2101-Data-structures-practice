//evaluation of postfix expression
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100
int stack[max];
int top=-1;

void push(int x ){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int main(){
    char ip[100];
    printf("Enter postfix expression \n");
    scanf("%s", &ip);

    for(int i=0; i<strlen(ip); i++){
        if(ip[i]>='0' && ip[i]<='9'){
            int x = ip[i]-'0';
            push(x);
        }
        else{
            if(ip[i]=='+'){
                int a = pop();
                int b = pop();
                push(a+b);
            }
            else if(ip[i]=='*'){
                int a = pop();
                int b = pop();
                push(a*b);
            }
            else if(ip[i]=='^'){
                int a = pop();
                int b = pop();
                push(a^b);
            }
            else if(ip[i]=='-'){
                int a = pop();
                int b = pop();
                push(b-a);
            }
            else{
                int a = pop();
                int b = pop();
                push(b/a);
            }
        }
    }

    printf("Final result of postfix expression = %d \n", pop());
    return 0;
}