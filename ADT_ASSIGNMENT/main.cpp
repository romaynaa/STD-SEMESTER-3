#include <iostream>
#include <cmath> // Untuk fungsi sqrt dan M_PI
using namespace std;

// Deklarasi infotype
struct Cone {
    float radius;
    float height;

    // Fungsi untuk menghitung volume
    float volume() {
        return (1.0 / 3.0) * M_PI * radius * radius * height;
    }

    // Fungsi untuk menghitung luas permukaan
    float surfaceArea() {
        float slantHeight = sqrt(radius * radius + height * height);
        return M_PI * radius * (radius + slantHeight);
    }
};

// Deklarasi node untuk list
struct Node {
    Cone data; // Data kerucut
    Node* next; // Pointer ke node berikutnya
};

// Deklarasi list
struct List {
    Node* head; // Pointer ke node pertama
    Node* tail; // Pointer ke node terakhir

    List() : head(NULL), tail(NULL) {} // Konstruktor
};

// Fungsi untuk menambahkan kerucut baru ke dalam list
void addCone(List& lst, double r, double h) {
    Node* newNode = new Node;
    newNode->data.radius = r;
    newNode->data.height = h;
    newNode->next = NULL;

    if (lst.head == NULL) {
        lst.head = newNode; // Jika list kosong
        lst.tail = newNode;
    } else {
        lst.tail->next = newNode; // Tambahkan ke akhir list
        lst.tail = newNode;
    }
}

// Fungsi untuk menampilkan semua kerucut dalam list
void displayCones(const List& lst) {
    Node* current = lst.head;
    while (current != NULL) {
        cout << "Radius: " << current->data.radius
             << ", Height: " << current->data.height
             << ", Volume: " << current->data.volume()
             << ", Surface Area: " << current->data.surfaceArea()
             << endl;
        current = current->next;
    }
}

int main() {
    List myList;

    // Menambahkan beberapa kerucut
    addCone(myList, 6.0, 20.0);
    addCone(myList, 8.0, 7.0);
    addCone(myList, 5, 7.8);

    // Menampilkan kerucut dalam list
    displayCones(myList);

    return 0;
}
