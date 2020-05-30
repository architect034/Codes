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
const int MAX = 3e5 + 9;
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
#ifndef OJ
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
#define int long long
int calc_brute(vector<int> v, int n) {
   vector<int> tmp;
   for (int i = 0; i < n - 1; i++) {
      for (int j = i + 1; j < n; j++) {
         tmp.pb((v[i] * v[j]) / __gcd(v[i], v[j]));
      }
   }
   int g = 0;
   for (int i = 0; i < tmp.size(); i++) {
      g = __gcd(g, tmp[i]);
   }
   return g;
}
void real_main() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &x : v) {
      cin >> x;
   }
   map<int, int> no_of_times;
   map<int, vector<int> > the_count;
   for (int i = 0; i < n; i++) {
      int x = v[i];
      while (x != 1) {
         int sp = spf[x];
         no_of_times[sp]++;
         int cnt = 0;
         while (x % sp == 0) {
            x = x / sp;
            cnt++;
         }
         the_count[sp].pb(cnt);
      }
   }
   int ans = 1;
   for (auto x : no_of_times) {
      int val = x.ff, kitne_baar = x.ss;
      if (kitne_baar >= (n - 1)) {
         vector<int> temp = the_count[val];
         if (kitne_baar == n - 1)
            temp.pb(0);
         sort(all(temp));
         ans = ans * power(val, max(temp[0], temp[1]));
      }
   }
   pl(ans);
}
signed main() {
   Fast;
   virtual_main();
   sieve();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}