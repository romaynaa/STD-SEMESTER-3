#include <iostream>
#include "graf.h"
using namespace std;

void createVertex_103032330131(char newVertexID, adrVertex &v){
    v = new vertex;
    v->IDVertex = newVertexID;
    v->nextVertex = NULL;
}
void initGraph_103032330131(graph &G){
    G.firstVertex = NULL;
}
void addVertex_103032330131(graph &G, char newVertexID){
    adrVertex v;
    createVertex_103032330131(newVertexID, v);
    if(G.firstVertex == NULL){
        G.firstVertex = v;
    }else{
//        v->nextVertex = G.firstVertex;
//        G.firstVertex = v;
        adrVertex Q;
        Q = G.firstVertex;
        while(Q->nextVertex != NULL){
            Q = Q->nextVertex;
    }
    Q->nextVertex = v;
    }
}
void buildGraph_103032330131(graph &G){
    initGraph_103032330131(G);
    char IDv;

    cout << "Masukkan ID Vertex (ID berupa huruf 'A'-'Z'): " << endl;
    while(true){
    cin >> IDv;
    if(IDv >= 'A' && IDv <= 'Z'){
        bool status = false;
        adrVertex v;
        v = G.firstVertex;
        while(v != NULL){
            if(v->IDVertex == IDv){
                status = true;
            }
            v = v->nextVertex;
        }
        if(!status){
            addVertex_103032330131(G, IDv);
        }else{
            cout << IDv <<" sudah ada. Masukkan ID lain!" << endl;
        }

        }else{
            cout << "ID vertex bukan huruf. Proses selesai" << endl;
            break;
        }
    }
}

