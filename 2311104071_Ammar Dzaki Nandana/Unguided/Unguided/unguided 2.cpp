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

    void hapusNode(int nilai) {
        if (head == nullptr) { 
            return;
        }
        if (head->data == nilai) { 
            Node* temp = head;
            head = head->next; 
            delete temp; 
            return;
        }
        Node* current = head; 
        Node* previous = nullptr; 
        while (current != nullptr && current->data != nilai) { 
            previous = current; 
            current = current->next; 
        }
        if (current != nullptr) { 
            previous->next = current->next; 
            delete current; 
        }
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

    cout << "Linked List sebelum penghapusan: ";
    linkedList.cetakList(); 

    linkedList.hapusNode(10); 

    cout << "Linked List setelah penghapusan nilai 10: ";
    linkedList.cetakList(); 

    return 0; 
}
