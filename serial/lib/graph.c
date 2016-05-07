#include <string.h>
#include "graph.h"

/*****************************************************************
 * Read the graph into memory, file location specified by filename
 * @return: 
 *  An list array of size vNum containing edgelist of all vertices
 *  vNum: number of vertices in the graph
 *  eNum: number of edges in the graph
 ****************************************************************/
List* readGraph(char* graphfile, long long *vNum, long long *eNum) {
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  List* edgelist = NULL;

  fp = fopen(graphfile, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);

    printf("Tokenizing...\n");
    char* pch;
    pch = strtok (line," ");
    if(strcmp(pch, "c")==0 || strcmp(pch, "c\n")==0) { //A comment line, process next line
      continue;
    }
    else if(strcmp(pch, "p")==0) {
      pch = strtok (NULL, " ");
      if(strcmp(pch, "sp")!=0) {//If second token is not "sp", wrong input format
        printf("Wrong input format in grph file, p should be followed by sp\n");
        exit(EXIT_FAILURE);
      }
      pch = strtok (NULL, " ");
      *vNum = atoll(pch);
      pch = strtok (NULL, " ");
      *eNum = atoll(pch);

      edgelist = malloc(sizeof(List)*(*vNum+1));
    }
    else if(strcmp(pch, "a")==0) { //An edge description
      long long source;
      long long dest;
      long long weight;
      pch = strtok (NULL, " ");
      source = atoll(pch);
      if(source > *vNum) {
        printf("Source Node id is too large: %lld\n", source);
      }
      pch = strtok (NULL, " ");
      dest = atoll(pch);
      if(source > *vNum) {
        printf("Dest Node id is too large: %lld\n", dest);
      }
      pch = strtok (NULL, " ");
      weight = atoll(pch);
      push_back(&edgelist[source], source, dest, weight);
    }
    else {
      printf("Illegal line starting token %s\n", pch);
      exit(EXIT_FAILURE);
    }

  }

  fclose(fp);
  if (line)
    free(line);
  return edgelist;
}
/*****************************************
 * read specfile which specifies the sources
 * @return
 *  a long long array contains all sources
 ****************************************/
long long *readSource(char* specfile, long long *numsource) {
  
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  int i=0;
  
  long long* sourcelist = NULL;

  fp = fopen(specfile, "r");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  while ((read = getline(&line, &len, fp)) != -1) {
    printf("Retrieved line of length %zu :\n", read);
    printf("%s", line);

    printf("Tokenizing...\n");
    char* pch;
    pch = strtok (line," ");
    if(strcmp(pch, "p")==0) {
      pch = strtok (NULL, " ");
      if(strcmp(pch, "aux")!=0) {//If second token is not "aux", wrong input format
        printf("Wrong input format in grph file, p should be followed by aux\n");
        exit(EXIT_FAILURE);
      }
      pch = strtok (NULL, " ");
      if(strcmp(pch, "sp")!=0) {//If third token is not "sp", wrong input format
        printf("Wrong input format in grph file, aux should be followed by sp\n");
        exit(EXIT_FAILURE);
      }
      pch = strtok (NULL, " ");
      if(strcmp(pch, "ss")!=0) {//If fourth token is not "ss", wrong input format
        printf("Wrong input format in grph file, sp should be followed by ss\n");
        exit(EXIT_FAILURE);
      }
      pch = strtok (NULL, " ");
      *numsource=atoll(pch);
      sourcelist = malloc(sizeof(long long)*(*numsource));
      assert(sourcelist!=NULL);
    }
    else if(strcmp(pch, "s")==0) { //A comment line, process next line
      pch = strtok (NULL, " ");
      long long source = atoll(pch);
      sourcelist[i++]=source;
    }
    else {
      continue;
    }
  }
  fclose(fp);
  if (line)
    free(line);
  return sourcelist;
}


/**************************************************************************
 * @return
 *  An array of long long contains the distance from source to every vertex
 *************************************************************************/
long long *moore_dist(List* edgelist, Queue* queue, long long vNum, long long eNum, long long source) {
  if(source > vNum || source==0) {
    printf("Invalid source vertex number: %lld\n", source);
    exit(-1);
  }
  
  int i;
  long long *dist=NULL;
  long long vj;
  long long newdist;
  Node* vi_p;
  Edge* vj_p;
  dist = malloc(sizeof(long long)*(vNum+1)); //Need 1 additional as v index start from 1
  assert(dist!=NULL);
  for(i=0; i<=vNum; i++) {
    dist[i] = LLONG_MAX;
  }
  dist[source] = 0;
  assert(isEmpty(queue));
  push(queue, source);
  while( (vi_p=pop(queue)) != 0 ) {
    printf("Now pulled %lld from queue\n", vi_p->val);
    vj_p = edgelist[vi_p->val].head;
    while(vj_p) {
      vj=vj_p->dest;
      printf("  Inspecting its neighbour %lld\n", vj);
      newdist = dist[vi_p->val] + vj_p->weight;
      printf("  The weight of edge is: %lld\n", vj_p->weight);
      printf("  New dist is %lld\n", newdist);

      if(newdist < dist[vj] || dist[vj] == LLONG_MAX) {
        printf("  dist at %lld modified to %lld\n", vj, newdist);
        dist[vj] = newdist;
        push(queue, vj);
      }
      vj_p=vj_p->next;
    }
  }
  return dist;
}

void printGraph(List* edgelist, long long vNum, long long eNum) {
  int i;
  printf("The graph has %lld nodes and %lld edges\n", vNum, eNum);
  for(i=1; i<vNum; i++) {
    printf("Node %d:\n", i);
    printList(&edgelist[i]);
    printf("\n");
  }
}

void printSource(long long *sourcelist, long long sourcenum) {
  int i;
  printf("The specification contains %lld sources:\n", sourcenum);
  for(i=0; i<sourcenum; i++){
    printf("%lld\n", sourcelist[i]);
  }
}
