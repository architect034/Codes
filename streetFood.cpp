#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans=0;
		for(ll i=0;i<n;i++){
			ll a,b,c;
			cin>>a>>b>>c;
			ans=max(ans,(b/(a+1))*c);
		}
		cout<<ans<<"\n";
	}
}