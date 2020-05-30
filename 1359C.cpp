#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
#define int long long
void real_main() {
   //bade harami nikle beta
   int h, c, t;
   cin >> h >> c >> t;
   int low = 1, high = 1000000000;
   long double m = (h + c) / 2.0;
   long double d = abs((long double)t - m);
   if (m >= (long double)t) {
      pl(2);
      return;
   }
   int cnt = 100;
   while ((high - low) > 2) {
      int pointer = (low + high) / 2;
      if (pointer % 2 == 0) {
         pointer--;
      }
      int value = ((pointer + 1) / 2) * h + (pointer / 2) * c;
      if (value <= t * pointer) {
         int ans1 = pointer;
         pointer -= 2;
         int v1 = value;
         value = ((pointer + 1) / 2) * h + (pointer / 2) * c;
         if (value <= t * pointer) {
            high = pointer;
            continue;
         }
         int d1 = abs(ans1 * t - v1), d2 = abs(pointer * t - value);
         if ((d1 * pointer) < (d2 * ans1)) {
            pl(ans1);
            return;
         } else {
            pl(pointer);
            return;
         }
      } else {
         low = pointer;
      }
   }
   int v1 = ((h * ((low + 1) / 2) + (low / 2) * c));
   int v2 = ((h * ((high + 1) / 2) + (high / 2) * c));
   int d1 = abs(v1 - low * t), d2 = abs(v2 - high * t);
   if (d1 * high <= d2 * low) {
      cout << low << "\n";
      return;
   } else {
      cout << high << "\n";
      return;
   }
   cout << 1 << "\n";
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // double tic, tac;
      // tic = clock();
      // cout << "Case #" << tc << ": ";
      real_main();
      // tac = clock(), cerr << "TC " << i << " done in:: " << 1000 * (tac - tic) / CLOCKS_PER_SEC << " ms\n";
   }
   // cerr << "GG in: " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";
   return 0;
}
