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
const int MAX = 400000;
const ll mod = 998244353;
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
#endif
}
#define int long long
bool say = 1;
int ans = 0, res = 1;
void dfs(vector<int> g[], int x, int p, vector<int> &vis, vector<int> &d) {
   vis[x] = 1;
   for (int y : g[x]) {
      if (y != p) {
         if (vis[y] && (abs(d[y] - d[x])) % 2 == 0) {
            say = 0;
            // return;
         }
         if (!vis[y]) {
            d[y] = d[x] + 1;
            dfs(g, y, x, vis, d);
         }
      }
   }
}
int tot = 0, one = 0;
void calc_dfs(vector<int> g[], int x, vector<int> &vis, int p) {
   vis[x] = 1;
   tot++;
   if (p & 1) {
      one++;
      res <<= 1;
      res %= mod;
   }
   for (int y : g[x]) {
      if (vis[y] == 0) {
         calc_dfs(g, y, vis, p ^ 1);
      }
   }
}
void real_main() {
   int n, m;
   cin >> n >> m;
   vector<int> g[n + 1];
   vector<int> vis(n + 1, 0), d(n + 1, 0);
   for (int i = 0; i < m; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      g[u1].pb(u2), g[u2].pb(u1);
   }
   if (m == 0) {
      pl(power(3LL, (ll)n, (ll)mod));
      return;
   }
   for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
         d[i] = 1;
         dfs(g, i, 0, vis, d);
         if (say == 0) {
            pl(0);
            say = 1;
            return;
         }
      }
   }
   ans = 1;
   vis.assign(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
         calc_dfs(g, i, vis, 1);
         ans = ans * (res + (power(2LL, (ll)(tot - one), mod)));
         ans %= mod;
         tot = one = 0;
         res = 1;
      }
   }
   pl(ans);
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
