#ifndef GRAPH_H
#define GRAPH_H

#include "limits.h"
#include "list.h"
#include "queue.h"

/*****************************************************************
 * Read the graph into memory, file location specified by filename
 * @return: 
 *  An list array of size vNum containing edgelist of all vertices
 *  vNum: number of vertices in the graph
 *  eNum: number of edges in the graph
 ****************************************************************/
List* readGraph(char* filename, long long *vNum, long long *eNum);

void printGraph(List* edgelist, long long vNum, long long eNum);

/*****************************************
 * read file which specifies the sources
 * @return
 *  a long long array contains all sources
 ****************************************/
long long *readSource(char* specfile, long long *numsource);

void printSource(long long *sourcelist, long long sourcenum);

  
/**************************************************************************
 * @return
 *  An array of long long contains the distance from source to every vertex
 *************************************************************************/
long long *moore_dist(List* edgelist, Queue* queue, long long vNum, long long eNum, long long source);


#endif
