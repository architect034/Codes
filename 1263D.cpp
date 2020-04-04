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
int root(int x, vector<int> &par)
{
   while (x != par[x])
   {
      x = par[x];
      par[x] = par[par[x]];
   }
   return x;
}
void u(int x, int y, vector<int> &par, vector<int> &size)
{
   int rx = root(x, par);
   int ry = root(y, par);
   if (rx == ry)
   {
      return;
   }
   else
   {
      if (size[rx] >= size[ry])
      {
         size[rx] += size[ry];
         size[ry] = 0;
         par[ry] = rx;
      }
      else
      {
         size[ry] += size[rx];
         size[rx] = 0;
         par[rx] = ry;
      }
   }
}
void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> v(26);
   for (int i = 0; i < n; i++)
   {
      string s;
      cin >> s;
      for (auto c : s)
      {
         v[c - 'a'].pb(i);
      }
   }
   vector<int> par(n), size(n, 1);
   for (int i = 0; i < n; i++)
      par[i] = i;
   for (int i = 0; i < 26; i++)
   {
      int l = v[i].size();
      for (int j = 0; j < l - 1; j++)
      {
         int x = v[i][j], y = v[i][j + 1];
         u(x, y, par, size);
      }
   }
   set<int> s;
   for (int i = 0; i < n; i++)
   {
      s.insert(root(i, par));
   }
   cout << (int)s.size() << "\n";
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