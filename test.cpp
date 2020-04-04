#include <bits/stdc++.h>
#define FF first
#define SS second
using namespace std;
bool say(vector<pair<int, int>>);
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		int n;
		cin >> n;
		vector<pair<int, pair<int, int>>> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i].FF >> v[i].SS.FF;
			v[i].SS.SS = i;
		}
		int find_index[n];
		sort(v.begin(), v.end());
		char ans[n];
		for (int i = 0; i < n; i++)
		{
			ans[i] = 'J';
			find_index[v[i].SS.SS] = i;
		}
		ans[v[0].SS.SS] = 'C';
		int prev = v[0].SS.FF;
		for (int i = 1; i < n; i++)
		{
			if (v[i].FF >= prev)
			{
				prev = v[i].SS.FF;
				ans[v[i].SS.SS] = 'C';
			}
		}
		vector<pair<int, int>> remaining_intervals;
		for (int i = 0; i < n; i++)
			if (ans[i] == 'J')
				remaining_intervals.push_back({v[find_index[i]].FF, v[find_index[i]].SS.FF});
		if (say(remaining_intervals))
		{
			cout << "Case #" << tc << ": ";
			for (char ch : ans)
				cout << ch;
			cout << endl;
		}
		else
			cout << "Case #" << tc << ": IMPOSSIBLE\n";
	}
}
bool say(vector<pair<int, int>> v)
{
	int sz = v.size();
	sort(v.begin(), v.end());
	if (sz < 2)
		return true;
	for (int i = 1; i < sz; i++)
	{
		if (v[i].FF < v[i - 1].SS)
			return false;
	}
	return true;
}