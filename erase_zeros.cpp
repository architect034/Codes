#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--)
	{
		ll n,g,b,x,y,ans;
		cin>>n>>g>>b;
		if(g>=(n+1)/2)
		{
			cout<<n<<endl;
			continue;
		}
		x=(n+1)/2;
		y=ceil(1.0*x/g);
		ans=x+(y-1)*b;
		if(ans<n)
			ans=n;
		cout<<ans<<endl;
	}
}