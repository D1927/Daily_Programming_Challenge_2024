# include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int sort_array(int a[] , int size) // Using Dutch National Flag Algorithm
{
    if (size == 0)
        return -1;

    int pointer_0 = 0 , pointer_1 = 0 , pointer_2 = size - 1;
    
    while (pointer_1 <= pointer_2) 
    {
        if (a[pointer_1] == 0)
        {
            swap(a[pointer_0] , a[pointer_1]);
            pointer_0++;
            pointer_1++;
        }
        else if (a[pointer_1] == 2)
        {
            swap(a[pointer_1] , a[pointer_2]);
            pointer_2--;
        }
        else
            pointer_1++;
    }
    return 1;
}

int main()
{
    int input_array[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int size_of_array = sizeof(input_array) / sizeof(input_array[0]);

    int ans = sort_array(input_array , size_of_array);
    if (ans == -1)
        cout<<"Array is Empty !";
    else
    {
        cout<<"Sorted Array is :- ";
        for (int i=0; i<size_of_array; i++)
            cout<<input_array[i]<<" ";
    }    
    cout<<endl;
 
    return 0;
}

// Time Complexity :- O(n) ---- n = Size of Array
// Space Complexity :- O(1)
