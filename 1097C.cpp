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
   cin >> n;
   int balanced = 0;
   map<int, int> open, close;
   while (n--)
   {
      string x;
      cin >> x;
      stack<char> s;
      int l = x.length();
      for (int i = 0; i < l; i++)
      {
         if (s.size() == 0)
         {
            s.push(x[i]);
         }
         else if (x[i] == '(')
         {
            s.push(x[i]);
         }
         else if (x[i] == ')')
         {
            if (s.top() == '(')
            {
               s.pop();
            }
            else
            {
               s.push(x[i]);
            }
         }
      }
      set<char> st;
      l = s.size();
      if (l == 0)
      {
         balanced++;
         continue;
      }
      while (!s.empty())
      {
         st.insert(s.top());
         s.pop();
      }
      if (st.size() == 1)
      {
         auto it = st.begin();
         if (*it == '(')
         {
            open[l]++;
         }
         else
         {
            close[l]++;
         }
      }
   }
   int res = balanced / 2;
   for (auto x : open)
   {
      res += min(x.ss, close[x.ff]);
   }
   cout << res << "\n";
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