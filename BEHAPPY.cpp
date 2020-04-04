#include<bits/stdc++.h>
using namespace std;
int a[101],b[101];
int dp[15][105];
int solve(int gf,int n,int m){
	if(gf==m){
		if(n==0){
			return 1;
		}
		return 0;
	}
	if(dp[gf][n]!=-1){
		return dp[gf][n];
	}
	int ans=0;
	for(int i=a[gf];i<=n&&i<=b[gf];i++){
		ans+=solve(gf+1,n-i,m);
	}
	return dp[gf][n]=ans;
}
int main(){
	while(true){
		int n,m;
		cin>>m>>n;
		if(n==0&&m==0){
			break;
		}
		memset(dp,-1,sizeof dp);
		for(int i=0;i<m;i++)cin>>a[i]>>b[i];
		cout<<solve(0,n,m)<<"\n";
	}
	
}