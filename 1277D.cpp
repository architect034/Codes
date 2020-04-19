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
const int MAX = 1e5 + 9;
const ll mod = 1e9 + 7;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
vector<int> primes;
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
void real_main(int test_no, int tc) {
   int n, z = 0, o = 0;
   cin >> n;
   vector<string> v(n);
   vector<int> zero_one, one_zero;
   for (int i = 0; i < n; i++) {
      cin >> v[i];
      int sz = v[i].size();
      if (v[i][0] == '0' && v[i][sz - 1] == '1') {
         zero_one.pb(i + 1);
      } else if (v[i][0] == '1' && v[i][sz - 1] == '0') {
         one_zero.pb(i + 1);
      } else if (v[i][0] == '1' && v[i][sz - 1] == '1') {
         o++;
      } else if (v[i][0] == '0' && v[i][sz - 1] == '0') {
         z++;
      }
   }
   if (zero_one.size() == 0 && one_zero.size() == 0) {
      if ((z == 0 && o) || (o == 0 && z)) {
         cout << 0 << "\n";
         return;
      }
      cout << -1 << "\n";
      return;
   }
   if (abs((int)zero_one.size() - (int)one_zero.size()) <= 1) {
      cout << "0\n\n";
      return;
   }
   if (zero_one.size() > one_zero.size()) {
      int d = abs((int)zero_one.size() - (int)one_zero.size());
      map<string, int> m;
      for (int i = 0; i < one_zero.size(); i++) {
         m[v[one_zero[i] - 1]] = 1;
      }
      int cnt = 0;
      vector<int> res;
      for (int i = 0; i < zero_one.size(); i++) {
         string x = v[zero_one[i] - 1];
         reverse(all(x));
         if (!m[x]) {
            cnt++;
            res.pb(zero_one[i]);
         }
         if (cnt == d / 2) {
            cout << d / 2 << "\n";
            for (auto values : res) {
               cout << values << " ";
            }
            nl;
            return;
         }
      }
      cout << -1 << "\n";
      return;
   } else {
      int d = abs((int)zero_one.size() - (int)one_zero.size());
      map<string, int> m;
      for (int i = 0; i < zero_one.size(); i++) {
         m[v[zero_one[i] - 1]] = 1;
      }
      int cnt = 0;
      vector<int> res;
      for (int i = 0; i < one_zero.size(); i++) {
         string x = v[one_zero[i] - 1];
         reverse(all(x));
         if (!m[x]) {
            cnt++;
            res.pb(one_zero[i]);
         }
         if (cnt == d / 2) {
            cout << d / 2 << "\n";  // yaha 2 se divide krna bhul gaya tha bc
            for (auto values : res) {
               cout << values << " ";
            }
            nl;
            return;
         }
      }
      cout << -1 << "\n";
      return;
   }
}
signed main() {
   Fast;
   virtual_main();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      real_main(i, test_cases);
   }
   return 0;
}
