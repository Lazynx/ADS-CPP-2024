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
        if (head == nullptr) {
            head = new Node(x);
            tail = head;
        } else {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    return head;
}   

void printLinkedList(Node* head) {
    Node* cur = head;
    while (cur!= nullptr) {
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node* insertLinkedList(Node* head, int data, int index) {
    Node* newNode = new Node(data);

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node* cur = head;
    for (int i = 0; i < index - 1; i++)
    {
        cur = cur->next;
    }
    
    newNode->next = cur->next;
    cur->next = newNode;
    
    return head;    
}

int main() {
    int n; cin >> n;

    Node* head = createLinkedList(n);

    int data, index;
    cin >> data >> index;
    head = insertLinkedList(head, data, index);
    printLinkedList(head);

    Node* cur = head;
    while (cur != nullptr)
    {
        Node* temp = cur->next;
        delete cur;
        cur = temp;
    }

    return 0;
}