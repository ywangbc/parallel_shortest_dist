#include "list.h"
/***************************
 * Create a List object
 * Initialize everything to 0
 ****************************/
List* newList() {
  List* list=malloc(sizeof(List));
  list->head=NULL;
  list->tail=NULL;
  list->size=0;
  return list;
}

/************************************
 * Put an element at the tail of list
 ************************************/
void push_back(List* list, long long source, long long dest, long long weight) {
  if(!list->head) {
    list->head = malloc(sizeof(Edge));
    list->head->source = source;
    list->head->dest = dest;
    list->head->weight = weight;

    list->head->next=NULL;
    list->head->prev=NULL;

    list->tail=list->head;
  }
  else {
    Edge* p = malloc(sizeof(Edge));
    p->source = source;
    p->dest = dest;
    p->weight = weight;

    p->prev = list->tail;
    p->next = NULL;

    list->tail->next = p;
    list->tail=p;
  }
  list->size++;
}

/**************************************************
 * Get an element from head of list
 * notice thsi effectively remove the head of list
 * @return: a pointer to the head element of list
 **************************************************/
Edge* pop_back(List* list) {
  Edge* p=list->head;
  if(!p) {
    return NULL;
  }
  list->size--;
  list->head = p->next;
  if(!list->head) {
    list->tail=NULL;
  }
  else {
    list->head->prev=NULL;
  }
  p->next=NULL;
  return p;
}

/*************************************************
 * Print every element of list, from head to tail
 * Separated by a single space
 *************************************************/
void printList(List* list) {
  printf("The size of list is %lld, the list contains (from head to tail):\n", list->size);
  Edge* p = list->head;
  while(p) {
    printf("source: %lld, dest: %lld, weight: %lld\n", p->source, p->dest, p->weight);
    p=p->next;
  }
  printf("\n");
}

unsigned int isListEmpty(List* list) {
  return list->head==NULL;
}

/***************************
 * Erase the entire list
 ***************************/
void freeList(List* list) {
  Edge* p = list->head;
  while(p) {
    Edge* next=p->next;
    free(p);
    p=next;
  }
  list->head=NULL;
  list->tail=NULL;
  list->size=0;
}

