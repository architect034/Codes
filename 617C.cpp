#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		map<pair<int,int>,int> m;
		m[{0,0}]=0;
		vector<pair<int,int> > v;
		int x=0,y=0;
		for(int i=0;i<n;i++){
			if(s[i]=='U')y++;
			if(s[i]=='D')y--;
			if(s[i]=='L')x--;
			if(s[i]=='R')x++;
			if(m.find({x,y})!=m.end()){
				v.push_back(make_pair(m[{x,y}]+1,i+1));

				// cout<<m[{x,y}]+1<<" "<<i+1<<"\n";
				m[{x,y}]=i+1;
			}else{
				// m.insert({x,y},i+1);
				m[{x,y}]=i+1;
			}
		}
		int ans=INT_MAX,l=-1,r=-1;
		for(int i=0;i<(int)v.size();i++){
			if(ans>(v[i].second-v[i].first)){
				ans=v[i].second-v[i].first;
				l=v[i].first;
				r=v[i].second;
			}
		}
		if(l!=-1){
			cout<<l<<" "<<r<<"\n";
		}else{
			cout<<-1<<"\n";
		}
	}
}