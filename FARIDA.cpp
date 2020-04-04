#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	for(int it=1;it<=t;it++){
		long long n;
		scanf("%lld",&n);
		vector<long long> v(n);
		for(int i=0;i<n;i++)scanf("%lld",&v[i]);
		vector<long long> dp(n);
		if(n==0){
			printf("Case %d: %lld\n",it,0);
			continue;
		}
		dp[0]=v[0];
		if(n>1){
			dp[1]=max(dp[0],v[1]);
		}
		for(int i=2;i<n;i++){
			dp[i]=max(dp[i-1],v[i]+dp[i-2]);
		}
		printf("Case %d: %lld\n",it,dp[n-1]);
	}
}