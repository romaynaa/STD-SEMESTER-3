#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>

using namespace std;

struct Maskapai{
    string namaMaskapai;
    string kodeMaskapai;
    string kelasMaskapai;
    int kapasitasPenumpang;
};
struct rutePenerbangan {
    string kota_asal;
    string kota_tujuan;
    string kode_penerbangan;
    int jumlah_penumpang;

};

typedef Maskapai infotypeMaskapai;
typedef rutePenerbangan infotypeRute;

typedef struct elm_Maskapai *adr_Maskapai;
typedef struct elm_Rute *adr_Rute;
typedef struct elm_Relation* adr_relasi;

struct elm_Maskapai{
    infotypeMaskapai infoMaskapai;
    adr_relasi pRelasi;
    adr_Maskapai next;
    adr_Maskapai prev;
};
struct elm_Rute {
    infotypeRute infoRute;
    adr_Rute next;
};
struct elm_Relation {
    adr_Rute child;
    adr_relasi next;
};

struct List_Maskapai{
    adr_Maskapai first;
    adr_Maskapai last;
};
struct List_Rute{
    adr_Rute first;
};

void createListMaskapai(List_Maskapai &Lm);
void createListRute(List_Rute &LR);
adr_Maskapai createElmMaskapai(infotypeMaskapai x);
adr_Rute newElementRute(infotypeRute x);
adr_relasi createElmRelation(adr_Rute child);
void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P);
void insertRute(List_Rute &LR, adr_Rute p);
void insertRelation(adr_Maskapai p, adr_Rute child);
void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P);
void delete_First(List_Rute &LR, adr_Rute p);
void delete_After(List_Rute &LR, adr_Rute prec, adr_Rute p);
void delete_Last(List_Rute &LR, adr_Rute p);
void delete_Rute(List_Rute &LR, adr_Rute p);
void deleteRelation( adr_Maskapai P, adr_Rute child);
adr_Maskapai findMaskapai(List_Maskapai Lm, string kode);
adr_Rute findRute(List_Rute LR, string kode);
adr_relasi findRelation(adr_Maskapai P, adr_Rute child);
void showMaskapai(List_Maskapai Lm);
void showRute(List_Rute LR);
void show_RutefromMaskapai(adr_Maskapai m);
void show_MaskapaifromRute(List_Maskapai Lm, adr_Rute p);
void show_MaskapaiAndRute(List_Maskapai LM, List_Rute LR);
void showAll_RelasiRutePenerbangan(List_Maskapai Lm,  List_Rute LR, string kode);
void countRelationMaskapai(List_Maskapai LM, adr_Maskapai P);
void countRelationRute(List_Maskapai LM, adr_Rute P);
int count_RuteDontHaveRelasi(List_Maskapai LM, List_Rute LR);
void edit_RuteFromMaskapai(List_Maskapai LM, List_Rute LR, string kodeMaskapai, string kodeRute);


#endif // MLL_H_INCLUDED
