#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define ll long long
using namespace std;
const int MAX = 1e5 + 9;
vector<bool> prime(MAX, 1);
void sieve() {
   prime[0] = prime[1] = 0;
   for (ll i = 4; i < MAX; i += 2) {
      prime[i] = 0;
   }
   for (ll i = 3; i < MAX; i += 2) {
      if (prime[i]) {
         for (ll j = i * i; j < MAX; j += i) {
            prime[j] = 0;
         }
      }
   }
}
void dfs(int x, int p, vector<int>& mark, vector<vector<int> > g, vector<int>& v, vector<int>& sz) {
   mark[x] = 1;
   for (int y : g[x]) {
      if (y != p) {
         dfs(y, x, mark, g, v, sz);
         sz[x] += sz[y];
      }
   }
   sz[x] += v[x - 1];
}

vector<int> solve(int n, vector<int>& f, vector<int>& s, vector<int>& v, vector<int>& q) {
   for (int i = 0; i < n; i++) {
      if (prime[v[i]]) {
         v[i] = 1;
      } else {
         v[i] = 0;
      }
   }
   int m = f.size();
   vector<vector<int> > g(n + 1);
   vector<int> mark(n + 1, 0), sz(n + 1, 0);
   for (int i = 0; i < m; i++) {
      int u = f[i], v = s[i];
      g[u].push_back(v), g[v].push_back(u);
   }
   for (int i = 1; i <= n; i++) {
      if (mark[i] == 0) {
         dfs(i, 0, mark, g, v, sz);
      }
   }
   vector<int> ans;
   for (int i = 0; i < q.size(); i++) {
      ans.push_back(sz[q[i]]);
   }
   return ans;
}
signed main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   sieve();
   int n, m;
   cin >> n >> m;
   vector<int> f(m), s(m), v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }
   for (int i = 0; i < m; i++) {
      cin >> f[i] >> s[i];
   }
   int q;
   cin >> q;
   vector<int> que(q);
   for (int& x : que) cin >> x;
   vector<int> ans = solve(n, f, s, v, que);
   for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] << endl;
   }
}