#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *link;
    int data;
} *LIST;

void initList(LIST *L);
void insertAtBeginning(LIST *L, int elem);
void deleteAtBeginning(LIST *L);
void display(LIST L);

int main(){
    LIST yes;
    initList(&yes);

    insertAtBeginning(&yes, 10);
    insertAtBeginning(&yes, 30);
    insertAtBeginning(&yes, 20);
    insertAtBeginning(&yes, 40);
    display(yes);

    deleteAtBeginning(&yes);
    display(yes);

    return 0;
}

void initList(LIST *L){
    *L = 0;
}

void insertAtBeginning(LIST *L, int elem){
    LIST newNode = (LIST)malloc(sizeof(struct node));

    if(newNode != NULL){
        newNode->data = elem;
        newNode->link = *L;
        *L = newNode;
    }
}

void deleteAtBeginning(LIST *L){
    LIST temp;

    if(*L != NULL){
        temp = *L;
        *L = temp->link;
        free(temp);
    }
}

void display(LIST L){
    LIST trav;

    for(trav = L; trav != NULL; trav = trav->link){
        printf("%d ", trav->data);
    }
    printf("\n");
}