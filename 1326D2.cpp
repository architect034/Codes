#include <bits/stdc++.h>
#define ll long long
#define f(i, st, en, in) for (ll i = st; i <= en; i += in)
#define rf(i, st, en, de) for (ll i = st; i >= en; i -= de)
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
   f(i, 4, MAX - 1, 2) {
      spf[i] = 2;
      prime[i] = 0;
   }
   primes.pb(2);
   f(i, 3, MAX - 1, 2) {
      if (prime[i]) {
         primes.pb(i);
         spf[i] = i;
         f(j, i * i, MAX - 1, i) {
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
void pre() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}
string calc(string p) {
   int n = p.size();
   int pt[n];
   pt[0] = 0;
   int i = 1, j = 0;
   while (i < n) {
      if (p[i] == p[j]) {
         pt[i] = j + 1;
         i++;
         j++;
      } else if (j > 0) {
         j = pt[j - 1];
      } else {
         pt[i] = 0;
         i++;
      }
   }
   int l = pt[n - 1];
   string res = p.substr(0, l);
   return res;
}
void solve() {
   string s;
   cin >> s;
   int n = s.length();
   string f1 = "", f2 = "", f3 = "";
   int l = 0, r = n - 1;
   for (int i = 0; i < s.length() / 2; i++) {
      if (s[i] == s[n - 1 - i]) {
         f1 += s[i];
         f3 += s[i];
         l++;
         r--;
      } else {
         break;
      }
   }
   string t = "";
   // cout << l + 1 << " " << r + 1 << "\n";
   for (int i = l; i <= r; i++) {
      t += s[i];
   }
   string st = t;
   reverse(all(t));
   st += '#' + t;
   // cout << st << "\n";
   string f20 = calc(st);
   st = t + '#';
   reverse(all(t));
   st += t;
   // cout << st << "\n";
   string f21 = calc(st);
   if (f20.size() > f21.size()) {
      f2 = f20;
   } else {
      f2 = f21;
   }
   reverse(all(f3));
   cout << f1 + f2 + f3 << endl;
}
int main() {
   ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   pre();
   int test_cases = 1;
   cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      // cout << "Case #" << tc << ": ";
      solve();
   }
   return 0;
}
