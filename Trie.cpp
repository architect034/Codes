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
const int MAX = 2e4 + 9;
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
class Trie {
  public:
   int trie[27][27][1000];
   void insert(string s) {
      int n = s.size();
      trie[0][s[0] - 'a' + 1][0] = s[0] - 'a' + 1;
      for (int i = 0; i < n - 1; i++) {
         trie[s[i] - 'a' + 1][s[i + 1] - 'a' + 1][i + 1] = s[i + 1] - 'a' + 1;
      }
   }
   bool dfs(string s, int a, int b, int idx) {
      if (idx == s.size() - 1) {
         if (char(b + 'a' - 1) == '.') return true;
         if (trie[a][b][idx] != 0)
            return true;
         return false;
      }
      int say = 0;
      if (char(b + 'a' - 1) == '.') {
         for (int i = 1; i <= 26; i++) {
            if (dfs(s, i, s[idx + 1] - 'a' + 1, idx + 1)) {
               return true;
            }
         }
      }
      if (trie[a][b][idx] == 0) return false;
      return dfs(s, b, s[idx + 1] - 'a' + 1, idx + 1);
   }
   bool search(string s) {
      return dfs(s, 0, s[0] - 'a' + 1, 0);
   }
   void solution() {
      int n;
      cin >> n;
      vector<string> v(n);
      for (int i = 0; i < n; i++) {
         cin >> v[i];
         insert(v[i]);
      }
      string t;
      cin >> t;
      cout << search(t);
   }
};
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      Trie obj;
      obj.solution();
   }
   return 0;
}
