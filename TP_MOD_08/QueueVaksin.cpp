#include "QueueVaksin.h"

void createQueue_103032330131(Queue &Q){
    Q.head = NULL;
    Q.tail = NULL;
}
bool isEmpty_103032330131(Queue Q){
    return Q.head == NULL;
}
ElemQ* createElemQueue_103032330131(string nama, int usia, string pekerjaan, int nomor_antrean){
    ElemQ *p = new ElemQ;
    p->info.nama = nama;
    p->info.usia = usia;
    p->info.pekerjaan = pekerjaan;
    p->info.prioritas = usia >= 60 || pekerjaan == "tenaga kesehatan";
    p->info.nomor_antrean = nomor_antrean;
    p->info.kondisi_darurat = false;
    p->next = NULL;
    return p;
}
void enqueue_103032330131(Queue &Q, ElemQ *p){
    if(isEmpty_103032330131(Q)){
        Q.head = p;
        Q.tail = p;
    }else if(p->info.prioritas){
        if(!Q.head->info.prioritas){
            p->next = Q.head;
            Q.head = p;
        }else{
            ElemQ *temp = Q.head;
            while (temp->next != NULL && temp->next->info.prioritas){
                temp = temp->next;
            }
            p->next = temp->next;
            temp->next = p;
            if (p->next == NULL){
                Q.tail = p;
            }
        }
    }else{
        Q.tail->next = p;
        Q.tail = p;
    }
}
void dequeue_103032330131(Queue &Q, ElemQ *p){
    if (isEmpty_103032330131(Q)){
        p = NULL;
        cout << "Semua warga telah terlayani." << endl;
    }else{
        p = Q.head;
        Q.head = Q.head->next;
        if (Q.head == NULL){
            Q.tail = NULL;
        }
        p->next = NULL;
    }
}
ElemQ* front_103032330131(Queue Q){
    return Q.head;
}
ElemQ* back_103032330131(Queue Q){
    return Q.tail;
}
int size_103032330131(Queue Q){
     int count = 0;
     ElemQ *temp = Q.head;
     while (temp != NULL) {
        count++;
        temp = temp->next;
     }
     return count;
}
void printInfo_103032330131(Queue Q){
    if(isEmpty_103032330131(Q)){
        cout << "Antrean kosong" << endl;
    }else{
        ElemQ *p = Q.head;
        while(p != NULL){
            cout << "Melayani warga: "<< endl;
            cout << "Nama           :" << p->info.nama << endl;
            cout << "Usia           :" << p->info.usia << endl;
            cout << "Pekerjaan      :" << p->info.pekerjaan << endl;
            if(p->info.prioritas){
                cout << "Prioritas      : Ya" << endl;
            }else{
                cout << "Prioritas      : Tidak" << endl;
            }
            cout << "Nomor Antrean  :" << p->info.nomor_antrean << endl;
            cout << "-----------------------------------------------" << endl;
            p = p->next;
        }
    }
}
void serveQueue_103032330131(Queue &Q){
     if (isEmpty_103032330054(Q)){
            cout << "antrian kosong" << endl;
    }else{
        int kapasitas = 100;
        ElemQ *p;
        cout << endl << "Melakukan pelayanan pada antrean:" << endl;
        while (!isEmpty_103032330131(Q) && kapasitas != 0){
            dequeue_103032330054(Q,p);
            cout << "Melayanin warga:" << endl;
            cout << "------------------------------" << endl;
            cout << "Nama: " << p->info.nama << endl;
            cout << "Usia: " << p->info.usia << endl;
            cout << "Pekerjaan: " << p->info.pekerjaan << endl;
            if (p->info.prioritas){
                cout << "Prioritas: Ya" << endl;
            }else{
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Vaksinasi berhasil." << endl;
            cout << "------------------------------" << endl;
            kapasitas--;
        }
        if (kapasitas == 0){
            cout << endl << "Kapasitas penuh" << endl;
        }
        if (!isEmpty_103032330054(Q)){
            cout << endl << "Harap kembali pada besok hari" << endl;
        }
    }

}
void reassignQueue_103032330131(Queue &Q){
    Queue tempQ;
    createQueue_103032330131(tempQ);
    ElemQ *p;

    while(!isEmpty_103032330131(Q)){
        dequeue_103032330131(Q, p);
        enqueue_103032330131(tempQ, p);
    }
    while(!isEmpty_103032330131(tempQ)){
        dequeue_103032330131(tempQ, p);
        if (p->info. prioritas){
            p->next = Q.head;
            Q.head = p;

            if(Q.tail == NULL){
                Q.tail = p;
            }
        }else{
            enqueue_103032330131(Q,p);
        }
    }
}
void checkWaitingTime_103032330131(Queue &Q, int waktu_sekarang){
    ElemQ *p = Q.head;
    if(waktu_sekarang > 120){
        p = Q.head;
        while(p != NULL){
            p->info.prioritas = true;
            p = p->next;
        }
    }
    reassignQueue_103032330131(Q);
}

void emergencyHandle_103032330131(Queue &Q, int nomor_antrean){
    ElemQ *p = Q.head;
    while(p != NULL){
        if(p->info.nomor_antrean == nomor_antrean){
            p->info.kondisi_darurat = true;
            p->info.prioritas = true;
            reassignQueue_103032330131(Q);
            return;
        }
        p = p->next;
    }
    cout << "Warga dengan nomor antrean " << nomor_antrean << "tidak ditemukan." << endl;
}
void updatePriority_103032330131(Queue &Q){
    ElemQ *p = Q.head;
    checkWaitingTime_103032330131(Q, 130);
    while (p != NULL){
        if(p->info.kondisi_darurat){
            reassignQueue_103032330131(Q);
        }
        p = p->next;
    }
}
ElemQ* findAndRemove_103032330131(Queue Q, int nomor_antrean){
    ElemQ *p, *prec, *q;
    p = Q.head;
    q = Q.head;
    while(p != NULL){
        if(nomor_antrean == p->info.nomor_antrean){
            if(p == Q.head){
                dequeue_103032330131(Q,prec);
                return prec;
            }else if(p == Q.tail){
                Q.tail = q;
                Q.tail->next = NULL;
                return p;
            }else{
                q->next= p->next;
                p->next = NULL;
                return p;
            }
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

