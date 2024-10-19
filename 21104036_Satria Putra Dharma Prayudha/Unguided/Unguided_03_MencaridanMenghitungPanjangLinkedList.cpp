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

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(int nilai) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == nilai) return true;
        temp = temp->next;
    }
    return false;
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    insertDepan(10);
    insertBelakang(20);
    insertDepan(5);

    if (cariNode(20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }

    cout << "Panjang linked list: " << hitungPanjang() << endl;

    return 0;
}
