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
#define PI 3.14159265358979323846
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
#define int long long
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
   freopen("error.txt", "w", stderr);
#endif
}

void real_main() {
   int n;
   cin >> n;
   string s;
   cin >> s;
   // int n = s.size();
   int ecnt = 0, ocnt = 0, m = 0, w = 0;
   for (int i = 0; i < n; i++) {
      if (s[i] == 'm')
         m++;
      else if (s[i] == 'e')
         ecnt++;
      else if (s[i] == 'o')
         ocnt++;
      else
         w++;
   }
   vector<int> e(ecnt + 1, 0), o(ocnt + 1, 0);
   e[1] = ecnt;
   o[1] = ocnt;
   for (int i = 2; i <= ecnt; i++) {
      int mul = ((ecnt - i + 1) * power<int>(i, mod - 2, mod)) % mod;
      e[i] = (e[i - 1] * mul) % mod;
   }
   for (int i = 2; i <= ocnt; i++) {
      int mul = ((ocnt - i + 1) * power<int>(i, mod - 2, mod)) % mod;
      o[i] = (o[i - 1] * mul) % mod;
   }

   for (int i = 1; i <= ocnt; i++) {
      o[i] += o[i - 1];
      o[i] %= mod;
   }
   int m_kitna = power<int>(2, m, mod) - 1;
   int w_kitna = power<int>(2, w, mod) - 1;
   // cout << m_kitna << " " << w_kitna << "\n";
   int ans = 0;
   for (int i = 2; i <= ecnt; i++) {
      int val = (m_kitna * w_kitna) % mod;
      val = (val * (e[i])) % mod;
      val = (val * o[min(i - 1, ocnt)]) % mod;
      ans = ans + val;
      ans %= mod;
   }
   pl(ans);
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // double tic, tac;
      // tic = clock();
      // cout << "Case #" << tc << ": ";
      real_main();
      // tac = clock(), cerr << "TC " << i << " done in:: " << 1000 * (tac - tic) / CLOCKS_PER_SEC << " ms\n";
   }
   // cerr << "GG in: " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";
   return 0;
}
