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
void in(T& x) {
   cin >> x;
}
template <typename T, typename U>
void in(T& x, U& y) {
   cin >> x >> y;
}
template <typename T, typename U, typename V>
void in(T& x, U& y, V& z) {
   cin >> x >> y >> z;
}
template <typename T>
void ps(T x) {
   cout << x << " ";
}
template <typename T>
void ps(const vector<T>& x, int n) {
   f(i, n) {
      cout << x[i];
      (i == n - 1) ? cout << endl : cout << " ";
   }
}
template <typename T>
void pl(T x) {
   cout << x << endl;
}
template <typename T>
void pl(const vector<T>& x, int n) {
   f(i, n) { cout << x[i] << "\n"; }
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
void real_main() {
   ll n;
   in(n);
   vector<ll> v(n);
   map<ll, ll> f;
   f(i, n) {
      in(v[i]);
      f[v[i]] = i + 1;
   }
   sort(all(v));
   vector<ll> p;
   ll m = 1;
   for (int i = 0; i < 33; i++) {
      p.pb(m);
      m = m << 1;
   }
   vector<ll> res;
   for (int i = 0; i < n; i++) {
      ll x = v[i];
      for (ll j = 0; j < p.size(); j++) {
         ll y = x + p[j];
         if (binary_search(all(v), y)) {
            ll z = x + 2 * p[j];
            if (binary_search(all(v), z)) {
               pl(3);
               ps(x), ps(y), pl(z);
               return;
            } else {
               res.clear();
               res.pb(x), res.pb(y);
            }
         }
      }
   }
   if (res.size() > 0) {
      pl(res.size());
      ps(res, res.size());
   } else {
      pl(1);
      ps(v[0]);
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