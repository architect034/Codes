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
int solve(int n,int d,int,int);
map<int,int> m;
int main()
{
	bhago;
	
	int n,d,c1,c2;
	cin>>n>>d>>c1>>c2;
	if(d==1)
	{
		cout<<(n-1)*c1;
	}
	else
	{
		cout<<solve(n,d,c1,c2);
	}
	return 0;
}
int solve(int n,int d,int c1,int c2)
{
	if(n<=1)
	{
		return 0;
	}
	else if(m[n]!=0)
	{
		return m[n];
	}
	else
	{
		int ans=c1*solve(n-1,d,c1,c2);
		if(n%d==0)
		{
			ans=min(ans,c2*solve(n/d,d,c1,c2));
		}
		m[n]=1+ans;   
		return m[n];
	}
}

















//
