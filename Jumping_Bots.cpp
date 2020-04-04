#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define f(i, start, end, increment) for (ll i = start; i <= end; i += increment)
#define rf(i, start, end, decrement) for (ll i = start; i >= end; i -= decrement)
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define yes printf("YES\n")
#define no printf("NO\n")
#define all(something) something.begin(), something.end()
const int MAX = 1e7 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
void sieve()
{
	prime[0] = prime[1] = 0;
	spf[2] = 2;
	f(i, 4, MAX - 1, 2)
	{
		spf[i] = 2;
		prime[i] = 0;
	}
	f(i, 3, MAX - 1, 2)
	{
		if (prime[i])
		{
			spf[i] = i;
			f(j, i * i, MAX - 1, i)
			{
				prime[j] = 0;
				if (spf[j] == 1)
				{
					spf[j] = i;
				}
			}
		}
	}
}

ll power(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1)
		{
			res = res * a;
		}
		a = a * a;
		b = b >> 1;
	}
	return res;
}
ll power(ll a, ll b, ll m)
{
	ll ans = 1;
	while (b != 0)
	{
		if (b % 2 == 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b = b >> 1;
	}
	return ans % m;
}
void pre()
{
	// sieve();
}
void solve()
{
	ll n;
	cin >> n;
	vector<ll> v(n), h(MAX, 0);
	// for (auto &x : v)
	// {
	// 	map<ll, ll> m;
	// 	cin >> x;
	// 	// while (x != 1)
	// 	// {
	// 	// 	m[sp[x]]++;
	// 	// 	x = x / sp[x];
	// 	// }
	// 	for (auto x : m)
	// 	{
	// 		h[x.ff] = max(h[x.ff], x.ss);
	// 	}
	// }
	cout << h[1] << "\n";
}
int main()
{
	pre();
	solve();
	return 0;
}
