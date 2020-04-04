/*
 *architect034
 *NIT Silchar<16-1-5-036>
*/
#include<bits/stdc++.h>
using namespace std;
#define ios_base  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll	long long
#define ull	unsigned long long
#define loop(i,start,end,increment)   for(ll i=start;i<=end;i+=increment)
#define rloop(i,start,end,decrement)   for(int i=start;i>=end;i-=decrement)
#define pb   push_back
#define popb   pop_back
#define pf   push_front
#define popf   pop_front
#define mp   make_pair
#define ff   first
#define ss   second
#define all(something)   something.begin(),something.end()
const ll mod=1e9+7;
void debug(string s){
	cout<<s<<"\n";
}
const int MAX = 2000007;
bool prime[MAX];
int spf[MAX];
void sieve(){
	for (int i=2;i<MAX;i+=2)
		spf[i]=2;
	for(ll i=3;i<MAX;i+=2){
		if(!prime[i]){
			spf[i]=i;
			for(ll j=i;(j*i)<MAX;j+=2){
				if(!prime[j*i]){
					prime[j*i]=true;
					spf[j*i]=i;
				}
			}
		}
	}
}
ll GCD(ll a,ll b){
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}
ll power(ll a,ll b){
	ll ans=1;
	while(b!=0){
		if(b%2==1)ans*=a;
		a*=a;
		b=b>>1;
	}
	return ans;
}
void void_main(){
	string s;
	cin>>s;
	int l=0,r=0,u=0,d=0;
	for(int i=0;i<(ll)s.size();i++){
		if(s[i]=='L')l++;
		if(s[i]=='R')r++;
		if(s[i]=='U')u++;
		if(s[i]=='D')d++;
	}
	int lr=min(l,r);
	int ud=min(u,d);
	
	if(ud==0){
		if(lr==0){
			cout<<0<<"\n";
			return;
		}else{
			cout<<2<<"\nLR\n";
			return;
		}
	}else if(lr==0){
		if(ud==0){
			cout<<"0\n";
			return;
		}else{
			cout<<"2\nUD\n";
			return;
		}
	}
	cout<<2*lr+2*ud<<"\n";
	for(int i=0;i<lr;i++){
		cout<<'L';
	}
	for(int i=0;i<ud;i++){
		cout<<'U';
	}
	for(int i=0;i<lr;i++){
		cout<<'R';
	}
	for(int i=0;i<ud;i++){
		cout<<'D';
	}
	cout<<"\n";
}
int main(){
	ios_base;
	int _=1;
	cin>>_;
	while(_--){
		void_main();
	}
	return 0;
}
