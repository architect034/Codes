#include<bits/stdc++.h>
#define ll long long 
using namespace std;
char a[1001][1001];
int dp[1001][1001];
int vis[1001][1001];
int n,k;
int solve(int x,int y){
	cout<<"aya\n";
	if(y==(n-1)){
		if(a[x][y]=='1'){
			cout<<x<<" and "<<y<<" returned 1\n";
			return 1;

		}
		cout<<x<<" and "<<y<<" returned \n";
		return INT_MAX;
	}
	if(dp[x][y]!=1000000000){
		// cout<<"Gere\n";
		return dp[x][y];
	}
	int ans=1;
	for(int i=max(0,(y-k));i<=min(n-1,y+k);i++){
		if(i==y||vis[i][i]==1){
			continue;
		}
		// cout<<i<<" i ka value\n";
		if(a[x][i]=='1'){
			vis[i][i]=1;
			cout<<i<<" "<<i<<" called\n";
			ans+=solve(i,i);
		}
	}
	return dp[x][y]=ans;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<1001;i++){
			for(int j=0;j<1001;j++){
				dp[i][j]=1000000000;
			}
		}
		cin>>n>>k;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
			}
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout<<a[i][j];
		// 	}
		// 	cout<<"\n";
		// }

		cout<<solve(0,0)<<"\n";
		for(int i=0;i<n;i++){
			cout<<dp[i][i]<<" ";
		}
	}
}