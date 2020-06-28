#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define nax 1000005
#define inf 100000000000000000LL
#define pb push_back
#define mp make_pair
#define in insert
#define ff first
#define ss second
#define pll pair<long long int, long long int>
#define pii pair<int, int>
#define vll vector<long long int>
#define vii vector<int>
#define sii set<int>
#define vb vector<bool>
#define sll set<long long int>
#define mii map<int, int>
#define mll map<long long int, long long int>
#define mis map<int, string>
#define all(n) n.begin(), n.end()
#define tr(container, it) for (__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define lpi(i, a, b) for (int i = a; i <= b; i++)
#define lpir(i, a, b) for (int i = a; i >= b; i--)
#define lpl(i, a, b) for (ll i = a; i <= b; ++i)
#define lplr(i, a, b) for (ll i = a; i >= b; --i)
#define lpv(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)

using namespace std;
typedef long long int ll;

ll dp[505][505];
int main() {
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
#endif
   //ios_base::sync_with_stdio(false); cin.tie(0);
   //cout << "hello";
   ll n, m, b, mod, ai;
   cin >> n >> m >> b >> mod;
   dp[0][0] = 1 % mod;
   lpi(i, 1, n) {
      cin >> ai;
      lpi(j, 0, m - 1) {
         for (int k = 0; k <= b - ai; k++) {
            dp[j + 1][k + ai] += dp[j][k];
            if (dp[j + 1][k + ai] >= mod)
               dp[j + 1][k + ai] -= mod;
         }
      }
   }
   ll ans = 0;
   lpi(i, 0, b) {
      ans = (ans + dp[m][i]) % mod;
   }
   cout << ans;
   return 0;
}