#include <iostream>
#include "DLL.h"
using namespace std;

int main()
{
    List L1, L2, L3;
    address p, q;
    infotype x;
    int n;
    string judul;
    createList_103032330131(L1);
    createList_103032330131(L2);
    createList_103032330131(L3);

    cout << "==================== Album pertama ====================";
    cout << endl << "Masukkan jumlah lagu yang ingin dimasukkan: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << endl << "Penyanyi ke-" << i+1 << ": ";
        cin >> x.Penyanyi;
        cout << endl << "Judul ke-" << i+1 << ": ";
        cin >> x.Judul;
        p = createNewElmt_103032330131(x);
        insertLast_103032330131(L1,p);
    }
    cout << "==================== Album kedua ====================";
    cout << endl << "Masukkan jumlah lagu yang ingin dimasukkan: ";
    cin >> n;
    for(int j = 0; j < n; j++){
        cout << endl << "Penyanyi ke-" << j+1 << ": ";
        cin >> x.Penyanyi;
        cout << endl << "Judul ke-" << j+1 << ": ";
        cin >> x.Judul;
        p = createNewElmt_103032330131(x);
        insertLast_103032330131(L2,p);
    }
    cout << "==================== Album pertama ===================="<< endl;
    show_103032330131(L1);
    cout << endl<< "==================== Album kedua ===================="<< endl;
    show_103032330131(L2);

    concat_103032330131(L1,L2,L3);
    cout << endl<< "==================== Album ketiga ===================="<< endl;
    show_103032330131(L3);
    cout << "==================== Album setelah delete first ===================="<< endl;
    deleteFirst_103032330131(L3, p);
    show_103032330131(L3);
    cout << "==================== Album setelah delete last ===================="<< endl;
    deleteLast_103032330131(L3, p);
    show_103032330131(L3);
    cout << "==================== Album setelah delete after ===================="<< endl;
    cout << endl << "Judul lagu yang setelahnya akan dihapus: ";
    cin >> judul;
    q = findSong_103032330131(L3, judul);
    if(q != NULL){
        deleteAfter_103032330131(L3, q, p);
        show_103032330131(L3);
    }
    cout << endl << "Masukkan judul lagu yang akan dihapus: ";
    cin >> judul;
    removeSong_103032330131(L3, judul);
    show_103032330131(L3);
    cout << "==================== Album insert after ====================";
    cout << endl << "Judul lagu yang setelahnya akan ditambah: ";
    cin >> judul;
    q = findSong_103032330131(L3, judul);
    if(q != NULL){
        cout << endl << "Judul lagu yang akan ditambahkan: ";
        cin >> x.Judul;
        cout << endl << "Nama penyannyi yang akan ditambahkan: ";
        cin >> x.Penyanyi;
        p = createNewElmt_103032330131(x);
        inserAfter_103032330131(L3,q,p);
        show_103032330131(L3);
    }
    return 0;
}
