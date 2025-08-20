#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int elem;
    struct node *link;
} *StackLL;

void initStackLL(StackLL *LL);
void push(StackLL *LL, int data);
void pop(StackLL *LL);
void displayStackLL(StackLL LL);
int top(StackLL LL);

int main(){

    StackLL myStackLL;
    initStackLL(&myStackLL);

    push(&myStackLL, 20);
    displayStackLL(myStackLL);
    
    push(&myStackLL, 10);
    push(&myStackLL, 30);
    push(&myStackLL, 40);
    push(&myStackLL, 5);
    displayStackLL(myStackLL);

    pop(&myStackLL);
    displayStackLL(myStackLL);

    pop(&myStackLL);
    displayStackLL(myStackLL);

    pop(&myStackLL);
    pop(&myStackLL);
    pop(&myStackLL);
    displayStackLL(myStackLL);
    
    return 0;
}

void initStackLL(StackLL *LL){
    *LL = NULL;
}

void push(StackLL *LL, int data){
    StackLL temp;

    temp = (StackLL)malloc(sizeof(struct node));
    if(temp != NULL){
        temp->elem = data;
        temp->link = *LL;
        *LL = temp;
    }
}

void pop(StackLL *LL){
    StackLL temp;

    if(*LL != NULL){
        temp = *LL;
        *LL = temp->link;
        free(temp);
    }
}

int top(StackLL LL){
    return LL->elem;
}

void displayStackLL(StackLL LL){
    StackLL temp;
    initStackLL(&temp);

    while(LL != NULL){
        push(&temp, top(LL));
        pop(&LL);
    }

    while(temp != NULL){
        printf("%d ", top(temp));
        push(&LL, top(temp));
        pop(&temp);
    }
    printf("\n\n");
}