#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ages(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ages[i];
    }
    
    vector<int> res(n); 
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top() > ages[i]) {
            s.pop();
        }

        if (s.empty()) {
            res[i] = -1;
        } else {
            res[i] = s.top();
        }

        s.push(ages[i]);
    }

    for (auto i: res) 
    {
        cout << i << " ";
    }
    

    return 0;
}