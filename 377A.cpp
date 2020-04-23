#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl cout << endl
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
   ll res = 1;
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
#endif
}
// #define int long long
int vis[501][501], dis[501][501];
int nn, mm;
void bfs(vector<vector<char>> v, int x, int y) {
   queue<pair<int, int>> q;
   q.push({x, y});
   vis[x][y] = 1;
   dis[x][y] = 1;
   while (!q.empty()) {
      int n = q.front().ff, m = q.front().ss;
      int d = dis[n][m];
      q.pop();
      if (m - 1 >= 0 && vis[n][m - 1] == 0 && v[n][m - 1] == '.') {
         dis[n][m - 1] = d + 1;
         vis[n][m - 1] = 1;
         q.push({n, m - 1});
      }
      if (n - 1 >= 0 && vis[n - 1][m] == 0 && v[n - 1][m] == '.') {
         dis[n - 1][m] = d + 1;
         vis[n - 1][m] = 1;
         q.push({n - 1, m});
      }
      if (m + 1 < mm && vis[n][m + 1] == 0 && v[n][m + 1] == '.') {
         vis[n][m + 1] = 1;
         dis[n][m + 1] = d + 1;
         q.push({n, m + 1});
      }
      if (n + 1 < nn && vis[n + 1][m] == 0 && v[n + 1][m] == '.') {
         vis[n + 1][m] = 1;
         dis[n + 1][m] = d + 1;
         q.push({n + 1, m});
      }
   }
}
void real_main() {
   int k;
   cin >> nn >> mm >> k;
   vector<vector<char>> v(nn, vector<char>(mm));
   for (int i = 0; i < nn; i++) {
      for (int j = 0; j < mm; j++) {
         cin >> v[i][j];
      }
   }
   memset(vis, 0, sizeof vis);
   for (int i = 0; i < nn; i++) {
      for (int j = 0; j < mm; j++) {
         if (v[i][j] == '.' && vis[i][j] == 0) {
            bfs(v, i, j);
            break;
         }
      }
   }
   vector<pair<int, pair<int, int>>> res;

   for (int i = 0; i < nn; i++) {
      for (int j = 0; j < mm; j++) {
         if (vis[i][j]) {
            res.pb({dis[i][j], {i, j}});
         }
      }
   }
   sort(all(res));
   reverse(all(res));
   for (int i = 0; i < k; i++) {
      int x = res[i].ss.ff, y = res[i].ss.ss;
      v[x][y] = 'X';
   }
   for (int i = 0; i < nn; i++) {
      for (int j = 0; j < mm; j++) {
         cout << v[i][j];
      }
      nl;
   }
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
