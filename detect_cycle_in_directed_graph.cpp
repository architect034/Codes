#include<bits/stdc++.h>
using namespace std;
int find(int x,vector<int> &par){
	while(x!=par[x]){
		x=par[par[x]];
	}
	return x;
}
int uni(int x,int y,vector<int> &rank,vector<int> &par,int n){
	int px=find(x,par);
	int py=find(y,par);
	if(px==py){
		return 1;
	}
	if(rank[px]>rank[py]){
		par[py]=px;
		par[y]=px;
		rank[y]=0;
		rank[px]+=rank[py];
		rank[py]=0;
	}else{
		par[px]=py;
		par[x]=py;
		rank[x]=0;
		rank[py]+=rank[px];
		rank[px]=0;
	}
	return 0;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,cnt=0;
		cin>>n>>m;
		bool say=0;
		vector<int> par(n),rank(n,1);
		for(int i=0;i<n;i++)par[i]=i;
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			say=uni(x,y,rank,par,n);
			if(say){
				cnt++;
				break;
			}
		}
		if(cnt>0){
			cout<<1<<"\n";
		}else{
			cout<<0<<"\n";
		}
	}
	return 0;
}
