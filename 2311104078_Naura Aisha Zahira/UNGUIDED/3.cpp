#include <iostream>

using namespace std;

// Struktur Node
struct Node {
  int data;
  Node *next;
};

// Fungsi untuk menambahkan node di depan
Node *insertAtBeginning(Node *head, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = head;
  return newNode;
}

// Fungsi untuk menambahkan node di belakang
Node *insertAtEnd(Node *head, int data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  if (head == NULL) {
    return newNode;
  }
  Node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  return head;
}

// Fungsi untuk mencari node dengan nilai tertentu
bool searchNode(Node *head, int data) {
  if (head == NULL) {
    return false;
  }
  Node *temp = head;
  while (temp != NULL) {
    if (temp->data == data) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

// Fungsi untuk menghitung panjang linked list
int countNodes(Node *head) {
  if (head == NULL) {
    return 0;
  }
  Node *temp = head;
  int count = 0;
  while (temp != NULL) {
    count++;
    temp = temp->next;
  }
  return count;
}

int main() {
  Node *head = NULL;
  head = insertAtBeginning(head, 10);
  head = insertAtEnd(head, 20);
  head = insertAtBeginning(head, 5);

  if (searchNode(head, 20)) {
    cout << "Node dengan nilai 20 ditemukan." << endl;
  } else {
    cout << "Node dengan nilai 20 tidak ditemukan." << endl;
  }

  cout << "Panjang linked list: " << countNodes(head) << endl;

  return 0;
}