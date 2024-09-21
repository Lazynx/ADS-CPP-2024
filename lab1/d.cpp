#include <iostream>
#include <stack>

using namespace std;

bool isBalancedString(string expr) {
    stack<char> temp;

    for (int i = 0; i < expr.length(); i++) {
        if (temp.empty()) {
            temp.push(expr[i]);
        } else if (expr[i] == temp.top()) {
            temp.pop();
        } else {
            temp.push(expr[i]);
        }
    }

    if (temp.empty()) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string str;
    cin >> str;

    isBalancedString(str) ? cout << "YES" : cout << "NO";

    return 0;
}