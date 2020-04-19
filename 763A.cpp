#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define rf for (int i = n; i >= 0; i--)
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
// #define ps(x) cout << x << " "
// #define pl(x) cout << x << endl
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
vector<int> primes;
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
void in(T& x) {
   cin >> x;
}
template <typename T>
void ps(T x) {
   cout << x << " ";
}
template <typename T>
void ps(const vector<T>& x, int n) {
   f(i, n) {
      cout << x[i];
      (i == n - 1) ? cout << endl : cout << " ";
   }
}
template <typename T>
void pl(T x) {
   cout << x << endl;
}
template <typename T>
void pl(const vector<T>& x, int n) {
   f(i, n) { cout << x[i] << "\n"; }
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
vector<int> color(MAX), vis(MAX, 0);
vector<vector<int> > v(MAX);
set<int> s;
void dfs(int x, int p) {
   vis[x] = 1;
   // cout << x << " ";
   s.insert(color[x]);
   for (int y : v[x]) {
      // cout << y << " children\n";
      if (y == p) continue;
      if (!vis[y]) {
         dfs(y, p);
      }
   }
}
void real_main() {
   int n;
   in(n);
   vector<pair<int, int> > edges;
   vector<int> mark(n + 1, 0);
   for (int i = 0; i < n - 1; i++) {
      int x, y;
      in(x), in(y);
      edges.pb({x, y});
      v[x].pb(y), v[y].pb(x);
   }

   f(i, n) { in(color[i + 1]); }
   f(i, edges.size()) {
      int x = edges[i].ff;
      int y = edges[i].ss;
      if (color[x] != color[y]) {
         // cout << x << " " << y << "\n";
         bool say = 1;
         // cout << x << "'s child : ";
         for (int u : v[x]) {
            // cout << u << " ,";
            if (u == x) {
               continue;
            }
            dfs(u, x);
            // nl;
            if (s.size() > 1) {
               say = 0;
               break;
            }
            s.clear();
         }

         s.clear();
         // nl;
         if (say) {
            yes;
            pl(x);
            return;
         }
         say = 1;
         vis.assign(MAX, 0);
         // cout << y << "'s child : ";
         for (int u : v[y]) {
            if (u == y) continue;
            // cout << u << " ,";
            dfs(u, y);
            // nl;
            if (s.size() > 1) {
               say = 0;
               break;
            }
            s.clear();
         }
         if (say) {
            yes;
            pl(y);
            return;
         }
         no;
         return;
      }
   }
   yes;
   pl(1);
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
