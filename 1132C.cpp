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
// #define int long long
void real_main() {
   int n, q;
   cin >> n >> q;
   vector<pair<int, int> > v(q);
   vector<int> dp(n + 2, 0);
   for (int i = 0; i < q; i++) {
      cin >> v[i].ff >> v[i].ss;
      dp[v[i].ff]++;
      dp[v[i].ss + 1]--;
   }
   int total = 0;
   for (int i = 1; i <= n; i++) {
      dp[i] += dp[i - 1];
      if (dp[i]) {
         total++;
      }
   }
   sort(all(v));
   vector<int> one(n + 1, 0), two(n + 1, 0);
   for (int i = 1; i <= n; i++)
      if (dp[i] == 1) one[i] = 1;
   for (int i = 1; i <= n; i++)
      if (dp[i] == 2) two[i] = 1;
   for (int i = 1; i <= n; i++) {
      one[i] += one[i - 1];
      two[i] += two[i - 1];
   }
   int ans = 0;
   // cout << total << "\n";
   for (int i = 0; i < q - 1; i++) {
      for (int j = i + 1; j < q; j++) {
         int fl = v[i].ff, fr = v[i].ss;
         int sl = v[j].ff, sr = v[j].ss;
         int one_seg_first_st = fl, one_seg_first_en = min(fr, sl - 1);
         int cnt = one[min(fr, sl - 1)] - one[fl - 1];
         if (sl <= fr) {
            cnt += (two[min(fr, sr)] - two[sl - 1]);
            // cout << "Two : " << two[min(fr, sr)] - two[sl - 1] << "\n";
         }
         if (sr != fr) {
            if (sr < fr) {
               cnt += (one[fr] - one[sr]);
            } else
               cnt += (one[max(fr, sr)] - one[max(fr, sl - 1)]);
         }
         // cout << cnt << " count on index " << i + 1 << " " << j + 1 << "\n";
         ans = max(ans, total - cnt);
      }
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
