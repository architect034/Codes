#include<bits/stdc++.h>
using namespace std;
const long long MAX=1e5+5,mod=1e9+7;
int main(){
	int t;
	cin>>t;
	long long k;
	cin>>k;
	vector<long long> dp(MAX,0);
	if(k==1){
		dp[1]=2;
	}else{
		dp[1]=1;
	}
	for(long long i=2;i<MAX;i++){
		if(i<k){
			dp[i]=dp[i-1];
		}
		else if(i==k){
			dp[i]=2;
		}
		else{
			dp[i]=dp[i-1]+dp[i-k];
		}
		dp[i]%=mod;
	}
	for(long long i=1;i<MAX;i++){
		dp[i]+=dp[i-1];
		dp[i]%=mod;
	}
	while(t--){
		long long a,b;
		cin>>a>>b;
		cout<<(dp[b]-dp[a-1]+mod)%mod<<"\n";
	}
}