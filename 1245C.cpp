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
ll fib[MAX];
void pre()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   fib[0] = 0;
   fib[1] = 1;
   fib[2] = 2;
   for (ll i = 3; i < MAX; i++)
   {
      fib[i] = fib[i - 1] + fib[i - 2];
      fib[i] %= mod;
   }
}
void solve()
{
   string s;
   cin >> s;
   int n = s.size(), cnt = 0;
   vector<ll> dp;
   bool hai = false;
   for (int i = 1; i < n; i++)
   {
      if (s[i] == 'm' || s[i] == 'w')
      {
         hai = true;
         break;
      }
      if (!i)
      {
         if (s[i] == 'n' || s[i] == 'u')
         {
            cnt++;
         }
         continue;
      }
      if (s[i] == s[i - 1] && (s[i] == 'u' || s[i] == 'n'))
      {
         cnt++;
      }
      else
      {
         if (cnt > 0)
         {
            dp.pb(cnt);
            cnt = 0;
         }
      }
   }
   if (hai || s[0] == 'm' || s[0] == 'w')
   {
      pl(0);
      return;
   }
   if (cnt > 0)
   {
      dp.pb(cnt);
   }
   ll res = 1;
   for (auto x : dp)
   {
      res = res * fib[x + 1];
      res %= mod;
   }
   pl(res);
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   while (test_cases--)
   {
      solve();
   }
   return 0;
}