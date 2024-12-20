#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    List L;
    address p;
    int x;

    creatList(L);
    cout << "Masukkan angka pertama"<< endl;
    cin >> x;
    p = allocate(x);
    insertFirst(L,p);
    printInfo(L);

    cout << "Masukkan angka kedua"<< endl;
    cin >> x;
    p = allocate(x);
    insertFirst(L,p);
    printInfo(L);

    cout << "Masukkan angka ketiga"<< endl;
    cin >> x;
    p = allocate(x);
    insertFirst(L,p);
    printInfo(L);
    return 0;
}
