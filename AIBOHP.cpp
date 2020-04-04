#include<bits/stdc++.h>
using namespace std;
int dp[6101][6101];
string s;
int solve(int l,int r){
	if(l>=r){
		return 0;
	}
	if(dp[l][r]!=-1){
		return dp[l][r];
	}
	if(s[l]==s[r]){
		return dp[l][r]=solve(l+1,r-1);
	}else{
		return dp[l][r]=min(solve(l+1,r)+1,solve(l,r-1)+1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin>>s;
		cout<<solve(0,(int)s.size()-1)<<"\n";
	}
}