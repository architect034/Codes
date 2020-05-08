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
#define int long long
void real_main() {
   int n;
   cin >> n;
   vector<int> v(n + 1);
   for (int i = 1; i <= n; i++) {
      cin >> v[i];
   }
   vector<int> dp1(n + 1, 0), dp2(n + 1, 0);
   vector<int> last_min(n + 1), next_min(n + 1);
   stack<int> s;
   for (int i = 1; i <= n; i++) {
      while (!s.empty() && v[s.top()] >= v[i]) {
         s.pop();
      }
      if (s.empty()) {
         last_min[i] = -1;
      } else {
         last_min[i] = s.top();
      }
      s.push(i);
   }
   while (s.empty() == 0) {
      s.pop();
   }
   for (int i = n; i >= 1; i--) {
      while (!s.empty() && v[s.top()] >= v[i]) {
         s.pop();
      }
      if (s.empty()) {
         next_min[i] = -1;
      } else {
         next_min[i] = s.top();
      }
      s.push(i);
   }
   for (int i = 1; i <= n; i++) {
      if (last_min[i] == -1) {
         dp1[i] = i * v[i];
      } else {
         dp1[i] = abs(last_min[i] - i) * v[i] + dp1[last_min[i]];
      }
   }
   for (int i = n; i >= 1; i--) {
      if (next_min[i] == -1) {
         dp2[i] = (n - i + 1) * v[i];
      } else {
         dp2[i] = abs(next_min[i] - i) * v[i] + dp2[next_min[i]];
      }
   }
   // for (int i = 1; i <= n; i++) {
   //    cout << dp1[i] << " ";
   // }
   // nl;
   // for (int i = 1; i <= n; i++) {
   //    cout << dp2[i] << " ";
   // }
   // nl;
   int index = 0, mx = 0;
   for (int i = 1; i <= n; i++) {
      if (dp1[i] + dp2[i] - v[i] > mx) {
         mx = dp1[i] + dp2[i] - v[i];
         index = i;
      }
   }
   // cout << index << "\n";
   vector<int> ans(n + 1);
   int cur = v[index];
   for (int i = index; i >= 1; i--) {
      ans[i] = min(v[i], cur);
      cur = min(v[i], cur);
   }
   cur = v[index];
   for (int i = index + 1; i <= n; i++) {
      ans[i] = min(v[i], cur);
      cur = min(v[i], cur);
   }
   for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
   }
   nl;
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
