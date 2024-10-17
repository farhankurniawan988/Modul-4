#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertDepan(Node*& head, int nilai) {
    Node* newNode = new Node();
    newNode->data = nilai;
    newNode->next = head;
    head = newNode;
}

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

void hapusNode(Node*& head, int nilai) {
    if (head == nullptr) {
        cout << "Linked list kosong, tidak ada yang bisa dihapus." << endl;
        return;
    }

    if (head->data == nilai) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != nilai) {
        temp = temp->next;
    }

    if (temp->next != nullptr) {
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    } else {
        cout << "Node dengan nilai " << nilai << " tidak ditemukan." << endl;
    }
}

void cetakLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        temp = temp->next;
        if (temp != nullptr)
            cout << " -> ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    cout << "Linked list sebelum penghapusan: ";
    cetakLinkedList(head);

    hapusNode(head, 10);

    cout << "Linked list setelah penghapusan: ";
    cetakLinkedList(head);

    return 0;
}
