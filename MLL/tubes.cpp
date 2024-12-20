#include <iostream>
using namespace std;
#include "tubes.h"


void createListMaskapai(List_Maskapai &Lm){
    Lm.first = NULL;
    Lm.last = NULL;
}

void createListRute(List_Rute &LR){
    LR.first = NULL;
}

adr_Maskapai createElmMaskapai(infotypeMaskapai x){
    adr_Maskapai P = new elm_Maskapai;
    P -> infoMaskapai = x;
    P -> next = NULL;
    P -> prev = NULL;
    return P;
}

adr_Rute newElementRute(infotypeRute x){
    adr_Rute p = new elm_Rute;
    p->infoRute = x;
    p->next = NULL;
    return p;
}

adr_relasi createElmRelation(adr_Rute child){
    adr_relasi P = new elm_Relation;
    P->child = child;
    P->next = NULL;
    return P;
}

void insertMaskapai(List_Maskapai &Lm, adr_Maskapai P){
    if (Lm.first != NULL && Lm.last != NULL){
        P -> prev = Lm.last;
        Lm.last -> next = P;
        Lm.last = P;
    }else{
        Lm.first = P;
        Lm.last = P;
    }
}

void insertRute(List_Rute &LR, adr_Rute p){
    adr_Rute Q;
    if(LR.first == NULL){
        LR.first = p;
    }else{
        Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}

//void insertRelation(adr_Maskapai P, adr_Rute child) {
//    adr_relasi R = createElmRelation( child);
//    if (P -> pRelasi == NULL) {
//        P ->pRelasi = R;
//    } else {
//        adr_relasi temp = P ->pRelasi;
//        while (temp->next != NULL) {
//            temp = temp->next;
//        }
//        temp->next = R;
//    }
//}
void insertRelation(adr_Maskapai p, adr_Rute child) {
//    adr_relasi R = createElmRelation(child);
//    if (P -> pRelasi == NULL) {
//        P ->pRelasi = R;
//    } else {
//        adr_relasi temp = P ->pRelasi;
//        while (temp->next != NULL) {
//            temp = temp->next;
//        }
//        temp->next = R;
//    }
    if(p == NULL || child == NULL){
        cout << "Rute tidak ditemukan" << endl;
        return;
    }
    adr_relasi rl = p->pRelasi;
    while(rl != NULL){
        if(rl->child == child){
            cout << "Relasi antara maskapai dan rute sudah ada!" << endl;
            return;
        }
        rl = rl->next;
    }
    adr_relasi r = createElmRelation(child);
    if(p->pRelasi == NULL){
        p->pRelasi = r;
    }else{
        rl = p->pRelasi;
        while(rl->next != NULL){
            rl = rl->next;
        }
        rl->next = r;
    }
}

void deleteMaskapai(List_Maskapai &Lm, adr_Maskapai &P){
    P = Lm.last;
    if (Lm.first != Lm.last){
        Lm.last = P -> prev;
        P -> prev = NULL;
        Lm.last -> next = NULL;
    }else{
        Lm.first = NULL;
        Lm.last = NULL;
    }
}

void delete_First(List_Rute &LR, adr_Rute p){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first = NULL;
    }else{
        p = LR.first;
        LR.first = p->next;
        p->next = NULL;
    }
}
void delete_After(List_Rute &LR, adr_Rute prec, adr_Rute p){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first == NULL;
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}

void delete_Last(List_Rute &LR, adr_Rute p){
    if(LR.first == NULL){
        LR.first = NULL;
    }else if(LR.first->next == LR.first){
        LR.first == NULL;
    }else{
        adr_Rute Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        p = Q->next;
        Q->next = NULL;
    }
}

void delete_Rute(List_Rute &LR, adr_Rute p){
    adr_Rute prec;
    if(LR.first == NULL){
         cout << "Data kosong" << endl;
    }else if(p == LR.first){
         delete_First(LR, p);
    }else if(p->next == NULL){
         delete_Last(LR, p);
    }else{
         delete_After(LR, prec, p);
    }
}

void deleteRelation( adr_Maskapai P, adr_Rute child) {
    if (P -> pRelasi!= NULL) {
        adr_relasi temp = P ->pRelasi;
        adr_relasi prev = NULL;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp ->next = prev;
        temp -> next = NULL;
    }
}

adr_Maskapai findMaskapai(List_Maskapai Lm, string kode){
    adr_Maskapai P;
    P = Lm.first;
    while(P -> next != NULL){
        if(P -> infoMaskapai.kodeMaskapai == kode){
            return P;
        }
        P = P -> next;
    }
}

adr_Rute findRute(List_Rute LR, string x){
    adr_Rute p;
    p = LR.first;
    while(p != NULL){
            if(p->infoRute.kode_penerbangan == x){
                return p;
            }
            p = p->next;
       }
    return NULL;
}

adr_relasi findRelation(adr_Maskapai P, adr_Rute child) {
    adr_relasi temp = P -> pRelasi;
    while (temp != NULL) {
        if (temp->child == child) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void showMaskapai(List_Maskapai Lm){
    adr_Maskapai P;
    P = Lm.first;
    while(P != NULL){
        cout << "Nama Maskapai: " << P -> infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << P -> infoMaskapai.kodeMaskapai << endl;
        cout << "Jenis Kelas Maskapai: " << P -> infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " <<  P -> infoMaskapai.kapasitasPenumpang << endl;
        P = P -> next;
    }
}

void showRute(List_Rute LR){
    adr_Rute p;
    if(LR.first == NULL){
        cout << "Data Kosong" << endl;
    }else{
       p = LR.first;
       while(p != NULL){
            cout << "Kota asal: " << p->infoRute.kota_asal << endl;
            cout << "Kota tujuan: " << p->infoRute.kota_tujuan << endl;
            cout << "Kode penerbangan: " << p->infoRute.kode_penerbangan << endl;
            cout << "Jumlah penumpang: " << p->infoRute.jumlah_penumpang << endl;
            p = p->next;
       }
    }
}
void show_RutefromMaskapai(adr_Maskapai p, List_Maskapai Lm){
    string kode;
    cin >> kode;
    p = findMaskapai(Lm,kode);
    adr_relasi q = p -> pRelasi;
    while(q != NULL){
        cout << "Kota asal" << q->child->infoRute.kota_asal;
        cout << "Kota Tujuan" << q->child->infoRute.kota_tujuan;
        cout << "Kode penerbangan" << q->child->infoRute.kode_penerbangan;
        cout << "Jumlah Penumpang" << q->child->infoRute.jumlah_penumpang;
        q = q ->next;
    }
}
void show_MaskapaifromRute(List_Maskapai Lm, adr_Maskapai p){
    adr_Maskapai temp = Lm.first;
    while(temp != NULL){
        adr_relasi r = temp -> pRelasi;
        while(r != NULL){
            if(r ->child->infoRute.kode_penerbangan == p->infoMaskapai.kodeMaskapai){
                cout << temp ->infoMaskapai.namaMaskapai;
            }
            r = r ->next;
        }
        temp = temp -> next;
    }
}

void show_MaskapaiAndRute(List_Maskapai LM, List_Rute LR, adr_Maskapai P, adr_Rute Q){
    P = LM.first;
    Q = LR.first;
    string x;
    while(Q != NULL){
        Q ->infoRute.kode_penerbangan = x;
         while(P != NULL){
            adr_relasi r = P -> pRelasi;
            while(r != NULL){
                if(r ->child == Q){
                    cout << x << " ";
                }
                r = r ->next;
            }
            P = P -> next;
        }
        Q = Q -> next;
    }
}
void showAllDataRelasi(List_Maskapai LM, adr_Rute P) {
    adr_Maskapai m = LM.first;
    bool foundRelasi = false;

    while (m != NULL) {
        adr_relasi r = m->pRelasi;
        while (r != NULL) {
            if (r->child == P) {

                cout << "Maskapai: " << m->infoMaskapai.namaMaskapai << endl;
                cout << "Kode Maskapai: " << m->infoMaskapai.kodeMaskapai << endl;
                cout << "Kelas Maskapai: " << m->infoMaskapai.kelasMaskapai << endl;
                cout << "Kapasitas Penumpang: " << m->infoMaskapai.kapasitasPenumpang << endl;

                cout << "Rute Penerbangan: " << endl;
                cout << "Kota Asal: " << P->infoRute.kota_asal << endl;
                cout << "Kota Tujuan: " << P->infoRute.kota_tujuan << endl;
                cout << "Kode Penerbangan: " << P->infoRute.kode_penerbangan << endl;
                cout << "Jumlah Penumpang: " << P->infoRute.jumlah_penumpang << endl;

                foundRelasi = true;
            }
            r = r->next;
        }
        m = m->next;
    }
}

void countRelationMaskapai(List_Maskapai LM, adr_Maskapai P) {
    int count = 0;
    adr_relasi relasi = P->pRelasi;
    while (relasi != NULL) {
        count++;
        relasi = relasi->next;
    }
    cout << "Jumlah relasi Maskapai " << P->infoMaskapai.namaMaskapai
         << " dengan rute penerbangan adalah: " << count << endl;
}

void countRelationRute(List_Maskapai LM, adr_Rute P) {
    int count = 0;
    adr_Maskapai maskapai = LM.first;
    while (maskapai != NULL) {
        adr_relasi relasi = maskapai->pRelasi;
        while (relasi != NULL) {
            if (relasi->child == P) {
                count++;
                break;
            }
            relasi = relasi->next;
        }
        maskapai = maskapai->next;
    }
    cout << "Jumlah Maskapai yang memiliki relasi dengan rute " << P->infoRute.kode_penerbangan
         << " adalah: " << count << endl;
}

int count_RuteDontHaveRelasi(List_Maskapai LM, List_Rute LR){
    int count = 0;
    adr_Rute p = LR.first;
    while(p != NULL){
        bool relasi = false;
        adr_Maskapai m = LM.first;
        while(m != NULL){
            adr_relasi r = m ->pRelasi;
            while(r != NULL){
                if(r->child == p){
                    relasi = true;
                }
                r = r->next;
            }
            m = m->next;
        }
        if(!relasi){
            count++;
        }
        p = p->next;
    }
    return count;
}
void edit_RuteFromMaskapai(List_Maskapai LM, List_Rute LR, string kodeMaskapai, string kodeRute){
    adr_Maskapai m;
    adr_Rute p;
    cin >> kodeMaskapai;
    m = findMaskapai(LM, kodeMaskapai);
    adr_relasi r = m->pRelasi;
    while(r != NULL){
        cin >> kodeRute;
        p = findRute(LR, kodeRute);
            cout << "Masukkan rute baru: " << endl;
            cout << "Kota asal: ";
            cin >> r->child->infoRute.kota_asal;
            cout << "Kota tujuan: ";
            cin >> r->child->infoRute.kota_tujuan;
            cout << "Kode penerbangan: ";
            cin >> r->child->infoRute.kode_penerbangan;
            cout << "Jumlah penumpang: ";
            cin >> r->child->infoRute.jumlah_penumpang;
         r = r->next;
    }
    cout << endl;
}
