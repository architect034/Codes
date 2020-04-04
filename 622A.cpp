/*
 *architect034
 *NIT Silchar<16-1-5-036>
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
void debug(string s){
	cout<<s<<"\n";
}
const int MAX = 2000007;
bool prime[MAX];
int sp[MAX];
void sieve(){
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
ll GCD(ll a,ll b){
	ll c=a%b;
	while(c!=0)
	{
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
ll power(ll a,ll b){
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
int main(){
	bhago;
	int t;
	cin>>t;
	while(t--){
		int out=0;
		vector<int> v(3),tmp(3);
		cin>>v[0]>>v[1]>>v[2];
		tmp[0]=v[0];
		tmp[1]=v[1];
		tmp[2]=v[2];
		sort(all(v));
		reverse(all(v));
		int ans=0;
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}
		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}

		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}


		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}

		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}


		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}

		if(v[0]&&v[2]){
			ans++;
			v[0]-=1;
			v[2]-=1;
		}
		if(v[0]&&v[1]){
			ans++;
			v[0]-=1;
			v[1]-=1;
		}
		if(v[1]&v[2]){
			ans++;
			v[1]-=1;
			v[2]-=1;
		}
		
		
		
		if(v[0]&&v[1]&&v[2]){
			ans++;
		}
		out=max(ans,out);
		ans=0;
		v[0]=tmp[0];v[1]=tmp[1];v[2]=tmp[2];
		for(int i=0;i<3;i++){
			if(v[i]>0){
				ans++;
				v[i]-=1;
			}
		}
		cout<<out<<"\n";
	}
	return 0;
}
