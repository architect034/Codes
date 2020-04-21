#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
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
   f(i, 0, n) {
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
   f(i, 0, n) { cout << x[i] << "\n"; }
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
#define int long long
void real_main() {
   string s, r;
   cin >> s >> r;
   vector<int> v;
   for (int i = 0; i < s.size(); i++) {
      if (s[i] != r[i]) {
         v.pb(i + 1);
      }
   }
   if (!v.size()) {
      pl(0);
      return;
   }
   // cout << v.size() << "\n";
   int mn = v[0];
   int t = 1, l = 1, res = 0;

   if (v.size() == 1) {
      pl(1);
      return;
   }
   for (int i = 1; i < v.size(); i++) {
      if (t * (l + v[i] - v[i - 1]) <= (t + 1) * (l + 1)) {
         res = t * (l + v[i] - v[i - 1]);
         l = l + v[i] - v[i - 1];
      } else {
         res = (t + 1) * (l + 1);
         t = t + 1;
         l = l + 1;
      }
      if (res > (v[i] - mn + 1)) {
         res = v[i] - mn + 1;
         t = 1;
         l = v[i] - mn + 1;
      }
   }
   pl(res);
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
