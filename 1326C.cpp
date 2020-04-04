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
#define endl '\n'
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
using namespace std;
const int MAX = 1e7 + 9;
const ll mod = 998244353;
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
}
void solve()
{
   ll n, k;
   cin >> n >> k;
   vector<ll> v(n), h(n + 1, -1);
   for (int i = 0; i < n; i++)
   {
      cin >> v[i];
      h[v[i]] = i;
   }
   sort(all(v));
   reverse(all(v));
   vector<pair<ll, ll>> ans;
   for (ll i = 0; i < k; i++)
   {
      ans.pb({h[v[i]], v[i]});
   }
   // for (auto x : ans)
   // {
   //    cout << x.ff << " " << x.ss << "\n";
   // }
   sort(all(ans));
   ll res1 = 0, res2 = 1;
   for (ll i = 0; i < k; i++)
   {
      res1 += ans[i].ss;
   }
   vector<ll> df;
   for (ll i = 1; i < (ll)ans.size(); i++)
   {
      df.pb(ans[i].ff - ans[i - 1].ff);
   }
   for (ll i = 0; i < (ll)df.size(); i++)
   {
      // cout << df[i] << "\n";
      res2 = (res2 * df[i]) % mod;
   }
   cout << res1 << " " << res2 << "\n";
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