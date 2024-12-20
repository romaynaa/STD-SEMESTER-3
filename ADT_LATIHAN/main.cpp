#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct mahasiswa{
    char nim[10];
    int nilai1, nilai2;
};


int main()
{
   mahasiswa mhs;
   inputMhs(mhs);
   cout << "Rata-rata = "<<rata2(mhs);
   return 0;
}
void inputMhs(mahasiswa &m){
    cout << "Input nama = ";
    cin >> (m).nim;
    cout << "Input nilai 1 = ";
    cin >> (m).nilai1;
    cout << "Input nilai 2 = ";
    cin >> (m).nilai2;
}
float rata2(mahasiswa m){
    return (m.nilai1 + m.nilai2)/2;
}
