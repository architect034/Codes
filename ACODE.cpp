#include<bits/stdc++.h>
using namespace std;
string s;
int dp[5005];
int solve(int x,int n){
	if(x>=n){
		return 1;
	}
	if(dp[x]!=-1){
		return dp[x];
	}
	if(x+1<n){
		if(s[x]=='1'&&s[x+1]=='0'){
			return dp[x]=solve(x+2,n);
		}else if(s[x]=='2'&&s[x+1]=='0'){
			return dp[x]=solve(x+2,n);
		}else if(s[x]<'2'){
			if(x+2<n&&s[x+2]=='0'){
				return dp[x]=solve(x+1,n);
			}
			return dp[x]=solve(x+1,n)+solve(x+2,n);
		}else if(s[x]=='2'&&s[x]<='6'){
			if(x+2<n&&s[x+2]=='0'){
				return dp[x]=solve(x+1,n);
			}
			return dp[x]=solve(x+1,n)+solve(x+2,n);
		}else if(s[x]=='2'&&s[x+1]>'6'){
			if(x+2<n&&s[x+2]=='0'){
				return 0;
			}
			return dp[x]=solve(x+2,n);
		}else{
			return dp[x]=solve(x+1,n);
		}
	}else{
		return dp[x]=solve(x+1,n);
	}
}
int main(){
	while(1){
		cin>>s;
		if(s=="0")break;
		memset(dp,-1,sizeof dp);
		cout<<solve(0,(int)s.size())<<"\n";
	}
	// cout<<dp[s.size()-1];
}