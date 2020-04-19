#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define rf for (int i = n; i >= 0; i--)
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
#define ps(x) cout << x << " "
#define pl(x) cout << x << endl
#define nl cout << endl
using namespace std;
const ll mod = 1e9 + 7;
// vector<bool> prime(MAX, 1);
// vector<int> spf(MAX, 1);
// vector<int> primes;
// void sieve() {
//    prime[0] = prime[1] = 0;
//    spf[2] = 2;
//    for (ll i = 4; i < MAX; i += 2) {
//       spf[i] = 2;
//       prime[i] = 0;
//    }
//    primes.pb(2);
//    for (ll i = 3; i < MAX; i += 2) {
//       if (prime[i]) {
//          primes.pb(i);
//          spf[i] = i;
//          for (ll j = i * i; j < MAX; j += i) {
//             prime[j] = 0;
//             if (spf[j] == 1) {
//                spf[j] = i;
//             }
//          }
//       }
//    }
// }
ll power(ll a, ll b) {
   ll res = 1;
   while (b) {
      if (b & 1) {
         res = res * a;
      }
      a = a * a;
      b = b >> 1;
   }
   return res;
}
ll power(ll a, ll b, ll m) {
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
const int MAX = 3e18 + 9;
int calc(int x, int y, int z) {
   // cout << x << " " << y << " " << z << " \n";
   return ((x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x));
}
void real_main() {
   // Chutiya jaisa soch raha tha
   int n1, n2, n3;
   cin >> n1 >> n2 >> n3;
   vector<int> a(n1), b(n2), c(n3);
   for (int &x : a) cin >> x;
   for (int &x : b) cin >> x;
   for (int &x : c) cin >> x;
   sort(all(a));
   sort(all(b));
   sort(all(c));
   int res = 3e18 + 9;
   res = min(res, calc(a[0], b[0], c[0]));
   int i = 0, j = 0, k = 0;
   while (i < n1 - 1 || j < n2 - 1 || k < n3 - 1) {
      ll Ase = MAX, Bse = MAX, Cse = MAX;
      if (i < n1 - 1) Ase = calc(a[i + 1], b[j], c[k]);
      if (j < n2 - 1) Bse = calc(a[i], b[j + 1], c[k]);
      if (k < n3 - 1) Cse = calc(a[i], b[j], c[k + 1]);
      if (Ase <= Bse && Ase <= Cse) {
         res = min(res, Ase);
         i++;
      } else if (Bse <= Ase && Bse <= Cse) {
         res = min(Bse, res);
         j++;
      } else if (Cse <= Ase && Cse <= Bse) {
         res = min(res, Cse);
         k++;
      }
   }
   res = min(res, calc(a[n1 - 1], b[n2 - 1], c[n3 - 1]));
   cout << res << "\n";
}
signed main() {
   // Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main();
   }
   return 0;
}
