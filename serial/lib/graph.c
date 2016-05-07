#include <string.h>
#include "graph.h"

/*****************************************************************
 * Read the graph into memory, file location specified by filename
 * @return: 
 *  An list array of size vNum containing edgelist of all vertices
 *  vNum: number of vertices in the graph
 *  eNum: number of edges in the graph
 ****************************************************************/
List* readGraph(char* filename, long long *vNum, long long *eNum) {
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  List* edgelist = NULL;

  fp = fopen(filename, "r");
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
