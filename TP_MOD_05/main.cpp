#include <iostream>
#include "SLL.h"
using namespace std;

int main()
{
//    int digitNIMke9;
//    cin >> digitNIMke9;
//    cout << digitNIMke9 % 3;
   List L;
   address p, Q;
   createList_103032330131(L);
   int NUM = 0, pilihan = 0, x;
   infotype data;
   char response;

   pilihan = selectMenu_103032330131();
   while(pilihan != 0){
    switch(pilihan){
    case 1:
        cout << "Masukkan jumlah data: ";
        cin >> x;
        for(int i = 0; i < x; i++){
            cout << "Masukkan data baru: ";
            cin >> data;
            p = newElement_103032330131(data);
            insertLast_103032330131(L,p);
            }

        cout << "Kembali ke menu utama? (Y/N): ";
        cin >> response;
        if(response == 'Y'){
            break;
        }else{
            return 0;
        }
    case 2:
        showData_103032330131(L);

        cout << endl << "Kembali ke menu utama? (Y/N): ";

        cin >> response;

        if(response == 'Y'){
            break;
        }else{
            return 0;
        }

    case 3:
        p = findMin_103032330131(L);
        cout << endl << "Nilai minimum: " << info(p) << endl;

        cout << endl << "Kembali ke menu utama? (Y/N): ";
        cin >> response;
        if(response == 'Y'){
            break;
        }else{
            return 0;
        }

    case 4:
        cout << "Masukkan data baru yang akan ditambahkan ke tengah list: ";
        cin >> data;
        insertMiddle_103032330131(L, data);

        cout << endl << "Kembali ke menu utama? (Y/N): ";
        cin >> response;
        if(response == 'Y'){
            break;
            }else{
                return 0;
            }

        }
        pilihan = selectMenu_103032330131();
   }
   cout << "ANDA TELAH KELUAR DARI PROGRAM" << endl;
   return 0;
}
