#include<bits/stdc++.h>
using namespace std;
int main()
{
	bool p[1000000];
	memset(p,true,sizeof(p));
	p[1]=0;p[2]=1;
	for(int i=2;i*i<1000000;i++)
	{
		if(p[i]==true)
		{
			for(int j=i*i;j<1000000;j+=i)
			{
				p[j]=false;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<1000000;i++)
	{
		if(p[i]==1)
		{
			cout<<i<<" is Prime\n";
			cnt++;
		}
	}
	cout<<"Total Primes -- "<<cnt;
}