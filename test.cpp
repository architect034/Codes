#include <bits/stdc++.h>
using namespace std;
int main() {
#ifndef OJ
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   priority_queue<pair<int, int> > pq;
   pq.push({2, 3});
   pq.push({3, 3});
   auto x = pq.top();
   cout << x.first;
   // cout << pq.top()->ss;
}
