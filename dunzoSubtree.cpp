#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
#define ll long long
#define pb push_back
#define all(something) something.begin(), something.end()
using namespace std;
const int MAX = 1e5 + 9;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1), primes;
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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
// #define int long long
vector<int> g[MAX], v(MAX), sz(MAX, 0), mark(MAX, 0);
void dfs(int x, int p) {
   mark[x] = 1;
   for (int y : g[x]) {
      if (y != p) {
         dfs(y, x);
         sz[x] += sz[y];
      }
   }
   sz[x] += v[x];
   dbg(x, sz);
}
void real_main() {
   sieve();
   int n, m;
   cin >> n >> m;
   for (int i = 1; i <= n; i++) {
      cin >> v[i];
      if (prime[v[i]]) {
         v[i] = 1;
      } else {
         v[i] = 0;
      }
   }
   for (int i = 0; i < m; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      g[u1].pb(u2), g[u2].pb(u1);
   }
   for (int i = 1; i <= n; i++) {
      if (mark[i] == 0) {
         dfs(i, 0);
      }
   }
   int q;
   cin >> q;
   while (q--) {
      int x;
      cin >> x;
      cout << sz[x] << "\n";
   }
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   for (int i = 1; i <= test_cases; i++) {
      real_main();
   }
   return 0;
}
