#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int a,b,q;
	cin>>a>>b>>q;
	int g=__gcd(a,b);
	int n=a/g,m=b/g;
	while(q--){
	    cin>>a>>b;
	}
	int i=1024;
	cout<<n<<" "<<m<<" 1024\n";
	while(i--){
	    if((rand()%2+1)==1){
	        cout<<1<<" "<<rand()%n+1<<"\n";
	    }else{
	        cout<<2<<" "<<rand()%m+1<<"\n";
	    }
	}
	return 0;
}
