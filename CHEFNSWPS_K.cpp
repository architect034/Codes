#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int t;
   cin >> t;
   while (t--) {
      solve();
   }
}
#define INF 1000000001
void solve() {
   long long n;
   cin >> n;
   vector<long long> a(n), b(n);
   for (long long i = 0; i < n; i++) {
      cin >> a[i];
   }
   for (long long i = 0; i < n; i++) {
      cin >> b[i];
   }
   map<long long, long long> AB, A, B;
   long long sm = INF;
   for (long long i = 0; i < n; i++) {
      AB[a[i]]++;
      AB[b[i]]++;
      A[a[i]]++;
      B[b[i]]++;
      sm = min({sm, a[i], b[i]});
   }
   bool flag = 1;
   for (pair<long long, long long> p : AB) {
      if (p.second & 1) {
         flag = 0;
      } else {
         AB[p.first] >>= 1;
      }
   }
   if (!flag) {
      cout << -1 << "\n";
   } else {
      long long res = 0, rem = 0;
      for (pair<long long, long long> p : AB) {
         rem += (max(0LL, p.second - A[p.first]));
      }
      for (pair<long long, long long> p : AB) {
         long long value = p.first;
         long long more = A[value] - p.second;
         if (more < 0) {
            more *= -1;
         }
         res = res + min(sm << 1, value) * min(more, rem);
         rem = rem - min(rem, more);
      }
      cout << res << "\n";
   }
}