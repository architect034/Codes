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
bool check(int x,int a[],int k,int n)
{
	int cnt=0,sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(sum>x)
		{
			cnt++;
			i--;
			sum=0;
		}
		else if(sum==x)
		{
			cnt++;
			sum=0;
		}
	}
	if(sum>0)
	{
		cnt++;
		sum=0;
	}
	if(cnt<=k)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	bhago;
	int tc;
	cin>>tc;
	while(tc--)
	{
		int k,n;
		cin>>k>>n;
		int a[n];
		int low=1,high=0;
		loop(i,0,n-1,1)
		{
			cin>>a[i];
			high+=a[i];
		}
		int ans=high;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(check(mid,a,k,n)==true)
			{
				ans=mid;
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}