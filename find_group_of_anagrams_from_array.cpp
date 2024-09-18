# include <iostream>
# include <vector>
# include <unordered_map>
# include <algorithm>
using namespace std;

vector<vector<string>> Anagrams(vector<string>& strs) 
{
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++) 
    {
        string temp = strs[i];           
        sort(temp.begin(), temp.end());  
        map[temp].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    auto i = map.begin();  
    while (i != map.end()) 
    {
        ans.push_back(i->second);
        i++;
    }

    return ans;
}

int main()
{
    vector <string> input_vec = {"eat" , "tea" , "tan" , "ate" , "nat" , "bat"};
    vector <vector <string>> ans = Anagrams(input_vec);
    cout<<"Anagrams are :- ";

    for (int i=0; i<ans.size(); i++)
    {
        cout<<"[ ";
        for (int j=0; j<ans[i].size(); j++)
            cout<<"\""<<ans[i][j]<<"\""<<" ";
        cout<<"]"<<" ";
    }

    return 0;
}

// Space Complexity: O(n * m) ------ m = length of string , n = length of array
// Time Complexity: O(n * m * log(m)) ------ m = length of string , n = length of array

