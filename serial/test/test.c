#include "../lib/queue.h"
#include "../lib/list.h"
#include "../lib/graph.h"


int main() {
  int i;
  Queue* q = newq();
  printq(q);
  for(i=0; i<10; i++) {
    push(q, i);
  }
  printq(q);
  for(i=0; i<5; i++) {
    Node* p = pop(q);
    free(p);
  }
  printq(q);
  while(!isEmpty(q)) {
    Node* p=pop(q);
    free(p);
  }
  printq(q);
  for(i=0; i<10; i++) {
    push(q, i);
  }
  printq(q);


  List* list = newList();
  printList(list);
  for(i=0; i<10; i++) {
    push_back(list, i, i+1, i+2);
  }
  printList(list);
  for(i=0; i<5; i++) {
    Edge* p = pop_back(list);
    free(p);
  }
  printList(list);
  while(!isListEmpty(list)) {
    Edge* p=pop_back(list);
    free(p);
  }
  printList(list);
  for(i=0; i<10; i++) {
    push_back(list, i, i+2, i+4);
  }
  printList(list);
  freeList(list);
  printList(list);
  assert(isListEmpty(list));

  List* edgelist;
  long long vNum;
  long long eNum;
  edgelist = readGraph("input.txt", &vNum, &eNum);

  for(i=1; i<=vNum; i++) {
    printList(&edgelist[i]);
  }

  return 0;
}
