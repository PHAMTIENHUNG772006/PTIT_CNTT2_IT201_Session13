#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50
typedef struct {
    int data[MAX];
    int top;
}Stack;

void initStack(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return s->top == MAX - 1;
}
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong");
        return 0;
    }
    return s->data[s->top--];
}
void push(Stack* s,int value) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = value;
    }
}
int calculatePostfix(Stack* s , char arr[]) {
    for (int i=0;i < strlen(arr);i++) {
        char c = arr[i];
        if (isdigit(c)) {
            push(s,c - '0');
        }else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int right = pop(s);
            int left = pop(s);
            int result;
            if (c == '+') {
                result = left + right;
            }
            else if (c == '-') {
                result = left - right;
            }
            else if (c == '*') {
                result = left * right;
            }
            else if (c == '/') {
                result = left / right;
            }
            push(s, result);
        }
    }
    return pop(s);
}
int main() {
    Stack s;
    initStack(&s);
    char arr[MAX];
    printf("Moi nhap chuoi bieu thuc : ");
    fgets(arr,MAX,stdin);
    int result = calculatePostfix(&s,arr);
    printf("Ket qua cua bieu thuc la %d \n",result);
    return 0;
}