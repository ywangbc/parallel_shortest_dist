#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

struct _Edge;
struct _List;

typedef struct _Edge Edge;
typedef struct _List List;

struct _Edge {
  long long source;
  long long dest;
  long long weight;
  Edge* prev;
  Edge* next;
};

/********************
 * Doubly linked list
 *******************/
struct _List {
  Edge* head;
  Edge* tail;
  long long size;
};

List* newList();

/************************************
 * Put an element at the tail of queue
 ************************************/
void push_back(List* list, long long source, long long dest, long long weight);

/**************************************************
 * Get an element from head of queue
 * notice thsi effectively remove the head of queue
 **************************************************/
Edge* pop_back(List* queue);

/*************************************************
 * Print every element of queue, from head to tail
 * Separated by a single space
 *************************************************/
void printList(List* list);

/*****************************
 * @return
 *   true if the list is empty
 *   false otherwise
 ****************************/
unsigned int isListEmpty(List* list);

/***************************
 * Erase the entire the list
 ***************************/
void freeList(List* list);

#endif
