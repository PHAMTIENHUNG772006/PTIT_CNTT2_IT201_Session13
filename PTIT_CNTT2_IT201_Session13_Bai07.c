#include <stdio.h>
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
 void push(Stack* s,int value) {
    if (isFull(s)) {
        printf("Stack da day");
    }else {
        s->data[++s->top] = value;
    }
}

// hàm này để xoá item ở vị trí đầu Stack
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack rong");
        return  '\0';
    }
    return s->data[s->top--];
}

int isMatching(char open,char close) {
    return (open == '(' && close == ')') ||
            (open == '{' && close == '}') ||
             (open == '[' && close == ']');
}
int isValid(Stack* s ,const char* string) {
    for (int i=0;string[i] != '\0';i++ ) {
        char c = string[i];
        if (c == '(' || c == '{' || c == '[') {
            push(s,c);
        }else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s))return 0; // thiếu dấu mở trong chuỗi
            char topChar = pop(s);
            if (!isMatching(topChar,c))return 0; // dữ liệu truyền vào sai dấu
        }
    }
    return isEmpty(s);
}

int main() {
    Stack s;
    initStack(&s);
    char string[MAX];
    printf("Moi nhap bieu thuc : ");
    fgets(string,sizeof(string),stdin);
    if (isValid(&s,string)) {
        printf("True");
    }else {
        printf("False");
    }
return 0;

}