#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#include <iostream>

#define info(p) p->info
#define next(p) p->next
#define first(L) L.first

using namespace std;

struct jadwalPenerbangan{
    string Kode;
    string Jenis;
    string Tanggal;
    string Waktu;
    string Asal;
    string Tujuan;
    int Kapasitas;
};
typedef jadwalPenerbangan infotype;
typedef struct elemenJadwal *adr_jadwalP;
struct elemenJadwal{
    infotype info;
    adr_jadwalP next;
};
struct ListJadwal{
    adr_jadwalP first;
};
void createListJadwal_103032330131(ListJadwal &L);
adr_jadwalP createElemenJadwal_103032330131(infotype x);
void insertLastJ_103032330131(ListJadwal &L, adr_jadwalP p);
void showJadwal_103032330131(ListJadwal L);
void deleteFirstJ_103032330131(ListJadwal &L, adr_jadwalP p);
bool searchJ_103032330131(ListJadwal L, string dari, string ke, string tanggal);



#endif // FLIGHT_H_INCLUDED
