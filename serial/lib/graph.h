#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"

/*****************************************************************
 * Read the graph into memory, file location specified by filename
 * @return: 
 *  An list array of size vNum containing edgelist of all vertices
 *  vNum: number of vertices in the graph
 *  eNum: number of edges in the graph
 ****************************************************************/
List* readGraph(char* filename, long long *vNum, long long *eNum);

#endif
