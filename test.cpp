/*
* I'm a Ghost
* Now you see me, now you don't
*/
#include <bits/stdc++.h>
#define fast()                   \
   ios_base::sync_with_stdio(0); \
   cin.tie(0);                   \
   cout.tie(0);
#define ll long long
#define mod 1000000007
#define inf ((ll)1e18)
#define eps 1e-9
#define ff first
#define ss second
#define pb push_back
#define endl "\n"
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   fast();
   ll t;
   cin >> t;
   while (t--) {
      ll n, k;
      cin >> n >> k;
      string s;
      cin >> s;
      sort(s.begin(), s.end());
      char last = s[n - 1];
      if (k == 1) {
         cout << s << endl;
         continue;
      }
      ll cnt = 1, v = 2;
      while ((k - v) >= 0 && s[k - v++] == s[k - 1])
         cnt++;
      if (s[k - 1] != s[k - 2] || s[0] != s[k - 1]) {
         cout << s[k - 1] << endl;
         continue;
      }
      if (s[k] != last) {
         for (ll i = k - 1; i < n; i++)
            cout << s[i];
         cout << endl;
         continue;
      }
      // cerr<<s<<endl;
      cout << s[k - 1];
      for (ll i = k; i < n; i += cnt)
         cout << s[i];

      cout << endl;
   }
}