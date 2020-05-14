#include <bits/stdc++.h>
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define all(something) something.begin(), something.end()
using namespace std;
const int MAX = 1e5 + 9;
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
#define int long long
void solve() {
   int n, m;
   cin >> n >> m;
   if (n == 1) {
      cout << 0 << "\n";
      return;
   }
   if (n == 2) {
      cout << m << "\n";
      return;
   }
   cout << 2 * m << "\n";
}
signed main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   int tc = 1;
   cin >> tc;
   while (tc--) {
      solve();
   }
}