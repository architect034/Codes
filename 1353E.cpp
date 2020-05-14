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
int calc(vector<char> &fn, int n, int k) {
   vector<char> v(n + 1);
   for (int i = n; i >= 1; i--) {
      v[n + 1 - i] = fn[i];
   }
   vector<int> dp(n + 1 + k, 0), pre(n + 1 + k, 0);
   pre[1] = (v[1] == '1') ? 1 : 0;
   for (int i = 2; i <= n; i++) {
      pre[i] = pre[i - 1] + ((v[i] == '1') ? 1 : 0);
   }
   for (int i = n + 1; i <= n + k + 1; i++) {
      pre[i] = pre[i - 1];
   }
   for (int i = 1; i <= k; i++) {
      dp[i] = pre[i - 1];
      // if (v[i] == '0') {
      //    dp[i]++;
      // }
   }
   for (int i = k + 1; i <= n; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
      if (v[i] == '0') {
         dp[i]++;
      }
   }
   for (int i = n + 1; i <= n + k; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
   }
   int ans = INT_MAX;
   for (int i = n + k; i > n; i--) {
      ans = min(ans, dp[i]);
   }
   ans = min(ans, pre[n]);
   return ans;
}
void solve() {
   int n, k;
   cin >> n >> k;
   vector<char> v(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> v[i];
   }
   vector<int> dp(n + 1 + k, 0), pre(n + 1 + k, 0);
   pre[1] = (v[1] == '1') ? 1 : 0;
   for (int i = 2; i <= n; i++) {
      pre[i] = pre[i - 1] + ((v[i] == '1') ? 1 : 0);
   }
   for (int i = n + 1; i <= n + k + 1; i++) {
      pre[i] = pre[i - 1];
   }
   for (int i = 1; i <= k; i++) {
      dp[i] = pre[i - 1];
      // if (v[i] == '0') {
      //    dp[i]++;
      // }
   }
   for (int i = k + 1; i <= n; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
      if (v[i] == '0' && v[i - k] == '1') {
         dp[i]++;
      }
   }
   for (int i = n + 1; i <= n + k; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
   }
   int ans = INT_MAX;
   for (int i = n + k; i > n; i--) {
      ans = min(ans, dp[i]);
   }
   ans = min(ans, pre[n]);

   //reverse
   vector<char> vv(n + 1);
   for (int i = n; i >= 1; i--) {
      vv[n + 1 - i] = v[i];
   }
   dp.assign(n + k + 1, 0);
   pre.assign(n + k + 1, 0);
   pre[1] = (vv[1] == '1') ? 1 : 0;
   for (int i = 2; i <= n; i++) {
      pre[i] = pre[i - 1] + ((vv[i] == '1') ? 1 : 0);
   }
   for (int i = n + 1; i <= n + k + 1; i++) {
      pre[i] = pre[i - 1];
   }
   for (int i = 1; i <= k; i++) {
      dp[i] = pre[i - 1];
   }
   for (int i = k + 1; i <= n; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
      if (vv[i] == '0' && vv[i - k] == '1') {
         dp[i]++;
      }
   }
   for (int i = n + 1; i <= n + k; i++) {
      dp[i] = dp[i - k] + pre[i - 1] - pre[i - k];
   }
   for (int i = n + k; i > n; i--) {
      ans = min(ans, dp[i]);
   }
   ans = min(ans, pre[n]);
   //
   cout << ans << endl;
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