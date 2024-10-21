#include <iostream>
using namespace std;

// Definisi struktur untuk Node dalam Linked List
struct Node {
    int data;       // Menyimpan nilai elemen
    Node* next;     // Pointer ke elemen berikutnya
};

// Fungsi untuk mengalokasikan memori untuk node baru
Node* createNode(int value) {
    Node* newNode = new Node;   // Alokasi memori untuk node baru
    newNode->data = value;      // Menyimpan nilai node
    newNode->next = nullptr;    // Set next menjadi nullptr
    return newNode;             // Mengembalikan pointer ke node baru
}

// Fungsi untuk menambah node di depan (di awal linked list)
void insertDepan(Node* &head, int value) {
    Node* newNode = createNode(value);  // Membuat node baru
    newNode->next = head;   // Node baru menunjuk ke node pertama sebelumnya
    head = newNode;         // Node baru menjadi node pertama
}

// Fungsi untuk menambah node di belakang (di akhir linked list)
void insertBelakang(Node* &head, int value) {
    Node* newNode = createNode(value); // Membuat node baru
    if (head == nullptr) {             // Jika linked list kosong
        head = newNode;                // Node baru menjadi node pertama
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Menelusuri sampai node terakhir
            temp = temp->next;
        }
        temp->next = newNode;          // Menambahkan node baru di akhir
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    if (head == nullptr) {             // Jika linked list kosong
        cout << "Linked List kosong!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {          // Menelusuri seluruh linked list
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";            // Cetak panah antara elemen
        }
        temp = temp->next;
    }
    cout << endl;                      // Baris baru setelah selesai mencetak
}

// Main Program
int main() {
    Node* head = nullptr;              // Inisialisasi linked list kosong (head = nullptr)

    // Input operasi pada linked list
    insertDepan(head, 10);             // Menambah node dengan nilai 10 di depan
    insertBelakang(head, 20);          // Menambah node dengan nilai 20 di belakang
    insertDepan(head, 5);              // Menambah node dengan nilai 5 di depan

    // Mencetak seluruh isi linked list
    cout << "Isi Linked List: ";
    printList(head);

    return 0;
}
