#ifndef GRAPH2_H_INCLUDED
#define GRAPH2_H_INCLUDED
#include <iostream>

using namespace std;

struct infotype{
    string id;
    string nama;
    int following;
    int followed;
};
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;
struct elmNode{
    infotype info;
    adrEdge firstEdge;
    adrNode nextNode;
};
struct elmEdge{
    string idEdge;
    adrEdge nextEdge;
};
struct Graph{
    adrNode start;
};

adrNode createNode(infotype data);
void insertNode(Graph &G, adrNode N);
adrEdge createEdge(string id);
void insertEdge(Graph &G, adrNode N, adrEdge E);
adrNode findNode(Graph G, string idAkun);
void showAkun(Graph G);
void follow(Graph &G, string idA, string idB);
void showFollowing(Graph G, string id);
void signUp(Graph &G, infotype newAkun);
void unFollow(Graph &G, string idA, string idB);
void deleteFirstNode(Graph &G, adrNode N);
void deleteAfterNode(Graph &G, adrNode prec, adrNode N);
void deleteLastNode(Graph &G, adrNode N);
void deleteNode(Graph &G, adrNode N);
void deleteFirstEdge(Graph &G, adrNode N, adrEdge E);
void deleteAfterEdge(Graph &G, adrNode N, adrEdge prec, adrEdge E);
void deleteLastEdge(Graph &G, adrNode N, adrEdge E);
void deleteEdge(Graph &G, adrNode N, adrEdge E);
adrEdge findEdge(Graph G, adrNode N, string id);
void deleteAkun(Graph &G, string idAkun);


#endif // GRAPH2_H_INCLUDED
