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

    bool cariNode(int nilai) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == nilai) return true;
            temp = temp->next;
        }
        return false;
    }

    int hitungPanjang() {
        int panjang = 0;
        Node* temp = head;
        while (temp != nullptr) {
            panjang++;
            temp = temp->next;
        }
        return panjang;
    }
};

int main() {
    LinkedList list;
    list.insertDepan(10);
    list.insertBelakang(20);
    list.insertDepan(5);

    if (list.cariNode(20)) {
        cout << "Node dengan nilai 20 ditemukan." << endl;
    } else {
        cout << "Node dengan nilai 20 tidak ditemukan." << endl;
    }

    cout << "Panjang linked list: " << list.hitungPanjang() << endl;
    return 0;
}
