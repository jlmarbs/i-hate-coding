#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct{
    int elem[MAX];
    int top;
} STACK;

void initStack(STACK *S);
void push(STACK *S, int data);
bool isFull(STACK S);
bool isEmpty(STACK S);
void pop(STACK *S);
int top(STACK S);
void displayStack(STACK S);

int main(){
    STACK myStack;
    initStack(&myStack);

    push(&myStack, 21);
    displayStack(myStack);

    push(&myStack, 54);
    push(&myStack, 23);
    push(&myStack, 13);
    displayStack(myStack);

    pop(&myStack);
    displayStack(myStack);

    return 0;
}

bool isFull(STACK S){
    return (S.top == MAX - 1) ? 1 : 0;
}

bool isEmpty(STACK S){
    return (S.top == -1) ? 1 : 0;
}

int top(STACK S){
    return S.elem[S.top];
}

void initStack(STACK *S){
    S->top = -1;
}

void push(STACK *S, int data){
    if(S->top != MAX - 1){
        S->top++;
        S->elem[S->top] = data;
    }
}

void pop(STACK *S){
    if(S->top != -1){
        S->top--;
    }
}

void displayStack(STACK S){
    STACK temp;
    initStack(&temp);

    while(!isEmpty(S)){
        push(&temp, top(S));
        pop(&S);
    }

    while(!isEmpty(temp)){
        printf("%d ", top(temp));
        push(&S, top(temp));
        pop(&temp);
    }
    printf("\n\n");
}

