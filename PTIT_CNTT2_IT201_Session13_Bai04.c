#include <stdio.h>
#define MAX 5
typedef struct {
    int data[MAX];
    int top;
}Stack;
void initStack(Stack* s) {
    s->top = -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int push(Stack* s ,int value) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = value;
    }
}
void printStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong");
    }
    for (int i = s->top;i >= 0;i--) {
        printf("%d -> ",s->data[i]);
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
    printf("Danh sach Stack : ");
    printStack(&s);
}