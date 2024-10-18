////Membuat SLL
//#include <iostream>
//using namespace std;
//
//// Definisi struktur untuk elemen linked list
//struct Node {
//    int data;
//    Node* next;
//};
//
//// Fungsi untuk menambah node di depan
//void insertDepan(Node* &head, int value) {
//    Node* newNode = new Node;
//    newNode->data = value;
//    newNode->next = head;
//    head = newNode;
//}
//
//// Fungsi untuk menambah node di belakang
//void insertBelakang(Node* &head, int value) {
//    Node* newNode = new Node;
//    newNode->data = value;
//    newNode->next = nullptr;
//    if (head == nullptr) {
//        head = newNode;
//    } else {
//        Node* temp = head;
//        while (temp->next != nullptr) {
//            temp = temp->next;
//        }
//        temp->next = newNode;
//    }
//}
//
//// Fungsi untuk mencetak seluruh isi linked list
//void cetakList(Node* head) {
//    Node* temp = head;
//    while (temp != nullptr) {
//        cout << temp->data;
//        if (temp->next != nullptr) {
//            cout << " -> ";
//        }
//        temp = temp->next;
//    }
//    cout << endl;
//}
//
//// Main function untuk Soal 1
//int main() {
//    Node* head = nullptr;
//
//    // Menambahkan node ke linked list
//    insertDepan(head, 10);
//    insertBelakang(head, 20);
//    insertDepan(head, 5);
//
//    // Mencetak isi linked list
//    cout << "Isi Linked List: ";
//    cetakList(head);
//
//    return 0;
//}

////Menghapus Node pada Linked List
//#include <iostream>
//using namespace std;
//
//// Struktur Node untuk linked list
//struct Node {
//    int data;
//    Node* next;
//};
//
//// Fungsi untuk menambahkan node di depan
//void insertDepan(Node*& head, int value) {
//    Node* newNode = new Node;
//    newNode->data = value;
//    newNode->next = head;
//    head = newNode;
//}
//
//// Fungsi untuk menambahkan node di belakang
//void insertBelakang(Node*& head, int value) {
//    Node* newNode = new Node;
//    newNode->data = value;
//    newNode->next = nullptr;
//
//    if (head == nullptr) {
//        head = newNode; // Jika list kosong, node baru menjadi head
//    } else {
//        Node* current = head;
//        while (current->next != nullptr) {
//            current = current->next; // Mencari node terakhir
//        }
//        current->next = newNode; // Menambahkan node baru di akhir list
//    }
//}
//
//// Fungsi untuk mencetak isi linked list
//void cetakList(Node* head) {
//    Node* current = head;
//    while (current != nullptr) {
//        cout << current->data << " ";
//        current = current->next;
//    }
//    cout << endl;
//}
//
//// Fungsi untuk menghapus node dengan nilai tertentu
//void hapusNode(Node*& head, int value) {
//    if (head == nullptr) {
//        cout << "List kosong!" << endl;
//        return;
//    }
//
//    // Menghapus node pertama jika sesuai
//    if (head->data == value) {
//        Node* temp = head;
//        head = head->next;
//        delete temp;
//        return;
//    }
//
//    // Mencari node yang sesuai dan menghapusnya
//    Node* current = head;
//    while (current->next != nullptr && current->next->data != value) {
//        current = current->next;
//    }
//
//    if (current->next == nullptr) {
//        cout << "Node dengan nilai " << value << " tidak ditemukan!" << endl;
//    } else {
//        Node* temp = current->next;
//        current->next = temp->next;
//        delete temp;
//    }
//}
//
//int main() {
//    Node* head = nullptr;
//
//    // Menambahkan node ke linked list
//    insertDepan(head, 10);
//    insertBelakang(head, 20);
//    insertDepan(head, 5);
//
//    // Mencetak isi linked list sebelum penghapusan
//    cout << "Isi Linked List sebelum penghapusan: ";
//    cetakList(head);
//
//    // Menghapus node dengan nilai tertentu
//    hapusNode(head, 10);
//
//    // Mencetak isi linked list setelah penghapusan
//    cout << "Isi Linked List setelah penghapusan: ";
//    cetakList(head);
//
//    return 0;
//}/

//Mencari dan Menghitung Panjang Linked list
#include <iostream>
using namespace std;

// Struktur Node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di depan
void insertDepan(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambahkan node di belakang
void insertBelakang(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; // Jika list kosong, node baru menjadi head
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; // Mencari node terakhir
        }
        current->next = newNode; // Menambahkan node baru di akhir list
    }
}

// Fungsi untuk mencetak isi linked list
void cetakList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk mencari node dengan nilai tertentu
bool cariNode(Node* head, int value) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == value) {
            return true; // Nilai ditemukan
        }
        current = current->next; // Melanjutkan ke node berikutnya
    }
    return false; // Nilai tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int hitungPanjang(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++; // Menambah jumlah node
        current = current->next; // Melanjutkan ke node berikutnya
    }
    return count; // Mengembalikan jumlah node
}

int main() {
    Node* head = nullptr;

    // Menambahkan node ke linked list
    insertDepan(head, 10);
    insertBelakang(head, 20);
    insertDepan(head, 5);

    // Mencetak isi linked list
    cout << "Isi Linked List: ";
    cetakList(head);

    // Mencari node dengan nilai tertentu
    int nilaiDicari = 20;
    if (cariNode(head, nilaiDicari)) {
        cout << "Node dengan nilai " << nilaiDicari << " ditemukan." << endl;
    } else {
        cout << "Node dengan nilai " << nilaiDicari << " tidak ditemukan." << endl;
    }

    // Menghitung dan mencetak panjang linked list
    int panjang = hitungPanjang(head);
    cout << "Panjang linked list: " << panjang << endl;

    return 0;
}
