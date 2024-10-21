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


void cetakLinkedList(Node* head) {
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

int main() {
    Node* head = nullptr;

    
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    
    cout << "Isi linked list: ";
    cetakLinkedList(head);

    return 0;
}
