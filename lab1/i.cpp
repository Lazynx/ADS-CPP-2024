#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n; string votes;

    cin >> n >> votes;

    queue<int> kat, sak; 

    for (int i = 0; i < n; i++)
    {
        votes[i] == 'K' ? kat.push(i) : sak.push(i);
    }

    while (!kat.empty() && !sak.empty()) {
        int k = kat.front(), s = sak.front();

        kat.pop();
        sak.pop();

        if (s < k) {
            sak.push(s + n);
        } else {
            kat.push(k + n);
        }
    }

    if (!kat.empty()) cout << "KATSURAGI"; else cout << "SAKAYANAGI";

    return 0;
}