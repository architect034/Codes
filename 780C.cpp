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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void real_main() {
   int n, mx = 0;
   cin >> n;
   vector<int> v[n + 1];
   vector<int> deg(n + 1, 0);
   for (int i = 1; i < n; i++) {
      int x, y;
      cin >> x >> y;
      v[x].pb(y), v[y].pb(x);
      deg[x]++;
      deg[y]++;
      mx = max({mx, deg[x], deg[y]});
   }
   int c = mx + 1;
   vector<int> color(n + 1, 0);
   queue<int> q;
   q.push(1);
   color[1] = 1;
   while (!q.empty()) {
      int x = q.front();
      q.pop();
      int what_color = color[x];
      set<int> s;
      s.insert(what_color);
      for (int y : v[x]) {
         if (color[y]) s.insert(color[y]);
      }
      int color_to_put = 1;
      for (int y : v[x]) {
         if (!color[y]) {
            while (s.find(color_to_put) != s.end()) {
               color_to_put++;
            }
            s.insert(color_to_put);
            color[y] = color_to_put;
            q.push(y);
         }
      }
   }
   cout << c << "\n";
   for (int i = 1; i <= n; i++) {
      cout << color[i] << " ";
   }
   nl;
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
