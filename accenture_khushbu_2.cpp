//Happy International Women's Day
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long N = 1e7+7,mod=1e9+7;
ll fact[N];
ll p(ll a,ll b,ll m){
	ll res=1;
	while(b){
		if(b%2){
			res=(res*a)%m;
		}
		a=(a*a)%m;
		b>>=1;
	}
	return res%m;
}
ll ncr(ll n,ll r){
	ll ans=fact[n]%mod;
	ans=(((ans*p(fact[r],mod-2,mod))%mod)*(p(fact[n-r],mod-2,mod)%mod))%mod;
	return ans;
}
void presolve(){
	fact[0]=1;
	for(ll i=1;i<N;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
	}
}
void solve(){
	ll n;
	cin>>n;
	vector<ll> negative,positive;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(x<0){
			negative.push_back(x);
		}else if(x>0){
			positive.push_back(x);
		}
	}
	ll res=0,multiplier = p(2,(ll)positive.size(),mod);
	for(ll i=1;i<=(ll)negative.size();i+=2){
		ll tmp=ncr((ll)negative.size(),i);
		res+=((multiplier*tmp)%mod);
		res%=mod;
	}
	cout<<res<<"\n";
}
int main(){
	presolve();
	int _;
	cin>>_;
	while(_--){
		solve();
	}
}