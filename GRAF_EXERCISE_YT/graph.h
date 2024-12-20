#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include <iostream>

using namespace std;

//struct Kota{
//    string namaKota;
//};
//struct Jalan{
//    string namaJalan;
//};
typedef string infotypeNode;
typedef string infotypeEdge;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;
struct elmNode{
    infotypeNode info;
    adrEdge firstEdge;
    adrNode nextNode;
};
struct elmEdge{
    infotypeEdge info;
    adrEdge nextEdge;
};
struct graph{
    adrNode start;
};

void createGraph(graph &G);
adrNode newElmNode(infotypeNode infoNode);
adrEdge newElmEdge(infotypeEdge infoEdge);
void addNode(graph &G, adrNode N);
adrNode findNode(graph G, infotypeNode x);
adrEdge findEdge(graph G, infotypeEdge y);
void addEdge(graph &G, adrNode N, adrEdge E);
void connecting(graph &G, infotypeNode node1, infotypeNode node2);
void deleteFirstEdge(graph &G, adrNode N, adrEdge E);
void deleteLastEdge(graph &G, adrNode N, adrEdge E);
void deleteAfterEdge(graph &G, adrNode N, adrEdge E, adrEdge prec);
void deleteAdge(graph &G, adrNode N, adrEdge E);
void disconeting(graph &G, infotypeNode node1, infotypeNode node2);


#endif // GRAPH_H_INCLUDED
