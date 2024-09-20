#include <iostream>
#include <stack>
using namespace std;

bool valid_parenthesis(string a , int n)
{
    stack <char> s;
    for (int i=0; i<n; i++)
    {
        if (!s.empty() && (a[i] - s.top()) < 3)
            s.pop();
        else
            s.push(a[i]);    
    }
    return s.empty();
}

int main() 
{
    string s = "[{()}]";
    int n = s.size();
    bool ans = valid_parenthesis(s , n);
    if (ans)
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    
    return 0;
}

// Space Complexity :- O(n) ------ n = length of string
// Time Complexity :- O(n) ------ n = length of string
