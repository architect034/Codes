#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,x,d,fee=0,upfront=0;
		cin>>n>>k>>x>>d;
		int p[n];
		for(int i=0;i<n;i++)	cin>>p[i];
		for(int i=0;i<n;i++)
		{
			fee+=max(k,(x*p[i])/100);
			upfront+=d;
		}
		if(fee<upfront)
			cout<<"fee\n";
		else	cout<<"upfront\n";
	}
}
