#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,c;cin>>n>>c;
	vector<int> v(n),w(n);
	for(int i=0;i<n;i++) cin>>v[i];
	for(int i=0;i<n;i++) cin>>w[i];
	int mxv=5e4;
	vector<long long> DP(mxv+3,INT_MAX);
	DP[0]=0;
	for(int i=0;i<n;i++){
		for(int val=mxv;val>=0;val--){
			DP[val]=min(DP[val],(val>=v[i])?w[i]+DP[val-v[i]]:INT_MAX);
		}
	}
	int ans=0;
	for(int val=0;val<=mxv;val++){
		if(DP[val]<=c) ans=val;
	}
	cout<<ans;
}