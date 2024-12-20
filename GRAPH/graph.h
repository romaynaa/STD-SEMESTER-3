#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>

using namespace std;

typedef char infotypeNode;
typedef char infotypeEdge;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;
struct elmNode{
    infotypeNode info;
    adrNode nextNode;
    adrEdge firstEdge;
};
struct elmEdge{
    infotypeEdge info;
    adrEdge nextEdge;
};
struct Graph{
    adrNode start;
};
void createGraph(Graph &G);
adrNode allocateNode(infotypeNode node);
adrEdge allocateEdge(infotypeEdge edge);
void addNode(Graph &G, adrNode N);
adrNode findNode(Graph G, infotypeNode node);
void addEdge(Graph &G, adrNode N, adrEdge E);
adrEdge findEdge(Graph G, adrNode N, infotypeEdge edge);
void deleteFirstEdge(Graph &G, adrNode N, adrEdge E);
void deleteAfterEdge(Graph &G, adrNode N, adrEdge prec, adrEdge E);
void deleteLastEdge(Graph &G, adrNode N, adrEdge E);
void deleteEdge(Graph &G, adrNode N, adrEdge E);
void connecting(Graph &G, char node1, char node2);
void disconecting(Graph &G, char node1, char node2);
void showTetangga(Graph G);
int hitungDegree(Graph G, char node);
void showDegree(Graph G);
int loop(Graph G);
#endif // GRAPH_H_INCLUDED
