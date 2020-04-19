
/*
    ullutv se main , Rajeev Talwar , azamgadh
*/
#pragma GCC optimize("unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("Ofast")
#define dbg(...)
#define db(...)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ld = long double;

#define _(_1, _2, _3, _4, NAME, ...) NAME
#define f3(i, a, n, inc) \
   for (int i = (a); (inc) > 0 ? i < (n) : i >= (n); i += (inc))
#define f2(i, a, n) f3(i, a, n, 1 - 2 * (a > n))
#define f1(i, n) f2(i, 0, n)
#define f0(i) f2(i, 0, n)
#define fr(...) _(__VA_ARGS__, f3, f2, f1, f0)(__VA_ARGS__)
#define trav(i, x) for (auto& i : x)
#define sz(x) ((int)x.size())
#define len(x) ((int)x.length())
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
const ll MOD = 1e9 + 7;  // 998244353

const ll INF = 1e18 + 10;

namespace amit {  // printf , scanf IO.
template <class T>
void re(complex<T>& x);
template <class T1, class T2>
void re(pair<T1, T2>& p);
inline bool blank(char c) {
   return (c == ' ' || c == '\t' || c == '\r' || c == '\n');
};
template <class T>
void re(vector<T>& a);
template <class T, size_t SZ>
void re(array<T, SZ>& a);
void re(int& x) { scanf("%d", &x); }
void re(long& x) { scanf("%ld", &x); }
void re(ll& x) { scanf("%lld", &x); }
void re(unsigned& x) { scanf("%u", &x); }
void re(unsigned long& x) { scanf("%lu", &x); }
void re(unsigned long long& x) { scanf("%llu", &x); }
void re(float& x) { scanf("%f", &x); }
void re(double& x) { scanf("%lf", &x); }
void re(ld& x) { scanf("%llf", &x); }
bool re(char& x) {
   if (scanf("%c", &x) == EOF) return false;
   if (blank(x)) re(x);
   return true;
}
bool red(char& x) {
   if (scanf("%c", &x) == EOF) return false;
   return true;
}
void re(string& x) {
   char c;
   if (!re(c)) return;
   while (!blank(c)) {
      x += c;
      if (!red(c)) break;
   }
}
template <class T, class... Ts>
void re(T& t, Ts&... ts) {
   re(t);
   re(ts...);
}
template <class T>
void re(complex<T>& x) {
   T a, b;
   re(a, b);
   x = {a, b};
}
template <class T1, class T2>
void re(pair<T1, T2>& p) {
   re(p.ff, p.ss);
}
template <class T>
void re(vector<T>& a) {
   fr(i, sz(a)) re(a[i]);
}
template <class T, size_t SZ>
void re(array<T, SZ>& a) {
   fr(i, SZ) re(a[i]);
}
void pr(int x) { printf("%d", x); }
void pr(long x) { printf("%ld", x); }
void pr(ll x) { printf("%lld", x); }
void pr(unsigned x) { printf("%u", x); }
void pr(unsigned long x) { printf("%lu", x); }
void pr(unsigned long long x) { printf("%llu", x); }
void pr(float x) { printf("%.3f", x); }
void pr(double x) { printf("%.5lf", x); }
void pr(ld x) { printf("%.10llf", x); }
void pr(char x) { printf("%c", x); }
void pr(const char* x) { printf("%s", x); }
void pr(const string& x) { printf("%s", x.c_str()); }
void pr(bool x) { pr(x ? "true" : "false"); }
template <class T>
void pr(const complex<T>& x) {
   cout << x;
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x);
template <class T>
void pr(const T& x);
template <class T, class... Ts>
void pr(const T& t, const Ts&... ts) {
   pr(t);
   pr(ts...);
}
template <class T1, class T2>
void pr(const pair<T1, T2>& x) {
   pr("(", x.ff, ", ", x.ss, ")");
}
template <class T>
void pr(const T& x) {
   pr("{");
   bool fst = 1;
   for (const auto& a : x) pr(!fst ? ", " : "", a), fst = 0;
   pr("}");
}
void ps() { pr("\n"); }
template <class T, class... Ts>
void ps(const T& t, const Ts&... ts) {
   pr(t);
   if (sizeof...(ts)) pr(" ");
   ps(ts...);
}
void pc() { pr("]\n"); }
template <class T, class... Ts>
void pc(const T& t, const Ts&... ts) {
   pr(t);
   if (sizeof...(ts)) pr(", ");
   pc(ts...);
}
template <class T>
bool ckmin(T& a, const T& b) {
   return b < a ? a = b, 1 : 0;
}
template <class T>
bool ckmax(T& a, const T& b) {
   return a < b ? a = b, 1 : 0;
}
vector<ll> fact;
vector<ll> inv;
ll mod = MOD;
ll power(ll x, ll n) {
   ll res = 1;
   while (n > 0) {
      if (n & 1) res = res * x % mod;
      x = x * x % mod;
      n >>= 1;
   }
   return res;
}
ll mod_inv(ll x) { return power(x, mod - 2); }
ll nCr(ll n, ll r) { return ((fact[n] * inv[r] % mod) * inv[n - r]) % mod; }
ll nPr(ll n, ll r) { return (fact[n] * inv[n - r]) % mod; }
ll nHr(ll n, ll r) { return nCr(r + n - 1, r); }
void comb_init(ll n, ll _mod = MOD) {
   mod = _mod;
   fact.resize(n + 1);
   fact[0] = 1;
   fr(i, n) { fact[i + 1] = (fact[i] * (i + 1LL)) % mod; }
   inv.resize(n + 1);
   inv[n] = mod_inv(fact[n]);
   for (int i = n; i > 0; i--) {
      inv[i - 1] = inv[i] * i % mod;
   }
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x = 0, ll y = INF) { return (rng() % (y - x + 1)) + x; };
};  // namespace amit
using namespace amit;
const int MX = 2e5 + 10;

int n;
int a[MX];
map<int, int> mp;
void solve() {
   int n;
   re(n);
   mp.clear();
   fr(i) re(a[i]), mp[a[i]]++;
   int ans = 0;
   trav(i, mp) {
      ckmax(ans, max(min(i.second, sz(mp) - 1), min(i.second - 1, sz(mp))));
   }
   ps(ans);
}

int main() {
   int _ = 1;
   re(_);
   while (_--) solve();
}
