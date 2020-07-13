#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define int long long
long long mod = 998244353;
void solve();
signed main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}
int power(int a, int b, int m) {
   int res = 1LL;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
void solve() {
   int n, x;
   cin >> n >> x;
   vector<int> v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }
   vector<int> a(n);
   a[0] = v[0];
   for (int i = 1; i < n; i++) {
      a[i] = (a[i - 1] * x) % mod + v[i];  // for same v[i]
      // a[i] = a[i - 1] + (v[i] * power(x, i, mod));
   }
   for (int i = 0; i < n; i++) {
      a[i] = power(a[i], 2, mod);
      a[i] %= mod;
   }
   int ans = 1;
   for (int i = 1; i < n; i++) {
      a[i] *= a[i - 1];
      a[i] %= mod;
   }
   for (int i = 0; i < n; i++) {
      ans *= (a[i]);
      ans %= mod;
   }
   cout << ans << "\n";
}