#include "QueueVaksin.h"

int main()
{
    Queue Q;
    createQueue_103032330131(Q);

    ElemQ* p1 = createElemQueue_103032330131("John Doe", 65, "lansia", 1);
    ElemQ* p2 = createElemQueue_103032330131("Alice", 30, "tenaga kesehatan", 2);
    ElemQ* p3 = createElemQueue_103032330131("Bob", 25, "pekerja", 3);
    ElemQ* p4 = createElemQueue_103032330131("Charlie", 70, "pensiunan", 4);
    ElemQ* p5 = createElemQueue_103032330131("David", 28, "pekerja", 5);

    enqueue_103032330131(Q, p1);
    enqueue_103032330131(Q, p2);
    enqueue_103032330131(Q, p3);
    enqueue_103032330131(Q, p4);
    enqueue_103032330131(Q, p5);

    cout << "Isi antrean awal: " << endl;
    printInfo_103032330131(Q);

    cout << "\nMelakukan pelayanan pada antrean: "<< endl;
    serveQueue_103032330131(Q);

    cout << "\nIsi antrean setelah pelayanan: "<< endl;
    printInfo_103032330131(Q);

    ElemQ* P6 = createElemQueue_103032330131("Edward", 22, "pekerja", 6);
    enqueue_103032330131(Q, P6);

    cout << "\nMengatur ulang antrean berdasarkan prioritas: "<< endl;
    reassignQueue_103032330131(Q);
    printInfo_103032330131(Q);

    cout << "\nMemeriksa waktu tunggu dan mengubah prioritas jika lebih dari 2 jam: "<< endl;
    checkWaitingTime_103032330131(Q, 130);
    printInfo_103032330131(Q);

    cout << "\nMenangani kondisi darurat untuk warga dengan nomor antrean 5: "<< endl;
    emergencyHandle_103032330131(Q, 5);
    printInfo_103032330131(Q);

    cout << "\nMengupdate prioritas antrean setiap jam: "<< endl;
    updatePriority_103032330131(Q);
    printInfo_103032330131(Q);

    cout << "\nMenghapus warga dengan nomor antrean 3:" << endl;
    ElemQ* removedElem = findAndRemove_103032330131(Q, 3);
    if (removedElem) {
    cout << "Warga yang dihapus: " << removedElem->info.nama << endl;
    }
    printInfo_103032330131(Q);

    return 0;

}
