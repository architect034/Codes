#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	ll h[n];
	for(ll i=0;i<n;i++){
		cin>>h[i];
		h[i]=h[i]%(a+b);
		if(h[i]==0){
			h[i]=a+b;
		}
	}
	ll ans[n];
	for(ll i=0;i<n;i++){
		if(h[i]<=a){
			ans[i]=0;
		}else{
			h[i]-=a;
			ll extra=ceil((long double)h[i]/(long double)a);
			ans[i]=extra;
		}
	}
	sort(ans,ans+n);;
	ll kitna=0,sum=0;
	for(int i=0;i<n;i++){
		sum+=ans[i];
		if(sum>k){
			break;
		}
		kitna++;
	}
	cout<<kitna<<"\n";
}