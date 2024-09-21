#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> students;
    string prev_name = "";
    string name;
    for (int i = 0; i < n; i++)
    {
        cin >> name;
        if (name != prev_name) {
            students.push_back(name);
        }
        prev_name = name;
    }

    cout << "All in all: " << students.size() << endl << "Students:" << endl;

    for (auto it = students.rbegin(); it != students.rend(); ++it) {
        cout << *it << endl;
    }
    
    return 0;
}
