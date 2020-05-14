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
   int n, k;
   cin >> n >> k;
   vector<int> a(n), b(n);
   for (int &i : a) {
      cin >> i;
   }
   for (int &i : b) {
      cin >> i;
   }
   sort(all(a));
   sort(all(b));
   reverse(all(b));
   int sum = 0;
   int ap = 0, bp = 0;
   int cnt = 0;
   while (cnt < k && ap < n && bp < n) {
      if (a[ap] < b[bp]) {
         swap(a[ap], b[bp]);
         ap++;
         bp++;
         cnt++;
      } else if (a[ap] > b[bp]) {
         break;
      } else {
         ap++;
         bp++;
      }
   }
   for (int i = 0; i < n; i++) {
      sum += a[i];
   }
   cout << sum << "\n";
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