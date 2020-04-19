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
   int n;
   cin >> n;
   vector<vector<int> > v(n);
   for (int i = 0; i < n; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      v[i].pb(x), v[i].pb(y), v[i].pb(z);
   }
   vector<int> mark(n, 0);

   for (int i = 0; i < n; i++) {
      if (mark[i]) continue;
      pair<int, int> p[1];
      p[0].ff = i + 1;
      int x1 = v[i][0], y1 = v[i][1], z1 = v[i][2];
      mark[i] = 1;
      int d = INT_MAX;
      for (int j = i + 1; j < n; j++) {
         if (mark[j]) continue;
         int x2 = v[j][0], y2 = v[j][1], z2 = v[j][2];
         if (abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1) < d) {
            d = abs(x2 - x1) + abs(y2 - y1) + abs(z2 - z1);
            p[0].ss = j + 1;
         }
      }
      mark[p[0].ss - 1] = 1;
      cout << p[0].ff << " " << p[0].ss << "\n";
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
