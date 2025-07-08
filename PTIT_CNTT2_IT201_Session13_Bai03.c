#include <stdio.h>
#define MAX 5
typedef struct Stack {
    int data[MAX];
    int top;
}Stack;

int initStack(Stack* s) {
    s->top = -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int top(Stack*  s) {
    if (isEmpty(s)) {
        printf("Khong co phan tu trong Stack ");
        return ;
    }
    printf(" phan tu o vi tri top %d",s->data[s->top]);
    return s->data[s->top--];
}
int push(Stack* s,int value) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = value;
    }
}
int main() {
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    top(&s);
}