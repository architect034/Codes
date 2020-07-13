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
   int n, k;
   cin >> n >> k;
   if (k < n) {
      int dp[n][n];
      memset(dp, 0, sizeof dp);
      for (int i = 0; i < k; i++) {
         dp[i][i] = 1;
      }
      (k) ? pl(2) : pl(0);
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cout << dp[i][j];
         }
         nl;
      }
      return;
   }
   int dp[n][n];
   memset(dp, 0, sizeof dp);
   int pc = k / n;
   for (int i = 0; i < n; i++) {
      for (int j = i, cnt = 0; cnt < pc; cnt++) {
         dp[j][i] = 1;
         j = (j + 1) % n;
      }
   }
   int ex = k % n;
   dbg(ex);
   if (ex) {
      for (int i = 0; i < ex; i++) {
         dp[pc][i] = 1;
         pc++;
         pc %= n;
      }
   }
   int mnr = INT_MAX, mxr = 0, ans = 0;
   for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
         sum += dp[i][j];
      }
      mxr = max(mxr, sum);
      mnr = min(mnr, sum);
   }
   ans += ((mxr - mnr) * (mxr - mnr));
   int mnc = INT_MAX, mxc = 0;
   for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = 0; j < n; j++) {
         sum += dp[j][i];
      }
      mnc = min(mnc, sum);
      mxc = max(mxc, sum);
   }
   ans += ((mxc - mnc) * (mxc - mnc));
   pl(ans);
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cout << dp[i][j];
      }
      nl;
   }
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
