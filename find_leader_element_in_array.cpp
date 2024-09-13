#include <iostream>
#include <stack>
using namespace std;

void leader(int a[] , int n)
{
	stack <int> s;
	int max = a[n-1];
	s.push(max); // Last Element


	for (int i = n-2; i >= 0; i--) 
	{
        if (a[i] > max) 
		{
            max = a[i];  
            s.push(a[i]);  
        }
    }
	
    while (!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}	
}

int main()
{
	
	int input_array[] = {16 , 17 , 4 , 3 , 5 , 2};
	int size = sizeof(input_array) / sizeof(input_array[0]);
	leader(input_array , size); 
	
	return 0;
}

// Space Complexity :- O(n) ---- n = Size of Array
// Time Complexity :- O(n) ---- n = Size of Array
