#include <iostream>
using namespace std;




// //Membuat Single Linked List

// struct Node {
//     int data;
//     Node* next;
// };

// void insertAtFront(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }

// void insertAtBack(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = nullptr;
    
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data;
//         if (temp->next != nullptr) {
//             cout << " -> ";
//         }
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;
    
//     insertAtFront(head, 10);
//     insertAtBack(head, 20);
//     insertAtFront(head, 5);
    
//     printList(head);
    
//     return 0;
// }




// //Menghapus Node pada Linked List

// struct Node {
//     int data;
//     Node* next;
// };

// void insertAtFront(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }

// void insertAtBack(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = nullptr;
    
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// void deleteNode(Node*& head, int value) {
//     if (head == nullptr) return;
    
//     if (head->data == value) {
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//     }
    
//     Node* temp = head;
//     while (temp->next != nullptr && temp->next->data != value) {
//         temp = temp->next;
//     }
    
//     if (temp->next != nullptr) {
//         Node* toDelete = temp->next;
//         temp->next = toDelete->next;
//         delete toDelete;
//     }
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data;
//         if (temp->next != nullptr) {
//             cout << " -> ";
//         }
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;
    
//     insertAtFront(head, 10);  // Linked list: 10
//     insertAtBack(head, 20);   // Linked list: 10 -> 20
//     insertAtFront(head, 5);   // Linked list: 5 -> 10 -> 20
    
//     deleteNode(head, 10);
    
//     printList(head); // Output: 5 -> 20
    
//     return 0;
// }




// //Mencari dan Menghitung Panjang Linked List

// struct Node {
//     int data;
//     Node* next;
// };

// void insertAtFront(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = head;
//     head = newNode;
// }

// void insertAtBack(Node*& head, int value) {
//     Node* newNode = new Node();
//     newNode->data = value;
//     newNode->next = nullptr;
    
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         Node* temp = head;
//         while (temp->next != nullptr) {
//             temp = temp->next;
//         }
//         temp->next = newNode;
//     }
// }

// bool searchNode(Node* head, int value) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         if (temp->data == value) {
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

// int lengthOfList(Node* head) {
//     int length = 0;
//     Node* temp = head;
//     while (temp != nullptr) {
//         length++;
//         temp = temp->next;
//     }
//     return length;
// }

// void printList(Node* head) {
//     Node* temp = head;
//     while (temp != nullptr) {
//         cout << temp->data;
//         if (temp->next != nullptr) {
//             cout << " -> ";
//         }
//         temp = temp->next;
//     }
//     cout << endl;
// }

// int main() {
//     Node* head = nullptr;
    
//     insertAtFront(head, 10);
//     insertAtBack(head, 20);
//     insertAtFront(head, 5);
    
//     if (searchNode(head, 20)) {
//         cout << "Node dengan nilai 20 ditemukan." << endl;
//     } else {
//         cout << "Node dengan nilai 20 tidak ditemukan." << endl;
//     }

//     cout << "Panjang linked list: " << lengthOfList(head) << endl; // Output: 3
    
//     return 0;
// }