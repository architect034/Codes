#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<pair<int,int> > v;
		for(int i=0;i<n;i++){
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair(x,y));
		}
		sort(v.begin(),v.end());
		string s="";
		int x=0,y=0;
		bool say=true;
		for(int i=0;i<n;i++){
			int xx=v[i].first;
			int yy=v[i].second;
			if(xx<x||yy<y){
				say=false;
				break;
			}
			for(int j=x+1;j<=xx;j++){
				s+='R';
			}
			for(int j=y+1;j<=yy;j++){
				s+='U';
			}
			x=xx;
			y=yy;
		}
		if(say==false){
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		cout<<s<<"\n";
	}
}