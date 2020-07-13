#include <bits/stdc++.h>
using namespace std;
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      int n;
      cin >> n;
      map<int, int> xc, yc;
      for (int i = 1; i < 4 * n; i++) {
         int x, y;
         cin >> x >> y;
         xc[x]++;
         yc[y]++;
      }
      int x = 0, y = 0;
      for (auto it : xc) {
         if (it.second % 2 == 1) {
            x = it.first;
            break;
         }
      }
      for (auto it : yc) {
         if (it.second % 2 == 1) {
            y = it.first;
            break;
         }
      }
      cout << x << " " << y << "\n";
   }
}