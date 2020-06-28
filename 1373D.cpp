#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define IOE ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
#define LL long long
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
const LL mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1), primes;
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   for (LL i = 4; i < MAX; i += 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   for (LL i = 3; i < MAX; i += 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         for (LL j = i * i; j < MAX; j += i) {
            prime[j] = 0;
            if (spf[j] == 1) {
               spf[j] = i;
            }
         }
      }
   }
}
// #include <ext/pb_ds/assoc_container.hpp> // Common file
// #include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// using namespace __gnu_pbds;
// typedef tree< pair<int,int> ,null_type,less< pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
#define int LL
int maxSubArraySum(vector<int> a, int size) {
   if (size == 0) {
      return 0LL;
   }
   int max_so_far = a[0];
   int curr_max = a[0];

   for (int i = 1; i < size; i++) {
      curr_max = max(a[i], curr_max + a[i]);
      max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
void _main() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &x : v) cin >> x;
   vector<int> a, b;
   int ans = 0;
   for (int i = 0; i < n; i += 2) {
      ans += v[i];
   }
   for (int i = 1; i < n; i += 2) {
      a.pb(v[i] - v[i - 1]);
      if (i + 1 < n) {
         b.pb(v[i] - v[i + 1]);
      }
   }
   dbg(a, b);
   int sum = 0, mx = 0;
   int ex = max(maxSubArraySum(a, a.size()), maxSubArraySum(b, b.size()));
   cout << (ans + max(0LL, ex)) << endl;
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
