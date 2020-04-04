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
void pre()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
bool check(char c, string s, int x, int n)
{
   int cnt = 0;
   for (int i = 0; i < x; i++)
   {
      if (s[i] == c)
      {
         cnt++;
      }
   }
   if (!cnt)
   {
      return false;
   }
   for (int i = x; i < n; i++)
   {
      if (s[i - x] == c)
      {
         cnt--;
      }
      if (s[i] == c)
      {
         cnt++;
      }
      if (!cnt)
      {
         return false;
      }
   }
   return true;
}
void solve()
{
   string s;
   cin >> s;
   int n = s.length();
   int low = 0, high = n, ans = n;
   while (low <= high)
   {
      int mid = (low + high) / 2;
      bool say = false;
      for (char c = 'a'; c <= 'z'; c++)
      {
         if (check(c, s, mid, n))
         {
            say = true;
            break;
         }
      }
      if (say)
      {
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