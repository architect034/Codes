#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[10],ans=0;
	for(int i=0;i<10;i++){
		cin>>a[i];
	}
	sort(a,a+10);
	// int v[8];
	for(int m=-20;m<=20;m++){
		for(int i=-20;i<=20;i++){
			for(int j=-20;j<=20;j++){
				for(int k=-20;k<=20;k++){
					for(int l=-20;l<=20;l++){
						vector<int> v;
						v.push_back(m);
						v.push_back(v.back()+i);
						v.push_back(v.back()+j);
						v.push_back(v.back()+k);
						v.push_back(v.back()+l);
						v.push_back(l);
						v.push_back(v.back()+k);
						v.push_back(v.back()+j);
						v.push_back(v.back()+i);
						v.push_back(v.back()+m);
						sort(v.begin(),v.end());
						bool say=1;
						for(int it=0;it<10;it++){
							if(v[it]!=a[it]){
								say=0;
								break;
							}
						}
						if(say==1){
							ans++;
							cout<<m<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
						}
					}
				}
			}
		}
	}
	
	cout<<ans<<"\n";
}
