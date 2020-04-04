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
#define all(sonething) something.begin(),something.end()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define ps(x) cout<<x<<" "
#define pl(x) cout<<x<<endl
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
   int n,q;
   cin>>n>>q;
   vector<int> a(n+1,0),b(n+1,0);
   f(i,1,n,1){
      cin>>a[i];
      a[i]=(a[i]%2+a[i-1]);
   }
   f(i,1,n,1){
      cin>>b[i];
      b[i]=(b[i]%2+b[i-1]);
   }
   while(q--){
      int a1,b1,a2,b2;
      cin>>a1>>b1>>a2>>b2;
      int x1=min(a1,a2),x2=max(a1,a2),y1=min(b1,b2),y2=max(b1,b2);
      if((a[x2]-a[x1-1]==0&&b[y2]-b[y1-1]==0)||(a[x2]-a[x1-1]==x2-x1+1&&b[y2]-b[y1-1]==y2-y1+1)){
         yes;
      }else{
         no;
      }
   }
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