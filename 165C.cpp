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
   int k;
   cin >> k;
   string s;
   cin >> s;
   int ans = 0;
   int n = s.size();
   vector<int> dp(n);
   if (k == 0) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
         if (s[i] == '0') {
            cnt++;
         } else {
            ans += (cnt * (cnt + 1)) / 2;
            cnt = 0;
         }
      }
      ans += (cnt * (cnt + 1)) / 2;
      pl(ans);
      return;
   }
   vector<int> st(n + 1, 0), end(n + 1, 0);
   for (int i = 0; i < n; i++) {
      dp[i] = s[i] - '0';
      if (i) {
         dp[i] += dp[i - 1];
      }
   }
   for (int i = 0; i < n; i++) {
      int val = dp[i];
      if (st[val] == 0) {
         st[val] = i + 1;
      }
      end[val] = i + 1;
   }
   for (int i = k; i <= n; i++) {
      if (st[i] == 0) continue;
      int st_of_n = st[i], end_of_n = end[i];
      int st_of_n_minus_k = st[i - k], st_of_n_minus_k_plus_1 = st[i - k + 1];
      if (i - k == 0 && st_of_n_minus_k != 0) {
         st_of_n_minus_k--;
      }
      ans = ans + (end_of_n - st_of_n + 1) * (st_of_n_minus_k_plus_1 - st_of_n_minus_k);
      // cout << (end_of_n - st_of_n + 1) * (st_of_n_minus_k_plus_1 - st_of_n_minus_k) << "\n";
   }
   pl(ans);
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
