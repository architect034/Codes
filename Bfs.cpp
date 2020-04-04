/*
 *architect034
 *NIT Silchar<36>
*/
#include<bits/stdc++.h>
using namespace std;
#define bhago   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll   long long
#define ull unsigned long long
#define loop(i,start,end,increment)   for(ll i=start;i<=end;i+=increment)
#define ulta(i,start,end,decrement)   for(int i=start;i>=end;i-=decrement)
#define pb   push_back
#define popb   pop_back
#define pf   push_front
#define popf   pop_front
#define mp   make_pair
#define FF   first
#define SS   second
#define all(something)   something.begin(),something.end()
#define vecitr   vector<ll>::iterator
#define setitr   set<ll>::iterator0
#define mapitr   map<ll,ll>::iterator
#define mod   1000000007
void debug(string s)
{
	cout<<s<<"\n";
}
const int MAX = 2000007;
bool prime[MAX];
int sp[MAX];
void sieve()
{
	for (int i=2;i<MAX;i+=2)
	{
		sp[i]=2;
	}
	for(ll i=3;i<MAX;i+=2)
	{
		if(!prime[i])
		{
			sp[i]=i;
			for(ll j=i;(j*i)<MAX;j+=2)
			{
				if(!prime[j*i])
				{
					prime[j*i]=true;
					sp[j*i]=i;
				}
			}
		}
	}
}
ll GCD(ll a,ll b)
{
	ll c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
ll power(ll a,ll b)
{
	ll ans=1;
	while(b!=0)
	{
		if(b%2==1)
			ans*=a;
		a*=a;
		b=b>>1;
	}
	return ans;
}
int main()
{
	bhago;
	int n,m,x,y;
	cin>>n;
	cin>>m;
	vector<vector<int> >v(n);
	vector<int>bfs_visit;
	loop(i,0,m-1,1)
	{
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	int vis[n]={0};
	queue<int>q;
	q.push(0);
	while(q.empty()==0)
	{
		int a=q.front();
		if(vis[a]==0)
			bfs_visit.pb(a);
		vis[a]=1;
		q.pop();
		for(auto i=0;i<(int)v[a].size();i++)
		{
			if(vis[v[a][i]]==0)
			{
				q.push(v[a][i]);
			}
		}
	}
	for(int i=0;i<(int)bfs_visit.size();i++)
	{
		cout<<bfs_visit.at(i)<<" ";
	}
	return 0;
}