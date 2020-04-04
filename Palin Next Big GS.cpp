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
	string s;
	cin>>s;
	int h[10]={0};
	loop(i,0,(int)s.size()-1,1)
	{
		h[s[i]-'0']++;
	}
	vector<int> v;
	loop(i,0,9,1)
	{
		if(h[i]%2==1)
		{
			v.pb(i);
		}
	}
	deque<char> d;
	if(v.size()>1)
	{
		cout<<-1;
	}
	else
	{
		
		if(v.size()==1)
		{
			d.pb(v[v.size()-1]+'0');
			h[v[v.size()-1]]--;
			loop(i,0,9,1)
			{
				for(int j=0;j<(h[i]/2);++j)
				{
					d.pb(i+'0');
					d.pf(i+'0');
				}
			}
		}
		else
		{
			loop(i,0,9,1)
			{
				for(int j=0;j<(h[i]/2);++j)
				{
					d.pb(i+'0');
					d.pf(i+'0');
				}
			}
		}
	}
	loop(i,0,(int)d.size()-1,1)
	{
		cout<<d[i];
	}
	return 0;
}