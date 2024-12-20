#include <iostream>
#include "SLL.h"

using namespace std;

int main()
{
    List jau;
    string nTeam_jau, kode_jau;
    int skor_jau;
    infotype x_jau;
    adr p_jau;

   createList(jau);
   cout << "Masukkan nama tim pertama: "<< endl;
   cin >> nTeam_jau;
   cout << "Masukkan kode pertandingan pertama: "<< endl;
   cin >> kode_jau;
   cout << "Masukkan total skor tim pertama: "<< endl;
   cin >> skor_jau;

   x_jau.namaTim = nTeam_jau;
   x_jau.kodeTanding = kode_jau;
   x_jau.skor = skor_jau;

   p_jau = newElment(x_jau);
   insertFirst(jau,p_jau);
   cout << "Masukkan nama tim kedua: "<< endl;
   cin >> nTeam_jau;
   cout << "Masukkan kode pertandingan kedua: "<< endl;
   cin >> kode_jau;
   cout << "Masukkan total skor tim kedua: "<< endl;
   cin >> skor_jau;

   x_jau.namaTim = nTeam_jau;
   x_jau.kodeTanding = kode_jau;
   x_jau.skor = skor_jau;

   p_jau = newElment(x_jau);
   insertLast(jau,p_jau);
   cout << "Masukkan nama tim ketiga: "<< endl;
   cin >> nTeam_jau;
   cout << "Masukkan kode pertandingan ketiga: "<< endl;
   cin >> kode_jau;
   cout << "Masukkan total skor tim ketiga: "<< endl;
   cin >> skor_jau;

   x_jau.namaTim = nTeam_jau;
   x_jau.kodeTanding = kode_jau;
   x_jau.skor = skor_jau;

   p_jau = newElment(x_jau);
   insertFirst(jau,p_jau);
   cout << "Masukkan nama tim keempat: "<< endl;
   cin >> nTeam_jau;
   cout << "Masukkan kode pertandingan keempat: "<< endl;
   cin >> kode_jau;
   cout << "Masukkan total skor tim keempat: "<< endl;
   cin >> skor_jau;

   x_jau.namaTim = nTeam_jau;
   x_jau.kodeTanding = kode_jau;
   x_jau.skor = skor_jau;

   p_jau = newElment(x_jau);
   insertLast(jau, p_jau);

   show(jau);

   deleteFirst(jau,p_jau);
   cout << "Tampilan setelah data pertama dihapus: "<< endl;
   show(jau);

   deleteLast(jau,p_jau);
   cout << "Tampilan setelah data terakhir dihapus: "<< endl;
   show(jau);

   return 0;
}
