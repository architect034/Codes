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
void pre()
{
}
void solve()
{
   string s;
   cin >> s;
   int n = s.size();
   int mx = 0;
   string res = "";
   for (int i = 1; i <= n; i++)
   {
      string tmp = s.substr(0, i);
      int ss = tmp.size();
      bool fl = 1;
      for (int j = 0; j < ss; j++)
      {
         if (tmp[j] != tmp[ss - 1 - j])
         {
            fl = 0;
            break;
         }
      }
      if (fl)
      {
         if (ss > mx)
         {
            mx = ss;
            res = tmp;
         }
      }
   }
   string naya = s;
   reverse(all(naya));
   for (int i = 1; i <= n; i++)
   {
      string tmp = naya.substr(0, i);
      reverse(all(tmp));
      int ss = tmp.size();
      bool fl = 1;
      for (int j = 0; j < ss; j++)
      {
         if (tmp[j] != tmp[ss - 1 - j])
         {
            fl = 0;
            break;
         }
      }
      if (fl)
      {
         if (ss > mx)
         {
            mx = ss;
            res = tmp;
         }
      }
   }
   string f1 = "", f2 = "";
   string m = "";
   string w = "";
   for (int i = 0; i < n; i++)
   {
      if (s[i] != s[n - 1 - i])
      {
         for (int j = i; j <= n - 1 - i; j++)
         {
            w += s[j];
         }
         break;
      }
      else if (i <= (n - 1 - i))
      {
         f1 += s[i];
         if (i != n - 1 - i)
            f2 += s[i];
      }
   }
   reverse(all(f2));
   int nn = w.size(), nmx = 0;
   for (int i = 1; i <= nn; i++)
   {
      string tmp = w.substr(0, i);
      int ss = tmp.size();
      bool fl = 1;
      for (int j = 0; j < ss; j++)
      {
         if (tmp[j] != tmp[ss - 1 - j])
         {
            fl = 0;
            break;
         }
      }
      if (fl)
      {
         if (ss > nmx)
         {
            nmx = ss;
            m = tmp;
         }
      }
   }
   naya = "";
   naya = w;
   reverse(all(naya));
   for (int i = 0; i <= nn; i++)
   {
      string tmp = naya.substr(0, i);
      reverse(all(tmp));
      int ss = tmp.size();
      bool fl = 1;
      for (int j = 0; j < ss; j++)
      {
         if (tmp[j] != tmp[ss - 1 - j])
         {
            fl = 0;
            break;
         }
      }
      if (fl)
      {
         if (ss > nmx)
         {
            nmx = ss;
            m = tmp;
         }
      }
   }
   string f = f1 + m + f2;
   if ((int)f.size() > mx)
   {
      cout << f << "\n";
   }
   else
   {
      cout << res << "\n";
   }
}
int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int _ = 1;
   cin >> _;
   while (_--)
   {
      solve();
   }
   return 0;
}