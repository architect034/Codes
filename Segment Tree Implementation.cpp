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
void update(int index,int v,int tree[],int n)
{
	tree[index+n]=v;
	index=index+n;
	while(index>0)
	{
		tree[index/2]=tree[index]+tree[index^1];
		index=index/2;
	}
}
int que(int l,int r,int tree[],int n)
{
	int ans=0;
	for(l=l+n,r=r+n;l<r;l=l/2,r=r/2)
	{
		if(l%2==1)
		{
			ans+=tree[l];
			l++;
		}
		if(r%2==1)
		{
			ans+=tree[--r];
		}
	}
	return ans;
}
int main()
{
	bhago;
	int n;
	cin>>n;
	int a[n],tree[2*n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		tree[i+n]=a[i];
	}
	for(int i=n-1;i>0;i--)
	{
		tree[i]=tree[i<<1]+tree[i<<1 | 1];
	}
	for(int i=1;i<n;i++)
	{
		cout<<"Index -- "<<i<<" Value -- "<<tree[i]<<"\n";
	}
	int index,value;
	cin>>index>>value;
	update(index,value,tree);

	cout<<que(0,2,tree,n);
	return 0;
}
