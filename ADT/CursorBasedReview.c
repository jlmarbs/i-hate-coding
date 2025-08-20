#include <stdio.h>
#define MAX 5

typedef struct{
    int elem;
    int link;
} nodeType;

typedef struct{
    nodeType Node[MAX];
    int avail;
} VHeap;

typedef int CLIST;

void initVHeap(VHeap *VH);
void initCList(CLIST *CL);
int allocSpace(VHeap *VH);
void deallocSpace(VHeap *VH, int ndx);
void insertFirst(CLIST *CL, VHeap *VH, int data);
void insertLast(CLIST *CL, VHeap *VH, int data);
void insertSorted(CLIST *CL, VHeap *VH, int data);
void deleteFirst(CLIST *CL, VHeap *VH);
void deleteLast(CLIST *CL, VHeap *VH);
void display(CLIST CL, VHeap VH);

int main(){
    CLIST CurList;
    VHeap Virtual;

    initVHeap(&Virtual);
    initCList(&CurList);

    insertSorted(&CurList, &Virtual, 10);
    insertSorted(&CurList, &Virtual, 20);
    insertSorted(&CurList, &Virtual, 30);
    insertSorted(&CurList, &Virtual, 40);
    insertSorted(&CurList, &Virtual, 50);
    insertSorted(&CurList, &Virtual, 60);
    display(CurList, Virtual);

    deleteFirst(&CurList, &Virtual);
    deleteFirst(&CurList, &Virtual);
    deleteFirst(&CurList, &Virtual);
    deleteFirst(&CurList, &Virtual);
    deleteFirst(&CurList, &Virtual);
    display(CurList, Virtual);

    return 0;
}

void initVHeap(VHeap *VH){
    int x;
    VH->avail = 0;

    for(x = 0; x < MAX - 1; x++){
        VH->Node[x].link = x + 1;
    }
    VH->Node[x].link = -1;
}

void initCList(CLIST *CL){
    *CL = -1;
}

int allocSpace(VHeap *VH){
    int retVal = VH->avail;

    if(retVal != -1){
        VH->avail = VH->Node[retVal].link;
    }
    return retVal;
}

void deallocSpace(VHeap *VH, int ndx){
    if(ndx >= 0 && ndx < MAX){
        VH->Node[ndx].link = VH->avail;
        VH->avail = ndx;
    }
}

void insertFirst(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);

    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = *CL;
        *CL = ndx;
    } else{
        printf("Cannot add an element.\n");
    }
}

void insertLast(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);

    if(ndx != -1){
        VH->Node[ndx].elem = data;
        VH->Node[ndx].link = -1;
        if(*CL == -1){
            *CL = ndx;
        } else{
            CLIST *trav;
            for(trav = CL; *trav != -1; trav = &(VH->Node[*trav].link)){}
            *trav = ndx;
        }
    } else{
        printf("Cannot add an element.\n");
    }
}

void insertSorted(CLIST *CL, VHeap *VH, int data){
    int ndx = allocSpace(VH);

    if(ndx != -1){
        VH->Node[ndx].elem = data;

        CLIST *trav;
        for(trav = CL; *trav != -1 && VH->Node[*trav].elem < data; trav = &(VH->Node[*trav].link)){}
        
        VH->Node[ndx].link = *trav;
        *trav = ndx;
    } else{
        printf("Cannot add an element.\n");
    }
}

void deleteFirst(CLIST *CL, VHeap *VH){
    CLIST temp;

    if(*CL != -1){
        temp = *CL;
        *CL = VH->Node[temp].link;
        deallocSpace(VH, temp);
    } else{
        printf("Cannot delete an empty list.\n");
    }
}

void deleteLast(CLIST *CL, VHeap *VH){
    CLIST temp, *trav;
    
    if(*CL != -1){
        for(trav = CL; VH->Node[*trav].link != -1; trav = &(VH->Node[*trav].link)){}
        temp = *trav;
        *trav = -1;
        deallocSpace(VH, temp);
    } else{
        printf("Cannot delete an empty list.\n");
    }
}

void display(CLIST CL, VHeap VH){
    CLIST trav;

    printf("\n");
    for(trav = CL; trav != -1; trav = VH.Node[trav].link){
        printf("%d ", VH.Node[trav].elem);
    }
    printf("\n");
}