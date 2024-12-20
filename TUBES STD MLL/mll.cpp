#include <iostream>
#include "mll.h"

using namespace std;

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
    if(LR.first == NULL){
        LR.first = p;
    }else{
        adr_Rute Q = LR.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = p;
    }
}

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
    adr_Maskapai m = Lm.first;
    if(m == NULL){
        return NULL;
        cout << endl << "Maskapai tidak ditemukan" << endl;
    }else{
        while(m != NULL){
            if(m->infoMaskapai.kodeMaskapai == kode){
                return m;
            }
            m = m->next;
        }
        return NULL;
    }
}

adr_Rute findRute(List_Rute LR, string kode){
    adr_Rute r = LR.first;
    if(r == NULL){
        return NULL;
        cout << endl << "Rute tidak ditemukan" << endl;
    }else{
        while(r != NULL){
            if(r->infoRute.kode_penerbangan == kode){
                return r;
            }
            r = r->next;
        }
        return NULL;
    }
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
void show_RutefromMaskapai(adr_Maskapai m){
    if(m == NULL){
        cout << "Maskapai tidak ditemukan." << endl;
        return;
    }
    adr_relasi rl = m->pRelasi;
    if(rl == NULL){
        cout << "Maskapai ini tidak memiliki rute yang berelasi." << endl;
    }else{
        cout << "Rute penerbangan dari maskapai " << m->infoMaskapai.namaMaskapai << ":" << endl;
        while(rl != NULL){
            cout << "  Kota asal       : " << rl->child->infoRute.kota_asal << endl;
            cout << "  Kota tujuan     : " << rl->child->infoRute.kota_tujuan << endl;
            cout << "  Kode penerbangan: " << rl->child->infoRute.kode_penerbangan << endl;
            cout << "  Jumlah penumpang: " << rl->child->infoRute.jumlah_penumpang << endl;
            rl = rl->next;
        }
    }
}
void show_MaskapaifromRute(List_Maskapai Lm, adr_Rute p){
    if (p == NULL) {
        cout << "Rute tidak ditemukan!" << endl;
        return;
    }

    bool found = false;
    adr_Maskapai m = Lm.first;

    while (m != NULL) {
        adr_relasi rl = m->pRelasi;
        while (rl != NULL) {
            if (rl->child == p) {
                if (!found) {
                    cout << "Maskapai yang memiliki rute penerbangan ini:" << endl;
                }
                found = true;
                cout << "  Nama Maskapai   : " << m->infoMaskapai.namaMaskapai << endl;
                cout << "  Kode Maskapai   : " << m->infoMaskapai.kodeMaskapai << endl;
                cout << "  Kelas Maskapai  : " << m->infoMaskapai.kelasMaskapai << endl;
                cout << "  Kapasitas       : " << m->infoMaskapai.kapasitasPenumpang << endl;
            }
            rl = rl->next;
        }
        m = m->next;
    }

    if (!found) {
        cout << "Tidak ada maskapai yang memiliki rute tersebut." << endl;
    }
}
void show_MaskapaiAndRute(List_Maskapai LM, List_Rute LR){
    if(LM.first == NULL){
        cout << "Maskapai tidak ditemukan." << endl;
        return;
    }
    adr_Maskapai m = LM.first;
    cout << "Maskapai Penerbangan: " << endl;
    while(m != NULL){
        cout << "Nama Maskapai: " << m->infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << m->infoMaskapai.kodeMaskapai << endl;
        cout << "Jenis Kelas Maskapai: " << m->infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " << m->infoMaskapai.kapasitasPenumpang << endl;
        m = m->next;
    }

    cout << "Rute Penerbangan: " << endl;
    showRute(LR);
}
void showAll_RelasiRutePenerbangan(List_Maskapai Lm,  List_Rute LR, string kode){
    if(Lm.first == NULL){
        cout << "List Maskapai Kosong!" << endl;
        return;
    }

    adr_Maskapai m = findMaskapai(Lm, kode);
    if(m == NULL){
        cout << "Maskapai dengan kode "<< kode << "tidak ditemukan." << endl;
        return;
    }
        cout << "Maskapai: " << endl;
        cout << "Nama Maskapai: "<< m->infoMaskapai.namaMaskapai << endl;
        cout << "Kode Maskapai: " << m->infoMaskapai.kodeMaskapai << endl;
        cout << "Kelas Maskapai: " << m->infoMaskapai.kelasMaskapai << endl;
        cout << "Kapasitas Penumpang: " << m->infoMaskapai.kapasitasPenumpang << endl;

        adr_relasi r = m->pRelasi;
        if(r == NULL){
            cout << "Tidak ada rute yang berelasi." << endl;
        }else{
            cout << "  Rute Penerbangan: " << endl;
            while(r != NULL){
                adr_Rute p = r->child;
                if(p != NULL){
                    cout << "    Kota Asal       : " << p->infoRute.kota_asal << endl;
                    cout << "    Kota Tujuan     : " << p->infoRute.kota_tujuan << endl;
                    cout << "    Kode Penerbangan: " << p->infoRute.kode_penerbangan << endl;
                    cout << "    Jumlah Penumpang: " << p->infoRute.jumlah_penumpang << endl;
                }
                r = r->next;
        }

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
            adr_relasi r = m->pRelasi;
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
    adr_Maskapai m = findMaskapai(LM, kodeMaskapai);
    if (m == NULL) {
        cout << "Maskapai dengan kode " << kodeMaskapai << " tidak ditemukan." << endl;
        return;
    }
     adr_relasi r = m->pRelasi;
    if (r == NULL) {
        cout << "Tidak ada rute yang berelasi untuk maskapai ini." << endl;
        return;
    }
    cout << "Masukkan kode rute yang akan diedit: ";
    cin >> kodeRute;

    while (r != NULL) {
        adr_Rute p = r->child;
        if (p->infoRute.kode_penerbangan == kodeRute) {
            cout << "Masukkan rute baru: " << endl;
            cout << "Kota asal: ";
            cin >> p->infoRute.kota_asal;
            cout << "Kota tujuan: ";
            cin >> p->infoRute.kota_tujuan;
            cout << "Kode penerbangan: ";
            cin >> p->infoRute.kode_penerbangan;
            cout << "Jumlah penumpang: ";
            cin >> p->infoRute.jumlah_penumpang;
            cout << "Rute berhasil diperbarui." << endl;
            return;
        }
        r = r->next;
    }

    cout << "Rute dengan kode " << kodeRute << " tidak ditemukan untuk maskapai ini." << endl;
}



