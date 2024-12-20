#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#define info(p) p -> info
#define next(p) p -> next
#define first(L) L.first

using namespace std;
typedef int infotype;
typedef struct elmList *address;
struct elmList{
    infotype info;
    address next;
};
struct List{
    address first;
};

void createList_103032330131(List &L);
address newElement_103032330131(infotype x);
void insertLast_103032330131(List &L, address p);
void showData_103032330131(List L);
address findMin_103032330131(List L);
void insertMiddle_103032330131(List &L, int x);
int selectMenu_103032330131();
#endif // SLL_H_INCLUDED
