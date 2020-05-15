#include "bits/stdc++.h"
using namespace std;
int tc = 0;
int n, m;
void solve() {
   cin >> n >> m;
   if (n == 1) {
      cout << 0 << endl;
      return;
   } else if (n == 2) {
      cout << m << endl;
      return;
   } else {
      cout << 2 * m << endl;
   }
}
int main() {
   ios::sync_with_stdio(0);
   cout.tie(0);
   cin.tie(0);
   cout << fixed << setprecision(10);
   if (tc != 1)
      cin >> tc;
   for (int i = 1; i <= tc; ++i) {
      double tic, tac;
      // if (!ONLINE_JUDGE)
      cerr << "While solving TC " << i << ":\n", tic = clock();
      solve();
      // if (!ONLINE_JUDGE)
      tac = clock(), cerr << "\nTC " << i << " done in:: " << 1000 * (tac - tic) / CLOCKS_PER_SEC << " ms\n";
   }
   // if (!ONLINE_JUDGE) cerr << "\nGG in: " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";
   return 0;
}