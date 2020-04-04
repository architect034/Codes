/*
 *architect034
 *NIT Silchar<16-1-5-036>
 */
#include<bits/stdc++.h>
using namespace std;
#define ios_base()  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll	long long
#define ull	unsigned long long
#define f(i,start,end,increment)   for(ll i=start;i<=end;i+=increment)
#define rf(i,start,end,decrement)   for(ll i=start;i>=end;i-=decrement)
#define pb   push_back
#define popb   pop_back
#define pf   push_front
#define popf   pop_front
#define mp   make_pair
#define ff   first
#define ss   second
#define yes printf("YES\n")
#define no printf("NO\n")
#define all(something)   something.begin(),something.end()
const ll mod=1e9+7;
const int MAX = 10000007;
bool prime[MAX];
int spf[MAX];
void sieve(){
	// memset(spf,1,sizeof spf);
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
		if(b%2==1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b=b>>1;
	}
	return ans%mod;
}
void precalc(){
	sieve();
}
void calc(){
	int x;
	cin>>x;
	cout<<x;
}
int main(){
	ios_base();
	precalc();
	int _=1;
	// cin>>_;
	while(_--){
		calc();
	}
	return 0;
}

