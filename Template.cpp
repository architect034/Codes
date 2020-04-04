/*
 *architect034
 *NIT Silchar<16-1-5-036>
 */
#include<bits/stdc++.h>
using namespace std;
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
#define all(anything)   anything.begin(),anything.end()
const ll mod=1e9+7;
const int MAX = 10000007;
bool prime[MAX];
int spf[MAX];
void sieve(){
	memset(prime,1,sizeof prime);
	prime[0]=prime[1]=0;
	spf[2]=2;
	for(int i=4;i<MAX;i+=2){
		spf[i]=2;
		prime[i]=0;
	}
	for(ll i=3;i<MAX;i+=2){
		if(prime[i]){
			spf[i]=i;
			for(ll j=i;(j*i)<MAX;j+=2){
				prime[j*i]=0;
				if(!spf[j*i]){
					spf[j*i]=i;
				}
			}
		}
	}
}
ll power(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=res*a;
		}
		a=a*a;
		b=b>>1;
	}
	return res;
}
void presolve(){

}
void solve(){
	
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	presolve();
	int _=1;
	cin>>_;
	while(_--){
		solve();
	}
	return 0;
}

