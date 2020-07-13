#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define test() \
   ll t;       \
   cin >> t;   \
   while (t--)
#define ll long long
#define ull unsigned long long
#define loop(i, start, end, increment) for (ll i = start; i <= end; i += increment)
#define ulta(i, start, end, decrement) for (ll i = start; i >= end; i -= decrement)
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define mp make_pair
#define FF first
#define SS second
#define all(something) something.begin(), something.end()
#define mod 1000000007
#define lpi(i, a, b) for (ll i = a; i < b; i++)
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   test() {
      string s;
      cin >> s;
      ll m;
      cin >> m;
      vector<ll> v(m);
      vector<ll> hax(26, 0);
      lpi(i, 0, m) cin >> v[i];
      lpi(i, 0, s.size()) hax[s[i] - 'a']++;
      vector<char> ans(m, '.');
      ll cnt = 0;
      while (true) {
         ll c = 0;
         vector<ll> dist;
         for (ll i = 0; i < m; i++) {
            if (v[i] == 0) {
               c++;
               dist.push_back(i);
            }
         }
         for (ll j = 25; j >= 0; j--) {
            if (hax[j] >= c && hax[j] != 0) {
               for (ll ind = 0; ind < m; ind++) {
                  if (v[ind] > 0) {
                     for (ll ii = 0; ii < dist.size(); ii++) {
                        v[ind] = abs(v[ind] - abs(ind - dist[ii]));
                     }
                  } else if (v[ind] == 0) {
                     v[ind] = -1;
                     ans[ind] = char(j + 'a');
                     hax[j] = 0;
                     cnt++;
                  }
               }
               break;
            }
         }
         if (cnt == m) break;
      }
      for (int i = 0; i < m; i++) {
         cout << ans[i];
      }
      cout << endl;
   }
}