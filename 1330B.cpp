#include <bits/stdc++.h>
#define ll long long
#define f(i, st, en, in) for (ll i = st; i <= en; i += in)
#define rf(i, st, en, de) for (ll i = st; i >= en; i -= de)
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
const int MAX = 1e7 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   f(i, 4, MAX - 1, 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   f(i, 3, MAX - 1, 2) {
      if (prime[i]) {
         spf[i] = i;
         f(j, i * i, MAX - 1, i) {
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
void solve() {
   int n;
   cin >> n;
   vector<int> v(n);
   map<int, int> l, r;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      r[v[i]]++;
   }
   int ans = 0;
   vector<int> res;
   for (int i = 0; i < n - 1; i++) {
      l[v[i]]++;
      r[v[i]]--;
      if (r[v[i]] == 0) {
         r.erase(v[i]);
      }
      auto x = l.rbegin(), y = r.rbegin();
      if (x->ff == (i + 1) && l.size() == (i + 1) && r.size() == (n - i - 1) &&
          y->ff == (n - i - 1)) {
         ans++;
         res.pb(i + 1);
      }
   }
   cout << ans << "\n";
   for (int i = 0; i < ans; i++) {
      cout << res[i] << " " << n - res[i] << "\n";
   }
}
int main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   while (test_cases--) {
      solve();
   }
   return 0;
}