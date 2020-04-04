#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define ull	unsigned long long int
#define dd	double
#define	 mp	make_pair
#define pb	push_back
#define lli	long long int
#define chota(a)	transform(a.begin(),a.end(),a.begin(),::tolower)
#define speed	ios_base::sync_with_stdio(0)
#define	llmax	1000000000000000000
#define	mod	10
#define	rep(i,n)	for(int i=0;i<n;i++)
#define rep1(i,n)	for(int i=1;i<=n;i++)
#define	distance(a,b,c,d)	(sqrt(((ll)(c-a)*(c-a))+((ll)(d-b)*(d-b))))
#define pure	cout<<fixed<<setprecision(6)
#define hoga	return 0
#define	FF	first
#define	SS	second
#define	all(v)	v.begin(),v.end()
#define boost	cin.tie(0)
#define GCD(x,y)	__gcd(x,y) 
#define kitnabit(x)	__builtin_popcount(x)
#define	tr(s,it)	for(typeof(s.begin())it=s.begin();it!=s.end();++it)
/*#define	isprime(i) (a[i>>1])
#define nonprime(i)	(a[i>>1]=false)
#define ifcmp(x)	(flagarr[x>>6]&(1<<((x>>1)&31)))
#define	iscmp(x)	(flagarr[x>>6]|=(1<<((x>>1)&31)))
*/
/*#define N 	100000
int flag[N>>6];
#define ifcmp(x)	(flag[x>>6]&(1<<((x>>1)&31)))
#define iscmp(x)	(flag[x>>6]|=(1<<((x>>1)&31)))
*/
#define newline	cout<<endl;
#define space " "
#define gc getchar_unlocked
#define dho	fflush(stdout);
const ll MOD=1000000007LL;
 
typedef	pair<int,int> pii;
typedef pair<ll,int>  pli;
typedef pair<ll,ll>   pll;
typedef pair<int,ll>  pil;
 
void swap(int *a,int *b){int temp=*a;*a=*b;*b=temp;}
ull POW(ull p,int b){ull ans=1LL;while(b>0){if(b&1){ans=ans*1LL*p;}b/=2;p=p*1LL*p;}return ans;}
 
ll power(ll a,ll b){ll x=1;ll y=a;while(b>0){if(b&1){x=x*y;x%=mod;}y=y*y;y%=mod;b/=2;}return x;}
lli add(lli a,lli b,lli m=MOD){lli x=a+b;while(x>=m)x-=m;while(x<0)x+=m;return x;}
lli sub(lli a,lli b,lli m=MOD){lli x=a-b;while(x<0)x+=m;while(x>=m)x-=m;return x;}
lli mul(lli a,lli b,lli m=MOD){lli x=a*1ll*b;x%=m;if(x<0)x+=m;return x;}
 
const int N=1e5+2;
ll dist[N];
 
priority_queue<pair<ll,int>,vector< pair<ll,int> >,greater< pair<ll,int> > >q;
vector<pair<pii,int> > g[N];
ll ans=0;
ll prevv=0;
int n,k;
bool visi[N];
map<int,pii> m;
bool used[N];
void dfs(int u,ll value)
{	if(visi[u])return;
	visi[u]=true;
	for(int i=0;i<g[u].size();i++)
	{	int v=g[u][i].first.first;
		ll W=1LL*g[u][i].second;
		int edge=g[u][i].first.second;
		if(used[edge]==false)
		{	int reqd=dist[v]-value;
		    
			if(reqd>=0 &&reqd<=W)
			{	
			    used[edge]=true;
				ans+=W-reqd;
			}
		}
		
		dfs(v,dist[v]);
	}
}
int main()
{	cin>>n>>k;
	for(int i=1;i<=n;i++)dist[i]=1000000000000;
	for(int i=0;i<k;i++)
	{	int x,y,w;
		cin>>x>>y>>w;
		prevv+=1LL*w;
		g[x].pb(mp(mp(y,i),w));
		g[y].pb(mp(mp(x,i),w));
 
		
		
	}
	dist[1]=0;
	q.push(mp(0LL,1));
	pair<ll,int> temp;
	while(!q.empty())
	{	temp=q.top();
		q.pop();
		int u=temp.second;
		ll value=temp.first;
		for(int i=0;i<g[u].size();i++)
		{	int v=g[u][i].first.first;
			ll value2=g[u][i].second;
			if((value+value2)<dist[v])
			{	dist[v]=value+value2;
				q.push(mp(dist[v],v));
			}
		}
	}
	dfs(1,dist[1]);
	
	cout<<prevv-ans<<endl;
}