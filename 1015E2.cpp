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
const int MAX = 1e3 + 9;
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
int n, m;
vector<vector<char> > v(MAX, vector<char>(MAX));
vector<vector<int> > rp(MAX, vector<int>(MAX, 0)), cp(MAX, vector<int>(MAX, 0));
bool check(int x, int i, int j) {
   int lsum = rp[i][j - 1] - (((j - x - 1) >= 0) ? rp[i][j - x - 1] : 0);
   int rsum = rp[i][j + x] - rp[i][j];
   int usum = cp[i - 1][j] - (((i - x - 1) >= 0) ? cp[i - x - 1][j] : 0);
   int dsum = cp[i + x][j] - cp[i][j];
   if (lsum == rsum && rsum == usum && usum == dsum && lsum == x) {
      return true;
   }
   return false;
}
void real_main() {
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> v[i][j];
         if (v[i][j] == '*') {
            rp[i][j] = 1;
            cp[i][j] = 1;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (j) rp[i][j] += rp[i][j - 1];
         if (i) cp[i][j] += cp[i - 1][j];
      }
   }
   map<pair<int, int>, int> mp;
   vector<vector<int> > rows(n, vector<int>(m + 1, 0)), col(n + 1, vector<int>(m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (v[i][j] == '.') continue;
         int low = 1, high = min({i, j, n - 1 - i, m - 1 - j}), ans = 0;
         while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid, i, j)) {
               ans = mid;
               low = mid + 1;
            } else {
               high = mid - 1;
            }
         }
         if (ans) {
            mp[{i + 1, j + 1}] = ans;
            rows[i][j - ans]++, rows[i][j + ans + 1] -= 1;
            col[i - ans][j]++, col[i + ans + 1][j] -= 1;
         }
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (j) rows[i][j] += rows[i][j - 1];
         if (i) col[i][j] += col[i - 1][j];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if ((v[i][j] == '*' && rows[i][j] == 0 && col[i][j] == 0) || (v[i][j] == '.' && rows[i][j] != 0 && col[i][j] != 0)) {
            pl(-1);
            return;
         }
      }
   }
   pl(mp.size());
   for (auto x : mp) {
      cout << x.ff.ff << " " << x.ff.ss << " " << x.ss << "\n";
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