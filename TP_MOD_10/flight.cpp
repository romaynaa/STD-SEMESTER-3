#include <iostream>
#include "flight.h"

using namespace std;

void createListJadwal_103032330131(ListJadwal &L){
    first(L) = NULL;
}
adr_jadwalP createElemenJadwal_103032330131(infotype x){
    adr_jadwalP p = new elemenJadwal;
    info(p) = x;
    next(p) = NULL;
    return p;
}
void insertLastJ_103032330131(ListJadwal &L, adr_jadwalP p){
    if(first(L) == NULL){
        first(L) = p;
    }else{
        adr_jadwalP Q = first(L);
        while(next(Q) != NULL){
            Q = next(Q);
        }
        next(Q) = p;
    }
}
void showJadwal_103032330131(ListJadwal L){
    adr_jadwalP p = first(L);
    if(p == NULL){
        cout << "Jadwal penerbangan kosong.\n";
    }
    while(p != NULL){
        cout << "Kode: " << info(p).Kode <<
        ", Jenis: " << info(p).Jenis <<
        ", Tanggal: " << info(p).Tanggal <<
        ", Waktu: " << info(p).Waktu <<
        ", Asal: " << info(p).Asal<<
        ", Tujuan: " << info(p).Tujuan <<
        ", Kapasitas: " << info(p).Kapasitas << endl;
        p = next(p);
    }
}
void deleteFirstJ_103032330131(ListJadwal &L, adr_jadwalP p){
    if(first(L) == NULL){
        first(L) = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}
bool searchJ_103032330131(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP p = first(L);
    while(first(L) != NULL){
        if(info(p).Asal == dari && info(p).Tujuan == ke && info(p).Tanggal == tanggal){
            cout << "Jadwal ditemukan:\n";
            cout << "Kode: " << info(p).Kode
                 << ", Jenis: " << info(p).Jenis
                 << ", Tanggal: " << info(p).Tanggal
                 << ", Waktu: " << info(p).Waktu
                 << ", Asal: " << info(p).Asal
                 << ", Tujuan: " << info(p).Tujuan
                 << ", Kapasitas: " << info(p).Kapasitas << endl;
        }
        p = next(p);
    }
    return NULL;
}
