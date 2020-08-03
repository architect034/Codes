#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define IOE ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
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
const int MAX = 2e5 + 9;
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
void _IOE() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
// #define int long long
class Solution {
  public:
   int shortestBridge(vector<vector<int> > &v) {
      int n = v.size(), m = v[0].size();
      int vis[n][m];
      int p = 2;
      vector<vector<pair<int, int> > > islands(2);
      memset(vis, 0, sizeof vis);
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
               queue<pair<int, int> > q;
               q.push({i, j});
               vis[i][j] = 1;
               v[i][j] = p;
               islands[p - 2].push_back({i, j});
               while (!q.empty()) {
                  int x = q.front().first;
                  int y = q.front().second;
                  q.pop();
                  if (y - 1 >= 0 && v[x][y - 1] == 1 && vis[x][y - 1] == 0) {
                     q.push({x, y - 1});
                     vis[x][y - 1] = 1;
                     v[x][y - 1] = p;
                     islands[p - 2].push_back({x, y - 1});
                  }
                  if (x - 1 >= 0 && v[x - 1][y] == 1 && vis[x - 1][y] == 0) {
                     q.push({x - 1, y});
                     vis[x - 1][y] = 1;
                     v[x - 1][y] = p;
                     islands[p - 2].push_back({x - 1, y});
                  }
                  if (y + 1 < m && vis[x][y + 1] == 0 && v[x][y + 1] == 1) {
                     q.push({x, y + 1});
                     vis[x][y + 1] = 1;
                     v[x][y + 1] = p;
                     islands[p - 2].push_back({x, y + 1});
                  }
                  if (x + 1 < n && v[x + 1][y] == 1 && vis[x + 1][y] == 0) {
                     q.push({x + 1, y});
                     vis[x + 1][y] = 1;
                     v[x + 1][y] = p;
                     islands[p - 2].push_back({x + 1, y});
                  }
               }
               p++;
            }
         }
      }
      int ans = INT_MAX;
      for (int i = 0; i < islands[0].size(); i++) {
         for (int j = 0; j < islands[1].size(); j++) {
            int x1 = islands[0][i].first, y1 = islands[0][i].second;
            int x2 = islands[1][j].first, y2 = islands[1][j].second;
            ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);
         }
      }
      return ans;
   }
   void solution() {
      int n, m;
      cin >> n >> m;
      vector<vector<int> > v(n, vector<int>(m));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> v[i][j];
         }
      }
      cout << shortestBridge(v);
   }
};
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      Solution obj;
      obj.solution();
   }
   return 0;
}
