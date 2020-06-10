#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
#define ll long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ff first
#define ss second
#define endl '\n'
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << endl
#define PI 3.14159265358979323846
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
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
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
// typedef tree< pair<int,int> ,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
template <typename T>
void in(T &x) {
   cin >> x;
}
template <typename T, typename U>
void in(T &x, U &y) {
   cin >> x >> y;
}
template <typename T, typename U, typename V>
void in(T &x, U &y, V &z) {
   cin >> x >> y >> z;
}
template <typename T>
void ps(T x) {
   cout << x << " ";
}
template <typename T>
void ps(const vector<T> &x, int n) {
   for (int i = 0; i < n; i++) {
      cout << x[i];
      (i == n - 1) ? cout << endl : cout << " ";
   }
}
template <typename T>
void pl(T x) {
   cout << x << endl;
}
template <typename T>
void pl(const vector<T> &x, int n) {
   for (int i = 0; i < n; i++) {
      cout << x[i] << "\n";
   }
}
template <typename T>
T power(T a, T b) {
   T res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
template <typename T>
T power(T a, T b, T m) {
   T res = 1;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
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
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
