#include <iostream>
using namespace std;

int gcd(int n1, int n2)
{
    while (n2 != 0) 
    {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }

    return n1;
}

int lcm(int n1 , int n2)
{
    return (n1 * n2) / gcd(n1 , n2);
}

int main() {

    int num1 = 4 , num2 = 6;
    int ans = lcm(num1 , num2);
    cout<<"Lowest Common Multiple is :- "<<ans<<endl;

    return 0;
}

// Time Complexity :- O(log n) ----- n = min(n1 , n2)
// Space Complexity :- O(1)
