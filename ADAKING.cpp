#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
#define IOE ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL), cerr.tie(NULL)
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
const int MAX = 2e5 + 9;
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
void _IOE() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
}
// #define int long long
void _main() {
   int k;
   cin >> k;
   vector<vector<char> > g(8, vector<char>(8, 'X'));
   queue<pair<int, int> > q;
   q.push({0, 0});
   g[0][0] = 'O';
   k--;
   while (!q.empty()) {
      if (k == 0) {
         break;
      }
      int x = q.front().ff, y = q.front().ss;
      q.pop();
      if (y - 1 >= 0 && k && g[x][y - 1] == 'X') {
         q.push({x, y - 1});
         k--;
         g[x][y - 1] = '.';
      }
      if (x - 1 >= 0 && k && g[x - 1][y] == 'X') {
         q.push({x - 1, y});
         k--;
         g[x - 1][y] = '.';
      }
      if (y + 1 < 8 && k && g[x][y + 1] == 'X') {
         q.push({x, y + 1});
         k--;
         g[x][y + 1] = '.';
      }
      if (x + 1 < 8 && k && g[x + 1][y] == 'X') {
         q.push({x + 1, y});
         k--;
         g[x + 1][y] = '.';
      }
   }
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
         cout << g[i][j];
      }
      nl;
   }
}
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      _main();
   }
   return 0;
}
