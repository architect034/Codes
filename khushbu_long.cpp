//I can be cute and sexy at same time :P
#include<bits/stdc++.h>
#define lld long long
#define fl(i,s,e,in) for(lld i=s;i<=e;i+=in)
#define pb push_back
using namespace std;
lld nikalo(lld dte,lld mon,lld year)
{
	lld out[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
	year -= mon < 3;
	return (year + year/4 - year/100 + year/400 + out[mon-1] + dte) % 7;
}
int main(){
	vector<lld> ans(4805,0);
	for(lld i=2;i<=4800;i+=12)
	{
		lld startDay=nikalo(1,2,i/12+1);
		if(startDay==6)
		{
			ans[i]=1;
		}
		if(startDay==0)
		{
			if((i/12+1)%400==0||((i/12+1)%4==0&&(i/12+1)%100!=0))
			{
				ans[i]=0;
			}
			else
			{
				ans[i]=1;
			}
		}
	}
	for(lld i=1;i<=4800;i++)
	{
		ans[i]=ans[i]+ans[i-1];
	}
	int t;
	cin>>t;
	while(t--)
	{
		lld a,b,c,d;
		cin>>a>>b>>c>>d;
		lld ret=0;
		lld tmp1=(b-1)*12+a-1,tmp2=(d-1)*12+c;
		ret+=(tmp2/4800)*ans[4800];
		ret+=ans[tmp2%4800];
		ret-=(tmp1/4800)*ans[4800];
		ret-=ans[tmp1%4800];
		cout<<ret<<"\n";
	}
}