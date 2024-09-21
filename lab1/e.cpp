#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> player1;
    queue<int> player2;
    
    int temp;
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        player1.push(temp);  
    }
    
    for (int i = 0; i < 5; i++) {
        cin >> temp;
        player2.push(temp);  
    }

    int count = 0;

    while (!player1.empty() && !player2.empty()) {
        int card1 = player1.front(); 
        int card2 = player2.front();

        player2.pop();
        player1.pop();

        if (card1 > card2) {
            if (card1 == 9 && card2 == 0) {
                player2.push(card1); 
                player2.push(card2);      
            } else {
                player1.push(card1); 
                player1.push(card2);  
            }
        } else {
            if (card2 == 9 && card1 == 0) {
                player1.push(card1); 
                player1.push(card2);      
            } else {
                player2.push(card1); 
                player2.push(card2);   
            }
        }

        count++;

        if (count > 1000000) {
            cout << "blin nichya" << endl;
            return 0;
        }
    }

    (!player1.empty()) ? cout << "Boris " << count : cout << "Nursik " << count;

    return 0;
}