
#include "bits/stdc++.h"
using namespace std;

struct node {
   long long x, y;
} a[100005];

bool cmp(struct node a, struct node b) {
   return a.y > b.y;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int n, i;
   cin >> n;
   long long re = 0;
   for (i = 1; i <= n; i++) {
      cin >> a[i].x >> a[i].y;
      re = max(re, a[i].x * a[i].y);
      if (a[i].x > a[i].y) swap(a[i].x, a[i].y);
   }
   sort(a + 1, a + n + 1, cmp);
   // dbg(a);
   long long xx = 0;
   for (int i = 1; i <= n; i++) {
      cout << a[i].x << " " << a[i].y << "\n";
      re = max(re, min(xx, a[i].x) * a[i].y * 2);
      xx = max(xx, a[i].x);
   }
   if (re % 2)
      printf("%lld.5\n", re / 2);
   else
      printf("%lld.0\n", re / 2);
   return 0;
}