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
   vector<int> v(n), mark(n, 0);
   for (int& x : v) {
      cin >> x;
   }
   int q;
   cin >> q;
   vector<int> ans(n, 0);
   vector<vector<int> > que(q);
   for (int i = 0; i < q; i++) {
      int t;
      cin >> t;
      que[i].pb(t);
      if (t == 1) {
         int p, x;
         cin >> p >> x;
         que[i].pb(p), que[i].pb(x);
      } else {
         int x;
         cin >> x;
         que[i].pb(x);
      }
   }
   reverse(all(que));
   int last = 0;
   for (int i = 0; i < q; i++) {
      int t = que[i][0];
      if (t == 1) {
         int idx = que[i][1], x = que[i][2];
         if (!mark[idx - 1]) {
            mark[idx - 1] = 1;
            ans[idx - 1] = max({ans[idx - 1], x, last});
         }
      } else {
         int x = que[i][1];
         last = max(last, x);
      }
   }
   for (int i = 0; i < n; i++) {
      if (!mark[i]) {
         ans[i] = max(v[i], last);
      }
   }
   for (int i : ans) {
      cout << i << " ";
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
