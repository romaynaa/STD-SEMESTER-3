#include <iostream>
#include <string>

using namespace std;

struct Buku {
    string Judul;
    string Penulis;
};

const int idxMax = 12;

struct RakBuku {
    Buku Data[idxMax];
    int Top;
};

void InitStack(RakBuku &S) {
    S.Top = 0; 
}

bool isEmpty(const RakBuku &S) {
    return S.Top == 0;
}

void Get(RakBuku &S, const string &judul, string &namaPenulis) {
    RakBuku tempStack;
    InitStack(tempStack); 
    bool found = false;

    while (!isEmpty(S) && !found) {
        Buku currentBuku = S.Data[S.Top - 1]; 

        tempStack.Data[tempStack.Top] = currentBuku;
        tempStack.Top++;
        S.Top--;

        if (currentBuku.Judul == judul) {
            found = true;
            namaPenulis = currentBuku.Penulis; 
        }
    }
   
    while (!isEmpty(tempStack)) {
        S.Data[S.Top] = tempStack.Data[tempStack.Top - 1];
        S.Top++;
        tempStack.Top--;
    }

    if (!found) {
        namaPenulis = "Buku tidak ditemukan";
    }
}

int main() {
    RakBuku rak;
    InitStack(rak);

    
    rak.Data[rak.Top++] = {"C++ Programming", "Bjarne Stroustrup"};
    rak.Data[rak.Top++] = {"Clean Code", "Robert C. Martin"};
    rak.Data[rak.Top++] = {"The Pragmatic Programmer", "Andrew Hunt"};

    string penulis;
    Get(rak, "Clean Code", penulis);
    cout << "Penulis buku 'Clean Code': " << penulis << endl;

    Get(rak, "Unknown Book", penulis);
    cout << "Penulis buku 'Unknown Book': " << penulis << endl;

    return 0;
}
