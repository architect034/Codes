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
const int MAX = 2e5 + 9;
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
struct node {
   int pos;
   int l;
   int r;
   int val;
};
bool comp(node a, node b) {
   if (a.val == b.val)
      return a.l > b.l;
   return a.val > b.val;
}

void update(int *BIT, int n, int idx) {
   while (idx <= n) {
      BIT[idx]++;
      idx += idx & (-idx);
   }
}

int query(int *BIT, int idx) {
   int ans = 0;
   while (idx) {
      ans += BIT[idx];

      idx -= idx & (-idx);
   }
   return ans;
}

void solveQuery(int arr[], int n, int QueryL[], int QueryR[], int QueryK[], int q) {
   node a[n + q + 1];
   for (int i = 1; i <= n; ++i) {
      a[i].val = arr[i - 1];
      a[i].pos = 0;
      a[i].l = 0;
      a[i].r = i;
   }
   for (int i = n + 1; i <= n + q; ++i) {
      a[i].pos = i - n;
      a[i].val = QueryK[i - n - 1];
      a[i].l = QueryL[i - n - 1];
      a[i].r = QueryR[i - n - 1];
   }
   sort(a + 1, a + n + q + 1, comp);
   int BIT[n + 1];
   memset(BIT, 0, sizeof(BIT));
   int ans[q + 1];
   for (int i = 1; i <= n + q; ++i) {
      if (a[i].pos != 0) {
         int cnt = query(BIT, a[i].r) - query(BIT, a[i].l - 1);
         ans[a[i].pos] = cnt;
      } else {
         update(BIT, n, a[i].r);
      }
   }
   int sum = 0;
   for (int i = 1; i <= q; ++i) {
      sum += ans[i];
   }
   pl(sum);
}
void _main() {
   int n;
   cin >> n;
   vector<int> v(n);
   for (int &x : v) {
      cin >> x;
   }
   map<int, int> m;
   vector<int> pre(n), suf(n);
   for (int i = 0; i < n; i++) {
      m[v[i]]++;
      pre[i] = m[v[i]];
   }
   m.clear();
   for (int i = n - 1; i >= 0; i--) {
      m[v[i]]++;
      suf[i] = m[v[i]];
   }
   int qL[n - 1], qR[n - 1], qK[n - 1];
   for (int i = n - 2; i >= 0; i--) {
      qL[i] = i + 2;
      qR[i] = n;
      qK[i] = -pre[i];
   }
   int arr[n];
   for (int i = 0; i < n; i++) {
      arr[i] = -suf[i];
   }
   solveQuery(arr, n, qL, qR, qK, n - 1);
}
signed main() {
   IOE;
   _IOE();
   int test_cases = 1;
   // cin >> test_cases;
   for (int i = 1; i <= test_cases; i++) {
      _main();
   }
   return 0;
}
