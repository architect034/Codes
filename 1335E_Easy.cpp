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
// LOGIC TH SAHI HI HAI BC MEMORY EXCEED HO RAHA HAI
void real_main() {
   int n;
   cin >> n;
   vector<int> v(n);
   vector<int> h(27, 0);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      h[v[i]] = 1;
   }
   int pre[27][n], suf[27][n];
   memset(pre, 0, sizeof pre);
   memset(suf, 0, sizeof suf);
   for (int i = 1; i <= 26; i++) {
      pre[i][0] = (v[0] == i);
      for (int j = 1; j < n; j++) {
         pre[i][j] = pre[i][j - 1] + (v[j] == i);
      }
      suf[i][n - 1] = (v[n - 1] == i);
      for (int j = n - 2; j >= 0; j--) {
         suf[i][j] = suf[i][j + 1] + (v[j] == i);
      }
   }
   int res = 1;
   for (int i = 1; i <= 26; i++) {
      if (!h[i]) continue;
      vector<int> p(n), s(n);
      for (int j = 0; j < n; j++) {
         p[j] = pre[i][j];
         s[j] = suf[i][j];
      }
      for (int j = 0; j < n; j++) {
         if (p[j] == 0) {
            continue;
         }
         for (int k = n - 1; k > j; k--) {
            if (s[k] == p[j]) {
               for (int f = 0; f <= 26; f++) {
                  res = max(res, 2 * p[j] + pre[f][k - 1] - pre[f][j]);
               }
               break;
            } else if (s[k] > p[j]) {
               break;
            }
         }
      }
   }
   cout << res << "\n";
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
