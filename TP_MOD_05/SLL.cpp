#include <iostream>
#include "SLL.h"
using namespace std;

void createList_103032330131(List &L){
    first(L) = 8
address newElement_103032330131(infotype x){
    address p = new elmList;
    info(p) = x;
    next(p) = NULL;
    return p;
}
void insertLast_103032330131(List &L, address p){
    if(first(L) == NULL){
        first(L) = p;
    }else{
       address Q = first(L);
       while(next(Q) != NULL){
        Q = next(Q);
       }
       next(Q) = p;
    }
}
void showData_103032330131(List L){
    address p = first(L);
    while(p != NULL){
        cout << info(p) << " ";
        p = next(p);
    }
}
address findMin_103032330131(List L){
    address p = first(L);
    address Q = first(L);
    while(p != NULL){
        if(info(Q) > info(p)){
            Q = p;
        }
        p = next(p);
    }
    return Q;
}
void insertMiddle_103032330131(List &L, int x){
    address p, Q;
    Q = newElement_103032330131(x);
    int a = 0;
    int b = 1;
    p = first(L);
    while (p != NULL){
        a++;
        p = next(p);
    }
    if(a % 2 == 0){
        a = a/2;
    }else{
        a = (a/2) + 1;
    }
    p = first(L);
    while (b != a){
        p = next(p);
        b++;
    }
    next(Q) = next(p);
    next(p) = Q;

}
int selectMenu_103032330131(){
    cout << endl << "==== MENU ====" << endl;
    cout << "1. Menambah N data baru" << endl;
    cout << "2. Menampilkan semua data" << endl;
    cout << "3. Mencari nilai minimum" <<endl;
    cout << "4. Menambah data di tengah" << endl;
    cout << "0. Exit" << endl;
    cout << "Pilihan menu: ";

    int input = 0;
    cin >> input;

    return input;
}

