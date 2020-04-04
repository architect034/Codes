#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		vector<int> dp1(n,1),dp2(n,1);
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(v[j]>v[i]){
					dp1[j]=max(dp1[j],dp1[i]+1);
				}
			}
		}
		for(int i=n-1;i>=0;i--){
			for(int j=i-1;j>=0;j--){
				if(v[j]>v[i]){
					dp2[j]=max(dp2[j],dp2[i]+1);
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,dp1[i]+dp2[i]-1);
		}
		cout<<ans<<"\n";
	}
}