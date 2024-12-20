#include <iostream>
#include "flight.h"

using namespace std;

int main()
{
    ListJadwal L;
    adr_jadwalP p;
    infotype jadwal;
    createListJadwal_103032330131(L);

    int n;
    cout << "Masukkan jumlah jadwal penerbangan: ";
    cin >> n;

    for(int i = 0; i < n; i++){
        cout << "Masukkan data jadwal ke-" << (i+1) << ":\n";
        cout << "Kode: "; cin >> jadwal.Kode;
        cout << "Jenis: "; cin >> jadwal.Jenis;
        cout << "Tanggal: "; cin >> jadwal.Tanggal;
        cout << "Waktu: "; cin >> jadwal.Waktu;
        cout << "Asal: "; cin >> jadwal.Asal;
        cout << "Tujuan: "; cin >> jadwal.Tujuan;
        cout << "Kapasitas: "; cin >> jadwal.Kapasitas;

        p = createElemenJadwal_103032330131(jadwal);
        insertLastJ_103032330131(L,p);
    }

    cout << "\nDaftar Jadwal Penerbangan:\n";
    showJadwal_103032330131(L);

    cout << "\nMenghapus jadwal pertama\n";
    deleteFirstJ_103032330131(L,p);
//    if(p != NULL){
//        cout << "Jadwal yang dihapus: " << info(p).Kode << endl;
//        delete p;
//    }
    cout << "\nDaftar Jadwal Penerbangan Setelah Di Hapus:\n";
    showJadwal_103032330131(L);

    cout << "\nMencari jadwal penerbangan:\n";
    string asal, tujuan, tanggal;
    cout << "Asal: "; cin >> asal;
    cout << "Tujuan: "; cin >> tujuan;
    cout << "Tanggal: "; cin >> tanggal;
    searchJ_103032330131(L, asal, tujuan, tanggal);
    showJadwal_103032330131(L);


    return 0;
}
