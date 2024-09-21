#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

string lcs(string s1, string s2) 
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int ind1 = 1; ind1 <= n; ind1++) 
    {
        for (int ind2 = 1; ind2 <= m; ind2++) 
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }

    int i = n, j = m;
    string lcsStr = "";

    while (i > 0 && j > 0) 
    {
        if (s1[i - 1] == s2[j - 1]) 
        {
            lcsStr.push_back(s1[i - 1]);
            i--;
            j--;
        } 
        else if (dp[i - 1][j] > dp[i][j - 1]) 
            i--;
        else 
            j--;
    }

    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

string longestPalindrome(string s) 
{
    string t = s;
    reverse(t.begin(), t.end()); 
    return lcs(s, t);
}

int main() {

    string s = "babad";
    cout << "The Longest Palindromic is: " << longestPalindrome(s) << endl;
    return 0;
}

// Space Complexity :- O(n^2) ------ n = length of string
// Time Complexity :- O(n^2) ------- n = length of string
