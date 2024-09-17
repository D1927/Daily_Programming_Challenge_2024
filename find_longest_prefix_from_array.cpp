# include <iostream>
using namespace std;

string prefix(string strs[] , int n)
{
    int s = sizeof(strs[0]); // Size of first word
    string ans = "";
    bool flag = 1;
    for(int i=0; i<s; i++)
    {
        int j;
        for (j=0; j<n-1; j++)
        {
            if ((i >= sizeof(strs[j])) || (strs[j][i] != strs[j+1][i]))
                flag = 0;
        }
        if (flag == 1)
            ans.push_back(strs[j][i]);
        if (flag == 0)
            break;   
    }

    return ans;
}

int main()
{
    string input_array[] = {"flower" , "flow" , "flight"};
    int size = ( sizeof(input_array) / sizeof(input_array[0]) );    
    string ans = prefix(input_array , size);
    cout<<"Longest Prefix Is :- "<<ans;

    return 0;
}

// Time Complexity :- O(m.n) ----- m = size of array , n = size of shortest string
// Space Complexity :- O(n) ------ n = size of shortest string
