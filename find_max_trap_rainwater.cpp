# include <iostream>
# include <vector>
# include <stack>
using namespace std;

int Area(int a [] , int n) {
    stack <int> s;
    stack <int> s1;
    vector <int> ls(n , -1);
    vector <int> rs(n , n);

    for (int i=0; i<n; i++)
    {
        while(!s.empty() && a[i] < a[s.top()])
        {
            rs[s.top()] = i;
            s.pop(); 
        }
        s.push(i);
    }
    
    for (int i=n-1; i>=0; i--)
    {
        while(!s1.empty() && a[i] < a[s1.top()])
        {
            ls[s1.top()] = i;
            s1.pop();
        }
        s1.push(i);
    }
        
    int max = 0;  
    for (int i=0; i<n; i++)
    {
        int area = 0;
        area = ((rs[i] - ls[i] - 1) * a[i]);
        if (area > max)
            max = area;
    }
    return max;
}


int main()
{
    int input_array[] = {0 , 1 , 0 , 2 , 1 , 0 , 1 , 3 , 2 , 1 , 2 , 1};
    int size = sizeof(input_array) / sizeof(input_array[0]);
    int ans = Area(input_array , size);
    cout<<"Maximum Area :- "<<ans<<endl;
    return 0;

}

// Time Complexity :- O(n) --- n = size of array
// Space Complexity :- O(n) --- n = size of array
