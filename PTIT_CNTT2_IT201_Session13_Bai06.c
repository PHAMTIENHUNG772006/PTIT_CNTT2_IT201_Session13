#include <stdio.h>
#include <string.h>
#define MAX 50
typedef struct {
    int data[MAX];
    int top;
}Stack;
void initStack(Stack *s) {
    s->top = -1;
}
int isEmpty(Stack *s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
void push(Stack* s,int value) {
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
    for (int i = 0;i <= s->top;i++) {
        printf("%c",s->data[i]);
    }
}
int pop(Stack*  s) {
    if (isEmpty(s)) {
        printf("Khong co phan tu trong Stack ");
        return -1;
    }
    return s->data[s->top--];
}
int main() {
    Stack s;
    initStack(&s);
    char str[50];
    printf("Moi nhap chuoi kiem tra doi xung :");
    scanf("%s",str);
    for (int i = 0;str[i] != '\0';i++) {
        push(&s,str[i]);
    }
    printStack(&s);
    int len = strlen(str);
    int flag = 1;
    for (int i = 0;i < len;i++) {
        char popped = pop(&s);
        if (popped != str[i]) {
            flag = 0;
            break;
        }
    }
    if (flag == 1) {
        printf(" \n True");
    }else {
        printf(" \n False");
    }
    return 0;
}