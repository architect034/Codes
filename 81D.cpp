#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(ll x){
    double ans=x;
    for (ll p=2;p*p<=x;p++) { 
        if (x%p==0) { 
            while(x%p==0) 
                x/=p; 
            ans*=(1.0-(1.0/(double)p)); 
        } 
    }
    if (x>1) 
        ans*=(1.0-(1.0/(double)x)); 
    return (ll)ans; 
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,m;
		cin>>a>>m;
		cout<<solve(m/__gcd(a,m))<<"\n";
	}
}