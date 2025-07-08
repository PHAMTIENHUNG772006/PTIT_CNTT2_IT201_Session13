#include <stdio.h>
#define MAX 5

typedef struct {
     int data[MAX];
     int top;
}Stack;

void initStack(Stack* s){
   s->top = -1;
}

int isFull(Stack* s){
    return s->top == MAX - 1;
}
int isEmty(Stack* s){
    return s->top == -1;
}
int push(Stack* s,int value) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = value;
    }
}
int main(){
    Stack s;
    initStack(&s);
    for (int i=1;i<=MAX;i++) {
        push(&s,i);
    }
}