
#include <iostream>
#include "DLL.h"
using namespace std;


bool isEmpty_103032330131(List L){
    return first(L) == NULL;
}
void createList_103032330131(List &L){
    first(L) = NULL;
    last(L) = NULL;
}
address createNewElmt_103032330131(infotype X){
    address p = new elmList;
    info(p) = X;
    prev(p) = NULL;
    next(p) = NULL;
    return p;
}
void insertFirst_103032330131(List &L, address p){
    if(isEmpty_103032330131(L)){
        first(L) = p;
        last(L) = p;
    }else{
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}
void inserAfter_103032330131(List &L, address prec, address p){
    if(first(L) == NULL && last(L)== NULL){
        first(L) = p;
        last(L) = p;
    }else{
        next(p) = next(prec);
        prev(p) = prec;
        prev(next(prec)) = p;
        next(prec) = p;
    }
}
void insertLast_103032330131(List &L, address p){
    if(isEmpty_103032330131(L)){
        first(L) = p;
        last(L) = p;
    }else{
        prev(p) = last(L);
        next(last(L)) = p;
        last(L) = p;
    }
}
void deleteFirst_103032330131(List &L, address p){
    p = first(L);
    if(first(L) == last(L)){
            first(L) = NULL;
            last(L) = NULL;
    }else{
            first(L) = next(first(L));
            prev(first(L)) = NULL;
            next(p) = NULL;
    }
}
void deleteAfter_103032330131(List &L, address prec, address p){
    if(first(L) == last(L)){
        first(L) = NULL;
        last(L) = NULL;
    }else{
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        prev(p) = NULL;
        next(p) = NULL;
    }
}
void deleteLast_103032330131(List &L, address p){
    if(first(L) == last(L)){
            p = first(L);
            first(L) = NULL;
            last(L) = NULL;
    }else{
            p = last(L);
            last(L) = prev(last(L));
            next(last(L)) = NULL;
            prev(p) = NULL;
    }
}
void concat_103032330131(List L1, List L2, List &L3){
    L3 = L1;
    next(last(L3)) = first(L2);
    prev(first(L2)) = last(L3);
    last(L3) = last(L2);
}
address findSong_103032330131(List L, string judul){
    if(isEmpty_103032330131(L)){
        return NULL;
        cout << endl << "Lagu tidak ditemukan"<< endl;
    }else{
        address p = first(L);
        while(p != NULL){
            if(info(p).Judul == judul){
                return p;
            }
        p = next(p);
        }
    return NULL;
    }
}
void removeSong_103032330131(List &L, string judul){
    if(isEmpty_103032330131(L)){
        cout << "List kosong" << endl;
    }else{
        address p = findSong_103032330131(L, judul);
        if(p != NULL){
            if(p == first(L)){
                deleteFirst_103032330131(L,p);
            }else if (p == last(L)){
                deleteLast_103032330131(L,p);
            }else{
                address prec = prev(p);
                deleteAfter_103032330131(L, prec, p);
            }
            delete p;
        }
    }
}
void show_103032330131(List L){
    address p = first(L);
    while(p != NULL){
        cout << "Lagu    : "<< info(p).Judul << endl;
        cout << "Penyanyi: "<< info(p).Penyanyi << endl;
        p = next(p);
    }
}
