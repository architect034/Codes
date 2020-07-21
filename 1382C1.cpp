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
   void solution() {
      int n;
      cin >> n;
      string a, b;
      cin >> a >> b;
      vector<int> ans;
      for (int i = n - 1; i >= 0; i--) {
         if (a[i] == b[i]) continue;
         if (a[i] == a[0]) {
            ans.pb(i + 1);
            int l = 0, r = i;
            for (int j = l; j <= r; j++) {
               if (a[j] == '0')
                  a[j] = '1';
               else
                  a[j] = '0';
            }
            while (l < r) {
               swap(a[l++], a[r--]);
            }
         } else {
            if (a[0] == '1')
               a[0] = '0';
            else
               a[0] = '1';
            ans.pb(1);
            ans.pb(i + 1);
            int l = 0, r = i;
            for (int j = l; j <= r; j++) {
               if (a[j] == '0')
                  a[j] = '1';
               else
                  a[j] = '0';
            }
            while (l < r) {
               swap(a[l++], a[r--]);
            }
         }
      }
      ps(ans.size());
      for (int i = 0; i < ans.size(); i++) {
         cout << ans[i] << " ";
      }
      nl;
   }
};
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   cin >> test_cases;
   Solution obj;
   for (int i = 1; i <= test_cases; i++) {
      obj.solution();
   }
   return 0;
}
