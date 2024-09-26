#include <iostream>
#include <vector>
using namespace std;

int factors(int n)
{
    vector <int> ans;

    for (int i=1; i<=(n/2); i++)
    {
        if (n % i == 0)
            ans.push_back(i);
    }

    ans.push_back(n); // number itself
    
    return ans.size();
}

int main() 
{
    int num = 12;
    int ans = factors(num);
    cout<<"Total Factors are :- "<<ans<<endl;
    
    return 0;
}

// Time Complexity :- O(n) ----- n = number
// Space Complexity :- O(n)
