#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#include <iostream>

using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;
struct vertex{
    char IDVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};
struct edge{
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};
struct graph{
     adrVertex firstVertex;
};

void createVertex_103032330131(char newVertexID, adrVertex &v);
void initGraph_103032330131(graph &G);
void addVertex_103032330131(graph &G, char newVertexID);
void buildGraph_103032330131(graph &G);



#endif // GRAF_H_INCLUDED
