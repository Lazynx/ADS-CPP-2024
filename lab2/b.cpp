#include <iostream>
#include <cmath>

using namespace std;

struct Node {
    string val;
    Node *next;

    Node(string x) : val(x), next(nullptr) {}
};

Node* createList(int n) { 
    string temp;
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        Node* newNode = new Node(temp);

        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

Node* shiftLinkedList(Node* head, int n, int k) {
    if (n == 0 || k == 0 || k % n == 0)
    {
        return head;
    }

    k = k % n;

    Node* cur = head;
    for (int i = 0; i < k - 1; i++)
    {
        cur = cur->next;
    }
    
    Node* newHead = cur->next;
    cur->next = nullptr;

    Node* tail = newHead;
    while (tail->next != nullptr) {
        tail = tail->next;
    }   
    
    tail->next = head;

    return newHead;
}

void printLinkedList(Node* head){
    Node* current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, k;
    cin >> n >> k;

    Node* head = createList(n);
    head = shiftLinkedList(head, n, k);
    printLinkedList(head);

    Node* current = head;
    while (current) {
        Node* temp = current->next;
        delete current;
        current = temp;
    }

    return 0;
}