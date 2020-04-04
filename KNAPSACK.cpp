#include<bits/stdc++.h>
using namespace std;
int main(){
	long long s,n;
	cin>>s>>n;
	vector<long long> w(n),v(n);
	for(long long i=0;i<n;i++){
		cin>>w[i]>>v[i];
	}
	long long dp[n+1][s+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			dp[i][j]=0;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=s;j++){
			if(j>=w[i-1]){
				dp[i][j]=max(dp[i-1][j],v[i-1]+dp[i-1][j-w[i-1]]);
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	cout<<dp[n][s];
}