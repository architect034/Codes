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
const int N = 1e5 + 10;
int n, m;
vector<int> ans(N);
int t[2 * N];

void build() {
   for (int i = n - 1; i > 0; --i) t[i] = (t[i << 1]) & (t[i << 1 | 1]);
}

int query(int l, int r) {
   int res = power<int>(2, 30) - 1;
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = (res) & (t[l++]);
      if (r & 1) res = (res) & (t[--r]);
   }
   return res;
}
void real_main() {
   cin >> n >> m;
   vector<pair<pair<int, int>, int> > v(m);
   for (int i = 0; i < m; i++) {
      cin >> v[i].ff.ff >> v[i].ff.ss >> v[i].ss;
   }
   vector<vector<int> > dp(32, vector<int>(n + 2, 0));
   for (int i = 0; i < m; i++) {
      int pos = 0;
      int x = v[i].ss;
      while (x) {
         if (x % 2 == 1) {
            dp[pos][v[i].ff.ff]++;
            dp[pos][v[i].ff.ss + 1]--;
         }
         x >>= 1;
         pos++;
      }
   }
   for (int i = 0; i < 32; i++) {
      for (int j = 1; j <= n + 1; j++) {
         dp[i][j] += dp[i][j - 1];
      }
   }
   vector<int> ans(n, power<int>(2, 30) - 1);

   for (int i = 1; i <= n; i++) {
      int x = 0;
      for (int j = 0; j < 31; j++) {
         if (dp[j][i]) {
            x += (1 << j);
         }
      }
      ans[i - 1] = x;
   }
   for (int i = 0; i < n; ++i) {
      t[n + i] = ans[i];
   }
   dbg(ans);
   build();
   db(t);
   for (int i = 0; i < m; i++) {
      int ret = query(v[i].ff.ff - 1, v[i].ff.ss);
      dbg(ret);
      if (ret != v[i].ss) {
         no;
         return;
      }
   }
   yes;
   ps(ans, ans.size());
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
