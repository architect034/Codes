#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
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
	int t;
	cin>>t;
	while(t--){
		ll n,num=0;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++){
			ll a=0,b=0;
			for(int j=i;j<n;j++){
				if(s[j]=='(')a++;
				if(s[j]==')'){
					b++;
					if(b>a){
						a++;
						b--;
						num++;
						num+=(n-j-1);
					}
				}
			}
		}
		ll deno=(n*(n+1))/2;
		num=(num*power(deno,mod-2,mod))%mod;
		cout<<num<<"\n";
	}
}