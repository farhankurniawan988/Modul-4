#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertFront(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = *head;
    *head = newNode;
}

void insertBack(Node** head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(Node** head, int value) {
    Node* temp = *head;
    Node* prev = nullptr;

    if (temp != nullptr && temp->data == value) {
        *head = temp->next; 
        delete temp; 
        return;
    }

    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) return;

    prev->next = temp->next;

    delete temp; 
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data ;
        if (temp->next != nullptr) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    
}


int main() {
    Node* head = nullptr;

    insertFront(&head, 10);
    insertBack(&head, 20);
    insertFront(&head, 5);
    
    cout << "Linked List before deletion: ";
    printList(head);

    deleteNode(&head, 10);
    
    cout << " Linked List after deletion: ";
    printList(head);

    return 0;
}