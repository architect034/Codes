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
void solve() {
   ll n, l, r;
   cin >> n >> l >> r;
   ll nn = n;
   ll x = 2 * (nn - 1);
   ll d = l;
   ll st = 1;
   while (x < l) {
      nn -= 1;
      d = l - x;
      st++;
      x += 2 * (nn - 1);
      if (nn == 1) {
         x++;
         break;
      }
   }
   ll t = d + (r - l);
   ll total = t;
   vector<ll> v;
   bool say = 0;
   for (ll i = st; i <= n; i++) {
      for (ll j = i + 1; j <= n; j++) {
         v.pb(i);
         v.pb(j);
         t -= 2;
         if (t <= 0) {
            say = 1;
            break;
         }
      }
      if (say) {
         break;
      }
   }
   v.pb(1);
   for (ll i = d - 1, cnt = 0; cnt < (r - l + 1); i++, cnt++) {
      cout << v[i] << " ";
   }
   nl;
}

int main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      int m;
      solve();
   }
   return 0;
}
