        #include <iostream>
        using namespace std;

        struct Node {
            int data;
            Node* next;
        };

        void insertFront(Node** head, int value) {
            Node* newNode = new Node();
            newNode->data = value;  
            newNode->next = *head;
            *head = newNode;
        }

        void insertBack(Node** head, int value) {
            Node* newNode = new Node();
            newNode->data = value;
            newNode->next = nullptr;
            
            if (*head == nullptr) {
                *head = newNode;
                return;
            }

            Node* temp = *head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        bool searchNode(Node* head, int value) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == value) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        int countLength(Node* head) {
            int count = 0;
            Node* temp = head;
            while (temp != nullptr) {
                count++;
                temp = temp->next;
            }
            return count;
        }

        void printList(Node* head) {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data ;
                if (temp->next != nullptr) {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            
        }

        int main() {
            Node* head = nullptr;

            insertFront(&head, 10);
            insertBack(&head, 20);
            insertFront(&head, 5);
            
            cout << "Linked List: ";
            printList(head);
            
            int searchValue = 20;
            if (searchNode(head, searchValue)) {
                cout << " Node with value " << searchValue << " found." << endl;
            } else {
                cout << " Node with value " << searchValue << " not found." << endl;
            }

            int length = countLength(head);
            cout << "Length of the linked list: " << length << endl;

            return 0;
        }