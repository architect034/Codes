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
// #define int long long
void real_main() {
   int n, m, gcount = 0;
   cin >> n >> m;
   vector<vector<char> > v(n + 2, vector<char>(m + 2, 'A'));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         cin >> v[i][j];
         if (v[i][j] == 'G') gcount++;
      }
   }
   if (gcount == 0) {
      yes;
      return;
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (v[i][j] == 'B') {
            if (v[i][j - 1] == 'G' || v[i - 1][j] == 'G' || v[i][j + 1] == 'G' || v[i + 1][j] == 'G') {
               no;
               return;
            }
         }
      }
   }
   vector<vector<int> > done(n + 2, vector<int>(m + 2, 0));
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (v[i][j] != 'G') continue;
         queue<pair<int, int> > q;
         vector<vector<int> > mark(n + 2, vector<int>(m + 2, 0));
         q.push({i, j});
         mark[i][j] = 1;
         while (!q.empty()) {
            int x = q.front().ff, y = q.front().ss;
            if (done[x][y] == 1) {
               done[i][j] = 1;
               break;
            }
            q.pop();
            if (v[x][y - 1] == 'B' || v[x - 1][y] == 'B' || v[x][y + 1] == 'B' || v[x + 1][y] == 'B') continue;
            if (x == n && y == m) {
               done[i][j] = 1;
               break;
            }
            if (y - 1 >= 1 && v[x][y - 1] != '#' && mark[x][y - 1] == 0) {
               q.push({x, y - 1});
               mark[x][y - 1] = 1;
            }
            if (x - 1 >= 1 && v[x - 1][y] != '#' && mark[x - 1][y] == 0) {
               q.push({x - 1, y});
               mark[x - 1][y] = 1;
            }
            if (x + 1 <= n && v[x + 1][y] != '#' && mark[x + 1][y] == 0) {
               q.push({x + 1, y});
               mark[x + 1][y] = 1;
            }
            if (y + 1 <= m && v[x][y + 1] != '#' && mark[x][y + 1] == 0) {
               q.push({x, y + 1});
               mark[x][y + 1] = 1;
            }
         }
      }
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         if (v[i][j] == 'G' && !done[i][j]) {
            no;
            return;
         }
      }
   }
   yes;
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
