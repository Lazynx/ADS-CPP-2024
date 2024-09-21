#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> listModes;

    for (int i = 0; i < n; i++) 
    {
        int num;
        cin >> num;

        if (listModes.find(num) == listModes.end()) 
        {
            listModes[num] = 1;
        } else {
            listModes[num]++;
        }
    }

    int max = 0;
    for (const auto& mode : listModes) 
    {
        if (mode.second > max) 
        {
            max = mode.second;
        }
    }
    
    vector<int> modes;
    for (const auto& mode : listModes) 
    {
        if (mode.second == max) 
        {
            modes.push_back(mode.first);
        }
    }

    sort(modes.rbegin(), modes.rend());

    for (int i : modes) 
    {
        cout << i << " ";
    } 

    return 0;
}