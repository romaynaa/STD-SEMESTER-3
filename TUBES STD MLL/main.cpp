#include <iostream>
#include "mll.h"
using namespace std;

int main()
{
    List_Maskapai LM;
    List_Rute LR;
    infotypeMaskapai Maskapai;
    infotypeRute rutePenerbangan;
    adr_Maskapai m;
    adr_relasi rl;
    adr_Rute r;

    createListMaskapai(LM);
    createListRute(LR);


    int pilihan;
    do{
        cout << "========== SISTEM MANAJEMEN PENERBANGAN ==========" << endl;
        cout << "1. Tambah Maskapai" << endl;
        cout << "2. Tambah Rute Penerbangan" << endl;
        cout << "3. Menghubungkan Maskapai dengan Rute Penerbangan" << endl;
        cout << "4. Hapus Maskapai" << endl;
        cout << "5. Hapus Rute" << endl;
        cout << "6. Tampilkan Semua Maskapai" << endl;
        cout << "7. Tampilkan Semua Rute Penerbangan" << endl;
        cout << "8. Tampilkan Rute dari Maskapai" << endl;
        cout << "9. Tampilkan Maskapai dari Rute Penerbangan" << endl;
        cout << "10. Tampilkan Semua Maskapai dan Rute Penerbangan" << endl;
        cout << "11. Tampilkan Semua Relasi Penerbangan" << endl;
        cout << "12. Hitung Relasi Maskapai" << endl;
        cout << "13. Hitung Relasi Rute Penerbangan" << endl;
        cout << "14. Hitung Rute Penerbangan yang Tidak Berelasi" << endl;
        cout << "15. Edit Rute Penerbangan dari Maskapai" << endl;
        cout << "16. Hapus Relasi Maskapai dari Rute" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        if(pilihan == 1){
            cout << endl << "Masukkan Nama Maskapai: ";
            cin >> Maskapai.namaMaskapai;
            cout << "Masukkan Kode Maskapai: ";
            cin >> Maskapai.kodeMaskapai;
            cout << "Masukkan Kelas Maskapai: ";
            cin >> Maskapai.kelasMaskapai;
            cout << "Masukkan Kapasitas Penumpang: ";
            cin >> Maskapai.kapasitasPenumpang;
            insertMaskapai(LM, createElmMaskapai(Maskapai));
        }else if(pilihan == 2){
            cout << endl << "Masukkan Kota Asal: ";
            cin >> rutePenerbangan.kota_asal;
            cout << "Masukkan Kota Tujuan: ";
            cin >> rutePenerbangan.kota_tujuan;
            cout << "Masukkan Kode Penerbangan: ";
            cin >> rutePenerbangan.kode_penerbangan;
            cout << "Masukkan Jumlah Penumpang: ";
            cin >> rutePenerbangan.jumlah_penumpang;
            insertRute(LR, newElementRute(rutePenerbangan));
        }else if(pilihan == 3){
            string kodeMaskapai, kodeRute;
            cout << "Masukkan Kode Maskapai: ";
            cin >> kodeMaskapai;
            cout << "Masukkan Kode Rute: ";
            cin >> kodeRute;

        adr_Maskapai m = findMaskapai(LM, kodeMaskapai);
        if (m == NULL) {
            cout << "Maskapai dengan kode " << kodeMaskapai << " tidak ditemukan." << endl;
        } else {
            adr_Rute r = findRute(LR, kodeRute);
            if (r == NULL) {
                cout << "Rute dengan kode " << kodeRute << " tidak ditemukan." << endl;
            } else {
                insertRelation(m, r);
                cout << "Relasi berhasil ditambahkan!" << endl;
            }
        }
        }else if(pilihan == 4){
            string kodeMaskapai;
            cout << "Masukkan kode maskapai yang mau dihapus: ";
            cin >> kodeMaskapai;
            m = findMaskapai(LM, kodeMaskapai);
            deleteMaskapai(LM, m);
            cout << "Maskapai dengan kode " << kodeMaskapai << " berhasil dihapus!" << endl;
        }else if(pilihan == 5){
            string kodeRute;
            cout << "Masukkan Kode Rute: ";
            cin >> kodeRute;
            r = findRute(LR, kodeRute);
            delete_Rute(LR, r);
            cout << "Rute dengan kode " << kodeRute << " berhasil dihapus!" << endl;
        }else if(pilihan == 6){
            cout << "Data Maskapai Penerbangan: " << endl;
            showMaskapai(LM);
        }else if(pilihan == 7){
            cout << "Data Rute Penerbangan: " << endl;
            showRute(LR);
        }else if(pilihan == 8){
            string kodeMaskapai;
            cout << "Masukkan Kode Maskapai: ";
            cin >> kodeMaskapai;
            m = findMaskapai(LM, kodeMaskapai);
            if(m != NULL){
                show_RutefromMaskapai(m);
            }else{
                cout << "Maskapai tidak ditemukan!" << endl;
            }
        }else if(pilihan == 9){
            string kodeRute;
            cout << "Masukkan Kode Rute: ";
            cin >> kodeRute;

            adr_Rute r = findRute(LR, kodeRute);
            if (r != NULL) {
                show_MaskapaifromRute(LM, r);
            } else {
                cout << "Rute tidak ditemukan." << endl;
            }
        }else if(pilihan == 10){
            cout << "Data Maskapai dan Rute Penerbangan: " << endl;
            show_MaskapaiAndRute(LM, LR);
        }else if(pilihan == 11){
            string kodeMaskapai;
            cout << "Masukkan kode maskapai: ";
            cin >> kodeMaskapai;
            showAll_RelasiRutePenerbangan(LM, LR, kodeMaskapai);
        }else if(pilihan == 12){
            string kodeMaskapai;
            cout << "Masukkan kode maskapai: ";
            cin >> kodeMaskapai;
            m = findMaskapai(LM, kodeMaskapai);
            if(m != NULL){
                countRelationMaskapai(LM, m);
            }else{
                cout << "Maskapai tidak ditemukan." << endl;
            }
        }else if(pilihan == 13){
            string kodeRute;
            cout << "Masukkan kode rute: ";
            cin >> kodeRute;
            r = findRute(LR, kodeRute);
            if(r != NULL){
                countRelationRute(LM, r);
            }else{
                cout << "Rute tidak ditemukan." << endl;
            }
        }else if(pilihan == 14){
            int count = count_RuteDontHaveRelasi(LM,LR);
            cout << "Jumlah rute yang tidak memiliki relasi: " << count << endl;
        }else if(pilihan == 15){
            string kodeMaskapai, kodeRute;
            cout << "Masukkan kode maskapai: ";
            cin >> kodeMaskapai;
            cout << "Masukkan kode rute: ";
            cin >> kodeRute;
            edit_RuteFromMaskapai(LM, LR, kodeMaskapai, kodeRute);
        }else if(pilihan == 16){
            string kodeMaskapai, kodeRute;
            cout << "Masukkan kode maskapai: ";
            cin >> kodeMaskapai;
            cout << "Masukkan kode rute: ";
            cin >> kodeRute;
            m = findMaskapai(LM, kodeMaskapai);
            r = findRute(LR, kodeRute);
            if(m != NULL && r != NULL){
                rl = findRelation(m, r);
                if(rl != NULL){
                    deleteRelation(m, r);
                    cout << "Relasi berhasil dihapus." << endl;
                }else{
                    cout << "Relasi tidak ditemukan." << endl;
                }
            }else{
                cout << "Maskapai atau relasi tidak ditemukan." << endl;
            }
        }else if(pilihan == 0){
            cout << "Keluar dari program." << endl;
        }else{
            cout << "Pilihan tidak valis!" << endl;
        }
    }while(pilihan != 0);
    return 0;
}
