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
bool check(vector<pair<int, int>> v)
{
   sort(all(v));
   int n = v.size();
   // cout << "checking\n";
   // for (int i = 0; i < n; i++)
   // {
   //    cout << v[i].ss << " " << v[i].ff << "\n";
   // }
   // cout << "checking end\n";
   for (int i = 1; i < n; i++)
   {
      if (v[i].ff < v[i - 1].ss)
      {
         return false;
      }
   }
   return true;
}
void solve(int tc)
{
   int n;
   cin >> n;
   vector<pair<int, pair<int, int>>> in(n);
   for (int i = 0; i < n; i++)
   {
      cin >> in[i].ff >> in[i].ss.ff;
      in[i].ss.ss = i;
   }
   sort(all(in));
   map<int, int> m;
   for (int i = 0; i < n; i++)
   {
      m[in[i].ss.ss] = i;
   }
   vector<char> res(n);
   res[in[0].ss.ss] = 'J';
   int last = in[0].ss.ff;
   // cout << in[0].ff << " " << in[0].ss.ff << " Add hua\n";
   for (int i = 1; i < n; i++)
   {
      if (in[i].ff >= last)
      {
         res[in[i].ss.ss] = 'J';
         last = in[i].ss.ff;
         // cout << in[i].ff << " " << in[i].ss.ff << " Add hua\n";
      }
   }

   vector<pair<int, int>> tmp;
   for (int i = 0; i < n; i++)
   {
      if (res[i] != 'J')
      {
         res[i] = 'C';
         int idx = m[i];
         tmp.pb({in[idx].ff, in[idx].ss.ff});
      }
   }
   // for (char c : res)
   // {
   //    cout << c;
   // }
   // nl;

   if (check(tmp))
   {
      cout << "Case #" << tc << ": ";
      for (char ch : res)
      {
         cout << ch;
      }
      nl;
   }
   else
   {
      cout << "Case #" << tc << ": IMPOSSIBLE\n";
   }
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++)
   {
      solve(i);
   }
   return 0;
}