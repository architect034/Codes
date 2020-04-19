/* Author: Vimal Patel
/* Problem ID:  TALCA
*/
#include <bits/stdc++.h>

#define INF 200000000000005
#define ll long long int
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define pll pair<ll, ll>
#define vl vector<ll>
#define vll vector<pll>
#define ff first
#define ss second
#define pb push_back

using namespace std;

class LCA
{
   vector<int> height, euler, first, segtree;
   vector<bool> visited;
   int n;

public:
   LCA(vector<vector<int>> &adj, int root = 0)
   {
      n = adj.size();
      height.resize(n);
      first.resize(n);
      euler.reserve(n * 2);
      visited.assign(n, false);
      dfs(adj, root);
      int m = euler.size();
      segtree.resize(m * 4);
      build(1, 0, m - 1);
   }

   void dfs(vector<vector<int>> &adj, int node, int h = 0)
   {
      visited[node] = true;
      height[node] = h;
      first[node] = euler.size();
      euler.push_back(node);
      for (auto to : adj[node])
      {
         if (!visited[to])
         {
            dfs(adj, to, h + 1);
            euler.push_back(node);
         }
      }
   }

   void build(int node, int b, int e)
   {
      if (b == e)
      {
         segtree[node] = euler[b];
      }
      else
      {
         int mid = (b + e) / 2;
         build(node << 1, b, mid);
         build(node << 1 | 1, mid + 1, e);
         int l = segtree[node << 1], r = segtree[node << 1 | 1];
         segtree[node] = (height[l] < height[r]) ? l : r;
      }
   }

   int query(int node, int b, int e, int L, int R)
   {
      if (b > R || e < L)
         return -1;
      if (b >= L && e <= R)
         return segtree[node];
      int mid = (b + e) >> 1;

      int left = query(node << 1, b, mid, L, R);
      int right = query(node << 1 | 1, mid + 1, e, L, R);
      if (left == -1)
         return right;
      if (right == -1)
         return left;
      return height[left] < height[right] ? left : right;
   }

   int lca(int u, int v)
   {
      int left = first[u], right = first[v];
      if (left > right)
         swap(left, right);
      return query(1, 0, euler.size() - 1, left, right);
   }

   int lca(int u, int v, int r)
   {
      int d1 = dist(u, r) + dist(v, r); //r is ans
      int d2 = dist(u, v) + dist(r, u);
      int d3 = dist(u, v) + dist(r, v);
      int x = lca(u, v);
      int d4 = dist(u, x) + dist(v, x) + dist(r, x);
      int y = lca(r, v);
      int d5 = dist(u, y) + dist(v, y) + dist(r, y);
      int z = lca(r, u);
      int d6 = dist(u, z) + dist(v, z) + dist(r, z);
      if (d1 <= min(d2, d3) and d1 <= min(d4, d5) and d1 <= d6)
         return r;
      if (d2 <= min(d3, d4) and d2 <= min(d5, d6))
         return u;
      if (d3 <= min(d4, d5) and d3 <= d6)
         return v;
      if (d4 <= min(d5, d6))
         return x;
      if (d5 <= d6)
         return y;
      return z;
   }

   int dist(int u, int v)
   {
      return height[u] + height[v] - 2 * height[lca(u, v)];
   }
};

int main()
{
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   vvi adj(n);
   for (int i = 0; i < n - 1; i++)
   {
      int u, v;
      cin >> u >> v;
      u -= 1, v -= 1;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   LCA tree(adj);
   int q;
   cin >> q;
   for (int i = 0; i < q; i++)
   {
      int u, v, r;
      cin >> r >> u >> v;
      u -= 1, v -= 1, r -= 1;
      cout << tree.lca(u, v, r) + 1 << endl;
   }
   return 0;
}