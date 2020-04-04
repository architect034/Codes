/*
 *architect034
 *NIT Silchar<36>
*/
#include <bits/stdc++.h>
using namespace std;
#define bhago ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define ull unsigned long long
#define loop(i, start, end, increment) for (ll i = start; i <= end; i += increment)
#define ulta(i, start, end, decrement) for (int i = start; i >= end; i -= decrement)
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define mp make_pair
#define FF first
#define SS second
#define all(something) something.begin(), something.end()
#define vecitr vector<ll>::iterator
#define setitr set<ll>::iterator0
#define mapitr map<ll, ll>::iterator
#define mod 1000000007
void debug(string s)
{
	cout << s << "\n";
}
const int MAX = 2000007;
bool prime[MAX];
int sp[MAX];
void sieve()
{
	for (int i = 2; i < MAX; i += 2)
	{
		sp[i] = 2;
	}
	for (ll i = 3; i < MAX; i += 2)
	{
		if (!prime[i])
		{
			sp[i] = i;
			for (ll j = i; (j * i) < MAX; j += 2)
			{
				if (!prime[j * i])
				{
					prime[j * i] = true;
					sp[j * i] = i;
				}
			}
		}
	}
}
ll GCD(ll a, ll b)
{
	ll c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
ll power(ll a, ll b)
{
	ll ans = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
			ans *= a;
		a *= a;
		b = b >> 1;
	}
	return ans;
}
stack<int> st;
void ts(int s, vector<vector<int>> v, int n, int vi[])
{
	vi[s] = 1;
	for (auto it = 0; it < (int)v[s].size(); ++it)
	{
		if (vi[v[s][it]] == 0)
			ts(v[s][it], v, n, vi);
	}
	st.push(s);
}
int main()
{
	bhago;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> v(n);
	int vi[n] = {0};
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		v[x].pb(y);
	}
	for (int i = 0; i < n; i++)
	{
		if (vi[i] == 0)
		{
			ts(i, v, n, vi);
		}
	}

	while (st.empty() == 0)
	{
		cout << st.top() << " ";
		st.pop();
	}
	return 0;
}
