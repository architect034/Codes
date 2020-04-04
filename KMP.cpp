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
	string s,p;
	cin>>s>>p;
	int pt[(int)p.size()];
	pt[0]=0;
	int i=1,j=0;
	while(i<(int)p.size())
	{
		if(p[i]==p[j])
		{
			pt[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=pt[j-1];
		}
		else
		{
			pt[i]=0;
			i++;
		}
	}
	loop(i,0,(int)p.size()-1,1)
	{
		cout<<pt[i]<<" ";
	}
	cout<<"\n";
	i=0,j=0;
	while(i<(int)s.size())
	{
		if(s[i]==p[j])
		{
			i++;
			j++;
		}
		else
		{
			if(s[i]!=p[j]&&j==0)
			{
				i++;
			}
			else if(s[i]!=p[j]&&j!=0)
			{
				j=pt[j-1];
			}
		}
		if(j==(int)p.size())
		{
			cout<<"Matched at Index -- "<<i-(int)p.size()<<"\n";
			j=0;
		}
	}
	return 0;
}
