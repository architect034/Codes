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
const int MAX = 1e7 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
void sieve() {
   prime[0] = prime[1] = 0;
   spf[2] = 2;
   f(i, 4, MAX - 1, 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   f(i, 3, MAX - 1, 2) {
      if (prime[i]) {
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
   string s, t;
   cin >> s >> t;
   set<string> st;
   int n;
   cin >> n;
   map<string, string> m;
   for (int i = 0; i < n; i++) {
      string x;
      cin >> x;
      st.insert(x);
   }
   if (st.find(t) == st.end()) {
      cout << 0 << "\n";
      return;
   }
   int ss = s.size();
   queue<string> q;
   q.push(s);
   int ans = 0;
   while (!q.empty()) {
      ans++;
      int len = q.size();
      for (int i = 0; i < len; i++) {
         string w = q.front();
         string o = q.front();
         q.pop();
         for (int j = 0; j < ss; j++) {
            char c = w[j];
            for (char k = 'a'; k <= 'z'; k++) {
               w[j] = k;
               if (w == t) {
                  cout << ans + 1 << "\n";
                  vector<string> result;
                  result.pb(w);
                  w = o;
                  int cnt = 0;
                  while (cnt < ans) {
                     if (w == t) {
                        break;
                     }
                     result.pb(w);
                     w = m[w];
                     cnt++;
                  }
                  while (!result.empty()) {
                     cout << result.back() << " ";
                     result.pop_back();
                  }
                  return;
               }
               if (st.find(w) == st.end()) {
                  continue;
               }
               st.erase(w);
               q.push(w);
               if (m.find(w) == m.end())
                  m[w] = o;
            }

            w[j] = c;
         }
      }
   }
   cout << 0 << "\n";
}
int main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   while (test_cases--) {
      solve();
   }
   return 0;
}