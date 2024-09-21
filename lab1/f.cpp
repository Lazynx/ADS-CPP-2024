#include <iostream>

using namespace std;

int nthPrimeNumber(int n) {
    int count = 0;
    int num = 2;

    while (count < n) {
        bool isPrime = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            count++;
        }

        num++;
    }

    return num - 1;
}

int main() {
    int num1;
    cin >> num1;

    cout << nthPrimeNumber(num1) << endl;

    return 0;
}