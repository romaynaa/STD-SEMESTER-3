#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
#include <iostream>
using namespace std;
#define info(p) p -> info
#define prev(p) p -> prev
#define next(p) p -> next
#define first(L) L.first
#define last(L) L.last

struct infotype{
    string Judul;
    string Penyanyi;
};
typedef struct elmList *address;
struct elmList{
    infotype info;
    address prev;
    address next;
};
struct List{
    address first;
    address last;
};
bool isEmpty_103032330131(List L);
void createList_103032330131(List &L);
address createNewElmt_103032330131(infotype X);
void insertFirst_103032330131(List &L, address p);
void inserAfter_103032330131(List &L, address prec, address p);
void insertLast_103032330131(List &L, address p);
void deleteFirst_103032330131(List &L, address p);
void deleteAfter_103032330131(List &L, address prec, address p);
void deleteLast_103032330131(List &L, address p);
void concat_103032330131(List L1, List L2, List &L3);
address findSong_103032330131(List L, string judul);
void removeSong_103032330131(List &L, string judul);
void show_103032330131(List L);

#endif // DLL_H_INCLUDED
