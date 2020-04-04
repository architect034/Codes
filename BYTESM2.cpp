#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m;
		cin>>n>>m;
		long long v[n][m];
		for(long long i=0;i<n;i++){
			for(long long j=0;j<m;j++){
				cin>>v[i][j];
			}
		}
		long long dp[n][m];
		memset(dp,0,sizeof(dp));
		for(long long i=0;i<m;i++){
			dp[n-1][i]=v[n-1][i];
		}
		for(long long i=n-2;i>=0;i--){
			for(long long j=0;j<m;j++){
				if(j-1>=0){
					dp[i][j]=max(dp[i][j],dp[i+1][j-1]+v[i][j]);
				}
				if(j+1<m){
					dp[i][j]=max(dp[i][j],dp[i+1][j+1]+v[i][j]);
				}
				dp[i][j]=max(dp[i][j],v[i][j]+dp[i+1][j]);
			}
		}
		long long ans=0;
		for(long long i=0;i<m;i++){
			ans=max(ans,dp[0][i]);
		}
		cout<<ans<<"\n";
	}
}