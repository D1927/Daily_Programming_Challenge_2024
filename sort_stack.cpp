#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int num) 
{
    if (s.empty() || num < s.top()) 
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    sortedInsert(s, num);
    s.push(temp);
}

void sortStack(stack <int> &s) 
{
    if (s.empty()) 
        return;
    
    int temp = s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s, temp);
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

    sortStack(s);

    cout << "Sorted Stack :- ";
    printStack(s);

    return 0;
}

// Time Complexity :- O(n^2) -------- n = size of stack
// Space Complexity :- O(n) -------- n = size of stack
