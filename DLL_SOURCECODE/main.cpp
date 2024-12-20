#include <iostream>

using namespace std;

typedef int infotype;
typedef struct elmList *adr;
struct elmList{
    infotype info;
    adr next;
    adr prev;
};
struct List{
    adr first;
    adr last;
};
void createList(List &L){
    first(L) = NULL;
    last(L) = NULL;
}
adr NewElemen(infotype x){
    adr p = new elmList;
    info(p) = x;
    next(p) = NULL;
    prev(p) = NULL;
    return p;
}
void insertFirst(List &L, adr p){
    if(first(L) != NULL && last(L) != NULL){
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }else{
        first(L) = p;
        last(L) = p;
    }
}
void insertLast(List &L, adr p){
    if(first(L) != NULL && last(L) != NULL){
        prev(p) = last(L);
        next(last(L)) = p;
        last(L) = p;
    }else{
        first(L) = p;
        last(L) = p;
    }
}
void insertAfter(List &L, adr prec, adr p){
    if(first(L) != NULL && last(L) != NULL){
        next(p) = next(prec);
        prev(p) = prec;
        prev(next(p)) = p;
        next(prec) = p;
    }else{
        first(L) = p;
        last(L) = p;
    }
}
void insertBefore(List &L, adr p, adr q){
    if(first(L) != NULL && last(L) != NULL){
        next(p) = q;
        prev(p) = prev(q);
        next(prev(q)) = p;
        prev(q) = p
    }else{
        first(L) = p;
        last(L) = p;
    }
}
void deleteFirst(List &L, adr p){
    if(first(L) != last(L)){
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
        prev(first(L)) = NULL;
    }else{
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
}
void deleteLast(List &L, adr p){
    if(first(L) != last(L)){
        p = last(L);
        last(L) = prev(last(L));
        prev(p) = NULL;
        next(last(L)) = NULL;
    }else{
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
}
void deleteAfter(List &L, adr prec, adr p){
    if(first(L) != last(L)){
        p = next(prec);
        next(prec) = next(p);
        prev(next(p)) = prec;
        prev(p) = NULL;
        next(p) = NULL;
    }else{
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
}
void deleteBefore(List &L, adr p, adr q){
    if(first(L) != last(L){
       p = prev(q);
       next(prev(p)) = q;
       prev(q) = prev(p);
       next(p) = NULL;
       prev(p) = NULL;
    }else{
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
    }
}
adr ShowMaju(List L){
    adr p = first(L);
    while(p != NULL){
        cout << info(p) ;
        p = next(p);
    }
    return p;
}
adr ShowMundur(List L){
    adr p = last(L);
    while(p != NULL){
        p = prev(p);
    }
}
adr findMin(List L){
    adr p = first(L);
    adr q = first(L);
    while(p != NULL){
        if(info(q) > info(p)){
            q = p;
        }
        p = neext(p);
    }
    return q;
}
adr findMax(List L){
    adr p = first(L);
    adr q = first(L);
    while(p != NULL){
        if(info(q) < info(p)){
            q = p;
        }
        p = next(p);
    }
    return q;
}
void insertMiddle(List &L, int x){
    adr p,q;
    q = NewElemen(x);
    int a = 0;
    int b = 1;
    p = first(L);
    while(p != NULL){
        a++;
        p = next(p);
    }
    if(a % 2 == 0){
        a = a / 2;
    }else{
        a = (a/2) + 1;
    }
    p = first(L);
    while (b != a){
        p = next(p)
        b++;
    }
    next(q) = next(p);
    next(p) = q;
}
void deleteMiddle(List &L) {
    adr p, q;
    int a = 0;
    p = first(L);
    while (p != NULL) {
        a++;
        p = next(p);
    }
    if (a % 2 == 0) {
        a = a / 2;
    } else {
        a = (a / 2) + 1;
    }
    p = first(L);
    int b = 1;
    while (b != a) {
        p = next(p);
        b++;
    }
    q = next(p);
    next(p) = next(q);
    prev(next(q)) = p;
    q = NULL;
}
