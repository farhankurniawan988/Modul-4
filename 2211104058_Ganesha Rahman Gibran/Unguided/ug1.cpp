#include <iostream>

using namespace std;

// Deklarasi struktur elemen linked list
struct Node {
    int data;        // Data yang disimpan di node
    Node* next;     // Pointer ke node berikutnya
};

// Fungsi untuk menambahkan node di depan linked list
void insertAtFront(Node*& head, int value) {
    Node* newNode = new Node(); // Alokasikan memori untuk node baru
    newNode->data = value;      // Set data
    newNode->next = head;       // Hubungkan node baru dengan head yang ada
    head = newNode;             // Pindahkan head ke node baru
}

// Fungsi untuk menambahkan node di belakang linked list
void insertAtBack(Node*& head, int value) {
    Node* newNode = new Node(); // Alokasikan memori untuk node baru
    newNode->data = value;      // Set data
    newNode->next = nullptr;    // Node baru akan menjadi node terakhir

    if (head == nullptr) {       // Jika list kosong, node baru menjadi head
        head = newNode;
    } else {
        Node* temp = head;       // Temp untuk menelusuri list
        while (temp->next != nullptr) { // Menelusuri hingga akhir list
            temp = temp->next;
        }
        temp->next = newNode;    // Hubungkan node terakhir dengan node baru
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    Node* temp = head;           // Temp untuk menelusuri list
    while (temp != nullptr) {    // Selama belum mencapai akhir list
        cout << temp->data;      // Cetak data node
        if (temp->next != nullptr) {
            cout << " -> ";      // Cetak panah jika bukan node terakhir
        }
        temp = temp->next;       // Pindah ke node berikutnya
    }
    cout << endl;                // Cetak newline setelah selesai
}

int main() {
    Node* head = nullptr;         // Inisialisasi head linked list

    // Contoh operasi
    insertAtFront(head, 10);      // Tambah node di depan (nilai: 10)
    insertAtBack(head, 20);        // Tambah node di belakang (nilai: 20)
    insertAtFront(head, 5);        // Tambah node di depan (nilai: 5)

    // Cetak linked list
    cout << "Linked List: ";
    printList(head);              // Menampilkan isi linked list

    return 0;
}
