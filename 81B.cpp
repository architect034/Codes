#include<bits/stdc++.h>
using namespace std;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		string s,t;
		cin>>s>>t;
		vector<vector<int> > v(26);
		for(int i=0;i<(int)s.size();i++){
			v[s[i]-'a'].push_back(i);
		}
		int ans=1,index=-1;
		bool say=true;
		for(int i=0;i<(int)t.size();i++){
			if(v[t[i]-'a'].size()==0){
				say=false;
				break;
			}
			int idx=upper_bound(v[t[i]-'a'].begin(),v[t[i]-'a'].end(),index)-v[t[i]-'a'].begin();
			if(idx==(int)v[t[i]-'a'].size()){
				index=-1;
				ans++;
				i--;
			}else{
				index=v[t[i]-'a'][idx];
			}
		}
		if(!say){
			cout<<-1<<"\n";
		}else{
			cout<<ans<<"\n";
		}
	}
}

// Acquire::http::proxy "http://172.16.199.40:8080";
// Acquire::https::proxy "https://172.16.199.40:8080";
// Acquire::ftp::proxy "ftp://172.16.199.40:8080";