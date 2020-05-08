#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
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
#define nl cout << endl
using namespace std;
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1), primes;
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
template <typename T>
void in(T &x) {
   cin >> x;
}
template <typename T, typename U>
void in(T &x, U &y) {
   cin >> x >> y;
}
template <typename T, typename U, typename V>
void in(T &x, U &y, V &z) {
   cin >> x >> y >> z;
}
template <typename T>
void ps(T x) {
   cout << x << " ";
}
template <typename T>
void ps(const vector<T> &x, int n) {
   for (int i = 0; i < n; i++) {
      cout << x[i];
      (i == n - 1) ? cout << endl : cout << " ";
   }
}
template <typename T>
void pl(T x) {
   cout << x << endl;
}
template <typename T>
void pl(const vector<T> &x, int n) {
   for (int i = 0; i < n; i++) {
      cout << x[i] << "\n";
   }
}
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
template <typename T>
T power(T a, T b, T m) {
   T res = 1;
   while (b) {
      if (b & 1) {
         res = (res * a) % m;
      }
      a = (a * a) % m;
      b = b >> 1;
   }
   return res % m;
}
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
// #define int long long
void real_main() {
   int n, m;
   cin >> n >> m;
   vector<int> grail[n + 1], groad[n + 1];
   for (int i = 0; i < m; i++) {
      int u1, u2;
      cin >> u1 >> u2;
      grail[u1].pb(u2), grail[u2].pb(u1);
   }
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         bool say = 0;
         for (int k = 0; k < grail[i].size(); k++) {
            if (grail[i][k] == j) {
               say = 1;
               break;
            }
         }
         if (say == 0) {
            groad[i].pb(j);
         }
      }
   }
   vector<int> drail(n + 1, 0), droad(n + 1, 0), vrail(n + 1, 0), vroad(n + 1, 0);
   queue<int> q;
   q.push(1);
   vrail[1] = 1;
   drail[1] = 1;
   while (q.empty() == 0) {
      int x = q.front();
      if (x == n) {
         break;
      }
      q.pop();
      for (int i : grail[x]) {
         if (vrail[i] == 0) {
            vrail[i] = 1;
            q.push(i);
            drail[i] = drail[x] + 1;
         }
      }
   }
   while (q.empty() == 0) q.pop();
   q.push(1);
   vroad[1] = 1;
   droad[1] = 1;
   while (q.empty() == 0) {
      int x = q.front();
      if (x == n) {
         break;
      }
      q.pop();
      for (int i : groad[x]) {
         if (vroad[i] == 0) {
            vroad[i] = 1;
            q.push(i);
            droad[i] = droad[x] + 1;
         }
      }
   }
   if (drail[n] && droad[n]) {
      pl(max(drail[n], droad[n]) - 1);
   } else {
      pl(-1);
   }
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
