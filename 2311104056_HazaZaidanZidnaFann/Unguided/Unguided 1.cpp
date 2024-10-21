#include <iostream>
using namespace std;

// Definisi struktur untuk elemen linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambah node di depan
void insertDepan(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertBelakang(Node* &head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
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

// Fungsi untuk mencetak seluruh isi linked list
void cetakList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Main function untuk Soal 1
int main() {
    Node* head = nullptr;
    
    // Menambahkan node ke linked list
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);
    
    // Mencetak isi linked list
    cout << "Isi Linked List: ";
    cetakList(head);
    
    return 0;
}
