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
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   f(i, 4, MAX - 1, 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   f(i, 3, MAX - 1, 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         f(j, i * i, MAX - 1, i) {
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
void pre() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
ll fl(ll n) { return ~n; }
void solve() {
   ll n;
   cin >> n;
   vector<ll> v(n);
   for (ll& x : v) cin >> x;
   vector<ll> pre(n), suf(n + 1);
   suf[n] = INT_MAX;
   pre[0] = INT_MAX & ~v[0];
   suf[n - 1] = suf[n] & ~v[n - 1];
   for (ll i = 1; i < n; i++) {
      pre[i] = ~v[i] & pre[i - 1];
   }
   for (int i = n - 2; i >= 0; i--) {
      suf[i] = suf[i + 1] & ~v[i];
   }
   ll ans = 0, idx = 0;
   for (ll i = 0; i < n; i++) {
      if (i == 0) {
         if ((v[i] & suf[i + 1]) > ans) {
            idx = i;
         }
         ans = max(ans, v[i] & suf[i + 1]);
      } else {
         if ((pre[i - 1] & v[i] & suf[i + 1]) > ans) {
            idx = i;
         }
         ans = max(ans, pre[i - 1] & v[i] & suf[i + 1]);
      }
   }
   cout << v[idx] << " ";
   for (ll i = 0; i < n; i++) {
      if (i != idx) {
         cout << v[i] << " ";
      }
   }
   return;
   cout << ans << "\n";
}
signed main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}
