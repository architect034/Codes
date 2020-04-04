#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		bool say;
		for(int i=0;i<(n+1)/2;i++){
			say=false;
			say=(a[i]>=i)?true:false;
			say&=((a[n-1-i]>=(i))?true:false);
			if(say==false){
				break;
			}
		}
		if(say==false){
			cout<<"No\n";
		}else{
			if(n%2==0&&a[n/2-1]==a[n/2]&&a[n/2-1]==(n/2-1)){
				cout<<"No\n";
				continue;
			}
			cout<<"Yes\n";
		}
	}
	return 0;
}