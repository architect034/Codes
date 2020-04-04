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
#define int long long
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
bool check(int x, int n, int m, vector<int> cities, vector<int> towers)
{
   int mn = 0, mx = 0;
   for (int i = 0; i < m; i++)
   {
      int l = lower_bound(all(cities), towers[i] - x) - cities.begin();
      int r = upper_bound(all(cities), towers[i] + x) - cities.begin();
      if (!i)
      {
         mn = l;
         mx = r - 1;
      }
      else
      {
         if (l - 1 > mx)
         {
            return false;
         }
         else
         {
            mx = r - 1;
         }
      }
   }
   if (mn != 0 || mx != n - 1)
   {
      return false;
   }
   return true;
}
void solve()
{
   int n, m;
   cin >> n >> m;
   vector<int> cities(n), towers(m);
   for (int &x : cities)
   {
      cin >> x;
   }
   for (int &x : towers)
   {
      cin >> x;
   }
   sort(all(cities));
   sort(all(towers));
   int low = 0, high = 8e9 + 1, ans = 8e9 + 7;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      // cout << mid << "\n";
      if (check(mid, n, m, cities, towers))
      {
         // cout << "aya\n";
         ans = mid;
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   cout << ans << "\n";
}
int32_t main()
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