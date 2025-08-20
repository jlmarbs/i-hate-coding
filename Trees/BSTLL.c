#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *LC;
    struct node *RC;
} *BST;

void initTree(BST *T);
void insertMem(BST *T, int elem);
int deleteMin(BST *T);
int deleteMax(BST *T);
void deleteMem(BST *T, int elem);
void preorder(BST T);
void postorder(BST T);
void inorder(BST T);
void display(BST T);
int isMember(BST T, int elem);

int main(){
    BST test;
    initTree(&test);

    insertMem(&test, 2);
    insertMem(&test, 23);
    insertMem(&test, 0);
    insertMem(&test, 21);
    insertMem(&test, 5);

    display(test);

    deleteMem(&test, 21);
    display(test);
    printf("%d ", isMember(test, 6));

    return 0;
}

void initTree(BST *T){
    *T = NULL;
}

void insertMem(BST *T, int elem){
    BST *trav;

    for(trav = T; *trav != NULL && (*trav)->data != elem;){
        trav = ((*trav)->data > elem) ? &(*trav)->LC : &(*trav)->RC;
    }

    if(*trav == NULL){
        *trav = (BST)calloc(1, sizeof(struct node));
        (*trav)->data = elem;
    }
}

int deleteMin(BST *T){
    BST temp, *trav;
    int num;

    for(trav = T; *trav != NULL && (*trav)->LC != NULL; trav = &(*trav)->LC){}
    if(*trav != NULL){
        temp = *trav;
        num = temp->data;
        *trav = temp->RC;
        free(temp);
    }
    return num;
}

int deleteMax(BST *T){
    BST temp, *trav;
    int num;

    for(trav = T; *trav != NULL && (*trav)->RC != NULL; trav = &(*trav)->RC){}
    if(*trav != NULL){
        temp = *trav;
        num = temp->data;
        *trav = temp->LC;
        free(temp);
    }
    return num;
}

void deleteMem(BST *T, int elem){
    BST temp, *trav;
    
    for(trav = T; *trav != NULL && (*trav)->data != elem;){
        trav = ((*trav)->data > elem) ? &(*trav)->LC : &(*trav)->RC;
    }

    if(*trav != NULL){
        temp = *trav;
        if((*trav)->LC == NULL || (*trav)->RC == NULL){
            *trav = (temp->LC != NULL) ? temp->LC : temp->RC;
            free(temp);
        } else{
            temp->data = deleteMin(&temp->RC);
        }
    }
}

void preorder(BST T){
    if(T != NULL){
        printf("%d ", T->data);
        preorder(T->LC);
        preorder(T->RC);
    }
}

void postorder(BST T){
    if(T != NULL){
        postorder(T->LC);
        postorder(T->RC);
        printf("%d ", T->data);
    }
}

void inorder(BST T){
    if(T != NULL){
        inorder(T->LC);
        printf("%d ", T->data);
        inorder(T->RC);
    }
}

void display(BST T){
    printf("Preorder: ");
    preorder(T);
    printf("\n");
    printf("Postorder: ");
    postorder(T);
    printf("\n");
    printf("Inorder: ");
    inorder(T);
    printf("\n\n");
}

int isMember(BST T, int elem){
    BST trav;

    for(trav = T; trav != NULL && trav->data != elem;){
        trav = (trav->data > elem) ? trav->LC : trav->RC;
    }
    return (trav != NULL) ? 1 : 0;
}