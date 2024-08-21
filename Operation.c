#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "Operation.h"

void PrintValues(Entry value) {
    printf("%d ", value);
}


void CreateList(List * pl){

    pl->head=NULL;
    pl->size=0;

}

int CheckKey(List *pl, int key) {
    if (pl->head == NULL || key <= 0) {
        return 0;
    } else {
        ListNode *pn = pl->head;
        while (pn) {
            if (pn->key == key) {
                return 1;
            }
            pn = pn->next;
        }
        return 0;
    }
}

void AddPairs(List *pl, int key, Entry e){
    ListNode * n = pl->head;
    ListNode * p;
    ListNode * curr=pl->head;
    while(curr && curr->key != key){
        curr=curr->next;
    }
    if(curr == NULL){
        ListNode * pn=(ListNode *)malloc(sizeof(ListNode));
        CreateListValue(&(pn->value));
        pn->key=key;
        AddSorted(&(pn->value),e);
        pn->next=NULL;
        if(!pl->head || key < pl->head->key ){

            pn->next=pl->head;
            pl->head=pn;
        }
        else{

            while(n && key > n->key){
                p=n;
                n=n->next;
            }
            p->next=pn;
            pn->next=n;

        }
            pl->size++;

    }
    else{
        Node * n = curr->value.h;
        while(n && n->entry != e){
            n=n->next;
        }
        if(n == NULL)
            AddSorted(&(curr->value),e);
        else
            return 0;
    }
}

void RemovePairs(List *pl, int key, Entry *pe) {
    ListNode *prev = NULL;
    ListNode *curr = pl->head;

    while (curr && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if(curr){
    DestroyList(&(curr->value));
    }

    if (prev) {
        prev->next = curr->next;
    } else {
        pl->head = curr->next;
    }
    free(curr);
    pl->size--;
}

void RemoveValue(List *pl, int key, Entry e) {
    ListNode *curr = pl->head;

    while (curr && curr->key != key) {
        curr = curr->next;
    }

    if (curr) {
        Node *n = curr->value.h;
        Node *prevEntry = NULL;

        while (n && n->entry != e) {
            prevEntry = n;
            n = n->next;
        }

        if (n) {
            if (prevEntry) {
                prevEntry->next = n->next;
            } else {
                curr->value.h = n->next;
            }
            free(n);
        }
    }
}



void ModifyValues(List *pl, int key,Entry oldValue ,Entry newValue){

    ListNode * pn=pl->head;
    while(pn && pn->key != key){
        pn=pn->next;
    }
    if(pn){
        Node *n = pn->value.h;
        while (n) {
            if (n->entry == oldValue) {
                n->entry = newValue;
            }
            n = n->next;
        }
    }

}

void PrintAllValuesAssociated(List *pl, int key) {
    ListNode *pn = pl->head;

    while (pn) {
        if (pn->key == key) {
            TraverseList(&(pn->value),PrintValues);
        }
        pn = pn->next;
    }

}

void PrintKey(List *pl,void(*pf)(Entry)){

    ListNode * pn= pl->head;
    while(pn){
        (*pf)(pn->key);
        pn=pn->next;
    }

}

int ListFull(List * pl){
    return 0;
}
int ListEmpty(List * pl){
    return (pl->size==0);
}
