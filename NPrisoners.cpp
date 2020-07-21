#define dbg(...) ;
#define db(...) ;
#include "bits/stdc++.h"
using namespace std;
class Solution {
  public:
   vector<int> prisonAfterNDays(vector<int>& cells, int N) {
      map<vector<int>, int> m;
      m[cells] = 1;
      int day = -1;
      int cur = 1;
      vector<vector<int>> res;
      res.push_back(cells);
      while (true) {
         vector<int> temp = cells;
         for (int i = 1; i < 7; i++) {
            if (cells[i - 1] == cells[i + 1]) {
               temp[i] = 1;
            } else {
               temp[i] = 0;
            }
         }
         temp[0] = temp[7] = 0;
         res.push_back(temp);
         if (m.find(temp) != m.end()) {
            day = m[temp] - 1;
            break;
         }
         if (cur == N) {
            return temp;
         }
         m.insert({temp, ++cur});
         cells = temp;
      }
      int d = cur - day;
      int idx = N % d;
      (idx == 0) ? idx = d : idx = idx;
      return res[idx];
   }
};
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   vector<int> v(8);
   for (int i = 0; i < 8; i++) {
      cin >> v[i];
   }
   int N;
   cin >> N;
   Solution obj;
   dbg(obj.prisonAfterNDays(v, N));
}