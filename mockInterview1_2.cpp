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
   int networkDelayTime(vector<vector<int>> &v, int n, int k) {
      vector<vector<pair<int, int>>> g(n + 1);
      for (int i = 0; i < v.size(); i++) {
         int x = v[i][0], y = v[i][1], wt = v[i][2];
         g[x].push_back({y, wt});
      }
      int vis[n + 1];
      memset(vis, 0, sizeof vis);
      int dis[n + 1];
      for (int i = 0; i <= n; i++) dis[i] = 1e9;
      dis[k] = 0;
      int cur = k;
      unordered_set<int> st;
      while (1) {
         dbg(st);
         vis[cur] = 1;
         for (int i = 0; i < g[cur].size(); i++) {
            int u = g[cur][i].first;
            if (vis[u]) continue;
            st.insert(u);
            int alt = dis[cur] + g[cur][i].second;
            if (alt < dis[u]) {
               dis[u] = alt;
            }
         }
         st.erase(cur);
         if (st.empty()) break;
         int minDis = 1e9;
         int idx = 1;
         for (int a : st) {
            if (dis[a] < minDis) {
               minDis = dis[a];
               idx = a;
            }
         }
         cur = idx;
      }
      int ans = 0;
      for (int i = 1; i <= n; i++) {
         if (dis[i] >= 1e9) return -1;
         ans = max(ans, dis[i]);
      }
      return ans;
   }
   void solution() {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> v;
      for (int i = 0; i < m; i++) {
         int x, y, w;
         cin >> x >> y >> w;
         v.push_back({x, y, w});
      }
      int k;
      cin >> k;
      cout << this->networkDelayTime(v, n, k);
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
