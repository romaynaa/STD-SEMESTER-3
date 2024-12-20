#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#define info(p) p -> info
#define next(p) p -> next
#define first(L) L.first

using namespace std;
struct tanding{
    string namaTim;
    string kodeTanding;
    int skor;
};
typedef tanding infotype;
typedef struct elmList *adr;
struct elmList{
    infotype info;
    adr next;
};
struct List{
    adr first;
};
void createList(List &L);
adr newElment(infotype x);
void insertFirst(List &L, adr p);
void insertLast(List &L, adr p);
void insertAfter(List &L, adr prec, adr p);
void deleteFirst(List &L, adr p);
void deleteLast(List &L, adr p);
void deleteAfter(List &L, adr prec, adr p);
void show(List L);

#endif // SLL_H_INCLUDED
