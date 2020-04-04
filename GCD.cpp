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

ll a,b,n,c,c1,c2;
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
ll GCD1()
{
	ll c=a%c1;
	while(c!=0)
	{
		a=c1;
		c1=c;
		c=a%c1;
	}
	return c1;
}
ll GCD2()
{
	ll c=b%c2;
	while(c!=0)
	{
		b=c2;
		c2=c;
		c=b%c2;
	}
	return c2;
}
ll power(ll a,ll b,ll m)
{
	ll ans=1;
	while(b!=0)
	{
		if(b%2==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return ans%m;
}
int main()
{
	bhago;
	ll t;
	cin>>t;
	while(t--)
	{
		
		cin>>a>>b>>n;
		c=a-b;
		c1=c,c2=c;
		if(c!=0)
		{
			a=a%c;
			cout<<a;
		}
		else
		{
			a=a%mod;
			b=b%mod;
			a=power(a,n,mod);
			b=power(b,n,mod);
			cout<<(a+b)%mod<<"\n";
		}
	}
	return 0;
}


/*


def fast_power(base, power, mod ):
    """
    Returns the result of a^b i.e. a**b
    We assume that a >= 1 and b >= 0
 
    Remember two things!
     - Divide power by 2 and multiply base to itself (if the power is even)
     - Decrement power by 1 to make it even and then follow the first step
    """
 
    result = 1
    while power > 0:
        # If power is odd
        if power % 2 == 1:
            result = (result * base) % mod
 
        # Divide the power by 2
        power = power / 2
        # Multiply base to itself
        base = (base * base) % mod
 
    return result
 
a,b,n=raw_input().split()
a=int(a)
b=int(b)
n=int(n)
if a==b:
	ans=fast_power(a,n,1000000007)
	ans1=fast_power(a,n,1000000007)
	print ((ans+ans1)%1000000007)
else:
	x=fast_power(a,n,(a-b))
	y=fast_power(b,n,(a-b))
	print (((x+y)%(a-b))%1000000007)
*/
