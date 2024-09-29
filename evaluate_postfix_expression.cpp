#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int ans(string s)
{
    stack <char> s1;
    for (int i=0; i<s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            s1.push(s[i] - '0');
        }
        else
        {
            int num2 = s1.top();
            s1.pop();
            int num1 = s1.top();
            s1.pop();
            char c = s[i];
            switch (c) 
            {
                case '+':
                    s1.push(num1 + num2);
                    break;
                case '-':
                    s1.push(num1 - num2);
                    break;
                case '*':
                    s1.push(num1 * num2);
                    break;
                case '/':
                    s1.push((num2 != 0) ? num1 / num2 : 0);
                    break;  
            }
        }
    }
    return s1.top();
}

int main() 
{
    string s = "21+3*";
    int result = ans(s);
    cout<<"Calculation is :- "<<result<<endl;
    
    return 0;
}

// Time Complexity :- O(n) ----- n = length of string
// Space Complexity :- O(n)
