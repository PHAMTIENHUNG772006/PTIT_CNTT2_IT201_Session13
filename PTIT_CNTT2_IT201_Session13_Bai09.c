#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define LEN 100
typedef struct {
    char data[MAX][LEN];
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
void push(Stack* s,char* c) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        strcpy(s->data[++s->top],c);
    }
}
char* pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong");
        return "";
    }
    return s->data[s->top--];
}
char* postfixInFix(Stack* s,char* postfix) {
    for (int i=0;postfix[i] != '\0';i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            char temp[2] = {c,'\0'};
            push(s,temp);
        }else if (c == '+' || c == '-' || c == '*' || c == '/') {
            char* element1 = pop(s);
            char* element2 = pop(s);
            char expr[LEN*2];
            snprintf(expr,sizeof(expr),"(%s%c%s)",element2,c,element1);
            push(s,expr);
        }
    }
    return pop(s);
}
int main() {
    Stack s;
    initStack(&s);
    char str[100];
    printf("Moi nhap chuoi : ");
    fgets(str,100,stdin);
    str[strcspn(str,"\n")] = '\0';

    char* result = postfixInFix(&s,str);
    printf("%s \n " ,result);
}