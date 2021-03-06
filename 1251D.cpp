#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define f(i, a, b) for (int i = a; i < b; i++)
#define rf(i, a, b) for (int i = a; i >= b; i--)
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
   f(i, 0, n) { cout << x[i] << "\n"; }
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
void virtual_main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
#define int long long
bool check(int x, vector<pair<int, int> > v, int n, int s) {
   int chota = 0, bada = 0, sum = 0;
   vector<int> extra;
   for (int i = 0; i < n; i++) {
      if (v[i].ff >= x) {
         bada++;
         sum += v[i].ff;
      } else if (v[i].ss < x) {
         chota++;
         sum += v[i].ff;
      } else {
         extra.pb(v[i].ff);
      }
   }
   int kitna = (n + 1) / 2;
   if (chota >= kitna) {
      return false;
   }
   int reqd = kitna - bada;
   for (int i = 0; i < reqd; i++) {
      sum += x;
      extra.pop_back();
   }
   for (auto it : extra) {
      sum += it;
   }
   if (sum <= s) {
      return true;
   }
   return false;
}
void real_main() {
   int n, s;
   cin >> n >> s;
   vector<pair<int, int> > v(n);
   int mn = INT_MAX, mx = INT_MIN;
   for (int i = 0; i < n; i++) {
      cin >> v[i].ff >> v[i].ss;
      mn = min(mn, v[i].ff);
      mx = max(mx, v[i].ss);
   }
   sort(all(v));
   int low = mn, high = mx, ans = mx;
   while (low <= high) {
      int mid = (low + high) / 2;
      if (check(mid, v, n, s)) {
         ans = mid;
         low = mid + 1;
      } else {
         high = mid - 1;
      }
   }
   pl(ans);
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
