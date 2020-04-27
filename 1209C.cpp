#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
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
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
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
      (i == n - 1) ? cout << endl : cout << "";
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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
// #define int long long
void real_main() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   vector<bool> h(10, false);
   for (int i = 0; i < n; i++) {
      h[s[i] - '0'] = 1;
   }
   for (int v = 0; v < 10; v++) {
      if (!h[v]) continue;
      int x = v;
      vector<int> f, se;
      bool say = 1;
      for (int i = 0; i < n; i++) {
         int y = s[i] - '0';
         if (y < x) {
            if (f.size() == 0) {
               f.pb(y);
            } else {
               if (y < f.back()) {
                  say = 0;
                  break;
               } else {
                  f.pb(y);
               }
            }
         } else if (y > x) {
            if (se.size() == 0) {
               se.pb(y);
            } else {
               if (se.back() > y) {
                  say = 0;
                  break;
               } else {
                  se.pb(y);
               }
            }
         }
      }
      if (say) {
         vector<int> res(n, 0);
         for (int i = 0; i < n; i++) {
            int x = s[i] - '0';
            if (x < v) {
               res[i] = 1;
            } else if (x > v) {
               res[i] = 2;
            }
         }
         for (int i = n - 1; i >= 0; i--) {
            int x = s[i] - '0';
            if (x == v) {
               res[i] = 1;
            } else if (x < v) {
               break;
            }
         }
         for (int i = 0; i < n; i++) {
            if (res[i] == 0) {
               res[i] = 2;
            }
         }
         bool s1 = 1, s2 = 1;
         int st = 0;
         for (int i = 0; i < n; i++) {
            if (res[i] == 1) {
               if (s[i] - '0' < st) {
                  s1 = 0;
                  break;
               }
               st = s[i] - '0';
            }
         }
         st = v;
         for (int i = 0; i < n; i++) {
            if (res[i] == 2) {
               if (s[i] - '0' < st) {
                  s2 = 0;
                  break;
               }
               st = s[i] - '0';
            }
         }
         if (s1 && s2) {
            ps(res, n);
            return;
         }
      }
   }
   pl("-");
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
