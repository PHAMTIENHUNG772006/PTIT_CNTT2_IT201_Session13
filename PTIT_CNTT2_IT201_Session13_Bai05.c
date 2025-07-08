#include <stdio.h>
#define MAX 5
typedef struct {
    int data[MAX];
    int top;
}Stack;

int initStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int push(Stack* s,int value) {
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
int pop(Stack*  s) {
    if (isEmpty(s)) {
        printf("Khong co phan tu trong Stack ");
        return -1;
    }
    return s->data[s->top--];
}
Stack reverse(Stack *s) {
    Stack temp;
    initStack(&temp);
    while (!isEmpty(s)) {
        push(&temp,pop(s));
    }
    return temp;
}
int main() {
    Stack s;
    initStack(&s);
    int n;
    printf("Moi nhap so luong phan tu trong Stack :");
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        int x;
        scanf("%d",&x);
        push(&s,x);

    }
    printStack(&s);
    Stack reversed = reverse(&s);
    printf(" \n Chuoi sau khi dao nguoc : \n");
    printStack(&reversed);

}