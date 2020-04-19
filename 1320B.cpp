#include <bits/stdc++.h>
using namespace std;
#define fl(i, a, b) for (int i = a; i < b; i++)
#define ll long long
#define endl '\n'
#define pb push_back
#define ff first
#define ss second
#define mod 1000000007
#define inf 1e9
#define fast                     \
   ios_base::sync_with_stdio(0); \
   cin.tie(NULL);                \
   cout.tie(NULL);
#define mx 200005
int dis[mx];
bool vis[mx];
vector<int> v[mx], g[mx];
main() {
   fast;
   int n, m;
   cin >> n >> m;
   fl(i, 1, m + 1) {
      int x, y;
      cin >> x >> y;
      v[y].pb(x);
      g[x].pb(y);
   }
   int k;
   cin >> k;
   vector<int> p(k);
   for (int i = 0; i < k; i++) {
      cin >> p[i];
   }
   int x = p.back();
   queue<pair<int, int> > q;
   q.push({x, 0});
   vis[x] = 1;
   while (!q.empty()) {
      pair<int, int> p = q.front();
      q.pop();
      int x = p.ff;
      int d = p.ss;
      dis[x] = d;
      for (auto i : v[x]) {
         if (!vis[i]) {
            vis[i] = 1;
            q.push({i, d + 1});
         }
      }
   }
   ll ans1 = 0, ans2 = 0;
   fl(i, 0, p.size() - 1) {
      int d = dis[p[i]];
      int cnt = 0;
      bool flag = 1;
      for (auto j : g[p[i]]) {
         if (dis[j] == d - 1) {
            cnt++;
            if (j == p[i + 1]) {
               flag = 0;
            }
         }
      }
      ans2 += flag;
      ans1 += (flag | (cnt > 1));
   }
   cout << ans2 << " " << ans1 << endl;
}