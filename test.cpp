#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX = 1e7 + 9;
vector<bool> prime(MAX, 1);
vector<int> spf(MAX, 1);
vector<int> p;
void sieve()
{
  prime[0] = prime[1] = 0;
  spf[2] = 2;
  p.push_back(2);
  for (int i = 4; i < MAX; i += 2)
  {
    spf[i] = 2;
    prime[i] = 0;
  }
  for (ll i = 3; i < MAX; i += 2)
  {
    if (prime[i])
    {
      spf[i] = i;
      p.push_back(i);
      for (ll j = i * i; j < MAX; j += i)
      {
        prime[j] = 0;
        if (spf[j] == 1)
        {
          spf[j] = i;
        }
      }
    }
  }
}
int main()
{
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  sieve();
  int t;
  cin >> t;
  while (t--)
  {
    int x, k;
    cin >> x >> k;
    int cnt = 0;
    for (int i = 0; i < (int)p.size(); i++)
    {
      if (x % p[i] == 0)
      {
        while (x != 1 && x % p[i] == 0)
        {
          cnt++;
          // cout << p[i] << " ";
          x /= p[i];
        }
      }
      if (x == 1)
      {
        break;
      }
    }
    // cout << endl;
    if (x > 1)
    {
      p.push_back(x);
      cnt++;
    }
    if (cnt >= k)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }
}