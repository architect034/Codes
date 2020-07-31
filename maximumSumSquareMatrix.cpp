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
const int INF = 1e9 + 10;
class Solution {
  public:
   int solve(vector<vector<int> > &A, int b) {
      int ans = -INF;
      int n = A.size();
      if (n == 0) return 0;
      int dp[n + 1][n + 1];
      memset(dp, 0, sizeof dp);
      for (int i = 1; i <= n; i++) {
         for (int j = 1; j <= n; j++) {
            dp[i][j] = A[i - 1][j - 1];
         }
      }
      for (int i = 2; i <= n; i++) {
         dp[1][i] += dp[1][i - 1];
         dp[i][1] += dp[i - 1][1];
      }
      for (int i = 2; i <= n; i++) {
         for (int j = 2; j <= n; j++) {
            dp[i][j] += (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]);
         }
      }
      for (int i = b; i <= n; i++) {
         for (int j = b; j <= n; j++) {
            ans = max(ans, dp[i][j] - dp[i - b][j] - dp[i][j - b] + dp[i - b][j - b]);
         }
      }
      return ans;
   }
   void solution() {
      int n;
      cin >> n;
      vector<vector<int> > v(n, vector<int>(n));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            cin >> v[i][j];
         }
      }
      int b;
      cin >> b;
      cout << this->solve(v, b);
   }
};
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      Solution obj;
      obj.solution();
   }
   return 0;
}
