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
const ll mod = 1e9 + 9;
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
   ll n, a, b, k;
   cin >> n >> a >> b >> k;
   string s;
   cin >> s;
   ll r = (power(b, k, mod) * power(power(a, k, mod), mod - 2, mod)) % mod;
   ll no_of_terms = (n + 1) / k;
   ll res = 0, i = 0;
   for (auto c : s)
   {
      ll ft = ((power(a, n - i, mod) % mod) * (power(b, i, mod) % mod)) % mod;
      ll mul = 1;
      if (r == 1)
      {
         ft = (ft * no_of_terms) % mod;
      }
      else if (b < a)
      {
         mul = power((1 - r), mod - 2, mod);
         ll rn = power(r, no_of_terms, mod);
         rn = (1 - rn + mod) % mod;
         mul = (mul * rn) % mod;
      }
      else
      {
         mul = power((r - 1), mod - 2, mod);
         ll rn = power(r, no_of_terms, mod);
         rn = (rn - 1 + mod) % mod;
         mul = (mul * rn) % mod;
      }
      ft = (ft * mul) % mod;
      if (c == '+')
      {
         res += ft;
         res += mod;
         res %= mod;
      }
      else
      {
         res -= ft;
         res = (res + mod) % mod;
      }
      ++i;
   }
   cout << res;
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