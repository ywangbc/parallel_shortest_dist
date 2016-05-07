#ifndef QUEUE_H
#define QUEUE_H
#include <stdlib.h>
#include <stdio.h>

struct _Node;
struct _Queue;

typedef struct _Node Node;
typedef struct _Queue Queue;

struct _Node {
  long long val;
  Node* prev;
  Node* next;
};

/********************
 * Doubly linked list
 *******************/
struct _Queue {
  Node* head;
  Node* tail;
  long long size;
};

Queue* newq();

/************************************
 * Put an element at the tail of queue
 ************************************/
void push(Queue* queue, long long val);

/**************************************************
 * Get an element from head of queue
 * notice thsi effectively remove the head of queue
 **************************************************/
Node* pop(Queue* queue);

/*************************************************
 * Print every element of queue, from head to tail
 * Separated by a single space
 *************************************************/
long long printq(Queue* queue);

unsigned int isEmpty(Queue* queue);
#endif
