#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
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
const int MAX = 1e6 + 1;
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
void in(T &x) {
   cin >> x;
}
template <typename T, typename U>
void in(T &x, U &y) {
   cin >> x >> y;
}
template <typename T, typename U, typename V>
void in(T &x, U &y, V &z) {
   cin >> x >> y >> z;
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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
#define int long long
int n, p;
vector<int> m(MAX);
int find(int a, int b) {
   int ret = 1;
   for (int i = 1; i <= b; i++) {
      if (ret * p > MAX) {
         return -1;
      }
      ret = ret * p;
   }
   if (a * ret > MAX) {
      return -1;
   }
   return a * ret;
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
void real_main() {
   cin >> n >> p;
   vector<int> v(n);
   set<int> s;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      m[v[i]]++;
      s.insert(v[i]);
   }
   if (p == 1) {
      if (n & 1) {
         pl(1);
      } else {
         pl(0);
      }
      for (int i = 0; i < n; i++) {
         m[v[i]] = 0;
      }
      return;
   }
   vector<int> a;
   for (int x : s) {
      a.pb(x);
   }
   sort(all(a));
   reverse(all(a));
   int idx = 0;
   n = a.size();
   while (idx < n) {
      int cnt = m[a[idx]];
      if (cnt % 2 == 0) {
         idx++;
         continue;
      }
      int want = 1;
      bool hua = false;
      int val = a[idx];
      for (int i = idx + 1; i < n; i++) {
         int want_updated = find(want, val - a[i]);
         if (want_updated == -1) {
            break;
         }
         if (want_updated <= m[a[i]]) {
            hua = true;
            m[a[i]] -= want_updated;
            idx = i;
            break;
         } else {
            want = want_updated - m[a[i]];  //this much needed
            val = a[i];
         }
      }
      if (hua == false) {
         int x = power<int>(p, a[idx], mod);
         x %= mod;
         int y = 0;
         for (int i = idx + 1; i < n; i++) {
            x -= (m[a[i]] * (power<int>(p, a[i], mod))) % mod;
            if (x < 0) {
               x = (x + mod) % mod;
            }
         }
         for (int i = 0; i < n; i++) {
            m[a[i]] = 0;
         }
         pl(x);
         return;
      }
   }
   for (int i = 0; i < n; i++) {
      m[a[i]] = 0;
   }
   pl(0);
}
signed main() {
   IO;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
