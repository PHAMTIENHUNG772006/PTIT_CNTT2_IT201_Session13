//
// Created by ACER on 08/07/2025.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
typedef struct {
    Node* top;
}Stack;

void initStack(Stack* s) {
    s->top = NULL;
}
int push(Stack* s,int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}
void printStack(Stack* s) {
    Node* curremt = s->top;
    while (curremt != NULL) {
        printf("%d -> ",curremt->data);
        curremt = curremt->next;
    }
    printf("NULL \n");
}
int main() {
    Stack s;
    initStack(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    printStack(&s);
}