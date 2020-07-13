#include <bits/stdc++.h>
using namespace std;
#define LL long long
void solve();
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}
LL res;
void solve() {
   res = 0;
   LL n, K;
   cin >> n >> K;
   vector<LL> a(n);
   for (LL i = 0; i < n; i++) {
      cin >> a[i];
   }
   multiset<LL> ms;
   for (LL i = 0; i < n; i++) {
      ms.insert(a[i]);
   }
   while (ms.size()) {
      LL LE = *(--(ms.end()));
      if (LE - K <= 0) {
         res += (LL)ms.size();
         break;
      }
      if (!(ms.find(K) == ms.end())) {
         res += 1;
         K <<= 1;
         ms.erase(ms.find(K >> 1));
         continue;
      } else if (*ms.begin() <= K) {
         multiset<LL>::iterator it = --(ms.lower_bound(K));
         if (((*it) << 1) >= K) {
            K = (*it) << 1;
            res += 1;
            ms.erase(it);
            continue;
         }
      }
      res += 1;
      multiset<LL>::iterator it = --ms.end();
      ms.erase(it);
      LL put = min(LE, (LE - K) << 1);
      K <<= 1;
      ms.insert(put);
   }
   cout << res << "\n";
}