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
   int n;
   map<int, int> m;
   cin >> n;
   int idx = 1, ans = -1;
   vector<int> h(n + 1, 0);
   for (int i = 0; i < n; i++)
   {
      int c;
      cin >> c;
      vector<int> v(c);
      for (int j = 0; j < c; j++)
      {
         cin >> v[j];
      }
      bool say = 0;
      for (int j = 0; j < c; j++)
      {
         if (!h[v[j]])
         {
            say = true;
            h[v[j]] = 1;
            if (v[j] == idx)
            {
               while (h[idx])
               {
                  idx++;
               }
            }
            break;
         }
      }
      if (!say)
      {
         m[i + 1] = 1;
         // h[idx] = 1;
      }
   }
   if (m.size())
   {
      auto x = m.begin();
      for (int i = 1; i <= n; i++)
      {
         if (!h[i])
         {
            cout << "IMPROVE\n";
            cout << x->ff << " " << i << "\n";
            return;
         }
      }
   }
   cout << "OPTIMAL\n";
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--)
   {
      solve();
   }
   return 0;
}