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
vector<int> g[MAX], lvl(MAX, 0);
int par[MAX][18];
void dfs(int x, int p) {
   par[x][0] = p;
   lvl[x] = lvl[p] + 1;
   for (int y : g[x]) {
      if (y != p) {
         dfs(y, x);
      }
   }
}
void precomputeSparseMatrix(int n) {
   for (int i = 1; i < 18; i++) {
      for (int node = 1; node <= n; node++) {
         if (par[node][i - 1] != -1)
            par[node][i] = par[par[node][i - 1]][i - 1];
      }
   }
}
int lca(int u, int v) {
   if (lvl[v] < lvl[u])
      swap(u, v);

   int diff = lvl[v] - lvl[u];
   for (int i = 0; i < 18; i++)
      if ((diff >> i) & 1)
         v = par[v][i];
   if (u == v)
      return u;
   for (int i = 18 - 1; i >= 0; i--)
      if (par[u][i] != par[v][i]) {
         u = par[u][i];
         v = par[v][i];
      }

   return par[u][0];
}
void real_main() {
   memset(par, -1, sizeof(par));
   int n, q;
   cin >> n >> q;
   for (int i = 0; i < n - 1; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      g[u1].pb(u2), g[u2].pb(u1);
   }
   lvl[0] = 0;
   dfs(1, 0);
   precomputeSparseMatrix(n);
   while (q--) {
      int k;
      cin >> k;
      vector<int> arr;
      int node = 1;
      for (int i = 0; i < k; i++) {
         int x;
         cin >> x;
         arr.pb(par[x][0]);
         if (lvl[par[x][0]] >= lvl[node]) {
            node = par[x][0];
         }
      }
      dbg(arr);
      bool say = true;
      for (int i = 0; i < k; i++) {
         int LCA = lca(arr[i], node);
         if (LCA != arr[i]) {
            say = false;
            break;
         }
      }
      say ? yes : no;
   }
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
