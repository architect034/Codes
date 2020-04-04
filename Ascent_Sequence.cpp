#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,ascent=0;
	cin>>n;
	vector<bool> hasAscent(n,false);
	vector<ll> chota(n),bada(n);
	for(ll i=0;i<n;i++){
		ll l;
		cin>>l;
		ll s[l];
		for(auto &x:s){
			cin>>x;
		}
		ll c=s[0],b=s[0];
		for(ll j=1;j<l;j++){
			if(s[j]>c){
				hasAscent[i]=true;
			}
			c=min(c,s[j]);
			b=max(b,s[j]);
		}
		chota[i]=c;
		if(!hasAscent[i])
			bada[i]=b;
		else{
			ascent++;
		}
	}
	ll ans=0;
	sort(bada.begin(),bada.end());
	for(ll i=0;i<n;i++){
		if(hasAscent[i]){
			ans+=n-1;
			continue;
		}
		ll c=chota[i];
		ll idx=upper_bound(bada.begin(),bada.end(),c)-bada.begin();
		ans+=(bada.size()-idx);
		ans+=ascent;
	}
	ans+=ascent;

	cout<<ans<<"\n";
}