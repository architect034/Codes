#include<bits/stdc++.h>
using namespace std;
int dp[10001][101];
int n;
string s;
int solve(string str,int k){
	if(k==n){
		if(stoi(str)>stoi(s)){
			return 1;
		}
		return 0;
	}
	if(dp[stoi(str)][k]!=-1)return dp[stoi(str)][k];
	int ans=0;
	if(k%2==1)ans=1;
	for(int i=0;i<4;i++){
		string tmp=str;
		if(tmp[i]=='9')tmp[i]='0';
		else tmp[i]++;
		if(k%2==1){
			ans&=solve(tmp,k+1);
		}else{
			ans|=solve(tmp,k+1);
		}
	}
	return dp[stoi(str)][k]=ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(dp,-1,sizeof dp);
		cin>>s>>n;
		string str=s;
		if(solve(str,0))cout<<"Ada\n";
		else cout<<"Vinit\n";
	}
}