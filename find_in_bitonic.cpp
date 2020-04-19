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
int dhundhoasc(vector<int> v, int low, int high, int x)
{
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (v[mid] == x)
      {
         return mid;
      }
      else if (v[mid] > x)
      {
         high = mid - 1;
      }
      else
      {
         low = mid + 1;
      }
   }
   return -1;
}
int dhundhodesc(vector<int> v, int low, int high, int x)
{
   while (low <= high)
   {
      int mid = (low + high) / 2;
      if (v[mid] == x)
      {
         return mid;
      }
      else if (v[mid] > x)
      {
         low = mid + 1;
      }
      else
      {
         high = mid - 1;
      }
   }
   return -1;
}
void solve()
{
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &x : v)
      cin >> x;
   int f;
   cin >> f;
   int bitonic_point = -1;
   int low = 1, high = n - 2;
   // cout << low << " " << high << "\n";
   while (low <= high)
   {
      int mid = (low + high) / 2;
      // cout << mid << " mid\n";
      if (v[mid] > v[mid - 1] && v[mid + 1] < v[mid])
      {
         bitonic_point = mid;
         break;
      }
      else
      {
         if (v[mid + 1] > v[mid])
         {
            low = mid + 1;
         }
         else
         {
            high = mid - 1;
         }
      }
   }
   if (bitonic_point != -1)
   {
      // cout << bitonic_point << " bp\n";
      int left = dhundhoasc(v, 0, bitonic_point, f);
      int right = dhundhodesc(v, bitonic_point + 1, n - 1, f);
      cout << max(left, right) << "\n";
   }
   else if (v[0] < v[n - 1])
   {
      cout << dhundhoasc(v, 0, n - 1, f) << "\n";
   }
   else
   {
      cout << dhundhodesc(v, 0, n - 1, f) << "\n";
   }
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