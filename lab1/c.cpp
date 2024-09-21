#include <iostream>
#include <vector>

using namespace std;

string eraseSyms(string str) {
    int i = 0;
    while (i < str.length()) {
        if (str[i] == '#') {
            str.erase(i - 1, 2);
            i--; 
        } else {
            i++;
        }
    }
    return str; 
}

int main() {
    string str1, str2, str3, str4;
    cin >> str1 >> str2;

    str3 = eraseSyms(str1);
    str4 = eraseSyms(str2);

    str3 == str4 ? cout << "Yes" : cout << "no";

    return 0;
}
// fhgshgfd#gkfjd#