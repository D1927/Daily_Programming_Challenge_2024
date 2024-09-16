# include <iostream>
using namespace std;

string reverse_words(string s , int n)
{
    string word = "";
    string ans = "";
    for (int i=0; i<n; i++)
    {
        if (s[i] != ' ')
            word += s[i];
        else if (word.size() > 1) // To avoid multiple spaces
        {
            ans = word + " " + ans;
            word = "";
        }
    }
    ans = word + " " + ans; // For Last word
    
    return ans;
}

int main()
{
    string s = "        hello          world     ";
    int size = s.size();
    string ans = reverse_words(s , size);
    
    while (ans.front() == ' ') // For forward space
    {
        ans.erase(0 , 1);
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i];    
    
    return 0;
}

// Space Complexity :- O(n) ----- n = length of string
// Time Complexity :- O(n) ----- n = length of string
