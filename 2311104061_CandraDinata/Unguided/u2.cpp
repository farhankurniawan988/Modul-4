#include <iostream>

using namespace std;

// Definisi Node untuk Single Linked List
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertDepan(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertBelakang(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }

    // Jika node yang akan dihapus adalah head
    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Mencari node yang memiliki nilai tertentu
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node tidak ditemukan
    if (temp == nullptr) {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan." << endl;
        return;
    }

    // Menghapus node
    prev->next = temp->next;
    delete temp;
}

// Fungsi untuk mencetak isi linked list
void cetakList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Inisialisasi linked list

    // Input contoh
    insertDepan(head, 10);  // Tambah node di depan dengan nilai 10
    insertBelakang(head, 20);  // Tambah node di belakang dengan nilai 20
    insertDepan(head, 5);  // Tambah node di depan dengan nilai 5

    cout << "Linked List sebelum penghapusan: ";
    cetakList(head);

    // Hapus node dengan nilai tertentu
    hapusNode(head, 10);  // Menghapus node dengan nilai 10

    // Cetak linked list setelah penghapusan
    cout << "Linked List setelah penghapusan: ";
    cetakList(head);

    return 0;
}