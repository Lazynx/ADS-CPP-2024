#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {};
};

Node* createLinkedList(int n) {
    int x;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        Node* newNode = new Node(x);


        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;    
}  

Node* delete2ndElLinkedList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* cur = head;

    while (cur != nullptr && cur->next != nullptr) {
        Node* nodeToDel = cur->next;
        cur->next = nodeToDel->next;
        delete nodeToDel;
        cur = cur->next;
    }

    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current!= nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    int n; cin >> n; 
    Node* head = createLinkedList(n);
    head = delete2ndElLinkedList(head); 
    printLinkedList(head); 

    Node* cur = head; 
    while (cur!=nullptr) {
        Node* temp = cur->next;
        delete cur;
        cur = temp;
    }

    return 0;
}