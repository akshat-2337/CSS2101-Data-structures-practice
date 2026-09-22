#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top < MAX_SIZE - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int main() {
    char str[100];
    printf("Enter infix expression : ");
    scanf("%s", str);

    char post[100];
    int k = 0;
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char ch = str[i];

        // 1. If alphanumeric operand, append to output
        if (isalnum(ch)) {
            post[k++] = ch;
        }
        // 2. Open parenthesis -> push to stack
        else if (ch == '(') {
            push('(');
        }
        // 3. Close parenthesis -> pop until '(' is found
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                post[k++] = pop();
            }
            pop(); // Remove '(' from stack without adding to post
        }
        // 4. Operator encountered
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                // Right-associative exponent operator handling
                if (ch == '^' && peek() == '^') {
                    break;
                }
                post[k++] = pop();
            }
            push(ch); // Push actual character, not precedence number
        }
    }

    // 5. Pop all remaining operators from the stack
    while (top != -1) {
        post[k++] = pop();
    }

    // 6. Null terminate the output string
    post[k] = '\0';

    printf("Final Postfix : %s\n", post);
    return 0;
}