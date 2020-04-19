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
void solve(int tc)
{
   // cout << "Case #" << tc << ": ";
   int n, m;
   cin >> n >> m;
   char arr[n][m];
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         cin >> arr[i][j];
      }
   }
   if (n % 3 == 0)
   {
      int w = n / 3;
      map<char, int> m1, m2, m3;
      for (int i = 0; i < w; i++)
      {
         for (int j = 0; j < m; j++)
         {
            m1[arr[i][j]]++;
         }
      }
      for (int i = w; i < 2 * w; i++)
      {
         for (int j = 0; j < m; j++)
         {
            m2[arr[i][j]]++;
         }
      }
      for (int i = 2 * w; i < n; i++)
      {
         for (int j = 0; j < m; j++)
         {
            m3[arr[i][j]]++;
         }
      }
      if (!((m1.size() > 1 || m2.size() > 1 || m3.size() > 1) || (m1.begin()->ff == m2.begin()->ff) || (m2.begin()->ff == m3.begin()->ff) || (m1.begin()->ff == m3.begin()->ff)))
      {
         yes;
         return;
      }
   }
   if (m % 3 == 0)
   {
      int w = m / 3;
      map<char, int> m1, m2, m3;
      for (int i = 0; i < w; i++)
      {
         for (int j = 0; j < n; j++)
         {
            m1[arr[j][i]]++;
         }
      }
      for (int i = w; i < 2 * w; i++)
      {
         for (int j = 0; j < n; j++)
         {
            m2[arr[j][i]]++;
         }
      }
      for (int i = 2 * w; i < m; i++)
      {
         for (int j = 0; j < n; j++)
         {
            m3[arr[j][i]]++;
         }
      }
      if (!((m1.size() > 1 || m2.size() > 1 || m3.size() > 1) || (m1.begin()->ff == m2.begin()->ff) || (m2.begin()->ff == m3.begin()->ff) || (m1.begin()->ff == m3.begin()->ff)))
      {
         yes;
         return;
      }
   }
   no;
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++)
   {
      solve(i);
   }
   return 0;
}