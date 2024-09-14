# include <iostream>
# include <vector>
using namespace std;

void sub_array(int a[] , int n)
{
    vector < vector <int> > ans;

    for(int i=0; i<n; i++)
    {
        bool flag = 0;
        int sum = a[i] , j = 0;
        for (j=i+1; j<n; j++)
        {
            sum += a[j];
            if (sum == 0)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
        {
            vector <int> subarray;
            subarray.push_back(i);
            subarray.push_back(j);
            ans.push_back(subarray);
        }
    }

    if (ans.size() == 0)
        cout<<"No Sub-Array Exists !"<<endl;
    else
    {    
        for (int i=0; i<ans.size(); i++)
            cout<<"("<<ans[i][0]<<", "<<ans[i][1]<<")"<<" ";
        cout<<endl;    
    }
}


int main()
{
    int input_array[] = {1 , 2 , -3 , 3 , -1 , 2};

    int size = ( sizeof(input_array) / sizeof(input_array[0]) );

    sub_array(input_array , size);

    return 0;
}

// Time Complexity :- O(n^2) --- n = size of array
// Space Complexity :- O(n)
