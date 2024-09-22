#include <iostream>
#include <cstring>
using namespace std;

long long int countSub(string str)
{
	int n = (int)str.size();
	long long int ans = 0;
	int cnt[26];

	memset(cnt, 0, sizeof(cnt));
	int i = 0, j = 0;

	while (i < n) 
    {
		if (j < n && (cnt[str[j] - 'a']
					== 0)) {
			cnt[str[j] - 'a']++;
			ans += (j - i + 1);
			j++;
		}
		else {

			cnt[str[i] - 'a']--;

			i++;
		}
	}

	return ans;
}

int main()
{
	string str = "pqpqs";

	cout << countSub(str);

	return 0;
}
