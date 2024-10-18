#include <iostream>

using namespace std;

struct Node {
    int data;      
    Node* next;  

    Node(int nilai) {
        data = nilai; 
        next = nullptr; 
    }
};

class SingleLinkedList {
private:
    Node* head; 

public:
    SingleLinkedList() {
        head = nullptr; 
    }

    void tambahNodeDiDepan(int nilai) {
        Node* nodeBaru = new Node(nilai);
        nodeBaru->next = head; 
        head = nodeBaru; 
    }

    void tambahNodeDiBelakang(int nilai) {
        Node* nodeBaru = new Node(nilai);
        if (head == nullptr) { 
            head = nodeBaru; 
            return;
        }
        Node* temp = head; 
        while (temp->next != nullptr) { 
            temp = temp->next; 
        }
        temp->next = nodeBaru; 
    }

    bool cariNode(int nilai) {
        Node* temp = head; 
        while (temp != nullptr) { 
            if (temp->data == nilai) { 
                return true; 
            }
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

    void cetakList() {
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

    ~SingleLinkedList() {
        Node* current = head; 
        Node* nextNode; 
        while (current != nullptr) { 
            nextNode = current->next;
            delete current; 
            current = nextNode; 
        }
    }
};

int main() {
    SingleLinkedList linkedList; 

    linkedList.tambahNodeDiDepan(10); 
    linkedList.tambahNodeDiBelakang(20); 
    linkedList.tambahNodeDiDepan(5); 

    cout << "Linked List: ";
    linkedList.cetakList(); 

    int nilaiDicari = 20;
    if (linkedList.cariNode(nilaiDicari)) {
        cout << "Node dengan nilai " << nilaiDicari << " ditemukan." << endl; 
    } else {
        cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << endl; 
    }

    int panjang = linkedList.hitungPanjang(); 
    cout << "Panjang linked list: " << panjang << endl; 

    return 0; 
}
