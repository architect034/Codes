#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 3e5 + 9;
vector<int> g[MAX], sz(MAX, 1), par(MAX, 0);
void dfs(int u, int pa) {
   for (int v : g[u]) {
      if (v != pa) {
         par[v] = u;
         dfs(v, u);
         sz[u] += sz[v];
      }
   }
}
signed main() {
   int n, a, b;
   cin >> n >> a >> b;
   for (int i = 0; i < n - 1; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      g[u1].push_back(u2), g[u2].push_back(u1);
   }
   int res = n * (n - 1);
   dfs(b, 0);
   int p = a;
   while (par[p] != b) {
      p = par[p];
   }
   res = res - sz[a] * (sz[b] - sz[p]);
   cout << res << "\n";
}