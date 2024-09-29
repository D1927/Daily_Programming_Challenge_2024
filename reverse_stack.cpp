#include <iostream>
#include <stack>
using namespace std;

void last(stack<int> &s, int num) 
{
    if (s.empty()) 
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    last(s, num);
    s.push(temp);
}

void reverseStack(stack <int> &s) 
{
    if (s.empty()) 
        return;
    
    int temp = s.top();
    s.pop();
    reverseStack(s);
    last(s, temp);
}

void printStack(stack<int> s) 
{
    while (!s.empty()) 
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() 
{
    stack<int> s;
    
    s.push(2);
    s.push(1);
    s.push(4);
    s.push(3);

    cout << "Stack :- ";
    printStack(s); 

    reverseStack(s);

    cout << "Sorted Stack :- ";
    printStack(s);

    return 0;
}

// Time Complexity :- O(n^2) -------- n = size of stack
// Space Complexity :- O(n) -------- n = size of stack
