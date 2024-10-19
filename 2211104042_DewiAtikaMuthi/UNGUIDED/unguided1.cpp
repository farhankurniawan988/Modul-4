#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insertDepan(int nilai) {
        Node* newNode = new Node{nilai, head};
        head = newNode;
    }

    void insertBelakang(int nilai) {
        Node* newNode = new Node{nilai, nullptr};
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void cetakList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    list.insertDepan(10);
    list.insertBelakang(20);
    list.insertDepan(5);
    list.cetakList();
    return 0;
}
