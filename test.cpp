#include <bits/stdc++.h>
using namespace std;
vector<int> e[100005];
int p[100005], h[100005], n, sz[100005];
bool res;
void dfs(int u, int fa) {
   int tmp = 0;
   sz[u] = p[u];
   for (int v : e[u])
      if (v != fa) dfs(v, u), tmp += h[v], sz[u] += sz[v];
   if (h[u] < tmp - p[u] || h[u] > sz[u]) res = false;
   int o = h[u] - tmp;
   if ((o ^ p[u]) & 1) res = false;
}
int main() {
   int T;
   scanf("%d", &T);
   while (T--) {
      scanf("%d%*d", &n);
      res = true;
      for (int i = 1; i <= n; i++) scanf("%d", &p[i]), e[i].clear();
      for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
      for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), e[u].emplace_back(v), e[v].emplace_back(u);
      dfs(1, 0);
      puts(res ? "YES" : "NO");
   }
   return 0;
}
