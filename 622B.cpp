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
	ll n;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++){
		cin>>v[i];
	}
	ll s1=0,s2=0,s3=0;
	//complete increasing
	ll abtakmax=v[n-1];
	for(ll i=n-1;i>=0;i--){
		s1+=min(abtakmax,v[i]);
		abtakmax=min(abtakmax,v[i]);
	}
	//complete decreasing
	abtakmax=v[0];
	for(ll i=0;i<n;i++){
		s2+=min(abtakmax,v[i]);
		abtakmax=min(abtakmax,v[i]);
	}
	// cout<<s2<<"\n";
	//mountain


	ll idx=0;
	// for(ll i=0;i<n;i++){
	// 	if(v[i]>=bada){
	// 		bada=v[i];
	// 		idx=i;
	// 	}
	// }
	// abtakmax=v[idx];
	// for(ll i=idx;i>=0;i--){
	// 	s3+=min(abtakmax,v[i]);
	// 	abtakmax=min(abtakmax,v[i]);
	// }
	// abtakmax=v[idx];
	// for(ll i=idx+1;i<n;i++){
	// 	s3+=min(abtakmax,v[i]);
	// 	abtakmax=min(abtakmax,v[i]);
	// }



	for(ll i=0;i<n;i++){
		ll tmp=0;
		abtakmax=v[i];
		for(ll j=i;j>=0;j--){
			tmp+=min(abtakmax,v[j]);
			abtakmax=min(abtakmax,v[j]);
		}
		abtakmax=v[i];
		for(ll j=i+1;j<n;j++){
			tmp+=min(abtakmax,v[j]);
			abtakmax=min(abtakmax,v[j]);
		}
		if(tmp>=s3){
			s3=tmp;
			idx=i;
		}
	}

	// cout<<s3<<"\n";

	if(s1>=s2&&s1>=s3){
		abtakmax=v[n-1];
		for(ll i=n-1;i>=0;i--){
			// s1+=min(abtakmax,v[i]);
			cout<<min(abtakmax,v[i])<<" ";
			abtakmax=min(abtakmax,v[i]);
		}
	}else if(s2>=s1&&s2>=s3){
		abtakmax=v[0];
		for(ll i=0;i<n;i++){
			// s2+=min(abtakmax,v[i]);
			cout<<min(abtakmax,v[i])<<" ";
			abtakmax=min(abtakmax,v[i]);
		}
	}else{
		deque<ll> dq;
		// idx=0,bada=v[0];
		// for(ll i=0;i<n;i++){
		// 	if(v[i]>=bada){
		// 		bada=v[i];
		// 		idx=i;
		// 	}
		// }
		abtakmax=v[idx];
		for(ll i=idx;i>=0;i--){
			// s3+=min(abtakmax,v[i]);
			dq.pf(min(abtakmax,v[i]));
			// cout<<min(abtakmax,v[i])<<" ";
			abtakmax=min(abtakmax,v[i]);
		}
		abtakmax=v[idx];
		for(ll i=idx+1;i<n;i++){
			// s3+=min(abtakmax,v[i]);
			dq.pb(min(abtakmax,v[i]));
			// cout<<min(abtakmax,v[i])<<" ";
			abtakmax=min(abtakmax,v[i]);
		}
		for(auto x:dq){
			cout<<x<<" ";
		}
	}

	return 0;
}
