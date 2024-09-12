# include <iostream>
using namespace std;

void sorted(int a[], int b[] , int n1, int n2)
{
    int c[n1 + n2];
    int i=0, j=0, k=0;
    while (i<n1 && j<n2)
    {
        if (a[i] <= b[j])
        {
            c[k] = a[i];
            k++;
            i++;
        }
        else
        {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while(i<n1)
    {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j<n2)
    {
        c[k] = b[j];
        k++;
        j++;
    }
    for (int g=0; g<(n1+n2); g++)
        cout<<c[g]<<" ";

    for (int y=0; y<n1; y++)
        a[y] = c[y];

    for (int y=0; y<n2; y++)
        b[y] = c[n1 + y];        
}

int main()
{
    int input_array_1[] = {1,2,7,8};
    int input_array_2[] = {3,4,5,6};

    int size_1 = ( sizeof(input_array_1) / sizeof(input_array_1[0]) );
    int size_2 = ( sizeof(input_array_2) / sizeof(input_array_2[0]) );

    sorted(input_array_1, input_array_2 , size_1 , size_2);

    cout<<endl;
    for (int i=0; i<size_1; i++)
        cout<<input_array_1[i]<<" ";
    cout<<endl;

    for (int i=0; i<size_2; i++)
        cout<<input_array_2[i]<<" ";
    cout<<endl;        

    return 0;
}

// Time Complexity :- O(m + n) --- m , n = size of array
// Space Complexity :- O(m + n)
