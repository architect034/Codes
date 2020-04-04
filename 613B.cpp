#include <bits/stdc++.h>
long long maxSubArraySum(long long a[], long long size) 
{ 
    long long max_so_far = -10000000000000000 , max_ending_here = 0; 
  
    for (long long i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		long long v[n];
		long long a=0,b=0,p=0,c=0;
		for(long long i=0;i<n;i++){
			cin>>v[i];
			a+=v[i];
			if(v[i]>=0){
				p++;
			}
		}
		long long vv[n-1],vvv[n-1];
		for(int i=0;i<n-1;i++){
			vv[i]=v[i];
		}
		for(int i=1;i<n;i++){
			vvv[i-1]=v[i];
		}
		// if(p==n){
		// 	cout<<"YES\n";
		// 	continue;
		// }
		b=maxSubArraySum(vv,n-1);
		c=maxSubArraySum(vvv,n-1);
		if(b<a&&c<a){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
}