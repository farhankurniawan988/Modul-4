#include <iostream>
using namespace std;

// Definisi struktur untuk elemen list
struct Node {
    int data;       // Menyimpan nilai elemen
    Node* next;     // Pointer ke elemen berikutnya
};

// Fungsi untuk mengalokasikan memori untuk node baru
Node* createNode(int value) {
    Node* newNode = new Node;  // Alokasi memori untuk elemen baru
    newNode->data = value;     // Mengisi data node
    newNode->next = nullptr;   // Set next ke nullptr
    return newNode;            // Mengembalikan pointer node baru
}

// Pengecekan apakah list kosong
bool isListEmpty(Node* head) {
    return head == nullptr;  // List kosong jika head adalah nullptr
}

// Menambahkan elemen di depan list
void insertAtFront(Node* &head, int value) {
    Node* newNode = createNode(value);  // Membuat node baru
    newNode->next = head;  // Hubungkan elemen baru ke elemen pertama
    head = newNode;        // Set elemen baru sebagai elemen pertama
}

// Menambahkan elemen di belakang list
void insertAtEnd(Node* &head, int value) {
    Node* newNode = createNode(value);  // Membuat node baru
    if (isListEmpty(head)) {  // Jika list kosong
        head = newNode;       // Elemen baru menjadi elemen pertama
    } else {
        Node* temp = head;
        while (temp->next != nullptr) { // Cari elemen terakhir
            temp = temp->next;
        }
        temp->next = newNode;  // Hubungkan elemen baru di akhir list
    }
}

// Menghapus node dengan nilai tertentu
void deleteNodeByValue(Node* &head, int value) {
    if (isListEmpty(head)) {  // Jika list kosong
        cout << "List kosong! Tidak ada yang bisa dihapus." << endl;
        return;
    }

    // Jika node yang ingin dihapus adalah node pertama
    if (head->data == value) {
        Node* temp = head;    // Simpan pointer ke node yang akan dihapus
        head = head->next;    // Pindahkan head ke node berikutnya
        delete temp;          // Dealokasi memori node yang dihapus
        return;
    }

    // Mencari node yang memiliki nilai yang akan dihapus
    Node* temp = head;
    Node* prev = nullptr;
    while (temp != nullptr && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node dengan nilai tersebut tidak ditemukan
    if (temp == nullptr) {
        cout << "Node dengan nilai " << value << " tidak ditemukan!" << endl;
        return;
    }

    // Hapus node dengan nilai yang ditemukan
    prev->next = temp->next;
    delete temp;  // Dealokasi memori node yang dihapus
}

// Menampilkan seluruh elemen dalam list
void printList(Node* head) {
    if (isListEmpty(head)) {
        cout << "List kosong!" << endl;
    } else {
        Node* temp = head;
        while (temp != nullptr) {       // Selama belum mencapai akhir list
            cout << temp->data;         // Tampilkan data elemen
            if (temp->next != nullptr)  // Tambahkan "->" jika masih ada elemen berikutnya
                cout << " -> ";
            temp = temp->next;          // Lanjut ke elemen berikutnya
        }
        cout << endl;
    }
}

int main() {
    Node* head = nullptr;  // Membuat list kosong
    
    // Input operasi
    insertAtFront(head, 10);   // Tambah node di depan (nilai: 10)
    insertAtEnd(head, 20);     // Tambah node di belakang (nilai: 20)
    insertAtFront(head, 5);    // Tambah node di depan (nilai: 5)
    
    // Cetak linked list sebelum penghapusan
    cout << "Isi Linked List: ";
    printList(head);  // Output: 5 -> 10 -> 20

    // Hapus node dengan nilai 10
    deleteNodeByValue(head, 10);

    // Cetak linked list setelah penghapusan
    cout << "Isi Linked List setelah penghapusan node dengan nilai 10: ";
    printList(head);  // Output: 5 -> 20

    return 0;
}
