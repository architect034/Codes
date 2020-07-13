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
#define int long long
int n, q;
vector<int> h(MAX), a(MAX);
deque<int> gr[MAX], gr2[MAX];
vector<int> tin(2 * MAX), tout(2 * MAX), dfsPath1, dfsPath2;
vector<int> tin2(MAX, 0), tout2(MAX, 0);
vector<int> g(MAX, -1), g2(MAX, -1);
void calculate_path_using_stack() {
   stack<int> s;
   for (int i = 1; i <= n; i++) {
      while (s.empty() == 0 && h[s.top()] <= h[i]) {
         s.pop();
      }
      if (s.empty()) {
         g[i] = -1;
      } else {
         g[i] = s.top();
      }
      s.push(i);
   }
   while (s.size()) {
      s.pop();
   }
   for (int i = n; i >= 1; i--) {
      while (s.empty() == 0 && h[s.top()] <= h[i]) {
         s.pop();
      }
      if (s.empty()) {
         g2[i] = -1;
      } else {
         g2[i] = s.top();
      }
      s.push(i);
   }
}
void make_graph1() {
   for (int i = n; i >= 1; i--) {
      if (g[i] == -1) {
         gr[0].pb(i);
         continue;
      }
      int par = g[i];
      gr[par].pf(i);
   }
}
void make_graph2() {
   for (int i = 1; i <= n; i++) {
      if (g2[i] == -1) {
         gr2[0].pb(i);
         continue;
      }
      int par = g2[i];
      gr2[par].pf(i);
   }
}
int in = 0;
void dfs(int u, int p) {
   tin[u] = in++;
   dfsPath1.pb(u);
   for (int v : gr[u]) {
      if (v == p) continue;
      dfs(v, u);
   }
   tout[u] = in++;
   dfsPath1.pb(u);
}
void dfs2(int u, int p) {
   tin2[u] = in++;
   dfsPath2.pb(u);
   for (int v : gr2[u]) {
      if (v == p) continue;
      dfs2(v, u);
   }
   tout2[u] = in++;
   dfsPath2.pb(u);
}
int seg_t[2 * MAX];
void build() {  // build the tree
   for (int i = n - 1; i > 0; --i) seg_t[i] = max(seg_t[i << 1], seg_t[i << 1 | 1]);
}

int query(int l, int r, int res) {  // sum on interval [l, r)
   for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = max(res, seg_t[l++]);
      if (r & 1) res = max(res, seg_t[--r]);
   }
   return res;
}
int seg_t1[4 * MAX], seg_t2[4 * MAX];
void build1() {
   int nn = dfsPath1.size();
   for (int i = nn - 1; i > 0; --i) seg_t1[i] = seg_t1[i << 1] + seg_t1[i << 1 | 1];
}
void modify1(int p, int value) {  // set value at position p
   int nn = dfsPath1.size();
   for (seg_t1[p += nn] = value; p > 1; p >>= 1) seg_t1[p >> 1] = seg_t1[p] + seg_t1[p ^ 1];
}
int query1(int l, int r) {  // sum on interval [l, r)
   int res = 0;
   int nn = dfsPath1.size();
   for (l += nn, r += nn; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += seg_t1[l++];
      if (r & 1) res += seg_t1[--r];
   }
   return res;
}

void build2() {
   int nn = dfsPath2.size();
   for (int i = nn - 1; i > 0; --i) seg_t2[i] = seg_t2[i << 1] + seg_t2[i << 1 | 1];
}
void modify2(int p, int value) {  // set value at position p
   int nn = dfsPath2.size();
   for (seg_t2[p += nn] = value; p > 1; p >>= 1) seg_t2[p >> 1] = seg_t2[p] + seg_t2[p ^ 1];
}
int query2(int l, int r) {  // sum on interval [l, r)
   int res = 0;
   int nn = dfsPath2.size();
   for (l += nn, r += nn; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res += seg_t2[l++];
      if (r & 1) res += seg_t2[--r];
   }
   return res;
}
void _main() {
   cin >> n >> q;
   for (int i = 1; i <= n; i++) cin >> h[i];
   for (int i = 1; i <= n; i++) cin >> a[i];
   vector<vector<int>> queries(n);
   int ch = 0;
   for (int i = 0; i < q; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      if (a == 1) ch++;
      queries[i].pb(a), queries[i].pb(b), queries[i].pb(c);
   }
   if (false && ch && n <= 1000 && q <= 1000) {
      if (ch) {
         for (int i = 0; i < q; i++) {
            int t = queries[i][0];
            if (t == 1) {
               int b = queries[i][1], k = queries[i][2];
               a[b] = k;
            } else {
               int b = queries[i][1], c = queries[i][2];
               if (b == c) {
                  pl(a[b]);
                  continue;
               } else if (h[b] <= h[c]) {
                  pl(-1);
                  continue;
               } else {
                  if (c > b) {
                     bool say = 1;
                     for (int j = b + 1; j <= c; j++) {
                        if (h[j] >= h[b]) {
                           say = 0;
                           pl(-1);
                           break;
                        }
                     }
                     if (say == 0) continue;
                     int ans = 0;
                     int st = c - 1;
                     for (int j = st; j >= b + 1; j--) {
                        if (h[j] > h[c]) {
                           st = j;
                           break;
                        }
                     }
                     int last = h[c];
                     for (int j = st; j >= b + 1; j--) {
                        if (h[j] > last) {
                           ans += a[j];
                           last = h[j];
                        }
                     }
                     ans += a[c] + a[b];
                     pl(ans);
                  } else {
                     bool say = 1;
                     for (int j = c; j <= b - 1; j++) {
                        if (h[j] >= h[b]) {
                           say = 0;
                           pl(-1);
                           break;
                        }
                     }
                     if (!say) continue;
                     int ans = 0;
                     int st = c + 1;
                     for (int j = st; j <= b - 1; j++) {
                        if (h[j] > h[c]) {
                           st = j;
                           break;
                        }
                     }
                     int last = h[c];
                     for (int j = st; j <= b - 1; j++) {
                        if (h[j] > last) {
                           last = h[j];
                           ans += a[j];
                        }
                     }
                     ans += a[c] + a[b];
                     pl(ans);
                  }
               }
            }
         }
      }
      // return;
   }
   calculate_path_using_stack();
   for (int i = 1; i <= n; i++) {
      seg_t[n - 1 + i] = h[i];
   }
   build();
   make_graph1();
   make_graph2();
   dfs(0, 0);

   unordered_map<int, bool> mp;
   for (int i = 1; i < dfsPath1.size() - 1; i++) {
      int x = dfsPath1[i];
      if (mp[x] == 0) {
         dfsPath1[i] = a[x];
      } else {
         dfsPath1[i] = -a[x];
         mp[x] = false;
      }
      mp[x] = true;
   }
   int nn = dfsPath1.size();
   for (int i = 0; i < nn; i++) {
      seg_t1[nn + i] = dfsPath1[i];
   }
   build1();
   in = 0;
   dfs2(0, 0);
   mp.clear();
   for (int i = 1; i < dfsPath2.size() - 1; i++) {
      int x = dfsPath2[i];
      if (mp[x] == 0) {
         dfsPath2[i] = a[x];
      } else {
         dfsPath2[i] = -a[x];
         mp[x] = false;
      }
      mp[x] = true;
   }
   for (int i = 0; i < nn; i++) {
      seg_t2[nn + i] = dfsPath2[i];
   }
   build2();
   for (int i = 0; i < q; i++) {
      int type = queries[i][0];
      if (type == 1) {
         int idx = queries[i][1], val = queries[i][2];
         int in1 = tin[idx], out1 = tout[idx];
         int dif = val - query1(in1, in1 + 1);
         modify1(in1, val);
         int v = query1(out1, out1 + 1);
         modify1(out1, v - dif);
         int in2 = tin2[idx], out2 = tout2[idx];
         dif = val - query2(in2, in2 + 1);
         v = query2(out2, out2 + 1);
         modify2(in2, val);
         modify2(out2, v - dif);
         continue;
      }
      int f = queries[i][1], to = queries[i][2];
      if (f == to) {
         pl(a[f]);
         continue;
      } else if (h[f] <= h[to]) {
         pl(-1);
         continue;
      } else if (f < to) {
         int mx = query(f, to - 1, INT_MIN);
         if (mx >= h[f]) {
            pl(-1);
            continue;
         }
         to = tin[to];
         f = tin[f];
         int ans = query1(0, to + 1) - query1(0, f + 1) + query1(f, f + 1);
         pl(ans);
      } else {
         int mx = query(to - 1, f - 1, INT_MIN);
         if (mx >= h[f]) {
            pl(-1);
            continue;
         }
         to = tin2[to];
         f = tin2[f];
         int ans = query2(0, to + 1) - query2(0, f + 1) + query2(f, f + 1);
         pl(ans);
         // pl(sum2[to] - sum2[f] + a[f]);
      }
   }
}
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      _main();
   }
   return 0;
}
