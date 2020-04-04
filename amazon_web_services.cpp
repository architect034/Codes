#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		int n=a.size();
		string aa=a;
		sort(aa.begin(),aa.end());
		for(int i=0;i<n;i++){
			if(a[i]!=aa[i]){
				for(int j=n-1;j>=0;j--){
					if(a[j]==aa[i]){
						swap(a[i],a[j]);
						break;
					}
				}
				break;
			}
		}
		if(a<b){
			cout<<a<<"\n";
		}else{
			cout<<"---\n";
		}
	}
}