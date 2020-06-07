#include <cstdio>
int a[200005];
int main() {
   int n, m, k, dq, ans = 0;
   scanf("%d%d%d", &n, &m, &k);
   for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
   dq = k;
   for (int i = n; i >= 1; --i) {
      if (dq < a[i]) --m, dq = k;
      if (!m) break;
      dq -= a[i];
      ++ans;
   }
   printf("%d", ans);
   return 0;
}