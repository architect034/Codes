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
void u(int x,int y,int p[],int size[])
{
	int rx=root(x,p);
	int ry=root(y,p);
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
			p[ry]=rx;
		}
		else
		{
			size[ry]+=size[rx];
			size[rx]=0;
			p[rx]=ry;
		}
	}
}
int main()
{
	bhago;
	int tc;
	cin>>tc;
	while(tc--)
	{
		int n,m;
		cin>>n>>m;
		int a[n][m]={0};
		int p[1000000],size[1000000];
		loop(i,0,99999,1)
		{
			p[i]=i;
			size[i]=1;
		}
		loop(i,0,n-1,1)
		{
			loop(j,0,m-1,1)
			{
				cin>>a[i][j];
				if(a[i][j]==1)
				{
					if((j-1)>=0&&a[i][j-1]==1)
					{
						u(i*m+j,i*m+(j-1),p,size);
					}
					if((i-1)>=0&&a[i-1][j]==1)
					{
						u(i*m+j,(i-1)*m+j,p,size);
					}
					if((i-1)>=0&&(j-1)>=0&&a[i-1][j-1]==1)
					{
						u(i*m+j,(i-1)*m+(j-1),p,size);
					}
					if((i-1)>=0&&(j+1)<m&&a[i-1][j+1]==1)
					{
						u(i*m+j,(i-1)*m+(j+1),p,size);
					}
				}
				else
				{
					p[i*m+j]=-1;
					size[i*m+j]=0;
				}
			}
		}
		map<int,int>roots;
		int bada=0,ans=0;
		for(int i=0;i<(m*n);i++)
		{
			if(p[i]!=-1)
			{
				if(size[i]>0)
				{
					ans++;
					bada=max(bada,size[i]);
				}
			}
		}
		cout<<ans<<" "<<bada<<"\n";
		// cout<<roots.size()<<" ";
	}
	return 0;
}