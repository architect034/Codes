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
   vector<int> v(n), h(n + 3, 0);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      h[v[i]]++;
   }
   vector<int> hh = h;
   vector<int> mark(n + 2, 0);
   for (int i = 1; i <= n; i++) {
      if (h[i]) {
         if (h[i + 1] && h[i + 2]) {
            h[i] = 0;
            h[i + 2] = 0;
            i = i + 2;
            continue;
         } else if (h[i + 1] && !h[i - 1]) {
            h[i + 1] = 0;
            i++;
         } else if (h[i - 1] && !h[i + 1]) {
            h[i] = 0;
         }
      }
      if (!h[i]) {
         if (h[i - 1] && h[i + 1]) {
            h[i - 1] = 0;
            h[i + 1] = 0;
            h[i] = 1;
            i++;
         }
      }
   }
   // for (int i = 1; i <= n; i++) {
   //    cout << hh[i] << " ";
   // }
   // nl;
   for (int i = 1; i <= n; i++) {
      if (hh[i]) {
         int x = hh[i];
         if (x >= 1 && !mark[i - 1]) {
            mark[i - 1] = 1;
            x--;
         }
         if (x >= 1 && !mark[i]) {
            mark[i] = 1;
            x--;
         }
         if (x >= 1 && !mark[i + 1]) {
            mark[i + 1] = 1;
         }
      }
   }
   int mn = 0, mx = 0;
   for (int i = 1; i <= n; i++) {
      // cout << h[i] << " ";
      if (h[i]) {
         mn++;
      }
   }
   // nl;
   for (int i = 0; i <= n + 1; i++) {
      if (mark[i]) {
         mx++;
      }
      // cout << mark[i] << " ";
   }
   ps(mn);
   pl(mx);
   // nl;
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
