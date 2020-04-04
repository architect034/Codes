#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<long long> v(n),pre(n,0),suf(n,0);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i==0){
			pre[i]=v[i];
		}
		if(i==n-1){
			suf[i]=v[i];
		}
		sum+=v[i];
	}
	for(int i=1;i<n;i++){
		pre[i]=pre[i-1]+v[i];
	}
	for(int i=n-2;i>=0;i--){
		suf[i]=suf[i+1]+v[i];
	}
	if(sum%3==0){
		long long kitna=sum/3;
		vector<long long> p,s;
		for(int i=0;i<n;i++){
			if(pre[i]==kitna){
				p.push_back(i);
			}
		}
		for(int i=n-1;i>=0;i--){
			if(suf[i]==kitna){
				s.push_back(i);
			}
		}
		reverse(s.begin(),s.end());
		// for(auto x:p){
		// 	cout<<x<<" ";
		// }
		// cout<<"\n";
		// for(auto x:s){
		// 	cout<<x<<" ";
		// }
		// cout<<"\n";

		long long ans=0;
		for(int i=0;i<(int)p.size();i++){
			int idx=upper_bound(s.begin(),s.end(),p[i]+1)-s.begin();
			ans+=(s.size()-idx);
		}
		cout<<ans<<"\n";
	}else{
		cout<<0<<"\n";
	}
}