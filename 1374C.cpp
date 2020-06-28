#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define FAST ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
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
LL power(LL a, LL b) {
   LL res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
LL power(LL a, LL b, LL m) {
   LL res = 1;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
// #define int long long
void solve() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   int c = 0, ans = 0;
   for (int i = 0; i < n; i++) {
      if (s[i] == '(')
         c++;
      else
         c--;
      if (c < 0) {
         ans++;
         c++;
      }
   }
   cout << ans << "\n";
}
signed main() {
   FAST;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   int _t;
   cin >> _t;
   while (_t--) {
      solve();
   }
   return 0;
}
