#include "bits/stdc++.h"
#define IOE ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
using namespace std;
const ll MAX = 100 + 7;
int poi = 0;
vector<int> prime(MAX + 9, 0);
vector<ll> spf(MAX + 9, 0);
void sieve() {
   for (ll i = 2; i <= MAX; ++i) {
      if (!spf[i]) spf[i] = prime[++poi] = i;
      for (ll j = 1; i * prime[j] <= MAX; ++j) {
         spf[i * prime[j]] = prime[j];
         if (i % prime[j] == 0) break;
      }
   }
}
void _IOE() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
vector<int> h(MAX + 9, 0);
void _main() {
   sieve();
   int n, mx = 1;
   cin >> n;
   vector<int> v(n);
   int g = 0;
   for (int &i : v) cin >> i, mx = max(mx, i), g = __gcd(g, i);
   for (int i = 0; i < n; i++) {
      v[i] /= g;
      while (v[i] > 1) {
         h[spf[v[i]]]++;
         int sp = spf[v[i]];
         while (v[i] % sp == 0) {
            v[i] /= sp;
         }
      }
   }
   int ans = n;
   for (int i = 2; i <= mx; i++) {
      ans = min(ans, n - h[i]);
   }
   (ans == n) ? cout << (-1) : cout << (ans);
   dbg(prime);
}
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   for (int i = 1; i <= test_cases; i++) {
      _main();
   }
   return 0;
}
