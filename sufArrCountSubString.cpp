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
// #define int long long
void _main() {
   string s;
   cin >> s;
   s += '$';
   int n = s.size();
   vector<pair<char, int>> a;
   vector<int> c(n), suf(n);
   for (int i = 0; i < n; i++) {
      a.pb({s[i], i});
   }
   sort(all(a));
   for (int i = 0; i < n; i++) suf[i] = a[i].ss;
   c[suf[0]] = 0;
   for (int i = 1; i < n; i++) {
      if (a[i].ff == a[i - 1].ff) {
         c[suf[i]] = c[suf[i - 1]];
      } else {
         c[suf[i]] = c[suf[i - 1]] + 1;
      }
   }
   int k = 0;
   while ((1 << (k)) < n) {
      vector<pair<pair<int, int>, int>> a(n);
      for (int i = 0; i < n; i++) {
         a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
      }
      sort(all(a));
      for (int i = 0; i < n; i++) suf[i] = a[i].ss;
      c[suf[0]] = 0;
      for (int i = 1; i < n; i++) {
         if (a[i].ff == a[i - 1].ff) {
            c[suf[i]] = c[suf[i - 1]];
         } else {
            c[suf[i]] = c[suf[i - 1]] + 1;
         }
      }
      k++;
   }
   s += s;
   int q;
   cin >> q;
   while (q--) {
      string t;
      cin >> t;
      int len = t.size();
      int low = 0, high = n - 1, ans = -1, say = 0;
      while (low <= high) {
         int mid = (low + high) / 2;
         string temp = s.substr(suf[mid], len);
         if (temp == t) {
            say = 1;
            break;
         } else if (temp < t) {
            low = mid + 1;
         } else {
            high = mid - 1;
         }
      }
      if (!say) {
         pl(0);
      } else {
         int low = 0, high = n - 1, ans = -1;
         while (low <= high) {
            int mid = (low + high) / 2;
            string temp = s.substr(suf[mid], len);
            if (temp >= t) {
               ans = mid;
               high = mid - 1;
            } else if (temp < t) {
               low = mid + 1;
            }
         }
         int lb = ans;
         low = 0, high = n - 1;
         while (low <= high) {
            int mid = (low + high) / 2;
            string temp = s.substr(suf[mid], len);
            if (temp <= t) {
               ans = mid;
               low = mid + 1;
            } else {
               high = mid - 1;
            }
         }
         int rb = ans;
         pl(rb - lb + 1);
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
