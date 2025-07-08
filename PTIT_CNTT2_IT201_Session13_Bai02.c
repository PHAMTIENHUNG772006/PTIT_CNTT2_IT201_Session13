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
int main() {
    Stack s;
    initStack(&s);
    int n;
    printf("Moi nhap so luong phan tu trong Stack :");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++) {
        scanf("%s",&arr[i]);
        push(&s,arr[i]);
    }
}