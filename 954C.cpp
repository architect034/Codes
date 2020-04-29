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
#endif
}
// #define int long long
void real_main() {
   //bada time le liya aapne th bhosdike
   int n;
   cin >> n;
   vector<int> v(n);
   map<int, int> m;
   bool say = 1;
   for (int &i : v) {
      cin >> i;
   }
   if (n == 1) {
      yes;
      ps(1000000000), pl(1);
      return;
   }
   if (!say) {
      no;
      return;
   } else {
      set<int> s;
      for (int i = 1; i < n; i++) {
         if (abs(v[i] - v[i - 1]) == 1) {
            continue;
         }
         if (abs(v[i] - v[i - 1]) == 0) {
            no;
            return;
         }
         s.insert(abs(v[i] - v[i - 1]));
      }
      if (s.size() > 1) {
         no;
         return;
      }
      if (s.size() == 0) {
         yes;
         ps(1000000000), pl(1);
         return;
      }
      int m = *s.begin();
      bool bolo = 0;
      for (int i = 0; i < n - 1; i++) {
         int r1 = (v[i] + m - 1) / m, c1 = (v[i] % m == 0) ? m : v[i] % m;
         int r2 = (v[i + 1] + m - 1) / m, c2 = (v[i + 1] % m == 0) ? m : v[i + 1] % m;
         if (!((r1 == r2 && abs(c1 - c2) == 1) || (c1 == c2 && abs(r1 - r2) == 1))) {
            no;
            return;
         }
      }
      yes;
      ps(1000000000), pl(m);
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