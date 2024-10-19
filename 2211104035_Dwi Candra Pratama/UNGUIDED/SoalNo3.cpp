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
    LinkedList() {
        head = NULL;
    }

    void insertDepan(int nilai) {
        Node* newNode = new Node();
        newNode->data = nilai;
        newNode->next = head;
        head = newNode;
    }

    void insertBelakang(int nilai) {
        Node* newNode = new Node();
        newNode->data = nilai;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    bool cariNode(int nilai) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == nilai)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int hitungPanjang() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    LinkedList list;
    int nilai;
    
    cout << "1. Tambah node di depan ";
    cin >> nilai;
    list.insertDepan(nilai);
    
    cout << "2. Tambah node di belakang ";
    cin >> nilai;
    list.insertBelakang(nilai);
    
    cout << "3. Tambah node di depan ";
    cin >> nilai;
    list.insertDepan(nilai);
    
    cout << "4. Cari node dengan nilai ";
    cin >> nilai;
    if (list.cariNode(nilai)) {
        cout << "Node dengan nilai " << nilai << " ditemukan." << endl;
    }
    
    cout << "5. Cetak panjang linked list" << endl;
    cout << "Panjang linked list: " << list.hitungPanjang() << endl;

    return 0;
}