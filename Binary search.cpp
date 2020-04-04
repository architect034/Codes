#include<bits/stdc++.h>
using namespace std;
int main()
{
	int lo=0,hi=999,cnt=0;
	while(lo<=hi)
	{
		int m=(lo+hi)/2;
		cnt++;
		cout<<lo<<" "<<hi<<"\n";
		if(m==137)
		{
			cout<<cnt;
			break;
		}
		else if(m<137)
		{
			lo=m+1;
		}
		else
		{
			hi=m-1;
		}
	}
}