#include "lib/queue.h" 
#include "lib/graph.h"


int main(int argc, char** argv) {
  if(argc<3) {
    printf("Usage: serial [filename (.gr)] [filename (.ss)]\n");
    exit(-1);
  }

  long long vNum, eNum;
  char* graphfile = argv[1];
  char* specfile = argv[2];

  List *edgelist, *sourcelist;
  edgelist = readGraph(graphfile, &vNum, &eNum);
  sourceList = readSource(specfile);
  

  return 0;
}
