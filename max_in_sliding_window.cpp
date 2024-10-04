#include <iostream>
#include <unordered_map>
using namespace std;

void max_num_in_k(int a[] , int n , int k)
{
    for (int i=0; i<=(n-k); i++)
    {
        int tem = max(a[i] , max(a[i+1] , a[i+2]));
        cout<<tem<<" ";
    }
    cout<<endl;
}

int main() 
{
    int arr [] = {1,3,-1,-3,5,3,6,7};
    int n = (sizeof(arr) / sizeof(arr[0]));
    int k = 3;
    cout<<"Max Element in window size of "<<k<<" is :- ";
    max_num_in_k(arr , n , k);

    return 0;
}

// Time Complexity :- O(n * k) -------- n = size of array , k = size of window
// Space Complexity :- O(1) 
