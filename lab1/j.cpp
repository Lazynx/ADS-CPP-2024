#include <iostream>
#include <deque>

using namespace std;

int main() {
    string command;
    deque<int> dq; 

    while (true)
    {
        cin >> command;

        if (command == "!") {
            break;
        }

        if (command == "+") {
            int num;
            cin >> num;
            dq.push_front(num);
        } else if (command == "-") {
            int num;
            cin >> num;
            dq.push_back(num);
        } else if (command == "*") {
            if (dq.empty()) {
                cout << "error" << endl;
            } else {
                int first = dq.front();
                dq.pop_front();
                
                int last;
                if (!dq.empty()) {
                    last = dq.back();
                    dq.pop_back();
                } else {
                    last = first;
                }
                
                cout << first + last << endl;
            }
        }
    }
    return 0;
}