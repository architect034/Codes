//Happy International Women's Day
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve(){
	ll n,salary,year;
	cin>>n>>salary>>year;
	vector<ll> rent(n);
	for(auto &x:rent){
		cin>>x;
	}
	ll ans=0;
	for(ll i=0;i<year;i++){
		ll l=0,r=0,tmp=0;
		while(r<n&&l<n){
			if(tmp+rent[r]<=salary){
				tmp+=rent[r];
				r++;
				ans=max(ans,tmp);
			}else{
				tmp-=rent[l];
				l++;
			}
		}
		for(ll i=0;i<n;i++){
			rent[i]<<=1;
		}
		salary<<=1;
	}
	cout<<ans<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	solve();
}