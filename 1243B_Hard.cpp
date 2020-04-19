#include <bits/stdc++.h>
#define ll long long
#define f(i, st, en, in) for (ll i = st; i <= en; i += in)
#define rf(i, st, en, de) for (ll i = st; i >= en; i -= de)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(something) something.begin(), something.end()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
vector<int> primes;
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   f(i, 4, MAX - 1, 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   f(i, 3, MAX - 1, 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         f(j, i * i, MAX - 1, i) {
            prime[j] = 0;
            if (spf[j] == 1) {
               spf[j] = i;
            }
         }
      }
   }
}
ll power(ll a, ll b) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
ll power(ll a, ll b, ll m) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
void pre() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
void solve() {
   int n;
   cin >> n;
   string s, t;
   cin >> s >> t;
   vector<int> h(26, 0);
   for (int i = 0; i < n; i++) {
      h[s[i] - 'a']++;
      h[t[i] - 'a']++;
   }
   for (auto x : h) {
      if (x % 2) {
         cout << "No\n";
         return;
      }
   }
   int res = 0;
   vector<pair<int, int> > ans;
   for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
         bool done = false;
         for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
               swap(s[j], t[i]);
               ans.pb({j + 1, i + 1});
               res++;
               done = true;
               break;
            }
         }
         if (!done) {
            for (int j = i + 1; j < n; j++) {
               if (t[j] == s[i]) {
                  ans.pb({j + 1, j + 1});
                  ans.pb({j + 1, i + 1});
                  res += 2;
                  swap(t[j], s[j]);
                  swap(s[j], t[i]);
                  break;
               }
            }
         }
      }
   }
   if (res == 1)
      cout << "Yes\n";
   else
      cout << "No\n";
   // cout << res << "\n";
   // for (auto x : ans) {
   //    cout << x.ff << " " << x.ss << "\n";
   // }
}
signed main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}
