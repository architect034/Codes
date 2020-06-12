#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define pb push_back
#define ff first
#define ss second
#define ll long long
using namespace std;
const int MAX = 1e6 + 9;
int solve(vector<vector<int> > v, int a, int b) {
   int n = v.size(), m = v[0].size(), coins = 0;
   vector<pair<int, int> > req;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (v[i][j] == 2) {
            coins++;
            req.pb({i, j});
         }
      }
   }
   map<vector<pair<int, int> >, int> dist;
   for (int i = 0; i < req.size(); i++) {
      for (int j = 0; j < req.size(); j++) {
         if (i == j) continue;
         dist[{{req[i].ff, req[i].ss}, {req[j].ff, req[j].ss}}] = MAX;
      }
   }
   for (int i = 0; i < req.size(); i++) {
      dist[{{0, 0}, {req[i].ff, req[i].ss}}] = MAX;
      dist[{{req[i].ff, req[i].ss}, {0, 0}}] = MAX;
      dist[{{a, b}, {req[i].ff, req[i].ss}}] = MAX;
      dist[{{req[i].ff, req[i].ss}, {a, b}}] = MAX;
   }
   dist[{{a, b}, {0, 0}}] = MAX;
   dist[{{0, 0}, {a, b}}] = MAX;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (!(v[i][j] == 2 || (i == 0 && j == 0) || (i == a && j == b))) continue;
         vector<vector<int> > vis(n + 1, vector<int>(m + 1, 0));
         vector<vector<int> > dis(n + 1, vector<int>(m + 1, MAX));
         queue<vector<int> > q;
         q.push({i, j, 0});
         dis[0][0] = 0;
         vis[i][j] = 1;
         while (!q.empty()) {
            int x = q.front()[0], y = q.front()[1], d = q.front()[2];
            if (v[x][y] == 2 || (x == 0 && y == 0) || (x == a && y == b)) {
               dist[{{x, y}, {i, j}}] = min(dist[{{x, y}, {i, j}}], d);
               dist[{{i, j}, {x, y}}] = min(dist[{{i, j}, {x, y}}], d);
            }
            q.pop();
            if (y - 1 >= 0 && v[x][y - 1] != 1 && vis[x][y - 1] == 0) {
               vis[x][y - 1] = 1;
               q.push({x, y - 1, d + 1});
               dis[x][y - 1] = d + 1;
            }
            if (x - 1 >= 0 && v[x - 1][y] != 1 && vis[x - 1][y] == 0) {
               vis[x - 1][y] = 1;
               q.push({x - 1, y, d + 1});
               dis[x - 1][y] = d + 1;
            }
            if (y + 1 < m && v[x][y + 1] != 1 && vis[x][y + 1] == 0) {
               vis[x][y + 1] = 1;
               q.push({x, y + 1, d + 1});
               dis[x][y + 1] = d + 1;
            }
            if (x + 1 < n && v[x + 1][y] != 1 && vis[x + 1][y] == 0) {
               vis[x + 1][y] = 1;
               q.push({x + 1, y, d + 1});
               dis[x + 1][y] = d + 1;
            }
         }
      }
   }
   if (!coins) {
      return (dist[{{0, 0}, {a, b}}] >= MAX) ? -1 : dist[{{0, 0}, {a, b}}];
   }
   sort(req.begin(), req.end());
   int ans = MAX;
   do {
      int stx = req[0].ff, sty = req[0].ss;
      int enx = req.back().ff, eny = req.back().ss;
      int dis = 0;
      for (int i = 1; i < req.size(); i++) {
         dis += (dist[{{req[i].ff, req[i].ss}, {req[i - 1].ff, req[i - 1].ss}}]);
      }
      dis += (dist[{{0, 0}, {stx, sty}}] + dist[{{a, b}, {enx, eny}}]);
      ans = min(ans, dis);
   } while (next_permutation(req.begin(), req.end()));
   return (ans >= MAX) ? -1 : ans;
}
signed main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   int n, m;
   cin >> n >> m;
   vector<vector<int> > v(n, vector<int>(m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> v[i][j];
      }
   }
   int a, b;
   cin >> a >> b;
   cout << solve(v, a, b);
}