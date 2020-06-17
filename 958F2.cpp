#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
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
vector<int> v(MAX), colorsCount(MAX);
int check(int len) {
   vector<int> a(m + 1);
   int sum = 0;
   int cnt = 0;
   for (int i = 1; i <= m; i++) {
      a[i] = colorsCount[i];
      if (a[i] == 0) {
         cnt++;
      }
      sum += a[i];
   }
   for (int i = 0; i < len; i++) {
      int col = v[i];
      a[col]--;
      if (a[col] == 0) cnt++;
   }
   // dbg(len, a, cnt);
   int ans = INT_MAX;
   if (cnt == m) {
      ans = min(ans, len - sum);
      return ans;
   }
   int lb = 0, ub = len;
   while (ub < n) {
      int ubCol = v[ub];
      int lbCol = v[lb];
      a[lbCol]++;
      if (a[lbCol] == 1) cnt--;
      a[ubCol]--;
      if (a[ubCol] == 0) cnt++;
      if (cnt == m) {
         ans = min(ans, len - sum);
         return ans;
      }
      ub++;
      lb++;
   }
   return -1;
}
void real_main() {
   cin >> n >> m;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }
   for (int i = 0; i < m; i++) {
      cin >> colorsCount[i + 1];
   }
   int lb = 0, rb = n, ans = INT_MAX;
   while (lb <= rb) {
      int mb = (lb + rb) / 2;
      int say = check(mb);
      if (say != -1) {
         ans = min(ans, say);
         rb = mb - 1;
      } else {
         lb = mb + 1;
      }
   }
   (ans == INT_MAX) ? no : yes;
}
signed main() {
   IO;
   virtual_main();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
