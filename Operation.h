#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED
#include "List.h"

typedef struct listnode{

    int key;
    ListValue value;
    struct listnode * next;

}ListNode;

typedef struct{

    ListNode * head;
    int size;

}List;

void CreateList(List * pl);
int CheckKey(List *pl, int key);
void AddPairs(List *pl, int key, Entry e);
void RemovePairs(List *pl, int key, Entry *pe);
void RemoveValue(List *pl, int key, Entry e);
void ModifyValues(List *pl, int key,Entry oldValue ,Entry newValue);
void PrintAllValuesAssociated(List *pl, int key);
void PrintKey(List *pl,void(*pf)(Entry));
int ListFull(List * pl);
int ListEmpty(List * pl);


#endif // OPERATION_H_INCLUDED
