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
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
vector<int> primes;
void sieve()
{
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   f(i, 4, MAX - 1, 2)
   {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   f(i, 3, MAX - 1, 2)
   {
      if (prime[i])
      {
         primes.pb(i);
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
   ll res = 1;
   while (b)
   {
      if (b & 1)
      {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
void pre()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void solve()
{
   ll n;
   cin >> n;
   map<ll, ll> m;
   ll v[n][3];
   for (ll i = 0; i < n; i++)
   {
      cin >> v[i][0] >> v[i][1] >> v[i][2];
      m[v[i][0]]++;
      m[v[i][1]]++;
   }
   vector<ll> dp;
   for (auto x : m)
   {
      if (x.ss >= n / 2)
      {
         dp.pb(x.ff);
      }
   }
   ll res = 10000000000000000;
   for (ll i = 0; i < dp.size(); i++)
   {
      ll num = dp[i];
      // cout << num << " num\n";
      vector<ll> up, niche;
      for (ll j = 0; j < n; j++)
      {
         if (v[j][0] == num)
            up.pb(v[j][2]);
         if (v[j][1] == num)
            niche.pb(v[j][2]);
      }
      sort(all(up));
      sort(all(niche));
      if (up.size() > n / 2)
      {
         ll kitna = up.size() - n / 2, sum = 0;
         for (ll it = 0; it < kitna; it++)
         {
            sum += up[it];
         }
         res = min(res, sum);
      }
      else
      {
         ll kitna = n / 2 - up.size(), sum = 0;
         for (ll it = 0; it < kitna; it++)
         {
            sum += niche[it];
         }
         res = min(res, sum);
      }
   }
   if (res == 10000000000000000)
   {
      cout << -1;
      return;
   }
   cout << res << "\n";
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++)
   {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}