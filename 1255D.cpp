#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
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
   //             /
   //            /
   // PASSED - \/
   string s = "";
   for (int c = '0'; c <= '9'; c++) s += c;
   for (char c = 'a'; c <= 'z'; c++) s += c;
   for (char c = 'A'; c <= 'Z'; c++) s += c;
   int n, m, k, rice = 0;
   in(n, m, k);
   vector<vector<char> > v(n, vector<char>(m));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         in(v[i][j]);
         if (v[i][j] == 'R') rice++;
      }
   }
   int per_chicken = rice / k;
   int how_many_extra = rice % k;
   if (how_many_extra == 0) per_chicken--;
   int rem = k - how_many_extra;
   int x = 0, y = 0, pointer = 0;
   vector<vector<char> > ans(n, vector<char>(m, '?'));
   int t1 = 0, t2 = 0;
   int how_much_done = 0;
   for (int r = x; r < n; r++) {
      if (r % 2 == 0) {
         for (int c = y; c < m; c++) {
            y = m - 1;
            ans[r][c] = s[pointer];
            if (v[r][c] == 'R') {
               how_much_done++;
            }
            if (how_much_done == per_chicken + 1) {
               x = r;
               y = c + 1;
               if (y == m) {
                  y = m - 1;
                  x += 1;
               }
               how_much_done = 0;
               pointer++;
               t1++;
               if (t1 == how_many_extra) {
                  per_chicken--;
               }
               if (t1 == k) {
                  pointer--;
                  break;
               }
            }
         }
      } else {
         for (int c = y; c >= 0; c--) {
            y = 0;
            ans[r][c] = s[pointer];
            if (v[r][c] == 'R') {
               how_much_done++;
            }
            if (how_much_done == per_chicken + 1) {
               x = r;
               y = c - 1;
               if (y == -1) {
                  y = 0;
                  x += 1;
               }
               how_much_done = 0;
               pointer++;
               t1++;
               if (t1 == how_many_extra) {
                  per_chicken--;
               }
               if (t1 == k) {
                  pointer--;
                  break;
               }
            }
         }
      }
      if (t1 == k) {
         break;
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (ans[i][j] == '?') ans[i][j] = s[pointer];
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cout << ans[i][j];
      }
      nl;
   }
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
