#include<bits/stdc++.h>
using namespace std;
int sum[26][26],n;
int ans=0;
int solve(int l,int r,int cur){
	if(l>=r){
		if(l==n&&sum[l][r]>=cur){
			return 1;
		}else{
			return 0;
		}
	}
	for(int i=l;i<r;i++){
		if(cur<=sum[l][i]&&sum[l][i]<=sum[i+1][r]){
			ans+=1+solve(i+1,r,sum[l][i]);
		}
	}
	return 0;
}
int main(){
	int t=0;
	while(++t){
		string s;
		cin>>s;
		ans=0;
		if(s=="bye")break;
		n=s.size();
		for(int i=0;i<n;i++){
			int tmp=0;
			for(int j=i;j<n;j++){
				tmp+=s[j]-'0';
				sum[i][j]=tmp;
			}
		}
		int nn=solve(0,n-1,0);
		cout<<t<<". "<<ans+1<<"\n";
	}
}