#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      vector<int> h(n + 1);
      for (int i = 0; i < n; i++) {
         int x;
         cin >> x;
         h[x]++;
      }
      int addon = 0, ans = 0;
      for (int i = 1; i <= n; i++) {
         if (!h[i]) continue;
         h[i] += addon;
         ans = ans + h[i] / i;
         addon = h[i] % i;
      }
      cout << (ans) << "\n";
   }
}