#include<bits/stdc++.h>
#define ll long long
#define f(i,st,en,in) for(ll i=st;i<=en;i+=in)
#define rf(i,st,en,de) for(ll i=st;i>=en;i-=de)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'
#define all(something) something.begin(),something.end()
#define p(x) printf("%s\n",x)
using namespace std;
const int MAX = 1e7+9;
const ll mod = 1e9+7;
vector<bool> prime(MAX,1);
vector<int> spf(MAX,1);
void sieve(){
   prime[0]=prime[1]=0;
   spf[2]=2;
   f(i,4,MAX-1,2){
      spf[i]=2;
      prime[i]=0;
   }
   f(i,3,MAX-1,2){
      if(prime[i]){
         spf[i]=i;
         f(j,i*i,MAX-1,i){
            prime[j]=0;
            if(spf[j]==1){
               spf[j]=i;
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
void pre(){

}
void solve(){
   int n,m,k;
   cin>>n>>m>>k;
   int ans=n;
   vector<int> v,dp;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      v.pb(x);
      if(i>0){
         dp.pb(v[i]-v[i-1]-1);
      }
   }
   sort(all(dp));
   for(int i=0;i<n-k;i++){
      ans+=dp[i];
   }
   cout<<ans<<"\n";
}
int main(){
   #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
   #endif
   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
   pre();
   int _=1;
   // cin>>_;
   while(_--){
      solve();
   }
   return 0;
}