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
   //jack and johny bhosdika
   int n, k, _a = 0, _b = 0;
   cin >> n >> k;
   vector<pair<int, int> > v;
   for (int i = 0; i < n; i++) {
      int t, a, b;
      cin >> t >> a >> b;
      if (a && b)
         v.pb({t, 0}), _a++, _b++;
      else if (a)
         v.pb({t, 1}), _a++;
      else if (b)
         v.pb({t, 2}), _b++;
   }
   if (_a < k || _b < k) {
      pl(-1);
      return;
   }
   int a = 0, b = 0;
   sort(all(v));
   n = v.size();
   int ans = 0;
   vector<int> alice_last, bob_last;
   for (int i = 0; i < n; i++) {
      int t = v[i].ff, ty = v[i].ss;
      if (ty == 0) {
         if (a == k && b == k) {
            if (alice_last.size() && bob_last.size()) {
               int sum = alice_last.back() + bob_last.back();
               if (sum > t) {
                  ans = ans - sum + t;
                  alice_last.pop_back(), bob_last.pop_back();
               }
            }
         } else if (a == k) {
            if (alice_last.size()) {
               ans -= alice_last.back();
               alice_last.pop_back();
               ans += t;
               b++;
            }
         } else if (b == k) {
            if (bob_last.size()) {
               ans -= bob_last.back();
               bob_last.pop_back();
               ans += t;
               a++;
            }
         } else {
            a++, b++;
            ans += t;
         }
      } else if (ty == 1 && a < k) {
         a++;
         ans += (t);
         alice_last.push_back(t);
      } else if (ty == 2 && b < k) {
         b++;
         ans += (t);
         bob_last.push_back(t);
      }
   }
   pl(ans);
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
