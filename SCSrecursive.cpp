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
   string s, t;
   int dp[1001][1001];
   int solve(int n, int m) {
      if (n == 0) return m;
      if (m == 0) return n;
      if (dp[n][m] != INT_MAX) return dp[n][m];
      if (s[n - 1] == t[m - 1]) return dp[n][m] = 1 + solve(n - 1, m - 1);
      return dp[n][m] = 1 + min(solve(n - 1, m), solve(n, m - 1));
   }
   string shortestCommonSupersequence(string s, string t) {
      this->s = s;
      this->t = t;
      for (int i = 0; i <= s.size(); i++) {
         for (int j = 0; j <= t.size(); j++) {
            dp[i][j] = INT_MAX;
         }
      }
      string ans = "";
      solve(s.size(), t.size());
      int i = s.size(), j = t.size();
      while (i > 0 && j > 0) {
         if (s[i - 1] == t[j - 1]) {
            ans += s[i - 1];
            i--;
            j--;
         } else {
            if (dp[i - 1][j] > dp[i][j - 1]) {
               ans += t[j - 1];
               j--;
            } else {
               ans += s[i - 1];
               i--;
            }
         }
      }
      cout << dp[s.size()][t.size()] << "\n";
      while (i > 0) ans += s[i - 1], i--;
      while (j > 0) ans += t[j - 1], j--;
      reverse(ans.begin(), ans.end());
      return ans;
   }
   void solution() {
      string s, t;
      cin >> s >> t;
      cout << this->shortestCommonSupersequence(s, t);
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
