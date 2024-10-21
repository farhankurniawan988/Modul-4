#include <iostream>
using namespace std;

// Struktur Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di depan
void insertDepan(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambahkan node di belakang
void insertBelakang(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode; // Jika list kosong, node baru menjadi head
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Mencari node terakhir
        }
        current->next = newNode; // Menambahkan node baru di akhir list
    }
}

// Fungsi untuk mencetak isi linked list
void cetakList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Nilai ditemukan
        }
        current = current->next; // Melanjutkan ke node berikutnya
    }
    return false; // Nilai tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++; // Menambah jumlah node
        current = current->next; // Melanjutkan ke node berikutnya
    }
    return count; // Mengembalikan jumlah node
}

int main() {
    Node* head = nullptr;

    // Menambahkan node ke linked list
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    // Mencetak isi linked list
    cout << "Isi Linked List: ";
    cetakList(head);

    // Mencari node dengan nilai tertentu
    int nilaiDicari = 20;
    if (cariNode(head, nilaiDicari)) {
        cout << "Node dengan nilai " << nilaiDicari << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << endl;
    }

    // Menghitung dan mencetak panjang linked list
    int panjang = hitungPanjang(head);
    cout << "Panjang linked list: " << panjang << endl;

    return 0;
}
