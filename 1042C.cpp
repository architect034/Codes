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
// #define int long long
void real_main() {
   //cakewalk it was but implementation and corner cases -_-
   int n, x, z = 0;
   in(n);
   vector<pair<int, int>> ps, ne, ze;
   for (int i = 0; i < n; i++) {
      in(x);
      if (x == 0) {
         z++;
         ze.pb({0, i + 1});
      } else if (x < 0) {
         ne.pb({-x, i + 1});
      } else {
         ps.pb({x, i + 1});
      }
   }
   int k = 0;
   sort(all(ps)), sort(all(ne));
   if ((int)ps.size() == n) {
      for (int i = 0; i < n - 1; i++) {
         cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
      }
      return;
   }
   if ((int)ne.size() % 2 == 0) {
      int last = -1;
      if ((int)ze.size() > 0) {
         last = ze[0].ss;
         for (int i = 0; i < (int)ze.size() - 1; i++) {
            cout << 1 << " " << ze[i].ss << " " << ze[i + 1].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ze[i + 1].ss;
         }
         cout << 2 << " " << last << "\n";
         k++;
         if (k == n - 1) return;
      }
      if (ne.size() > 0) {
         last = ne[0].ss;
      }
      if (ps.size() == 1) {
         last = ps[0].ss;
      }
      for (int i = 0; i < (int)ps.size() - 1; i++) {
         cout << 1 << " " << ps[i].ss << " " << ps[i + 1].ss << "\n";
         k++;
         if (k == n - 1) return;
         last = ps[i + 1].ss;
      }
      for (int i = (ps.size() > 0) ? 0 : 1; i < (int)ne.size(); i++) {
         cout << 1 << " " << last << " " << ne[i].ss << "\n";
         k++;
         if (k == n - 1) return;
         last = ne[i].ss;
      }
      return;
   }
   if ((int)ne.size() % 2 == 1) {
      if ((int)ze.size() > 0) {
         int last = ze[0].ss;
         for (int i = 0; i < (int)ze.size() - 1; i++) {
            cout << 1 << " " << ze[i].ss << " " << ze[i + 1].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ze[i + 1].ss;
         }
         cout << 1 << " " << last << " " << ne[0].ss << "\n";
         k++;
         if (k == n - 1) return;
         cout << 2 << " " << ne[0].ss << "\n";
         k++;
         if (ne.size() > 1) {
            last = ne[1].ss;
         }
         if (k == n - 1) return;
         for (int i = 0; i < (int)ps.size() - 1; i++) {
            cout << 1 << " " << ps[i].ss << " " << ps[i + 1].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ps[i + 1].ss;
         }
         if (ps.size() == 1) {
            last = ps[0].ss;
         }
         for (int i = (ps.size()) ? 1 : 2; i < (int)ne.size(); i++) {
            cout << 1 << " " << last << " " << ne[i].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ne[i].ss;
         }
      } else {
         int last = -1;
         if (ne.size() > 1) {
            last = ne[1].ss;
         }
         cout << 2 << " " << ne[0].ss << "\n";
         k++;
         if (k == n - 1) return;
         for (int i = 0; i < (int)ps.size() - 1; i++) {
            cout << 1 << " " << ps[i].ss << " " << ps[i + 1].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ps[i + 1].ss;
         }
         if (ps.size() == 1) {
            last = ps[0].ss;
         }
         for (int i = (ps.size()) ? 1 : 2; i < (int)ne.size(); i++) {
            cout << 1 << " " << last << " " << ne[i].ss << "\n";
            k++;
            if (k == n - 1) return;
            last = ne[i].ss;
         }
      }
   }
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
