#include <iostream>
#include "graph.h"

using namespace std;

void createGraph(graph &G){
    G.start == NULL;
}
adrNode newElmNode(infotypeNode infoNode){
    adrNode N = new elmNode;
    N->info = infoNode;
    N->firstEdge = NULL;
    N->nextNode = NULL;
    return N;
}
adrEdge newElmEdge(infotypeEdge infoEdge){
    adrEdge E = new elmEdge;
    E->info = infoEdge;
    E->nextEdge = NULL;
    return E;
}
void addNode(graph &G, adrNode N){
    adrNode Q;
    if(G.start == NULL){
        G.start = N;
    }else{
        Q = G.start;
        while(Q->nextNode != NULL){
            Q = Q->nextNode;
        }
        Q->nextNode = N;
    }
}
adrNode findNode(graph G, infotypeNode x){
    adrNode N = G.start;
    while(N != NULL){
        if(N->info == x){
            return N;
        }else{
            return NULL;
        }
        N = N->nextNode;
    }

    //algoritma 2
    if(G.start == NULL){
        return NULL;
    }else{
        N = G.start;
        while(N->info != x && N->nextNode != NULL){
            N = N->nextNode;
        }
        if(N->info == x){
            return N;
        }else{
            return NULL;
        }
    }
}
adrEdge findEdge(graph G, infotypeEdge y){
    adrEdge E;
    adrNode N;
    if(G.start == NULL || N == NULL){
        return NULL;
    }else{
        E = N->firstEdge;
        while(E->info != y && E->nextEdge != NULL){
            E = E->nextEdge;
        }
        if(E->info == y){
            return E;
        }else{
            return NULL;
        }
    }
}
void addEdge(graph &G, adrNode N, adrEdge E){
    adrEdge Q;
    if(N == NULL){
        cout << "Node tidak ditemukan" << endl;
    }else if(N->firstEdge == NULL){
        N->firstEdge = E;
    }else{
        Q = N->firstEdge;
        while(Q->nextEdge != NULL){
            Q = Q->nextEdge;
        }
        Q->nextEdge = E;
    }
}
void connecting(graph &G, infotypeNode node1, infotypeNode node2){
    adrEdge E1, E2;
    adrNode N1, N2;
    N1 = findNode(G, node1);
    N2 = findNode(G, node2);
    if(N1 != NULL && N2 != NULL){
        E1 = newElmEdge(node1);
        addEdge(G, N1, E1);
        E2 = newElmEdge(node2);
        addEdge(G, N2, E2);
    }else{
        cout << "Node tidak ditemukan" << endl;
    }
}
void deleteFirstEdge(graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        E = N->firstEdge;
        N->firstEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteLastEdge(graph &G, adrNode N, adrEdge E){
    adrEdge Q;
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        Q = N->firstEdge;
        while(Q->nextEdge != NULL){
            Q = Q->nextEdge;
        }
        E = Q->nextEdge;
        Q->nextEdge = NULL;
    }
}
void deleteAfterEdge(graph &G, adrNode N, adrEdge E, adrEdge prec){
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        E = prec->nextEdge;
        prec->nextEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteAdge(graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){

    }
}
void disconeting(graph &G, infotypeNode node1, infotypeNode node2);
