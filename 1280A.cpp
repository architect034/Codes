#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define rf for (int i = n; i >= 0; i--)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define fl(i, a, b) for (int i = a; i < b; i++)
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
// #define int long long
void real_main() {
   int x;
   cin >> x;
   string s;
   cin >> s;
   string ans = s;
   int i = 0;
   while (ans.size() < x && i < x) {
      if (i >= ans.size()) break;
      int cnt = ans[i] - '0';
      string temp;
      if (cnt > 1) {
         fl(j, i + 1, ans.size()) { temp += ans[j]; }
      }
      while (cnt > 1) {
         ans += temp;
         cnt--;
      }
      i++;
   }
   ll res = ans.size();
   ll t = ans.size();
   for (ll j = i; j < x; j++) {
      if (i >= ans.size()) {
         break;
      }
      ll d = ans[j] - '0';
      res += (t - 1 - j) * (d - 1);
      t = res;
      res %= mod, t %= mod;
   }
   res = (res + mod) % mod;
   cout << res << "\n";
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
