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

    void hapusNode(int nilai) {
        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == nilai) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != NULL && temp->data != nilai) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) return;

        prev->next = temp->next;
        delete temp;
    }

    void cetakList() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int nilai;

    cout << "1. Tambah node di depan ,nilai: ";
    cin >> nilai;
    list.insertDepan(nilai);

    cout << "2. Tambah node di belakang ,nilai: ";
    cin >> nilai;
    list.insertBelakang(nilai);

    cout << "3. Tambah node di depan ,nilai: ";
    cin >> nilai;
    list.insertDepan(nilai);

    cout << "4. Hapus node dengan nilai ,nilai: ";
    cin >> nilai;
    list.hapusNode(nilai);

    cout << "5. Cetak linked list" << endl;
    list.cetakList();

    return 0;
}