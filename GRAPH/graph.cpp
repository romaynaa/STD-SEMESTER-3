#include <iostream>
#include "graph.h"

using namespace std;

void createGraph(Graph &G){
    G.start == NULL;
}
adrNode allocateNode(infotypeNode node){
    adrNode N = new elmNode;
    N->info = node;
    N->firstEdge = NULL;
    N->nextNode = NULL;
    return N;
}
adrEdge allocateEdge(infotypeEdge edge){
    adrEdge E = new elmEdge;
    E->info = edge;
    E->nextEdge = NULL;
    return E;
}
void addNode(Graph &G, adrNode N){
    if(G.start == NULL){
        G.start = N;
    }else{
        adrNode Q = G.start;
        while(Q->nextNode != NULL){
            Q = Q->nextNode;
        }
        Q->nextNode = N;
    }
}
adrNode findNode(Graph G, infotypeNode node){
   if(G.start == NULL){
    return NULL;
   }else{
        adrNode N = G.start;
        while(N->nextNode != NULL && N->info != node){
            N = N->nextNode;
        }
        if(N->info == node){
            return N;
        }else{
            return NULL;
        }
   }

}
void addEdge(Graph &G, adrNode N, adrEdge E){
   N = G.start;
   if(N == NULL){
        cout << "Node tidak ditemukan" << endl;
   }else if(N->firstEdge == NULL){
        N->firstEdge = E;
   }else{
        adrEdge Q = N->firstEdge;
        while(Q->nextEdge != NULL){
            Q = Q->nextEdge;
        }
        Q->nextEdge = E;
   }
}
adrEdge findEdge(Graph G, adrNode N, infotypeEdge edge){
    if(G.start == NULL){
        return NULL;
    }else{
        adrEdge Q = N->firstEdge;
        while(Q->nextEdge != NULL && Q->info != edge){
            Q = Q->nextEdge;
        }
        if(Q->info == edge){
            return Q;
        }else{
            return NULL;
        }
    }
}
void deleteFirstEdge(Graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        E = N->firstEdge;
        N->firstEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteAfterEdge(Graph &G, adrNode N, adrEdge prec, adrEdge E){
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        E = prec->nextEdge;
        prec->nextEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteLastEdge(Graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "EMPTY" << endl;
    }else{
        adrEdge Q = N->firstEdge;
        while(Q->nextEdge != NULL){
            Q = Q->nextEdge;
        }
        E = Q->nextEdge;
        Q->nextEdge = NULL;
    }
}
void deleteEdge(Graph &G, adrNode N, adrEdge E){
    adrEdge p, prec;
    if(E == N->firstEdge){
        deleteFirstEdge(G, N, E);
    }else if(E->nextEdge == NULL){
        deleteLastEdge(G, N, E);
    }else{
        while(prec->nextEdge != E){
            prec = prec->nextEdge;
        }
        deleteAfterEdge(G, N, prec, E);
    }
}
void connecting(Graph &G, char node1, char node2){
    adrNode N1, N2;
    adrEdge E1, E2, Q;
    N1 = findNode(G, node1);
    N2 = findNode(G, node2);
    if(N1 != NULL && N2 != NULL){
        E1 = allocateEdge(node2);
        addEdge(G, N1, E1);
        E2 = allocateEdge(node1);
        addEdge(G, N2, E2);
    }else{
        cout << "Node tidak ditemukan." << endl;
    }
}
void disconecting(Graph &G, char node1, char node2){
    adrNode N1, N2;
    adrEdge E1, E2, Q;
    N1 = findNode(G, node1);
    N2 = findNode(G, node2);
    if(N1 != NULL && N2 != NULL){
        E1 = findEdge(G, N1, node2);
        E2 = findEdge(G, N2, node1);
        if(E1 != NULL && E2 != NULL){
            deleteEdge(G, N1, E1);
            deleteEdge(G, N2, E2);
        }else{
            cout << "Edge tidak ditemukan." << endl;
        }
    }else{
        cout << "Node tidak ditemukan." << endl;
    }
}
void showTetangga(Graph G){
    adrNode N;
    adrEdge E;
    if(G.start == NULL){
        cout << "Graph Kosong" << endl;
    }else{
        N = G.start;
        while(N != NULL){
            E = N->firstEdge;
            while(E != NULL){
                cout << E->info;
                E = E->nextEdge;
            }
            N = N->nextNode;
        }
    }
}
int hitungDegree(Graph G, char node){
    adrNode N = G.start;
    adrEdge E;
    int degree = 0;
    while(N != NULL){
        if(N->info == node){
            E = N->firstEdge;
            while(E != NULL){
                degree++;
                E = E->nextEdge;
            }
            return degree;
        }
        N = N->nextNode;
    }
    return -1;
}
void showDegree(Graph G){
    adrNode N = G.start;
    while(N != NULL){
        cout << "Node %c memiliki degree: %d\n" << N->info << hitungDegree(G, N->info) << endl;
        N = N->nextNode;
    }
//    adrNode N = G.start;
    adrEdge E;
    while(N != NULL){
        E = N->firstEdge;
        if(E == NULL){
            cout << "Tidak ada edge." << endl;
        }else{
            while(E != NULL){
                cout << E->info << " ";
                E = E->nextEdge;
            }
        }
        N = N->nextNode;
    }

}
int loop(Graph G){
    adrNode N = G.start;
    adrEdge E;
    int count = 0;
    while(N != NULL){
        E = N->firstEdge;
        while(E != NULL){
            if(E->info == N->info){
                count++;
            }
            E = E->nextEdge;
        }
        N = N->nextNode;
    }
    return count;
}

