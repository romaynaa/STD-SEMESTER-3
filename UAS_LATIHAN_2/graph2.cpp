#include <iostream>
#include "graph2.h"

using namespace std;

adrNode createNode(infotype data){
    adrNode N = new elmNode;
    N->info = data;
    N->firstEdge = NULL;
    N->nextNode = NULL;
    return NULL;
}
void insertNode(Graph &G, adrNode N){
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
adrEdge createEdge(string id){
    adrEdge E = new elmEdge;
    E->idEdge = id;
    E->nextEdge = NULL;
    return E;
}
void insertEdge(Graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "Node kosong" << endl;
    }else if(N->firstEdge == NULL){
        N->firstEdge = E;
    }else{
        adrEdge Q = N->firstEdge;
        while(Q->nextEdge !=  NULL){
            Q = Q->nextEdge;
        }
        Q->nextEdge = E;
    }
}
adrNode findNode(Graph G, string idAkun){
    if(G.start == NULL){
        return NULL;
    }else{
        adrNode N = G.start;
        while(N->nextNode != NULL && N->info.id != idAkun){
            N = N->nextNode;
        }
        if(N->info.id == idAkun){
            return N;
        }else{
            return NULL;
        }
    }
}
void showAkun(Graph G){
    adrNode N = G.start;
    while(N != NULL){
        cout << "ID Akun  : " << N->info.id << endl;
        cout << "Nama Akun: " << N->info.nama << endl;
        cout << "Following: " << N->info.following << endl;
        cout << "Followed : " << N->info.followed << endl;
        cout << endl;
        N = N->nextNode;
    }
}
void follow(Graph &G, string idA, string idB){
    adrNode N1 = findNode(G, idA);
    adrNode N2 = findNode(G, idB);
    if(N1 != NULL && N2 != NULL){
        adrEdge E = createEdge(N2->info.id);
        insertEdge(G, N1, E);
        N1->info.following++;
        N2->info.followed++;
    }else{
        cout << "Akun tidak ditemukan." << endl;
    }

}
void showFollowing(Graph G, string id){
    adrNode N = findNode(G, id);
    if(N != NULL){
        adrEdge E = N->firstEdge;
        if(E == NULL){
            cout << "Tidak ada following." << endl;
        }else{
            while(E != NULL){
                cout << "ID Akun: " << E->idEdge << endl;
                E = E->nextEdge;
            }
        }
    }else{
        cout << "Akun tidak ditemukan" << endl;
    }
}
void signUp(Graph &G, infotype newAkun){
    adrNode N = createNode(newAkun);
    if(G.start != NULL){
        insertNode(G, N);
    }else{
        G.start = N;
    }
}
void unFollow(Graph &G, string idA, string idB){
    adrNode N1 = findNode(G, idA);
    adrNode N2 = findNode(G, idB);
    if(N1 != NULL && N2 != NULL){
        adrEdge E = findEdge(G, N1, idB);
        deleteEdge(G, N1, E);
        N1->info.following--;
        N2->info.followed--;
    }else{
        cout << "Akun tidak ditemukan." << endl;
    }

}
void deleteFirstNode(Graph &G, adrNode N){
    if(G.start == NULL){
        G.start = NULL;
    }else{
        N = G.start;
        G.start = N->nextNode;
        N->nextNode = NULL;
    }
}
void deleteAfterNode(Graph &G, adrNode prec, adrNode N){
    if(G.start == NULL){
        G.start = NULL;
    }else{
        N = prec->nextNode;
        prec->nextNode = N->nextNode;
        N->nextNode = NULL;
    }
}
void deleteLastNode(Graph &G, adrNode N){
    if(G.start == NULL){
        G.start = NULL;
    }else{
        adrNode Q = G.start;
        while(Q->nextNode != NULL){
            Q = Q->nextNode;
        }
        N = Q->nextNode;
        Q->nextNode = NULL;
    }
}
void deleteNode(Graph &G, adrNode N){
    adrNode prec;
    if(N == G.start){
        deleteFirstNode(G, N);
    }else if(N->nextNode == NULL){
        deleteLastNode(G, N);
    }else{
        while(prec->nextNode != N){
            prec = prec->nextNode;
        }
        deleteAfterNode(G, prec, N);
    }
}
void deleteFirstEdge(Graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "Node kosong." << endl;
    }else{
        E = N->firstEdge;
        N->firstEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteAfterEdge(Graph &G, adrNode N, adrEdge prec, adrEdge E){
    if(G.start == NULL){
        cout << "Node kosong." << endl;
    }else{
        E = prec->nextEdge;
        prec->nextEdge = E->nextEdge;
        E->nextEdge = NULL;
    }
}
void deleteLastEdge(Graph &G, adrNode N, adrEdge E){
    if(G.start == NULL){
        cout << "Node kosong" << endl;
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
    adrEdge prec;
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
adrEdge findEdge(Graph G, adrNode N, string id){
    if(G.start == NULL){
        return NULL;
    }else{
        adrEdge E = N->firstEdge;
        while(E->nextEdge != NULL && E->idEdge != id){
            E = E->nextEdge;
        }
        if(E->idEdge == id){
            return E;
        }else{
            return NULL;
        }
    }
}
void deleteAkun(Graph &G, string idAkun){
    adrNode N;
    adrEdge E;
    deleteNode(G, N);
    N = G.start;
    while(N != NULL){
        E = N->firstEdge;
        while(E != NULL){
            if(E->idEdge == idAkun){
                deleteEdge(G, N, E);
            }
            E = E->nextEdge;
        }
        N = N->nextNode;
    }
}
