/*
*architect034
*NIT Silchar<36>
*/
#include<bits/stdc++.h>
using namespace std;
#define fast_io   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll        long long
#define ull     unsigned long long
#define pb   push_back
#define popb   pop_back
#define pf   push_front
#define popf   pop_front
#define mp   make_pair
#define FF   first
#define SS   second
#define all(something)   something.begin(),something.end()
const int mod = 1000000007;
void debug(string s){
	cout<<s<<"\n";
}
const int MAX = 2000007;
bool prime[MAX];
int sp[MAX];
void sieve(){
	for (int i = 2; i < MAX; i += 2)	sp[i] = 2;
	for (ll i = 3; i < MAX; i += 2){
		if (!prime[i]){
			sp[i] = i;
			for (ll j = i; (j*i) < MAX; j += 2){
				if (!prime[j*i]){
					prime[j*i] = true;
					sp[j*i] = i;
				}
			}
		}
	}
}
ll GCD(ll a,ll b){
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
ll power(ll a,ll b){
	ll ans=1;
	while(b!=0){
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
void uni(int x,int y,int par[],int size[])
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
int main(){
	fast_io;
	int n,I;
	cin>>n>>I;
	int bytes=8*I;
	int a[n];
	map<int,int> m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		m[a[i]]++;
	}
	int diff=m.size();
	int k=ceil(log2((long double)diff));
	if(n*k<=bytes){
		cout<<0<<"\n";
	}else{
		vector<int> v;
		for(auto it=m.begin();it!=m.end();++it){
			v.pb(it->SS);
		}
		int total=v.size();
		int ans=0;
		for(int i=0;;i++){
			k=ceil(log2((long double)(total-i)));
			if(n*k<=bytes){
				ans=i;
				break;
			}
		}
		vector<int> pre(total),suff(total);
		pre[0]=v[0];
		suff[total-1]=v[total-1];
		for(int i=1;i<total;i++){
			pre[i]=v[i]+pre[i-1];
		}
		for(int i=total-2;i>=0;i--){
			suff[i]=v[i]+suff[i+1];
		}
		int sum=0,minn=INT_MAX;
		for(int i=0;i<=ans;i++){
			if(i==0){
				sum+=suff[total-ans];
			}else if(i==ans){
				sum+=pre[i-1];
			}else{
				sum+=(pre[i-1]+suff[total-(ans-i)]);
			}
			minn=min(minn,sum);
			sum=0;
		}
		cout<<minn;
	}
	return 0;
}