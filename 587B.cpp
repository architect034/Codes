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
#define rloop(i,start,end,decrement)   for(ll i=start;i>=end;i-=decrement)
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
void precompute(){
	// sieve();
}
void compute(){
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].ff;
		v[i].ss=i;
	}
	sort(all(v));
	reverse(all(v));
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=(v[i].ff*i+1);
	}
	cout<<ans<<"\n";
	for(auto x:v){
		cout<<x.ss+1<<" ";
	}
}
int main(){
	ios_base;
	precompute();
	int _=1;
	// cin>>_;
	while(_--){
		compute();
	}
	return 0;
}
