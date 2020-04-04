#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,x;
	cin>>n>>x;
	vector<int> v(800005,0);
	set<pair<int,int> > s;
	for(int i=0;i<x;i++){
		s.insert({0,i});
	}
	for(int i=0;i<n;i++){
		int y;
		cin>>y;
		int t1=y%x;
		int t2=v[t1];
		s.erase(s.find({t2,t1}));
		s.insert({t2+1,t1});
		v[t1]++;
		auto it=s.begin();
		cout<<(((*it).first))*x+(*it).second<<"\n";
	}
}