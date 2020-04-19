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
void solve()
{
   ll n;
   cin >> n;
   vector<ll> v;
   ll sq = n;
   ll xx = sqrt(n);
   ll srt = sqrt(sqrt(n));
   for (ll j = 1; j <= srt; j++)
   {
      if (xx % j == 0)
      {
         v.push_back(j);
         if (j != xx / j)
         {
            v.push_back(xx / j);
         }
      }
   }
   sort(v.begin(), v.end());
   deque<ll> asli;
   map<ll, ll> mark;
   ll l = v.size();
   for (ll j = 0; j < l; j++)
   {
      for (ll k = j; k < l; k++)
      {
         ll val = v[j] * v[k];
         // if (val > 1000)
         // {
         //    break;
         // }
         if (mark[val] == 0)
         {
            asli.push_back(val);
            mark[val] = 1;
            if (/*sq / val <= 1000 &&*/ mark[sq / val] == 0)
            {
               asli.push_back(sq / val);
               mark[sq / val] = 1;
            }
         }
      }
   }
   sort(all(asli));
   // asli.popf();
   // for (auto x : asli)
   // {
   //    cout << x << "\n";
   // }
   // nl;
   ll sz = asli.size();
   ll red = 0, green = 0;
   for (ll i = 0; i < sz / 2; i++)
   {
      ll d = asli[sz - 1 - i] - asli[i];
      if (!i)
      {
         red += (d * d);
         continue;
      }
      if (i % 2 == 0)
      {
         red += (d * d);

         green -= (d * d);
      }
      else
      {
         green += (d * d);
         red -= (d * d);
      }
      // cout << red << " red\n";
      // cout << green << " green\n";
   }
   cout << red << " " << green << "\n";
}
int main()
{
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++)
   {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}