#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define rf for (int i = n; i >= 0; i--)
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
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   for (ll i = 4; i < MAX; i += 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   for (ll i = 3; i < MAX; i += 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         for (ll j = i * i; j < MAX; j += i) {
            prime[j] = 0;
            if (spf[j] == 1) {
               spf[j] = i;
            }
         }
      }
   }
}
ll power(ll a, ll b) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
ll power(ll a, ll b, ll m) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void real_main(int xx) {
   ll n, T, a, b;
   cin >> n >> T >> a >> b;
   vector<ll> ty(n);
   ll total_easy = 0, total_hard = 0;
   vector<pair<ll, pair<ll, ll>>> t(n);
   for (ll& x : ty) {
      cin >> x;
      if (x)
         total_hard++;
      else
         total_easy++;
   }
   vector<ll> p, q;
   for (ll i = 0; i < n; i++) {
      cin >> t[i].ff;
      q.pb(t[i].ff);
      t[i].ss.ss = i;
      t[i].ss.ff = ty[i];
   }
   sort(all(t));
   vector<ll> ev, hv;
   for (ll i = 0; i < n; i++) {
      if (t[i].ss.ff == 0) {
         ev.pb(1);
         hv.pb(0);
      } else {
         ev.pb(0);
         hv.pb(1);
      }
   }
   for (ll i = 0; i < n; i++) {
      p.pb(t[i].ff);
      if (i) {
         ev[i] += ev[i - 1];
         hv[i] += hv[i - 1];
      }
   }
   ll h = 0, e = 0, hx = 0, ex = 0;
   map<ll, pair<ll, ll>> m;
   for (ll i = 0; i < n; i++) {
      ll x = t[i].ff - 1;
      ll it = upper_bound(all(p), x) - p.begin() - 1;
      if (it == -1) {
         m[x] = {0, 0};
         continue;
      }
      m[x] = {ev[it], hv[it]};
   }
   m[T] = {ev[n - 1], hv[n - 1]};
   ll res = 0;
   for (auto x : m) {
      ll time = x.ff;
      ll easy = x.ss.ff, hard = x.ss.ss;
      ll kitna = easy * a + hard * b;
      ll bacha = time - kitna;
      if (bacha >= 0) {
         int extra_easy = min(total_easy - easy, bacha / a);
         bacha -= extra_easy * a;
         int extra_hard = min(total_hard - hard, bacha / b);
         res = max(res, easy + hard + extra_easy + extra_hard);
      }
   }
   cout << res << "\n";
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main(i);
   }
   return 0;
}
