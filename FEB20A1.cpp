//I am cute and i know it..
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX=1e5+5;
ll n,m,s=0,t,out=0,tc;
vector<ll> posx,posy,negx,negy;
int main(){
	cin>>tc;
	while(tc--){
		out=0,s=0;
		cin>>n>>m;
		for(ll i=0;i<n;i++)
		{
			cin>>t;
			if(t>0)posx.push_back(t);
			else if(t<0)negx.push_back(t);
			else s++;
		}
		for(ll i=0;i<m;i++)
		{
			cin>>t;
			if(t>0)posy.push_back(t);
			else if(t<0)negy.push_back(t);
			else s+=2;
		}
		if(s==1)
		{
			out+=m*(n-1);
		}
		else if(s==2)
		{
			out+=n*(m-1);
		}
		sort(posx.begin(),posx.end());
		sort(posy.begin(),posy.end());
		sort(negx.begin(),negx.end());
		sort(negy.begin(),negy.end());
		for(ll i=0;i<posx.size();i++)
		{
			for(ll j=0;j<negx.size();j++)
			{
				ll temp=abs(posx[i]*negx[j]);
				temp=sqrt(temp);
				if((temp*temp)==abs(posx[i]*negx[j]))
				{
					if(binary_search(posy.begin(),posy.end(),temp))
					{
						out++;
					}
					if(binary_search(negy.begin(),negy.end(),-temp))
					{
						out++;
					}
				}
			}
		}
		for(ll i=0;i<posy.size();i++)
		{
			for(ll j=0;j<negy.size();j++)
			{
				ll temp=abs(posy[i]*negy[j]);
				temp=sqrt(temp);
				if((temp*temp)==abs(posy[i]*negy[j]))
				{
					if(binary_search(posx.begin(),posx.end(),temp))
					{
						out++;
					}
					if(binary_search(negx.begin(),negx.end(),-temp))
					{
						out++;
					}
				}
			}
		}
		cout<<out<<"\n";
		out=0,s=0;
		posx.clear(),posy.clear();
		negx.clear(),negy.clear();
	}
	return 0;
}