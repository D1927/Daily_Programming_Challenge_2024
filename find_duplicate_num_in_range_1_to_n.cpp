# include <iostream>
using namespace std;

int duplicate_element(int a[] , int n)
{
    for (int i=0; i<n; i++)
    {
        int ans = a[i] - 1;
        if (a[ans] < 0)
            return abs(a[i]);
            
        a[ans] = -a[ans];
    }
    return -1;
}

int main()
{
    int input_array[] = {1,4,4,2,3};
    int size = ( sizeof(input_array)/sizeof(input_array[0]) );

    int result = duplicate_element(input_array , size);
    cout<<"Duplicate Element is :- "<<result<<endl;

    return 0;
}

// Time Complexity :- O(n) --- n = length of array
// Space Complexity :- O(1)
