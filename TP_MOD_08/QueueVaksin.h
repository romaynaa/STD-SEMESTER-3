#ifndef QUEUEVAKSIN_H_INCLUDED
#define QUEUEVAKSIN_H_INCLUDED

#include <iostream>
using namespace std;

struct infotype{
    string nama;
    int usia;
    string pekerjaan;
    bool prioritas;
    int nomor_antrean;
    bool kondisi_darurat;
};
struct ElemQ{
    infotype info;
    ElemQ *next;
};
struct Queue{
    ElemQ *head;
    ElemQ *tail;
};

void createQueue_103032330131(Queue &Q);
bool isEmpty_103032330131(Queue Q);
ElemQ* createElemQueue_103032330131(string nama, int usia, string pekerjaan, int nomor_antrean);
void enqueue_103032330131(Queue &Q, ElemQ *p);
void dequeue_103032330131(Queue &Q, ElemQ *p);
ElemQ* front_103032330131(Queue Q);
ElemQ* back_103032330131(Queue Q);
int size_103032330131(Queue Q);
void printInfo_103032330131(Queue Q);
void serveQueue_103032330131(Queue &Q);
void reassignQueue_103032330131(Queue &Q);
void checkWaitingTime_103032330131(Queue &Q, int waktu_sekarang);
void emergencyHandle_103032330131(Queue &Q, int nomor_antrean);
void updatePriority_103032330131(Queue &Q);
ElemQ* findAndRemove_103032330131(Queue Q, int nomor_antrean);

#endif // QUEUEVAKSIN_H_INCLUDED
