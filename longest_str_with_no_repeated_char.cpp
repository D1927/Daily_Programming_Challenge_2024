#include <iostream>
#include <vector>
using namespace std;

int longstr(string s)
{
	int max = 0;
	for (int i=0; i<s.size(); i++)
	{
		int count = 0;
		vector <int> chars(26 , 0);
		for (int j=i; j<s.size(); j++)
		{
			int tem = s[j] - 'a';
			if (chars[tem] == 0)
			{
				chars[tem] = 1;
			    count++;
			}
			else
			    break;	
		}
		if (count > max)
		    max = count;
	}
	return max;
}

int main()
{
	string str = "abcabdcbb";
    int ans = longstr(str);
	cout<<"The Longest String Without Repeated Characters is :- "<<ans<<endl;

	return 0;
}

// Time Complexity :- O(n^2) ------ n = length of string
// Space Complexity :- O(1)
