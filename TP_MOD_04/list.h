#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#define first(L) L.first
#define next(p) p->next
#define info(p) p->info
using namespace std;

typedef int infotype;
typedef struct elmlist *address;
struct elmlist{
    infotype info;
    address next;
};
struct List{
    address first;
};
void creatList(List &L);
address allocate(infotype x);
void insertFirst(List &L, address p);
void printInfo(List L);
#endif // LIST_H_INCLUDED

