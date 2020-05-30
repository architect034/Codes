#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define endl '\n'
ll n, x;
set<ll> ans, oldD, newD;
/*
    Di = {f(j,i) for every j <= i}
    ans = union of D1,D2,D3,....Dn
    D3 = set{[gcd(a[3],i) for i in D2]} union {a[3]}
    D4 = set{[gcd(a[4],i) for i in D2]} union {a[4]}
    in general D[i] = set{[gcd(a[i],v) for v in D[i-1]]} union {a[i]}
    this way we can calculate all the D[i] using  D[i-1] like DP
*/
signed main() {
   ios::sync_with_stdio(0);
   cout.tie(0);
   cin.tie(0);
   cin >> n >> x;
   oldD.insert(x);
   ans.insert(x);  //
   for (int i = 2; i <= n; i++) {
      cin >> x;
      newD.insert(x);
      for (auto it : oldD) {
         ll gcd = __gcd(it, x);
         newD.insert(gcd);
      }
      ans.insert(newD.begin(), newD.end());  // ans = ans U D[i]
      oldD = newD;                           // D_new will act as D_prev now
      newD.clear();
   }
   cout << ans.size() << endl;
   for (auto I : ans) {
      cout << I << " ";
   }
   cout << endl;
   return 0;
}