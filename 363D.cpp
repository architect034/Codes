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
int n, m, a;
vector<int> p(MAX), r(MAX);
int check(int x) {
   if (x > n) {
      return -1;
   }
   vector<int> rent, personal_money;
   for (int i = 0; i < x; i++) {
      rent.pb(r[i]);
      personal_money.pb(p[n - 1 - i]);
   }
   reverse(all(personal_money));
   int extra = 0, sum = 0;
   for (int i = 0; i < x; i++) {
      extra += max(0LL, rent[i] - personal_money[i]);
      sum += rent[i];
   }
   if (extra > a) {
      return -1;
   }
   return max(0LL, sum - a);
}
void real_main() {
   cin >> n >> m >> a;
   for (int i = 0; i < n; i++) {
      cin >> p[i];
   }
   for (int i = 0; i < m; i++) {
      cin >> r[i];
   }
   sort(p.begin(), p.begin() + n), sort(r.begin(), r.begin() + m);
   int low = 1, high = m, kitna_ko_rent = 0, paisa = 0;
   while (low <= high) {
      int mid = (low + high) >> 1;
      int total_sum = check(mid);
      if (total_sum != -1) {
         kitna_ko_rent = mid;
         paisa = total_sum;
         low = mid + 1;
      } else {
         high = mid - 1;
      }
   }
   ps(kitna_ko_rent);
   pl(paisa);
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
