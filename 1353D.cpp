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
void solve() {
   int n;
   cin >> n;
   map<int, set<int>> m;
   m[n].insert(1);
   vector<int> ans(n + 1);
   int cnt = 0;
   while (cnt < n) {
      int lsz = m.rbegin()->ff;
      int st = *(m[lsz].begin());
      m[lsz].erase(m[lsz].begin());
      if (m[lsz].size() == 0) {
         m.erase(lsz);
      }
      int en = st + lsz - 1;
      if (lsz % 2 == 1) {
         ans[(st + en) / 2] = cnt + 1;
         int mid = (st + en) / 2;
         if (mid - 1 >= st) {
            m[(mid - 1) - st + 1].insert(st);
         }
         if (mid + 1 <= en) {
            m[en - mid - 1 + 1].insert(mid + 1);
         }
      } else {
         ans[(st + en - 1) / 2] = cnt + 1;
         int mid = (st + en - 1) / 2;
         if (mid - 1 >= st) {
            m[(mid - 1) - st + 1].insert(st);
         }
         if (mid + 1 <= en) {
            m[en - mid - 1 + 1].insert(mid + 1);
         }
      }
      cnt++;
   }
   for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
   }
   cout << "\n";
}
int main() {
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