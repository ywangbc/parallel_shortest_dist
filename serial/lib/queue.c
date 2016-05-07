#include "queue.h"
/***************************
 * Create a Queue object
 * Initialize everything to 0
 ****************************/
Queue* newq() {
  Queue* q=malloc(sizeof(Queue));
  q->head=NULL;
  q->tail=NULL;
  q->size=0;
  return q;
}

/************************************
 * Put an element at the tail of queue
 ************************************/
void push(Queue* queue, long long val) {
  if(!queue->head) {
    queue->head = malloc(sizeof(Node));
    queue->head->val = val;

    queue->head->next=NULL;
    queue->head->prev=NULL;

    queue->tail=queue->head;
  }
  else {
    Node* p = malloc(sizeof(Node));
    p->val = val;

    p->prev = queue->tail;
    p->next = NULL;

    queue->tail->next = p;
    queue->tail=p;
  }
  queue->size++;
}

/**************************************************
 * Get an element from head of queue
 * notice thsi effectively remove the head of queue
 * @return: a pointer to the head element of queue
 **************************************************/
Node* pop(Queue* queue) {
  Node* p=queue->head;
  if(!p) {
    return NULL;
  }
  queue->size--;
  queue->head = p->next;
  if(!queue->head) {
    queue->tail=NULL;
  }
  else {
    queue->head->prev=NULL;
  }
  p->next=NULL;
  return p;
}

/*************************************************
 * Print every element of queue, from head to tail
 * Separated by a single space
 *************************************************/
void printq(Queue* queue) {
  printf("The size of queue is %lld, the queue contains (from head to tail):\n", queue->size);
  Node* p = queue->head;
  while(p) {
    printf("%lld ", p->val);
    p=p->next;
  }
  printf("\n");
}

unsigned int isEmpty(Queue* queue) {
  return queue->head==NULL;
}
