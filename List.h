#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef int Entry;


typedef struct node{

    Entry entry;
    struct node * next;

}Node;

typedef struct{

    Node * h;
    int size;

}ListValue;

void CreateListValue(ListValue *pl);
int ListEmptyValue(ListValue *pl);
int ListFullValue(ListValue *pl);
int ListSize(ListValue *pl);
void DestroyList(ListValue *pl);
void Append(int pos,ListValue * pl,Entry e);
void AddSorted(ListValue * pl,Entry e);
void Delete(int pos,ListValue * pl,Entry * pe);
void TraverseList(ListValue *pl, void (*pf)(Entry));


#endif // LIST_H_INCLUDED
