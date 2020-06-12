#include "bits/stdc++.h"
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define all(something) something.begin(), something.end()
using namespace std;
const int MAX = 1e5 + 9;
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
#define int long long
void real_main() {
   int n, m, coins = 0;
   cin >> n >> m;
   vector<vector<int> > v(n + 2, vector<int>(m + 2));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> v[i][j];
         if (v[i][j] == 2) coins++;
      }
   }
   int a, b;
   cin >> a >> b;
   ++a, ++b;
   dbg(coins);
   vector<pair<int, int> > req;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (v[i][j] == 2) {
            req.pb({i, j});
         }
      }
   }
   map<vector<pair<int, int> >, int> dist;
   for (int i = 0; i < req.size(); i++) {
      for (int j = 0; j < req.size(); j++) {
         if (i == j) continue;
         dist[{{req[i].ff, req[i].ss}, {req[j].ff, req[j].ss}}] = INT_MAX;
      }
   }
   for (int i = 0; i < req.size(); i++) {
      dist[{{1, 1}, {req[i].ff, req[i].ss}}] = INT_MAX;
      dist[{{req[i].ff, req[i].ss}, {1, 1}}] = INT_MAX;
      dist[{{a, b}, {req[i].ff, req[i].ss}}] = INT_MAX;
      dist[{{req[i].ff, req[i].ss}, {a, b}}] = INT_MAX;
   }
   dist[{{a, b}, {1, 1}}] = INT_MAX;
   dist[{{1, 1}, {a, b}}] = INT_MAX;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (!(v[i][j] == 2 || (i == 1 && j == 1) || (i == a && j == b))) continue;
         vector<vector<int> > vis(n + 2, vector<int>(m + 2, 0));
         vector<vector<int> > dis(n + 2, vector<int>(m + 2, INT_MAX));
         queue<vector<int> > q;
         q.push({i, j, 0});
         dis[1][1] = 0;
         vis[i][j] = 1;
         while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1], d = q.front()[2];
            if (v[x][y] == 2 || (x == 1 && y == 1) || (x == a && y == b)) {
               dist[{{x, y}, {i, j}}] = min(dist[{{x, y}, {i, j}}], d);
               dist[{{i, j}, {x, y}}] = min(dist[{{i, j}, {x, y}}], d);
            }
            q.pop();
            if (y - 1 >= 1 && v[x][y - 1] != 1 && vis[x][y - 1] == 0) {
               vis[x][y - 1] = 1;
               q.push({x, y - 1, d + 1});
               dis[x][y - 1] = d + 1;
            }
            if (x - 1 >= 1 && v[x - 1][y] != 1 && vis[x - 1][y] == 0) {
               vis[x - 1][y] = 1;
               q.push({x - 1, y, d + 1});
               dis[x - 1][y] = d + 1;
            }
            if (y + 1 <= m && v[x][y + 1] != 1 && vis[x][y + 1] == 0) {
               vis[x][y + 1] = 1;
               q.push({x, y + 1, d + 1});
               dis[x][y + 1] = d + 1;
            }
            if (x + 1 <= n && v[x + 1][y] != 1 && vis[x + 1][y] == 0) {
               vis[x + 1][y] = 1;
               q.push({x + 1, y, d + 1});
               dis[x + 1][y] = d + 1;
            }
         }
      }
   }
   if (!coins) {
      (dist[{{1, 1}, {a, b}}] >= INT_MAX) ? cout << -1 << "\n" : cout << dist[{{1, 1}, {a, b}}] << "\n";
      return;
   }
   sort(all(req));
   int ans = INT_MAX;
   do {
      int stx = req[0].ff, sty = req[0].ss;
      int enx = req.back().ff, eny = req.back().ss;
      int dis = 0;
      for (int i = 1; i < req.size(); i++) {
         dis += (dist[{{req[i].ff, req[i].ss}, {req[i - 1].ff, req[i - 1].ss}}]);
      }
      dis += (dist[{{1, 1}, {stx, sty}}] + dist[{{a, b}, {enx, eny}}]);
      ans = min(ans, dis);
   } while (next_permutation(all(req)));
   (ans >= INT_MAX) ? cout << -1 << "\n" : cout << ans << "\n";
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
