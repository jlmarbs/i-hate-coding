    #include <stdio.h>
    #include <stdlib.h>

    typedef struct node{
        int data;
        struct node *link;
    } *LIST;

    void initList(LIST *LL);
    void displayList(LIST LL);
    void insertFirst(LIST *LL, int elem);
    void insertLast(LIST *LL, int elem);
    void delete(LIST *LL, int elem);
    void deleteManyOccurences(LIST *LL, int elem);

    int main(){

        LIST myList;
        initList(&myList);

        insertFirst(&myList, 21);
        displayList(myList);

        insertLast(&myList, 9);
        displayList(myList);

        delete(&myList, 9);
        displayList(myList);

        insertFirst(&myList, 8);
        insertFirst(&myList, 3);
        insertFirst(&myList, 4);
        insertFirst(&myList, 8);
        insertLast(&myList, 3);
        insertLast(&myList, 7);
        insertLast(&myList, 20);
        displayList(myList);

        deleteManyOccurences(&myList, 3);
        displayList(myList);

        return 0;
    }

    void initList(LIST *LL){
        *LL = NULL;
    }

    void displayList(LIST LL){
        LIST trav;
        for(trav = LL; trav != NULL; trav = trav->link){
            printf("%d ", trav->data);
        }
        printf("\n\n");
    }

    void insertFirst(LIST *LL, int elem){
        LIST newNode = (LIST)malloc(sizeof(struct node));
        
        if(newNode != NULL){
            newNode->data = elem;
            newNode->link = *LL;
            *LL = newNode;
        }
    }

    void insertLast(LIST *LL, int elem){
        LIST *trav;
        for(trav = LL; *trav != NULL; trav = &(*trav)->link){}
        
        LIST newNode = (LIST)malloc(sizeof(struct node));
        if(newNode != NULL){
            newNode->data = elem;
            newNode->link = NULL;
            *trav = newNode;
        }
    }

    void delete(LIST *LL, int elem){
        LIST temp, *trav;

        for(trav = LL; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->link){}
        if(*trav != NULL){
            temp = *trav;
            *trav = temp->link;
            free(temp);
        }
    }

    void deleteManyOccurences(LIST *LL, int elem){
        LIST temp, *trav;

        for(trav = LL; *trav != NULL;){
            if((*trav)->data == elem){
                temp = *trav;
                *trav = temp->link;
                free(temp);
            } else{
                trav = &(*trav)->link;
            }
        }
    }