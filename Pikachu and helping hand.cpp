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
ll que(ll l,ll r,ll tree[],ll n)
{
	ll ans=0;
	for(l=l+n,r=r+n;l<r;l=l/2,r=r/2)
	{
		if(l%2==1)
		{
			ans=ans|tree[l];
			l++;
		}
		if(r%2==1)
		{
			ans=ans|tree[--r];
		}
	}
	return ans;
}
int main()
{
	bhago;
	ll n,k;
	cin>>n>>k;
	ll a[n],tree[2*n],ans[n+1]={0};
	ll alt[n]={0};
	loop(i,0,n-1,1)
	{
		cin>>a[i];
		tree[i+n]=a[i];
		if(i==0)
		    alt[i]=a[i];
		else
		    alt[i]=alt[i-1]|a[i];
	}
	if(k>=n)
	{
		loop(i,0,n-1,1)
		{
			cout<<alt[i]<<" ";
		}
		return 0;
	}
	for(ll i=n-1;i>0;i--)
	{
		tree[i]=(tree[i<<1]|tree[i<<1 | 1]);
	}
	for(ll i=0;i<n;i++)
	{

		ll l;
		if(i-k>0)
		{
			l=i-k;
		}
		else
		{
			l=0;
		}
		ll r=i;
		ll v=que(l,r,tree,n);
		ans[i]=a[i]|v;
	}
	loop(i,0,n-1,1)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
