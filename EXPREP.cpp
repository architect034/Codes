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
const ll mod = 998244353;
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
long long power(long long a, long long b, long long m) {
   long long res = 1LL;
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
   string s;
   cin >> s;
   int n = s.size();
   vector<int> a(26);
   for (int i = 0; i < 26; i++) cin >> a[i];
   vector<vector<int> > v(n);
   vector<int> h(26, 0);
   for (int i = 0; i < n; i++) {
      h[s[i] - 'a']++;
      v[i] = h;
   }
   int sum = 0LL;
   int d = (n * (n + 1)) / 2LL;
   for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
         vector<int> t(26, 0);
         for (int k = 0; k < 26; k++) {
            t[k] = v[j][k] - (((i - 1) >= 0) ? (v[(i - 1)][k]) : 0);
         }
         for (int k = i; k <= j; k++) {
            vector<int> tmp(26, 0);
            int len = k - i + 1;
            int kit = (j - i + 1) / len;
            for (int p = 0; p < 26; p++) {
               tmp[p] = v[k][p] - (((i - 1) >= 0) ? (v[(i - 1)][p]) : 0);
               tmp[p] *= kit;
            }
            int rem = (j - i + 1) % len;
            if (rem) {
               for (int p = 0; p < 26; p++) {
                  tmp[p] += ((((i + rem - 1) >= 0) ? v[i + rem - 1][p] : 0) - (((i - 1) >= 0) ? (v[(i - 1)][p]) : 0));
               }
            }
            bool say = 1;
            for (int p = 0; p < 26; p++) {
               if (t[p] != tmp[p]) {
                  say = 0;
                  break;
               }
            }
            if (say) {
               for (int p = 0; p < 26; p++) {
                  tmp[p] = v[k][p] - (((i - 1) >= 0) ? (v[(i - 1)][p]) : 0);
                  sum = sum + (tmp[p] * a[p]);
               }
            }
         }
      }
   }
   int g = __gcd(sum, d);
   sum /= g;
   d /= g;
   sum = ((sum % mod) * (power(d, mod - 2, mod))) % mod;
   cout << sum << "\n";
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
