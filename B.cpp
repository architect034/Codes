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
#define smart auto
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
	int n=s.size();
	deque<int> f,b;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			for(int j=n-1;j>i;j--){
				if(s[j]==')'){
					s[i]='0';
					s[j]='0';
					f.pb(i+1);
					b.pf(j+1);
					break;
				}
			}
		}
	}
	if(f.size()==0){
		cout<<0<<"\n";
		return;
	}
	
	cout<<1<<"\n"<<f.size()+b.size()<<"\n";
	for(smart x:f){
		cout<<x<<" ";
	}
	for(smart x:b){
		cout<<x<<" ";
	}
}
int main(){
	ios_base;
	int _=1;
	// cin>>_;
	while(_--){
		void_main();
	}
	return 0;
}
