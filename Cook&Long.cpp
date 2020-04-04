#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll cal(ll d,ll m,ll y){
	static ll t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	y -= m < 3;
	return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}
int main(){
	ll mnth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	ll dp[400*12+5];
	memset(dp,0,sizeof(dp));
	for(ll i=1;i<=400*12;i++){
		ll m=i%12;
		if(m==0)m=12;
		ll y=ceil((long double)i/12.0);
		ll st=cal(1,m,y);
		st=(st-1+7)%7;
		if(st==5){
			if(m==2){
				dp[i]=1;
			}
		}
		if(st==6){
			if(m==2){
				if(y%400==0||(y%4==0&&y%100!=0)){
					dp[i]=0;
				}else{
					dp[i]=1;
				}
			}
		}
	}
	ll tot=0;
	for(ll i=1;i<=400*12;i++){
		dp[i]+=dp[i-1];
	}
	tot=dp[400*12];
	ll tc;
	cin>>tc;
	while(tc--){
		ll ans=0;
		ll m1,y1,m2,y2;
		cin>>m1>>y1>>m2>>y2;
		ll months2=(y2-1)*12+m2;
		ll months1=(y1-1)*12+m1-1;
		ll mul2=months2/(400*12),mul1=months1/(400*12);
		ans+=mul2*tot;
		ans+=dp[(months2%(400*12))];
		ans-=mul1*tot;
		ans-=dp[(months1%(400*12))];
		cout<<ans<<"\n";
	}
}