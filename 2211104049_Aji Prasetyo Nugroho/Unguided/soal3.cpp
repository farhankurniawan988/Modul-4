#include <iostream>
using namespace std;

// Definisi struktur untuk elemen list
struct Node {
    int data;       // Menyimpan nilai elemen
    Node* next;     // Pointer ke elemen berikutnya
};

// Fungsi untuk mengalokasikan memori untuk node baru
Node* createNode(int value) {
    Node* newNode = new Node;  // Alokasi memori untuk elemen baru
    newNode->data = value;     // Mengisi data node
    newNode->next = nullptr;   // Set next ke nullptr
    return newNode;            // Mengembalikan pointer node baru
}

// Pengecekan apakah list kosong
bool isListEmpty(Node* head) {
    return head == nullptr;  // List kosong jika head adalah nullptr
}

// Menambahkan elemen di depan list
void insertAtFront(Node* &head, int value) {
    Node* newNode = createNode(value);  // Membuat node baru
    newNode->next = head;  // Hubungkan elemen baru ke elemen pertama
    head = newNode;        // Set elemen baru sebagai elemen pertama
}

// Menambahkan elemen di belakang list
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);  // Membuat node baru
    if (isListEmpty(head)) {  // Jika list kosong
        head = newNode;       // Elemen baru menjadi elemen pertama
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Cari elemen terakhir
            temp = temp->next;
        }
        temp->next = newNode;  // Hubungkan elemen baru di akhir list
    }
}

// Fungsi untuk mencari apakah node dengan nilai tertentu ada di linked list
bool searchNode(Node* head, int value) {
    Node* temp = head;
    while (temp != nullptr) {  // Selama belum mencapai akhir list
        if (temp->data == value) {  // Jika nilai ditemukan
            return true;
        }
        temp = temp->next;  // Lanjut ke node berikutnya
    }
    return false;  // Nilai tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {  // Selama belum mencapai akhir list
        count++;  // Tambah jumlah node
        temp = temp->next;  // Lanjut ke node berikutnya
    }
    return count;  // Mengembalikan jumlah node
}

// Menampilkan seluruh elemen dalam list
void printList(Node* head) {
    if (isListEmpty(head)) {
        cout << "List kosong!" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {       // Selama belum mencapai akhir list
            cout << temp->data;         // Tampilkan data elemen
            if (temp->next != nullptr)  // Tambahkan "->" jika masih ada elemen berikutnya
                cout << " -> ";
            temp = temp->next;          // Lanjut ke elemen berikutnya
        }
        cout << endl;
    }
}

int main() {
    Node* head = nullptr;  // Membuat list kosong
    
    // Input operasi
    insertAtFront(head, 10);   // Tambah node di depan (nilai: 10)
    insertAtEnd(head, 20);     // Tambah node di belakang (nilai: 20)
    insertAtFront(head, 5);    // Tambah node di depan (nilai: 5)
    
    // Cetak linked list
    cout << "Isi Linked List: ";
    printList(head);  // Output: 5 -> 10 -> 20

    // Cari node dengan nilai 20
    int valueToSearch = 20;
    if (searchNode(head, valueToSearch)) {
        cout << "Node dengan nilai " << valueToSearch << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << valueToSearch << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = countNodes(head);
    cout << "Panjang linked list: " << length << endl;  // Output: 3

    return 0;
}
