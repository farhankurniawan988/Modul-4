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

    // Cetak linked list
    cout << "Isi Linked List: ";
    cetakList(head);

    return 0;
}