#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long ans=(n/9)*10+(n%9);
		if(n%9==0){
			ans--;
		}
		cout<<ans<<"\n";
	}
}