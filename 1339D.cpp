#include <bits/stdc++.h>
#define FaSt ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
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
ll power(ll a, ll b) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
ll power(ll a, ll b, ll m) {
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
void pre() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
int n;
vector<int> vis(MAX, 0), dist(MAX, 0);
vector<vector<int> > v(MAX);
int s, mx;
void diameter() {
   queue<int> q;
   q.push(1);
   vis[1] = 1;
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto y : v[x]) {
         if (!vis[y]) {
            vis[y] = 1;
            dist[y] = dist[x] + 1;
            q.push(y);
         }
      }
   }
   s = 0, mx = 0;
   for (int i = 1; i <= n; i++) {
      vis[i] = 0;
      if (dist[i] > mx) {
         mx = dist[i];
         s = i;
      }
      dist[i] = 0;
   }
   q.push(s);
   vis[s] = 1;
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto y : v[x]) {
         if (!vis[y]) {
            vis[y] = 1;
            dist[y] = dist[x] + 1;
            q.push(y);
         }
      }
   }
}
void solve() {
   cin >> n;
   for (int i = 0; i < n - 1; i++) {
      int x, y;
      cin >> x >> y;
      v[x].pb(y);
      v[y].pb(x);
   }
   vector<int> p(n + 1, 0);
   set<int> pa;
   int kitna_leaves = 0;
   diameter();
   vector<int> leaves(n + 1, 0);
   int mn = 1;
   for (int i = 1; i <= n; i++) {
      if (v[i].size() == 1) {
         if (dist[i] & 1) {
            mn = 3;
         }
         kitna_leaves++;
         pa.insert(v[i][0]);
         leaves[i] = 1;
      }
   }
   cout << mn << " ";
   cout << n - 1 - kitna_leaves + pa.size() << "\n";
}
signed main() {
   FaSt;
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}
