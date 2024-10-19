#include <iostream>

using namespace std;

// Definisi struktur node
struct Node
{
    int data;
    Node *next;
};

// Fungsi untuk membuat node baru
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambah node di depan
void insertAtFront(Node *&head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

// Fungsi untuk menambah node di belakang
void insertAtEnd(Node *&head, int value)
{
    Node *newNode = createNode(value);
    if (head == nullptr)
    {
        head = newNode; // Jika linked list kosong
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menghapus node dengan nilai tertentu
void deleteNode(Node *&head, int value)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong, tidak ada yang dapat dihapus." << endl;
        return;
    }

    // Jika node pertama yang memiliki nilai tersebut
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Node dengan nilai " << value << " berhasil dihapus." << endl;
        return;
    }

    // Mencari node yang memiliki nilai tersebut
    Node *temp = head;
    while (temp->next != nullptr && temp->next->data != value)
    {
        temp = temp->next;
    }

    // Jika node ditemukan
    if (temp->next != nullptr)
    {
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        cout << "Node dengan nilai " << value << " berhasil dihapus." << endl;
    }
    else
    {
        cout << "Node dengan nilai " << value << " tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencetak seluruh isi linked list
void printList(Node *head)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong." << endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
        {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi utama
int main()
{
    Node *head = nullptr; // Inisialisasi linked list kosong

    // Contoh penggunaan fungsi
    insertAtFront(head, 10); // Tambah node di depan (10)
    insertAtEnd(head, 20);   // Tambah node di belakang (20)
    insertAtFront(head, 5);  // Tambah node di depan (5)

    cout << "Isi linked list sebelum penghapusan: ";
    printList(head);

    deleteNode(head, 10); // Hapus node dengan nilai 10

    cout << "Isi linked list setelah penghapusan: ";
    printList(head);

    return 0;
}
