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

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node *head, int value)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            return true; // Nilai ditemukan
        }
        temp = temp->next;
    }
    return false; // Nilai tidak ditemukan
}

// Fungsi untuk menghitung panjang linked list
int getLength(Node *head)
{
    int length = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;
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

    // Cetak seluruh isi linked list
    cout << "Isi linked list: ";
    printList(head);

    // Cari node dengan nilai 20
    int searchValue = 20;
    if (searchNode(head, searchValue))
    {
        cout << "Node dengan nilai " << searchValue << " ditemukan." << endl;
    }
    else
    {
        cout << "Node dengan nilai " << searchValue << " tidak ditemukan." << endl;
    }

    // Hitung panjang linked list
    int length = getLength(head);
    cout << "Panjang linked list: " << length << endl;

    return 0;
}
