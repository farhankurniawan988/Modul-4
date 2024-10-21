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

// Fungsi untuk menghapus node dengan nilai tertentu
void hapusNode(Node*& head, int value) {
    if (head == nullptr) {
        cout << "List kosong!" << endl;
        return;
    }

    // Menghapus node pertama jika sesuai
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Mencari node yang sesuai dan menghapusnya
    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Node dengan nilai " << value << " tidak ditemukan!" << endl;
    } else {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;

    // Menambahkan node ke linked list
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    // Mencetak isi linked list sebelum penghapusan
    cout << "Isi Linked List sebelum penghapusan: ";
    cetakList(head);

    // Menghapus node dengan nilai tertentu
    hapusNode(head, 10);

    // Mencetak isi linked list setelah penghapusan
    cout << "Isi Linked List setelah penghapusan: ";
    cetakList(head);

    return 0;
}
