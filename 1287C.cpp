#include <bits/stdc++.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define rf for (int i = n; i >= 0; i--)
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
   for (ll i = 4; i < MAX; i += 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   for (ll i = 3; i < MAX; i += 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         for (ll j = i * i; j < MAX; j += i) {
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
   int n, cnt = 0;
   cin >> n;
   bool say = false;
   vector<int> v(n);
   for (int& x : v) {
      cin >> x;
      if (x == 0) cnt++;
   }
   if (cnt == n) {
      if (n == 1) {
         pl(0);
         return;
      }
      pl(1);
      return;
   }
   int res = 0, idx = -1;
   for (int i = 1; i < n; i++) {
      if (v[i] && idx == -1) idx = i;
      if (v[i] % 2 != v[i - 1] % 2 && v[i] && v[i - 1]) res++;
   }
   cout << res << "\n";
   int e = 0, o = 0;
   for (int i = 1; i <= n; i++) {
      for (int j = 0; j < n; j++) {
         if (v[j] == i) say = true;
      }
      if (!say) {
         if (i & 1)
            o++;
         else
            e++;
      }
      say = false;
   }
   cout << o << " " << e << "\n";
   int st = 0, en;
   vector<pair<int, int> > seg, seg2;
   for (int i = 1; i < n; i++) {
      if (!v[i] && v[i - 1]) {
         st = i;
      } else if (v[i] && !v[i - 1]) {
         if (st == 0) {
            seg2.pb({i - st, st});
            st = -1;
            continue;
         }
         if (st != 0) {
            int p1 = v[st - 1] % 2, p2 = v[i] % 2;
            if (p1 != p2) {
               // cout << v[i - 1] << " st\n";
               // cout << st << " " << i - 1 << " added 1\n";
               res++;
               st = -1;
               continue;
            }
         }
         seg.pb({i - st, st});
         st = -1;
      }
   }
   if (st != -1 && v[st] == 0 && v[n - 1] == 0) {
      seg2.pb({n - st, st});
   }
   sort(all(seg));
   sort(all(seg2));
   // cout << seg2.size() << "\n";
   for (int i = 0; i < (int)seg.size(); i++) {
      int len = seg[i].ff;
      cout << seg[i].ss << " " << seg[i].ss + len - 1 << " with parity : ";
      st = seg[i].ss, en = seg[i].ss + seg[i].ff - 1;
      int parity = v[st - 1] % 2;
      cout << parity << " and length : " << len << "\n";
      if (parity) {
         if (o >= len) {
            o -= len;
            cout << 0 << " added\n";
         } else {
            res += 2;
            cout << "2 added\n";
            e = e - (len - o);
            o = 0;
         }
      } else {
         if (e >= len) {
            cout << "0 added\n";
            e -= len;
         } else {
            res += 2;
            cout << "2 added\n";
            o = o - (len - e);
            e = 0;
         }
      }
   }
   cout << res << "\n";
   for (int i = 0; i < seg2.size(); i++) {
      st = seg2[i].ss, en = seg2[i].ss + seg2[i].ff - 1;
      int len = seg2[i].ff;
      if (st == 0) {
         int parity = v[en + 1] % 2;
         if (parity) {
            if (o >= len) {
               o -= len;
            } else {
               res += 1;
               e = e - (len - o);
               o = 0;
            }
         } else {
            if (e >= len) {
               e -= len;
            } else {
               res += 1;
               o = o - (len - e);
               e = 0;
            }
         }
         continue;
      }
      if (en == n - 1) {
         int parity = v[st - 1] % 2;
         if (parity) {
            if (o >= len) {
               o -= len;
            } else {
               res += 1;
               e = e - (len - o);
               o = 0;
            }
         } else {
            if (e >= len) {
               e -= len;
            } else {
               res += 1;
               o = o - (len - e);
               e = 0;
            }
         }
         continue;
      }
   }
   pl(res);
   // yeh mc tha
   // for (auto x : seg) {
   //    cout << x.ss << " " << x.ss + x.ff - 1 << "\n";
   // }
}
signed main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}
