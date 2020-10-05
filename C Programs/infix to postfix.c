#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    char data[MAX];
    int top;
} STACK;

void push(STACK* s, int val) {
    s->top++;
    s->data[s->top] = val;
}

void pop(STACK* s, int* del) {
    *del = s->data[s->top];
    s->top--;
}

int is_operator(char ch) {
    char OPERATORS[] = "+-*/^()\0";
    for (int i = 0; OPERATORS[i] != '\0'; ++i) {
        if (ch == OPERATORS[i]) {
            return 1;
        }
    }
    return 0;
}

int is_opening_brace(char op) {
    return op == '(';
}

int is_closing_brace(char op) {
    return op == ')';
}

int priority_val(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

int is_low_to_high_priority(char op1, char op2) {
    if (priority_val(op1) < priority_val(op2)) {
        return 1;
    }
    return 0;
}

void infix_to_postfix(char* infix, char* postfix) {
    int i, j;
    i = j = 0;
    STACK s;
    s.top = -1;
    int del;
    while (infix[i] != '\0') {
        if (is_operator(infix[i])) {
            if (is_opening_brace(infix[i])) {
                push(&s, infix[i]);
            } else if (is_closing_brace(infix[i])) {
                pop(&s, &del);
                while (!is_opening_brace(del)) {
                    postfix[j++] = del;
                    pop(&s, &del);
                }
            } else {
                if (s.top == -1) {
                    push(&s, infix[i]);
                } else {
                    pop(&s, &del);
                    if (is_opening_brace(del) || is_low_to_high_priority(del, infix[i])) {
                        push(&s, del);       // pushing back removed operator since stack will remain same
                        push(&s, infix[i]);  // pushing current operator in the stack
                    } else {
                        postfix[j++] = del;  // pushing deleted operator to our final answer
                        --i;                 // checking if the now previous operator complies with the current operator
                    }
                }
            }
        } else {
            postfix[j++] = infix[i];  // pushing operands to our final answer
        }
        ++i;
    }
    while (s.top != -1) {
        pop(&s, &del);
        postfix[j++] = del;
    }
}

int main(int argc, char* argv[]) {
    char infix[100], postfix[100];
    scanf("%[^\n]%*c", infix);
    infix_to_postfix(&infix, &postfix);
    printf("%s", postfix);
    return 0;
}