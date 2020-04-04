#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int e=0,o=0;
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			if(x%2==0){
				e++;
			}else{
				o++;
			}
		}
		if(e==n){
			cout<<"NO\n";
		}else{
			if(o==n&&n%2==0){
				cout<<"NO\n";
			}else{
				cout<<"YES\n";
			}
		}
	}
}