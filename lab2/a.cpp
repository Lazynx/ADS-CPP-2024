#include <iostream>
#include <cmath>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        ListNode *newNode = new ListNode(x);

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

    int k;
    cin >> k;
    
    int minDiff = abs(head->val - k);
    int index = 0;
    int currentIndex = 0;
    ListNode *current = head;

    while (current) {
        int diff = abs(current->val - k);
        if (diff < minDiff) {
            minDiff = diff;
            index = currentIndex;
        }

        current = current->next;
        currentIndex++;
    }

    cout << index << endl;

    current = head;
    while (current) {
        ListNode* temp = current->next;
        delete current;
        current = temp;
    }

    return 0;
}