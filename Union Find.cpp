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
vector<vector<int> (10) > v(10);
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
int root(int x,int par[])
{
	while(x!=par[x])
	{
		x=par[x];
		par[x]=par[par[x]];
	}
	return x;
}
void u(int x,int y,int par[],int size[])
{
	int rx=root(x,par);
	int ry=root(y,par);
	if(rx==ry)
	{
		return;
	}
	else
	{
		if(size[rx]>=size[ry])
		{
			size[rx]+=size[ry];
			size[ry]=0;
			par[ry]=rx;
		}
		else
		{
			size[ry]+=size[rx];
			size[rx]=0;
			par[rx]=ry;
		}
	}
}
int main()
{
	bhago;
	int n,m,x,y;
	cin>>n>>m;
	int par[n+1],size[n+1]={1};
	loop(i,1,n,1)
	{
		par[i]=i;
		size[i]=1;
	}
	while(m--)
	{
		cin>>x>>y;
		u(x,y,par,size);
	}
	for(int i=1;i<=n;++i)
	{
		cout<<"Size of "<<i<<" is "<<size[i]<<"\n";
	}
	return 0;
}