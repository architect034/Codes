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
class Solution {
  public:
   int optimised(int l, int r) {
      int ans = 0;
      while (l != r) {
         l >>= 1;
         r >>= 1;
         ans++;
      }
      return l << ans;
   }
   int another(int l, int r) {
      if (l == r) return l;
      vector<int> h(35, 0);
      int i = 0;
      while (l) {
         h[i++] = l % 2;
         l >>= 1;
      }
      i = 0;
      while (r) {
         h[i++] += r % 2;
         r >>= 1;
      }
      int ans = 0;
      for (i = 34; i >= 0; i--) {
         if (h[i] == 0) continue;
         if (h[i] == 2)
            ans += (1 << i);
         if (h[i] == 1) break;
      }
      return ans;
   }
   int rangeBitwiseAnd(int l, int r) {
      int ans = 0;
      vector<int> v(35, 0);
      int j = 0;
      int p = 2;
      while (p / 2 <= r) {
         int d = (r / p) * (p / 2);
         int rem = r % p + 1;
         d += (max(0, rem - p / 2));
         v[j++] += d;
         p *= 2;
      }
      if (l - 1 > 0) {
         l -= 1;
         p = 2;
         j = 0;
         while (p / 2 <= l) {
            int d = (l / p) * (p / 2);
            int rem = l % p + 1;
            d += (max(0, rem - p / 2));
            v[j++] -= d;
            p *= 2;
         }
         l += 1;
      }
      for (int i = 0; i < 34; i++) {
         if (v[i] == (r - l + 1)) {
            ans += (1 << i);
         }
      }
      if (ans != optimised(l, r)) {
         no;
      }
      int a = another(l, r);
      if (a != optimised(l, r)) {
         cout << l << " " << r << "\n";
         no;
      }
      dbg(a, ans);
      return ans;
   }
   void solution() {
      int l, r;
      cin >> l >> r;
      // cin >> l >> r;
      this->rangeBitwiseAnd(l, r);
   }
};
signed main() {
   IOE;
   _IOE();
   srand(time(0));
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      Solution obj;
      obj.solution();
   }
   return 0;
}
