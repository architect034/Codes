#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX=1e6+5,mod=1e9+7;
ll power(ll a,ll b,ll m){
	ll ans=1;
	while(b!=0){
		if(b%2==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return ans%m;
}
int main(){
	vector<ll> fact(MAX,1);
	for(int i=2;i<MAX;i++){
		fact[i]=i*fact[i-1];
		fact[i]%=mod;
	}
	ll n,m;
	cin>>n>>m;
	ll nu=fact[n+2*m-1];
	ll de=((fact[2*m]%mod)*(fact[n-1]%mod))%mod;
	nu=(nu*power(de,mod-2,mod))%mod;
	cout<<nu<<"\n";
}