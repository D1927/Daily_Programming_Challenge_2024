#include <iostream>
#include <vector>
using namespace std;

vector<int> find(int n) {
    vector<int> primeFactors;
    
    while (n % 2 == 0) {
        primeFactors.push_back(2);
        n /= 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            primeFactors.push_back(i);
            n /= i;
        }
    }

    if (n > 2) {
        primeFactors.push_back(n);
    }

    return primeFactors;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    vector<int> result = find(number);

    if (result.size() == 1 && result[0] == number) {
        cout << "The number itself is prime :- " << number << endl;
    } else {
        cout << "Prime factors :- ";
        for (int factor : result) {
            cout << factor << " ";
        }
        cout << endl;
    }

    return 0;
}

// Space Complexity :- O(log n) ------ n = number
// Time Complexity :- O(n^(0.5)) ------ n = number
