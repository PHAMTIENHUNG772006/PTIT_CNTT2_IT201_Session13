#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define LEN 100
typedef struct {
    char data[MAX];
    int top;
}Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return  s->top == MAX - 1;
}
char peek(Stack *s) {
    return s->data[s->top];
}
void push(Stack* s,char c) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = c;
    }
}
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong");
        return "";
    }
    return s->data[s->top--];
}

// Hàm trả độ ưu tiên toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}


void infixToPostfix(Stack* s,char *infix, char *postfix) {
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isdigit(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(s, ch);
        } else if (ch == ')') {
            while (!isEmpty(s) && peek(s) != '(')
                postfix[j++] = pop(s);
            pop(s);
        } else if (strchr("+-*/", ch)) {
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch))
                postfix[j++] = pop(s);
            push(s, ch);
        }
    }

    while (!isEmpty(s)) {
        postfix[j++] = pop(s);
    }

    postfix[j] = '\0';
}
int main() {
    Stack s;
    initStack(&s);
    char str[100], postfix[MAX];
    printf("Moi nhap chuoi : ");
    fgets(str,100,stdin);
    str[strcspn(str,"\n")] = '\0';

    infixToPostfix(&s,str,postfix);
    printf("Bieu thuc Postfix : %s", postfix);
    return 0;
}