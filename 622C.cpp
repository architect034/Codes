#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,a[2];
		cin>>n>>a[0]>>a[1];
		sort(a,a+2);
		ll maxx=min(n,a[1]+a[0]-1);
		ll minn=min(maxx,((a[0]+a[1]))<=n?1:(a[0]+a[1])-n+1);
		cout<<minn<<" "<<maxx<<"\n";
	}
}