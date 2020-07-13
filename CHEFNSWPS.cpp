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
void _main() {
   int n, mn = INT_MAX;
   cin >> n;
   vector<int> a(n), b(n);
   map<int, int> m, ma, mb;
   for (int &i : a) cin >> i, m[i]++, ma[i]++, mn = min(mn, i);
   for (int &i : b) cin >> i, m[i]++, mb[i]++, mn = min(mn, i);
   dbg(m);
   for (auto x : m) {
      if (x.ss % 2 == 1) {
         pl(-1);
         return;
      }
      m[x.ff] /= 2;
   }
   int ans = 0;
   sort(all(a)), sort(all(b));
   int bal = 0;
   for (auto x : m) {
      if (x.ss > ma[x.ff])
         bal += ((x.ss - ma[x.ff]));
   }
   dbg(bal);
   for (auto x : m) {
      int v = x.ff, cnt = x.ss;
      if (ma[v] == cnt) continue;
      int ex = abs(ma[v] - cnt);
      if (ma[v] < cnt) {
         ans += (min(2 * mn, v) * min(bal, ex));
         bal -= min(bal, ex);
      } else {
         ans += (min(2 * mn, v) * min(bal, ex));
         bal -= min(bal, ex);
      }
   }
   pl(ans);
}
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      _main();
   }
   return 0;
}
