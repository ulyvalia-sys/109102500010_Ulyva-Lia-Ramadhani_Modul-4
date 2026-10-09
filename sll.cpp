#include <iostream>
using namespace std;

// ===== DEFINISI TIPE DATA =====
typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

typedef ElmList* address;

struct List {
    address First;
};

// ===== IMPLEMENTASI FUNGSI =====

// Membuat list kosong
void createList(List &L) {
    L.First = NULL;
}

// Alokasi elemen baru
address alokasi(infotype x) {
    address P = new ElmList;
    if (P != NULL) {
        P->info = x;
        P->next = NULL;
    }
    return P;
}

// Dealokasi elemen
void dealokasi(address &P) {
    delete P;
    P = NULL;
}

// Cetak semua elemen
void printInfo(List L) {
    address P = L.First;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Sisipkan di posisi pertama
void insertFirst(List &L, address P) {
    if (P != NULL) {
        P->next = L.First;
        L.First = P;
    }
}

// ===== PROGRAM UTAMA =====
int main() {
    List L;
    address P1 = NULL, P2 = NULL, P3 = NULL, P4 = NULL, P5 = NULL;
    
    createList(L);
    
    P1 = alokasi(2);
    insertFirst(L, P1);
    
    P2 = alokasi(0);
    insertFirst(L, P2);
    
    P3 = alokasi(8);
    insertFirst(L, P3);
    
    P4 = alokasi(12);
    insertFirst(L, P4);
    
    P5 = alokasi(9);
    insertFirst(L, P5);
    
    printInfo(L);
    
    return 0;
}
