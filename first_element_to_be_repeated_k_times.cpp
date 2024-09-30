#include <iostream>
#include <unordered_map>
using namespace std;

int first_num_at_k(int a[] , int n , int k)
{
    unordered_map <int , int> freq;
    for (int i=0; i<n; i++)
        freq[a[i]]++;

    for (int i=0; i<n; i++)
    {
        if (freq[a[i]] == k)
            return a[i];
    }    
    return -1;
}

int main() 
{
    int arr [] = {3 , 1 , 4 , 4 , 5 , 2 , 6 , 1 , 4};
    int n = (sizeof(arr) / sizeof(arr[0]));
    int k = 2;
    int result = first_num_at_k(arr , n , k);
    cout<<"First Number To Repeat "<<k<<" times is :- "<<result<<endl;

    return 0;
}

// Time Complexity :- O(n) -------- n = size of array
// Space Complexity :- O(n) -------- n = size of array
