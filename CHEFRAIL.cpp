#include<bits/stdc++.h>
#define fast_io   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll long long 
#define loop(i,st,en,in)   for(ll i=st;i<=en;i+=in)
#define pb push_back
#define all(something)   something.begin(),something.end()
using namespace std;
int main(){
	fast_io;
	int t;
	cin>>t;
	vector<ll> h(100005,0);
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> xs,ys;
		vector<ll> mpx(100005,0),mnx(100005,0),mpy(100005,0),mny(100005,0);
		bool say1=false,say2=false;
		loop(i,0,n-1,1){
			ll x;
			cin>>x;
			if(x<0){
				mnx[-x]=1;
				xs.pb(x*x);
			}else if(x>0){
				mpx[x]=1;
				xs.pb(x*x);
			}else{
				say1=1;
			}
		}
		loop(i,0,m-1,1){
			ll x;
			cin>>x;
			if(x<0){
				mny[-x]=1;
				ys.pb(x*x);
			}else if(x>0){
				mpy[x]=1;
				ys.pb(x*x);
			}else{
				say2=1;
			}
		}
		ll ans=0;
		
		for(ll i=0;i<(ll)ys.size();i++){
			ll extra=0,cnt=0;
			ll l=sqrt(sqrt(ys[i])),x=sqrt(ys[i]);
			vector<ll> v;
			for(ll i=1;i<=l;i++){
				if(x%i==0){
					v.push_back(i);
					if(i!=x/i){
						v.push_back(x/i);
					}
				}
			}
			vector<ll> vect;
			sort(v.begin(),v.end());
			ll ss=v.size();
			for(ll j=0;j<ss;j++){
				for(ll k=j;k<ss;k++){
					ll tmp=v[j]*v[k];
					if(tmp>100000){
						break;
					}else{
						if(h[tmp]==0){
							h[tmp]=1;
							vect.push_back(tmp);
						}
						ll val=ys[i]/tmp;
						if(val<=100000&&h[val]==0){
							h[val]=1;
							vect.push_back(val);
						}
					}
				}
			}
			for(auto it:vect){
				ll val=ys[i]/it;
				if(val<=100000&&h[(val)]){
					if(it==val){
						if(mpx[it]&&mnx[val]){
							extra++;
						}
						h[it]=0;
					}else{
						if(mpx[it]&&mnx[val]){
							cnt++;
						}
						if(mpx[val]&&mnx[it]){
							cnt++;
						}
					}
				}
				h[it]=0;
			}
			ans+=(cnt)+extra;
		}

		for(ll i=0;i<(ll)xs.size();i++){
			set<ll> st;
			ll extra=0,cnt=0;
			ll l=sqrt(sqrt(xs[i])),x=sqrt(xs[i]);
			vector<ll> v,vect;
			for(ll i=1;i<=l;i++){
				if(x%i==0){
					v.push_back(i);
					if(i!=x/i){
						v.push_back(x/i);
					}
				}
			}
			sort(v.begin(),v.end());
			ll ss=v.size();
			for(ll j=0;j<ss;j++){
				for(ll k=j;k<ss;k++){
					ll tmp=v[j]*v[k];
					if(tmp>100000){
						break;
					}else{
						if(h[tmp]==0){
							h[tmp]=1;
							vect.push_back(tmp);
						}
						ll val=xs[i]/tmp;
						if(val<=100000&&h[val]==0){
							h[val]=1;
							vect.push_back(val);
						}
					}
				}
			}
			for(auto it:vect){
				ll val=xs[i]/it;
				if(val<=100000&&h[(val)]){
					if(it==val){
						if(mpy[it]&&mny[val]){
							extra++;
						}
					}else{
						if(mpy[it]&&mny[val]){
							cnt++;
						}
						if(mpy[val]&&mny[it]){
							cnt++;
						}
					}
				}
				h[it]=0;
			}
			ans+=(cnt)+extra;
		}

		if(say1){
			ans+=(m*(n-1));
		}else if(say2){
			ans+=(n*(m-1));
		}
		cout<<ans<<"\n";
	}
}