#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
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
    char ip[100];
    printf("Enter Infix expression: ");
    scanf("%s", ip);

    // STEP 1: Reverse input string & swap brackets
    char rev[100];
    int k = 0;
    int len = strlen(ip);

    for (int i = len - 1; i >= 0; i--) { // Fixed: i-- instead of i++
        char ch = ip[i];
        if (ch == '(') rev[k++] = ')';
        else if (ch == ')') rev[k++] = '(';
        else rev[k++] = ch;
    }
    rev[k] = '\0'; // Null-terminate string

    // STEP 2: Convert reversed string to modified postfix
    char res[100];
    int z = 0;
    int revLen = strlen(rev);

    for (int i = 0; i < revLen; i++) {
        char ch = rev[i];

        // If operand, directly output
        if (isalnum(ch)) {
            res[z++] = ch; // Fixed: append character, not pop()
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                res[z++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        else if (isOperator(ch)) {
            while (top != -1 && (
                   (ch == '^' && precedence(peek()) >= precedence(ch)) ||
                   (ch != '^' && precedence(peek()) > precedence(ch))
            )) {
                res[z++] = pop();
            }
            push(ch);
        }
    }

    // Pop remaining operators
    while (top != -1) {
        res[z++] = pop();
    }
    res[z] = '\0';

    // STEP 3: Reverse postfix output to get final prefix
    char prefix[100];
    int p = 0;
    int resLen = strlen(res);

    for (int i = resLen - 1; i >= 0; i--) { // Fixed: reverse 'res', not 'ip'
        prefix[p++] = res[i];
    }
    prefix[p] = '\0';

    printf("Prefix Expression: %s\n", prefix);
    return 0;
    
}