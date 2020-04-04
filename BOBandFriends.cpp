#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n);
		
		ll a,b,c;
		cin>>a>>b>>c;
		for(ll i=0;i<n;i++)cin>>v[i];
		ll ans=1e15+1;
		for(ll i=0;i<n;i++){
			ll tmp=abs(b-v[i])+c+abs(v[i]-a);
			ans=min(ans,tmp);
		}
		cout<<ans<<"\n";
	}
}