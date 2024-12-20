#include <iostream>
#include "SLL.h"

using namespace std;

void createList(List &L){
    first(L) = NULL;
}
adr newElment(infotype x){
    adr p = new elmList;
    info(p) = x;
    next(p) = NULL;
    return p;
}
void insertFirst(List &L, adr p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        next(p) = first(L);
        first(L) = p;
    }
}
void insertLast(List &L, adr p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        adr Q = first(L);
        while(Q != NULL){
            Q = next(Q);
        }
        next(Q) = p;
    }
}
void insertAfter(List &L, adr prec, adr p){
    if (first(L)== NULL){
        first(L) = p;
    }else{
        next(p) = next(prec);
        next(prec) = p;
    }
}
void deleteFirst(List &L, adr p){
    if (first(L)== NULL){
        p = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}
void deleteLast(List &L, adr p){
    if (first(L)== NULL){
        p = NULL;
    }else{
        adr Q = first(L);
        while (next(next(Q)) != NULL){
            Q = next(Q);
        }
       p = next(Q);
       next(Q) = NULL;
    }
}
void deleteAfter(List &L, adr prec, adr p){
    if (first(L)== NULL){
        p = NULL;
    }else{
        p = next(prec);
        next(prec) = next(p);
        next(p) = NULL;
    }
}
void show(List L){

    if (first(L) == NULL){
        cout <<"List kosong" << endl;
    }else{
        adr p = first(L);
        while(p != NULL){
            cout << "Nama tim: " << info(p).namaTim<< endl;
            cout << "Kode tanding: "<< info(p).kodeTanding << endl;
            cout << "Skor: "<< info(p).skor << endl;
            p = next(p);
        }
    }
}
