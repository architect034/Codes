#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.length();
		int i = 0, j = -1;
		vector<int> hash(26, 0), h(26, 0);
		//vector 'hash' string s ke characters ko hash krne k lie
		//vector 'h' i to j k segment ko hash kar raha hai in the program
		for (char c : s)
			hash[c - 'a']++;
		int ans = n;
		while (j <= n)
		{
			//yaha check ho raha hai ki i se j ke andar string k sabhi characters hai yaa nahi
			bool say = 1;
			for (int k = 0; k < 26; k++)
			{
				if (hash[k] > 0 && h[k] == 0)
				{
					say = 0;
					break;
				}
			}
			//agar saare charcters the i to j ke beech then ans is min(ans,j-i+1)
			//aur left pointer ko forward move kr denge aur woh jispe point kar
			//raha tha woh character k frequency of ek kam kr denge kyunki ab woh
			//i to j k beech nahi raha (i.e i increment hogaya hai)
			if (say)
			{
				ans = min(ans, j - i + 1);
				h[s[i] - 'a']--;
				i++;
			}
			//agar nahi hai saare characters iska matlb hmlog ko apne segment ka
			//length badhana hai and islie j ko increment kar rahe hai aur
			//ab woh jispe point kar raha hai uska frequency 1 badh gaya hai
			else
			{
				j++;
				if (j < n)
					h[s[j] - 'a']++;
			}
		}
		cout << ans << "\n";
	}
}