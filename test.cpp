#include <bits/stdc++.h>
using namespace std;
bool comp(string &s1, string &s2) {
   return s1.size() < s2.size();
}
void solve(int tc) {
   // if (!tc) return;
   // string s;
   // getline(cin, s);
   // cout << s;
   // cout << "\n";

   string S, T;

   getline(cin, S);
   stringstream X(S);
   vector<pair<int, int> > v;
   vector<string> gs;
   int i = 0;
   while (getline(X, T, ' ')) {
      // cout << T << endl;
      v.push_back({T.size(), i});
      gs.push_back(T);
      i++;
   }
   sort(gs.begin(), gs.end(), comp);
   sort(v.begin(), v.end());
   for (int i = 0; i < gs.size(); i++) {
      cout << gs[i];
      if (i != gs.size() - 1) {
         cout << " ";
      } else {
         cout << "\n";
      }
   }
}
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   int t;
   scanf("%d\n", &t);
   int i = 0;
   while (t--) {
      solve(i);
      i++;
   }
}