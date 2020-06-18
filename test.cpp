#define dbg(...) ;
#define db(...) ;
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#include "bits/stdc++.h"

using namespace std;

const int Nmax = 1000005;
const int INF = 1000000000;
const int MOD = 1000000007;

int a[Nmax], fr[Nmax];

int do_calc(int x, int p, int y) {
   if (p == 1) {
      return x;
   }
   int ans = 1;
   for (int i = 1; i <= y; i++) {
      if (1LL * ans * p > Nmax) {
         return -1;
      }
      ans *= p;
   }
   if (1LL * x * ans > Nmax) {
      return -1;
   }
   return x * ans;
}

int Pow_log(int x, int p) {
   int ans = 1;
   while (p) {
      if (p % 2) {
         ans = (1LL * ans * x) % MOD;
         p--;
      } else {
         x = (1LL * x * x) % MOD;
         p >>= 1;
      }
   }
   return ans;
}

int main() {
   int t, n, p;
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   cin.sync_with_stdio(false);
   cin >> t;
   while (t--) {
      cin >> n >> p;
      for (int i = 1; i <= n; i++) {
         cin >> a[i];
         fr[a[i]]++;
      }
      sort(a + 1, a + n + 1);
      reverse(a + 1, a + n + 1);
      int new_n = 1;
      for (int i = 2; i <= n; i++) {
         if (a[i] != a[i - 1]) {
            a[++new_n] = a[i];
         }
      }
      n = new_n;
      int pos = 1, dif = 0;
      while (pos <= n) {
         if (fr[a[pos]] % 2 == 0) {
            pos++;
            continue;
         }
         //cout << a[pos] << " " << fr[a[pos]] << "\n";
         int x = a[pos];
         int cnt_need = 1, is_good = 0;
         for (int i = pos + 1; i <= n; i++) {
            int new_cnt_need = do_calc(cnt_need, p, (x - a[i]));
            dbg(i, new_cnt_need);
            //cout << new_cnt_need << "\n";
            if (new_cnt_need == -1) {
               break;
            }
            if (new_cnt_need <= fr[a[i]]) {
               fr[a[i]] -= new_cnt_need;
               pos = i;
               is_good = 1;
               break;
            } else {
               cnt_need = new_cnt_need - fr[a[i]];
               x = a[i];
            }
         }
         if (!is_good) {
            dbg(pos);
            dif = Pow_log(p, a[pos]);
            dbg(dif);
            for (int i = pos + 1; i <= n; i++) {
               dif -= (1LL * fr[a[i]] * Pow_log(p, a[i])) % MOD;
               if (dif < 0) {
                  dif += MOD;
               }
            }
            break;
         }
      }

      for (int i = 1; i <= n; i++) {
         fr[a[i]] = 0;
      }

      cout << dif << "\n";
   }
   return 0;
}