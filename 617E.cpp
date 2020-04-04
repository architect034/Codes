#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans[n];
	ans[0]=0;
	char a,b='a';
	a=s[0];
	for(int i=1;i<n;i++){
		if(s[i]>=a){
			ans[i]=0;
			a=s[i];
		}else if(s[i]>=b){
			ans[i]=1;
			b=s[i];
		}else{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	for(auto x:ans){
		cout<<x;
	}
}