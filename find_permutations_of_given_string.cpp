#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void permute(string str, int l, int r, vector<string>& result) 
{
    if (l == r) 
    {
        result.push_back(str);
    } else 
    {
        for (int i = l; i <= r; i++) 
        {
            swap(str[l], str[i]); 
            permute(str, l + 1, r, result); 
            swap(str[l], str[i]); 
        }
    }
}

vector<string> findPermutations(string str) 
{
    vector<string> result;
    permute(str, 0, str.length() - 1, result);
    return result;
}

int main() 
{
    string input = "ABC";
    vector<string> permutations = findPermutations(input);
    
    cout << "Permutations of the string " << input << " are: " << endl;
    for (string s : permutations) 
        cout<<"\""<<s<<"\""<<"  ";
    
    
    return 0;
}
// Time complexity :- O(n * n!) ----- n = length of string
// Space complexity :- O(n * n!) ------ n = length of string
