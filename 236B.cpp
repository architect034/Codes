#include <bits/stdc++.h>
#define ll long long
#define f(i, st, en, in) for (ll i = st; i <= en; i += in)
#define rf(i, st, en, de) for (ll i = st; i >= en; i -= de)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define nl cout << "\n"
#define endl '\n'
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
using namespace std;
const int MAX = 1e6 + 5;
const ll mod = 1073741824;
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
void pre()
{
   sieve();
}
int dp[MAX];
void solve()
{
   int a, b, c;
   cin >> a >> b >> c;
   ll ans = 0;
   for (int i = 1; i <= a; i++)
   {
      for (int j = 1; j <= b; j++)
      {
         for (int k = 1; k <= c; k++)
         {
            int x = i * j * k;
            if (dp[x])
            {
               ans += dp[x];
               continue;
            }
            map<int, int> m;
            while (x > 1)
            {
               m[spf[x]]++;
               x = x / spf[x];
            }
            int tmp = 1;
            for (auto it : m)
            {
               tmp = tmp * (it.ss + 1);
            }
            dp[i * j * k] = tmp;
            ans += tmp;
            ans %= mod;
         }
      }
   }
   pl(ans);
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int _ = 1;
   // cin>>_;
   while (_--)
   {
      solve();
   }
   return 0;
}