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
#define int long long
void real_main() {
   int n, a, b;
   cin >> n >> a >> b;
   string s;
   cin >> s;
   vector<vector<int> > dp(n + 1, vector<int>(2, 1000000000000000000));
   dp[0][0] = b;
   for (ll i = 0; i < n; ++i) {
      if (s[i] == '0') {
         dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a + b);
         dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2 * (a + b));
         dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2 * b);
         dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2 * a + b);
      } else {
         dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2 * b);
      }
   }

   cout << dp[n][0] << "\n";

   // vector<int> dpu(n, 0), dpd(n, 0);
   // if (s[1] == '1') {
   //    dpu[0] = min(2 * a + 3 * b, 4 * b + a);
   //    dpd[0] = dpu[0];
   // } else {
   //    dpu[0] = min(2 * a + 3 * b, 4 * b + a);
   //    dpd[0] = 2 * b + a;
   // }
   // // cout << dpu[0] << " " << dpd[0] << "\n";
   // for (int i = 1; i < n - 1; i++) {
   //    if (s[i + 1] == '1' || s[i] == '1') {
   //       dpu[i] = min(dpu[i - 1] + a + 2 * b, dpd[i - 1] + 2 * a + 2 * b);
   //       dpd[i] = dpu[i];
   //    } else {
   //       dpu[i] = min(dpu[i - 1] + a + 2 * b, (s[i - 1] == '0') ? dpd[i - 1] + 2 * a + 2 * b : 1000000000000000000);
   //       dpd[i] = min(dpu[i - 1] + 2 * a + b, (s[i - 1] == '0') ? dpd[i - 1] + a + b : 1000000000000000000);
   //    }
   //    // cout << dpu[i] << " " << dpd[i] << "\n";
   // }
   // dpu[n - 1] = min(dpu[n - 2] + a + 2 * b, (s[n - 2] == '0') ? dpd[n - 2] + 2 * a + 2 * b : 1000000000000000000);
   // dpd[n - 1] = min(dpu[n - 2] + 2 * a + b, (s[n - 2] == '0') ? dpd[n - 2] + a + b : 1000000000000000000);
   // // cout << dpu[n - 1] << " " << dpd[n - 1] << "\n";
   // pl(min(dpd[n - 1], dpu[n - 1]));
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
