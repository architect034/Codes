#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAX = 2e5 + 5;
void solve();
signed main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   solve();
}
int n, q;
vector<int> height(MAX), taste(MAX);
deque<int> g1(MAX, -1), gr1[MAX];
void graph1() {
   stack<int> st;
   for (int i = 1; i <= n; i++) {
      while (st.size() && height[st.top()] <= height[i]) {
         st.pop();
      }
      if (st.size()) {
         g1[i] = st.top();
      }
      st.push(i);
   }
   for (int i = n; i >= 1; i--) {
      if (g1[i] != -1) {
         gr1[g1[i]].push_front(i);
      } else {
         gr1[0].push_back(i);
      }
   }
}
deque<int> g2(MAX, -1), gr2[MAX];
void graph2() {
   stack<int> st;
   for (int i = n; i >= 1; i--) {
      while (st.size() && height[st.top()] <= height[i]) {
         st.pop();
      }
      if (st.size()) {
         g2[i] = st.top();
      }
      st.push(i);
   }
   for (int i = 1; i <= n; i++) {
      if (g2[i] != -1) {
         gr2[g2[i]].push_front(i);
      } else {
         gr2[0].push_back(i);
      }
   }
}
vector<int> _inG1(MAX), _outG1(MAX);
int tym = 0;
vector<int> _tree1;
void dfsGR1(int u, int par) {
   _tree1.push_back(u);
   _inG1[u] = tym++;
   for (int v : gr1[u]) {
      if (v != par) {
         dfsGR1(v, u);
      }
   }
   _tree1.push_back(u);
   _outG1[u] = tym++;
}
vector<int> _inG2(MAX), _outG2(MAX);
vector<int> _tree2;
void dfsGR2(int u, int par) {
   _tree2.push_back(u);
   _inG2[u] = tym++;
   for (int v : gr2[u]) {
      if (v != par) {
         dfsGR2(v, u);
      }
   }
   _tree2.push_back(u);
   _outG2[u] = tym++;
}
vector<int> _tree;
void build_tree() {
   for (int i = 1; i <= n; i++) {
      _tree.push_back(height[i]);
   }
   for (int i = 0; i < n; i++) {
      _tree.push_back(_tree[i]);
   }
   for (int i = n - 1; i > 0; --i) {
      int c1 = i << 1;
      int c2 = c1 | 1;
      _tree[i] = max(_tree[c1], _tree[c2]);
   }
}
int MX(int l, int r) {
   int res = 0;
   for (l = l + n, r = r + n; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
         res = max(res, _tree[l]);
         l++;
      }
      if (r % 2 == 1) {
         r -= 1;
         res = max(res, _tree[r]);
      }
   }
   return res;
}
void build_tree1() {
   map<int, int> m;
   int N = _tree1.size();
   for (int i = 0; i < N; i++) {
      if (m[_tree1[i]] == 0) {
         m[_tree1[i]] = 1;
         _tree1[i] = taste[_tree1[i]];
      } else {
         m[_tree1[i]] = 0;
         _tree1[i] = -taste[_tree1[i]];
      }
   }
   for (int i = 0; i < N; i++) {
      _tree1.push_back(_tree1[i]);
   }
   for (int i = N - 1; i > 0; --i) {
      int c1 = i << 1;
      int c2 = c1 | 1;
      _tree1[i] = _tree1[c1] + _tree1[c2];
   }
}
void changeT1(int p, int value) {
   int N = _tree1.size() / 2;
   for (_tree1[p += N] = value; p > 1; p /= 2) {
      _tree1[p / 2] = _tree1[p] + _tree1[p ^ 1];
   }
}
int sumT1(int l, int r) {
   int res = 0;
   int N = _tree1.size() / 2;
   for (l += N, r += N; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
         res += _tree1[l];
         l += 1;
      }
      if (r % 2 == 1) {
         r -= 1;
         res += _tree1[r];
      }
   }
   return res;
}
void build_tree2() {
   map<int, int> m;
   int N = _tree2.size();
   for (int i = 0; i < N; i++) {
      if (m[_tree2[i]] == 0) {
         m[_tree2[i]] = 1;
         _tree2[i] = taste[_tree2[i]];
      } else {
         m[_tree2[i]] = 0;
         _tree2[i] = -taste[_tree2[i]];
      }
   }
   for (int i = 0; i < N; i++) {
      _tree2.push_back(_tree2[i]);
   }
   for (int i = N - 1; i > 0; --i) {
      int c1 = i << 1;
      int c2 = c1 | 1;
      _tree2[i] = _tree2[c1] + _tree2[c2];
   }
}
void changeT2(int p, int value) {
   int N = _tree2.size() / 2;
   for (_tree2[p += N] = value; p > 1; p /= 2) {
      _tree2[p / 2] = _tree2[p] + _tree2[p ^ 1];
   }
}
int sumT2(int l, int r) {
   int res = 0;
   int N = _tree2.size() / 2;
   for (l += N, r += N; l < r; l /= 2, r /= 2) {
      if (l % 2 == 1) {
         res += _tree2[l];
         l += 1;
      }
      if (r % 2 == 1) {
         r -= 1;
         res += _tree2[r];
      }
   }
   return res;
}
void solve() {
   cin >> n >> q;
   for (int i = 1; i <= n; i++) {
      cin >> height[i];
   }
   for (int i = 1; i <= n; i++) {
      cin >> taste[i];
   }
   graph1();
   graph2();
   dfsGR1(0, 0);
   tym = 0;
   dfsGR2(0, 0);
   build_tree();
   build_tree1();
   build_tree2();
   while (q--) {
      int _t;
      cin >> _t;
      if (_t == 1) {
         int b, k;
         cin >> b >> k;
         taste[b] = k;
         int dx = k - sumT1(_inG1[b], _inG1[b] + 1);
         changeT1(_inG1[b], k);
         int val = sumT1(_outG1[b], _outG1[b] + 1);
         changeT1(_outG1[b], val - dx);
         dx = k - sumT2(_inG2[b], _inG2[b] + 1);
         changeT2(_inG2[b], k);
         val = sumT2(_outG2[b], _outG2[b] + 1);
         changeT2(_outG2[b], val - dx);
      } else {
         int from, to;
         cin >> from >> to;
         if (from == to) {
            cout << taste[from] << "\n";
         } else if (height[from] <= height[to]) {
            cout << -1 << endl;
         } else if (from < to) {
            int mx = MX(from, to - 1);
            if (mx >= height[from]) {
               cout << -1 << "\n";
               continue;
            }
            int res = sumT1(0, _inG1[to] + 1) - sumT1(0, _inG1[from] + 1);
            res += sumT1(_inG1[from], _inG1[from] + 1);
            cout << res << "\n";
         } else {
            int mx = MX(to - 1, from - 1);
            if (mx >= height[from]) {
               cout << -1 << "\n";
               continue;
            }
            int res = sumT2(0, _inG2[to] + 1) - sumT2(0, _inG2[from] + 1);
            res += sumT2(_inG2[from], _inG2[from] + 1);
            cout << res << "\n";
         }
      }
   }
}