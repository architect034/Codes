#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	cin>>n;
	vector<long long> v(n);
	for(long long i=0;i<n;i++) cin>>v[i];
	vector<pair<int,vector<long long> > >dp;
	for(long long i=1;i<=10;i++){
		vector<long long> tmp;
		for(int k=0)
		for(long long j=n-1;j>=0;j-=i){
			if(tmp.size()==0){
				tmp.push_back(v[j]);
			}else{
				tmp.push_back(tmp.back()+v[j]);
			}
			
		}
		dp.push_back(tmp);
	}
	long long q;
	cin>>q;
	while(q--){
		long long l,r,d;
		cin>>l>>r>>d;
		long long kitna=(r-l)/d;
		cout<<dp[d-1][kitna]<<"\n";
	}
}