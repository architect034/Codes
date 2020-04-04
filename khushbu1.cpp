#include<bits/stdc++.h>
#define ll long long
#define fl(i,s,e,in) for(ll i=s;i<=e;i+=in)
#define pb push_back
using namespace std;
int main(){
	int tc;
	cin>>tc;
	ll total=0;
	while(tc--){
		ll n;
		cin>>n;
		ll dp[4][4];
		memset(dp,0,sizeof dp);
		fl(i,0,n-1,1){
			char c;
			ll t;
			cin>>c>>t;
			dp[c-'A'][t/3-1]++;
		}
		ll ans=INT_MIN;
		vector<ll> s(4,0);
		for(ll i=0;i<4;i++){
			for(ll j=0;j<4;j++){
				for(ll k=0;k<4;k++){
					for(ll l=0;l<4;l++){
						if(i!=j&&j!=k&&k!=l&&i!=k&&i!=l&&j!=l){
							s[0]=dp[i][0];
							s[1]=dp[j][1];
							s[2]=dp[k][2];
							s[3]=dp[l][3];
							sort(s.begin(),s.end());
							ll tmp=0,mul=100;
							for(ll m=3;m>=0;m--){
								if(s[m]==0){
									tmp-=100;
								}
								tmp+=(s[m]*mul);
								mul-=25;
							}
							ans=max(ans,tmp);
							
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
		total+=ans;
	}
	cout<<total<<"\n";
}