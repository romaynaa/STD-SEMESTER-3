#include <iostream>
using namespace std;

#define info(p) p->info
#define prev(p) p->prev
#define next(p) p->next
#define first(L) L.first
#define last(L) L.last

struct infotype {
    string Judul;
    string Penyanyi;
};

typedef struct elmList *address;

struct elmList {
    infotype info;
    address prev;
    address next;
};

struct List {
    address first;
    address last;
};

// Fungsi untuk membuat list kosong
void createList(List &L) {
    first(L) = nullptr;
    last(L) = nullptr;
}

// Fungsi untuk membuat elemen baru
address createNewElement(string judul, string penyanyi) {
    address p = new elmList;
    info(p).Judul = judul;
    info(p).Penyanyi = penyanyi;
    prev(p) = nullptr;
    next(p) = nullptr;
    return p;
}

// Fungsi untuk insert elemen di awal list (insert first)
void insertFirst(List &L, address p) {
    if (first(L) == nullptr) { // Jika list kosong
        first(L) = p;
        last(L) = p;
    } else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}

// Fungsi untuk insert elemen di akhir list (insert last)
void insertLast(List &L, address p) {
    if (first(L) == nullptr) { // Jika list kosong
        first(L) = p;
        last(L) = p;
    } else {
        prev(p) = last(L);
        next(last(L)) = p;
        last(L) = p;
    }
}

// Fungsi untuk mencetak list dari depan ke belakang (Ascending)
void printListAscending(const List &L) {
    address p = first(L);
    while (p != nullptr) {
        cout << "Judul: " << info(p).Judul << ", Penyanyi: " << info(p).Penyanyi << endl;
        p = next(p);
    }
}

// Fungsi untuk mencetak list dari belakang ke depan (Descending)
void printListDescending(const List &L) {
    address p = last(L);
    while (p != nullptr) {
        cout << "Judul: " << info(p).Judul << ", Penyanyi: " << info(p).Penyanyi << endl;
        p = prev(p);
    }
}

// Fungsi insert secara ascending dengan insertFirst dan insertLast
void insertAscending(List &L, address p) {
    if (first(L) == nullptr || info(p).Judul <= info(first(L)).Judul) {
        // Jika list kosong atau elemen lebih kecil dari elemen pertama
        insertFirst(L, p);
    } else if (info(p).Judul >= info(last(L)).Judul) {
        // Jika elemen lebih besar dari elemen terakhir
        insertLast(L, p);
    } else {
        // Sisipkan di tengah
        address q = first(L);
        while (info(next(q)).Judul < info(p).Judul) {
            q = next(q);
        }
        next(p) = next(q);
        prev(p) = q;
        prev(next(q)) = p;
        next(q) = p;
    }
}

// Fungsi insert secara descending dengan insertFirst dan insertLast
void insertDescending(List &L, address p) {
    if (first(L) == nullptr || info(p).Judul <= info(first(L)).Judul) {
        // Jika list kosong atau elemen lebih besar dari elemen pertama
        insertFirst(L, p);
    } else if (info(p).Judul >= info(last(L)).Judul) {
        // Jika elemen lebih kecil dari elemen terakhir
        insertLast(L, p);
    } else {
        // Sisipkan di tengah
        address q = first(L);
        while (info(next(q)).Judul < info(p).Judul) {  // Perbaikan: Menggunakan operator '>'
            q = next(q);
        }
        next(p) = next(q);
        prev(p) = q;
        prev(next(q)) = p;
        next(q) = p;
    }
}

int main() {
    List L;
    createList(L);

    // Menambah data secara ascending
    cout << "Menambah data secara ascending:" << endl;
    insertAscending(L, createNewElement("Song B", "Penyanyi B"));
    insertAscending(L, createNewElement("Song A", "Penyanyi A"));
    insertAscending(L, createNewElement("Song C", "Penyanyi C"));
    printListAscending(L);
    cout << endl;

    // Membuat list baru untuk descending
    createList(L);

    // Menambah data secara descending
    cout << "Menambah data secara descending:" << endl;
    insertDescending(L, createNewElement("Song B", "Penyanyi B"));
    insertDescending(L, createNewElement("Song A", "Penyanyi A"));
    insertDescending(L, createNewElement("Song C", "Penyanyi C"));
    printListDescending(L);

    return 0;
}
