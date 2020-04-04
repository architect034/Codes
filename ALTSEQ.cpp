#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> l(n,1);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(abs(v[j])>abs(v[i])&&((v[i]<0&&v[j]>0)||(v[i]>0&&v[j]<0))){
				l[j]=max(l[j],l[i]+1);
			}
		}
	}
	int ans=1;
	for(int i=0;i<n;i++)ans=max(ans,l[i]);
	cout<<ans;
}