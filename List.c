#include <stdio.h>
#include <stdlib.h>
#include "List.h"

void CreateListValue(ListValue *pl) {
    pl->h = NULL;
    pl->size = 0;

}

int ListEmptyValue(ListValue *pl) {
    return !pl->size;
}

int ListFullValue(ListValue *pl) {
    return 0;
}

int ListSize(ListValue *pl) {
    return pl->size;
}

void DestroyList(ListValue *pl) {
    Node *q;
    while (pl->h) {
        q = pl->h->next;
        free(pl->h);
        pl->h = q;
    }
    pl->size = 0;
}
void Append(int pos,ListValue * pl,Entry e){
    Node *p,*q;
    int i;
    p=(Node *)malloc(sizeof(Node));
    p->entry=e;
    p->next=NULL;
    if(pos == 0){
        p->next=pl->h;
        pl->h=p;
    }
    else{

        for(q=pl->h,i=0;i<pos-1;i++){
            q=q->next;
        }
        p->next=q->next;
        q->next=p;

    }
    pl->size++;

}

void AddSorted(ListValue * pl,Entry e){
    Node * pn = (Node *)malloc(sizeof(Node));
    Node * n= pl->h;
    Node * curr= pl->h;
    Node * p;
    pn->entry=e;
    while(curr && curr->entry != e){
        curr = curr->next;
    }
    if(curr == NULL){
        if(!pl->h || e < pl->h->entry){

            pn->next=pl->h;
            pl->h=pn;
        }
        else{
            while(n && n->entry < e){
                p=n;
                n = n->next;
            }
            p->next=pn;
            pn->next=n;
        }

    }

}



void Delete(int pos,ListValue * pl,Entry * pe){
    Node *q,*tmp;
    int i;
    if(pos == 0){
        *pe=pl->h->entry;
        tmp=pl->h->next;
        free(pl->h);
        pl->h=tmp;
    }
    else{

        for(q=pl->h,i=0;i<pos-1;i++){
            q=q->next;
        }
        *pe=q->next->entry;
        tmp=q->next->next;
        free(q->next);
        q->next=tmp;
    }
    pl->size--;

}

void TraverseList(ListValue *pl, void (*pf)(Entry)) {
    Node *q = pl->h;
    while (q) {
        (*pf)(q->entry);
        q = q->next;
    }
}
