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
int root(int x,int p[])
{
	while(x!=p[x])
	{
		x=p[x];
		p[x]=p[p[x]];
	}
	return x;
}
void u(int a,int b,int p[],int r[])
{
	int ra=root(a,p);
	int rb=root(b,p);
	if(r[ra]>=r[rb])
	{
		r[ra]+=r[rb];
		p[rb]=ra;
	}
	else if(r[ra]<r[rb])
	{
		r[rb]+=r[ra];
		p[ra]=rb;
	}
}
int main()
{
	bhago;
	int n;
	cin>>n;
	int m;
	cin>>m;
	int x,y,w;
	vector<pair<int,pair<int,int> > >v; 
	loop(i,0,m-1,1)
	{
		cin>>x>>y>>w;
		v.pb(mp(w,mp(x,y)));
	}
	int p[n],r[n];
	loop(i,0,n-1,1)
	{
		p[i]=i;
		r[i]=1;
	}
	sort(all(v));
	vector<pair<int,pair<int,int> > > ans;
	cout<<"The Answer is --- \n";
	loop(i,0,m-1,1)
	{
		int a=v[i].SS.FF;
		int b=v[i].SS.SS;
		int ra=root(a,p);
		int rb=root(b,p);
		if(ra!=rb)
		{
			u(a,b,p,r);
			cout<<a<<" "<<b<<" "<<v[i].FF<<"\n";
			ans.pb(mp(a,mp(b,v[i].FF)));
		}
		if((int)ans.size()==(n-1))
		{
			break;
		}
	}
	return 0;
}