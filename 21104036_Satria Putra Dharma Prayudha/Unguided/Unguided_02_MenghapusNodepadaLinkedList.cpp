#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

// Fungsi untuk menambah node di depan
void insertDepan(int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertBelakang(int nilai) {
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

// Fungsi untuk menghapus node berdasarkan nilai tertentu
void hapusNode(int nilai) {
    Node* temp = head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == nilai) {
        head = temp->next;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    prev->next = temp->next;
    delete temp;
}

// Fungsi untuk mencetak linked list
void cetakList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);
    hapusNode(10);
    cetakList();
    
    return 0;
}
