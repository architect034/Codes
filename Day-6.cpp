#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1000000007;
ll power(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b%2)
            ans=(ans*a)%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return ans%mod;
}
ll pehla[100005],dusra[100005],DP[100005];
int main(){
    ll n;
    string s;
    char x,y;
    cin>>n>>s>>x>>y;
    for(int i=0;i<(int)s.size();i++){
        if(s[i]==x)
            pehla[i+1] = power(power(2,i+1),mod-2)%mod;
        if(s[i]==y)
            dusra[i+1] = (power(2,i))%mod;
    }
    for(int i=1;i<=n;i++) {
        pehla[i]=(pehla[i]+pehla[i-1])%mod;
        dusra[i]=(dusra[i]+dusra[i-1])%mod;
    }
    DP[0]=0;
    if(x!=y){
        for(int i=1;i<=(int)s.size();i++) {
            DP[i] = DP[i-1];
            if(s[i-1]==y)
                DP[i]=DP[i] + ((pehla[i-1]*power(2,i-1))%mod);
            DP[i]%=mod;
        }
    } else {
        for(int i=1;i<=(int)s.size();i++) {
            DP[i] = DP[i-1];
            if(s[i-1]==y) {
                DP[i]=DP[i] + 1 +((pehla[i-1]*power(2,i-1))%mod);
            }
            DP[i]%=mod;
        }
    }
    cout<<((DP[n]-DP[1]+mod)%mod-(pehla[0]*(dusra[n]-dusra[0]+mod)%mod)%mod)%mod;
}