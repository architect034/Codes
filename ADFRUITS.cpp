#include<bits/stdc++.h>
using namespace std;
string s,t,ans="";
int dp[1001][1001];
string solve(){
	int n=s.size(),m=t.size();
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(i==0)dp[i][j]=j;
			else if(j==0)dp[i][j]=i;
			else if(s[i-1]==t[i-1])dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	int i=n,j=m;
	while(i>0&&j>0){
		if(s[i-1]==t[j-1]){
			ans.push_back(s[i-1]);
			i--;j--;
		}else{
			if(dp[i][j-1]>dp[i-1][j]){
				ans.push_back(s[i-1]);
				i--;
			}else{
				ans.push_back(t[j-1]);
				j--;
			}
		}
	}
	while(i>0){
		ans.push_back(s[i-1]),i--;
	}
	while(j>0){
		ans.push_back(t[j-1]),j--;
	}
	reverse(ans.begin(),ans.end());
	return ans;

}
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		memset(dp,0,sizeof dp);
		cin>>s>>t;
		cout<<solve();
	}
}