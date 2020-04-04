/*
*architect034
*NIT Silchar<36>
*/
#include<bits/stdc++.h>
using namespace std;
#define fast_io   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define ll	long long
#define ull	unsigned long long
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define fl(i,st,en,in)	for(auto i=st;i<=en;i+=in)
#define rfl(i,st,en,de)	for(auto i=st;i>e=n;i-=de)
#define mp   make_pair
#define FF   first
#define SS   second
#define all(something)   something.begin(),something.end()
const int mod = 1000000007;
const int MAX = 1000001;
void debug(string s){
	cout<<s<<"\n";
}

//SIEVE_START
const int SVE=1000000;
vector<bool> primes(SVE,true);
vector<ll> spf(SVE,0);
void smallest_prime_factors(){
	primes[2]=true;
	spf[2]=2;
	for(ll i=2;i<SVE;i+=2){
		if(i!=2){
			primes[i]=false;
			spf[i]=2;
		}
	}
	for(ll i=3;i<SVE;i+=2){
		if(primes[i]==false)continue;
		spf[i]=i;
		for(ll j=i*i;j<SVE;j+=i){
			if(primes[j]==false){
				continue;
			}
			spf[j]=i;
			primes[j]=false;
		}
	}
}
//SIEVE_END

//calculate hcf of a and b
ll GCD(ll a,ll b){
	ll c=a%b;
	while(c!=0){
		a=b;
		b=c;
		c=a%b;
	}
	return b;
}

//calculate a^b
ll power(ll a,ll b,ll m){
	ll ans=1;
	while(b!=0){
		if(b%2==1)
			ans=(ans*a)%m;
		a=(a*a)%m;
		b=b>>1;
	}
	return ans%m;
}

//string to int conversion
long long string_to_int(string s){
	long long x=0;
	fl(i,0,(int)s.size()-1,1){
		x=x*10+s[i]-'0';
	}
	return x;
}

//int to string 
string int_to_string(int x){
	string s="";
	while(x){
		s=char(x%10+'0')+s;
		x=x/10;
	}
	return s;
}

//finds root of x
int root(int x,int par[]){
	while(x!=par[x]){
		x=par[x];
		par[x]=par[par[x]];
	}
	return x;
}

//does union of x and y
void uni(int x,int y,int par[],int size[]){
	int rx=root(x,par);
	int ry=root(y,par);
	if(rx==ry){
		return;
	}
	else{
		if(size[rx]>=size[ry]){
			size[rx]+=size[ry];
			size[ry]=0;
			par[ry]=rx;
		}
		else{
			size[ry]+=size[rx];
			size[rx]=0;
			par[rx]=ry;
		}
	}
}

//tree node
struct node{
	int data;
	struct node* left;
	struct node* right;
};

//generate new node
struct node* newNode(int data){
	struct node* temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

//inorder traversal
void inOrder(struct node* root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
	
}

//preorder traversal
void preOrder(struct node* root){
	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		
		preOrder(root->right);
	}
	
}

//postorder traversal
void postOrder(struct node* root){
	if(root){
		postOrder(root->left);
		
		postOrder(root->right);
		cout<<root->data<<" ";
	}
	
}

//inserts a value in tree
void insert(int x,struct node* root){
	if(root){
		if(x<root->data){
			if(root->left==NULL){
				cout<<"Inserted "<<x<<" at left of "<<root->data<<"\n";
				root->left=newNode(x);
				return;
			}
			insert(x,root->left);
		}else if(x>=root->data){
			if(root->right==NULL){
				cout<<"Inserted "<<x<<" at right of "<<root->data<<"\n";
				root->right=newNode(x);
				return;
			}
			insert(x,root->right);
		}
	}
}

//calculates height of tree
int heightTree(struct node* root){
	if(root==NULL){
		return 0;
	}else{
		return 1+max(heightTree(root->left),heightTree(root->right));
	}
}
 
//calculate diameter of a tree
int diameterTree(struct node* root){
	if(root==NULL){
		return 0;
	}else{
		int lh=heightTree(root->left);
		int rh=heightTree(root->right);
		int ldd=diameterTree(root->left);
		int rdd=diameterTree(root->right);
		return max(lh+rh+1,max(ldd,rdd));
	}
}

//sum of nodes of a tree
int treeSum(struct node* root){
	if(root->left==NULL&&root->right==NULL){
		return root->data;
	}
 
	root->data=root->data+((root->left)?treeSum(root->left):0)+((root->right)?treeSum(root->right):0);
	return root->data;
}
 
//check if a path with sum exists
bool hasPathWithGivenSum(struct node* root,int sum){
	if(root==NULL){
		if(sum==0){
			return true;
		}else{
			return false;
		}
	}else{
		bool ans=false;
		int remSum=sum-root->data;
		if(remSum==0&&root->left==NULL&&root->right==NULL){
			return true;
		}
		if(root->left){
			ans=ans||hasPathWithGivenSum(root->left,remSum);
		}
		if(root->right){
			ans=ans||hasPathWithGivenSum(root->right,remSum);
		}
		return ans;
	}
}
 
int maxSum=0;
int maximumSumPath(struct node* root){
	if(!root){
		return 0;
	}else{
		int lsum=maximumSumPath(root->left);
		int rsum=maximumSumPath(root->right);
		int ekrasta=max(max(lsum,rsum)+root->data,root->data);	
		int pura=max(ekrasta,lsum+rsum+root->data);
		maxSum=max(maxSum,pura);
		return ekrasta;
	}
}
 
//least commom ancestor
int lca(struct node* root,int a,int b){
	if(root==NULL){
		return 0;
	}else{
		if(root->data==a||root->data==b){
			return root->data;
		}
		int l=lca(root->left,a,b);
		int r=lca(root->right,a,b);
		if(l!=0&&r!=0){
			return root->data;
		}
		if(l==0&&r==0){
			return 0;
		}
		if(l==0){
			return r;
		}
		else{
			return l;
		}
	}
}
map<int,int> m;
void verticalSum(struct node* root,int hd){
	if(root==NULL){
		return;
	}
	else{
		m[hd]+=root->data;
		verticalSum(root->left,hd-1);
		
		verticalSum(root->right,hd+1);
	}
}
 
bool check(ll x,ll a[],ll n,ll k){
	fl(i,n/2,n-1,1){
		if(a[i]<x){
			k=k-(x-a[i]);
		}
	}
	if(k>=0){
		return true;
	}
	return false;
}
int togglebit(int n) 
{ 
	if (n == 0) 
		return 1;
	int i = n;
	n |= n >> 1;
	n |= n >> 2; 
	n |= n >> 4; 
	n |= n >> 8; 
	n |= n >> 16; 
	// n |= n >> 32;
 
	return i ^ n; 
}
int xnor(int num1, int num2) 
{ 
	if (num1 < num2) 
		swap(num1, num2); 
	num1 = togglebit(num1); 
	return num1 ^ num2; 
}

int dp2d[9999][101]; 
string tt;

bool solvve(string s,int n){
	if(n==0){
		if(string_to_int(s)>string_to_int(tt)){
			return 1;
		}else{
			return 0;
		}
	}
	int z=string_to_int(s);
	if(dp2d[z][n]!=-1){
		return dp2d[z][n];
	}
	bool ans=0;
	if(n%2==1){
		ans=1;
	}
	string ss=s;
	string a=ss,b=ss,c=ss,d=ss;
	a[0]=a[0]+1;b[1]=b[1]+1;c[2]=c[2]+1;d[3]=d[3]+1;
	if(ss[0]=='9')a[0]=0;
	if(ss[1]=='9')b[1]=0;
	if(ss[2]=='9')c[2]=0;
	if(ss[3]=='9')d[3]=0;
	if(n%2==0){
		ans=ans||(solvve(a,n-1)||solvve(b,n-1)||solvve(c,n-1)||solvve(d,n-1));
	}
	else{
		ans=ans&&(solvve(a,n-1)&&solvve(b,n-1)&&solvve(c,n-1)&&solvve(d,n-1));	
	}
	dp2d[z][n]=ans;
	return ans;
	
}
vector<string> vs;

//number of binary strings of length n such that no 1's are consecutive
void number_of_binary_strings(int n,string s){
	if((int)s.size()==n){
		vs.pb(s);
		return;
	}
	if(s.size()==0){
		number_of_binary_strings(n,s+'1');
		number_of_binary_strings(n,s+'0');
	}
	if(s.back()=='0'){
		number_of_binary_strings(n,s+'1');
		number_of_binary_strings(n,s+'0');
	}else{
		number_of_binary_strings(n,s+'0');
	}
}

//generate all combinations of balances brackets
void genbrackets(int op,int cl,int pos,int n){
	static char s[100];
	if(cl==n){
		cout<<s<<"\n";
		return;
	}
	if(op>cl){
		s[pos]=')';
		genbrackets(op,cl+1,pos+1,n);
	}
	if(op<n){
		s[pos]='(';
		genbrackets(op+1,cl,pos+1,n);
	}
}


int coinsways_recursion(vector<int> &v,int n,int sum){
	if(sum==0){
		return dp2d[n][sum]=1;
	}
	if(n==0){
		return dp2d[n][sum]=0;
	}
	if(dp2d[n][sum]!=-1){
		return dp2d[n][sum];
	}
	if(sum>=v[n-1])
		return dp2d[n][sum]=coinsways_recursion(v,n,sum-v[n-1])+coinsways_recursion(v,n-1,sum);
	else
		return dp2d[n][sum]=coinsways_recursion(v,n-1,sum);
}

//maximum diff between two numbers such that bigger no. is at higher index
int max_diff(int a[],int n){
	int mm=a[0];
	int ans=0;
	for(int i=0;i<n;i++){
		mm=min(mm,a[i]);
		ans=max(ans,a[i]-mm);
		cout<<a[i]-mm<<" ";
	}
	cout<<"\n";
	return ans;
}
vector<int> KMP(string s,string t){
	int n1=s.size();
	int n2=t.size();

	//longest prefix and suffix
	int lps[n2];
	lps[0]=0;
	int i=0,j=1;
	while(j<n2){
		if(s[j]==s[i]){
			i++;
			lps[j++]=i;
		}else{
			if(i>0){
				i=lps[i-1];
			}else{
				lps[j++]=0	;
			}
		}
	}

	//string matching
	vector<int> indexes;
	for(int i=0,j=0;i<n1;){
		if(s[i]==t[j]){
			i++;
			j++;
		}
		if(j==n2){
			indexes.pb(i-n2);
			cout<<i-n2<<" ";
			j=lps[j-1];
		}else if(i<n1&&t[j]!=s[i]){
			if(j>0){
				j=lps[j-1];
			}else{
				i++;
			}
		}
	}
	return indexes;

}
int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		int n,p,k;
		cin>>n>>p>>k;
		vector<int> a(n+1,0);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(all(a));
		int ans=0;
		for(int i=1;i<=n;i++){
			if(i<k){
				a[i]=a[i-1]+a[i];
			}else if(i>=k){
				a[i]=a[i]+a[i-k];
			}
			if(a[i]<=p){
				ans=i;
			}
		}
		cout<<ans<<"\n";
	}
	// int n,k;
	// cin>>n>>k;
	// string s;
	// cin>>s;
	// string t;
	// vector<int> v(n);
	// for(int i=0;i<n;i++){
	// 	t+=s[i%k];
	// 	v[i]=s[i]-'0';
	// }
	// if(t<s){
	// 	// debug("chota hua hai");
	// 	v[k-1]++;
	// }
	// for(int i=k-1;i>0;i--){
	// 	if(v[i]>9){
	// 		v[i]=0;
	// 		v[i-1]++;
	// 		// cout<<"aya!";
	// 	}else{
	// 		break;
	// 	}
	// }
	// for(int i=0;i<k;i++){
	// 	for(int j=i;j<n;j+=k){
	// 		// debug("updating");
	// 		v[j]=v[i];
	// 	}
	// }
	// cout<<n<<"\n";
	// for(int i=0;i<n;i++){
	// 	cout<<v[i%k];
	// }
	// ll n,m;
	// cin>>n>>m;
	// ll a[n],b[n];
	// ll aa=0,bb=0;
	// for(ll i=0;i<n;i++){
	// 	cin>>a[i];
	// 	aa+=a[i];
	// 	// aa=aa%m;
	// }

	// for(ll i=0;i<n;i++){
	// 	cin>>b[i];
	// 	bb+=b[i];
	// 	// bb=bb%m;
	// }
	// ll ans=(bb-aa+m)%m;
	// cout<<ans<<"\n";
	// // ll pp=power(n,(m-2+m)%m,m);
	// // ans=(ans*pp)%m;
	// ans=ans/n;
	// cout<<ans;

	// int n;
	// cin>>n;
	// cout<<9*n<<" "<<8*n;
	// int n,x,y;
	// cin>>n>>x>>y;
	// int l=0,r=0,u=0,d=0;
	// for(int i=0;i<n;i++){
	// 	int xx,yy;
	// 	cin>>xx>>yy;
	// 	if(xx<x){
	// 		l++;
	// 	}
	// 	if(xx>x){
	// 		r++;
	// 	}
	// 	if(yy>y){
	// 		u++;
	// 	}
	// 	if(yy<y){
	// 		d++;
	// 	}
	// }
	// if(l>=r&&l>=u&&l>=d){
	// 	cout<<l<<"\n";
	// 	cout<<x-1<<" "<<y;
	// 	return 0;
	// }
	// if(r>=l&&r>=u&&r>=d){
	// 	cout<<r<<"\n";
	// 	cout<<x+1<<" "<<y;
	// 	return 0;
	// }
	// if(u>=l&&u>=r&&u>=d){
	// 	cout<<u<<"\n";
	// 	cout<<x<<" "<<y+1;
	// 	return 0;
	// }
	// if(d>=r&&d>=l&&d>=u){
	// 	cout<<d<<"\n";
	// 	cout<<x<<" "<<y-1;
	// 	return 0;
	// }
	// int n;
	// cin>>n;
	// string s,ss;
	// cin>>s;
	// ss=s;
	// vector<int> v1,v2;
	// for(int i=0;i<n-1;i++){
	// 	if(s[i]=='B'){
	// 		v1.pb(i+1);
	// 		s[i]='W';
	// 		if(s[i+1]=='B')s[i+1]='W';
	// 		else s[i+1]='B';
	// 	}
	// 	if(ss[i]=='W'){
	// 		ss[i]='B';
	// 		v2.pb(i+1);
	// 		if(ss[i+1]=='B')ss[i+1]='W';
	// 		else ss[i+1]='B';
	// 	}
	// }
	// // cout<<s<<" "<<ss<<"\n";
	// set<char> st,sts;
	// for(int i=0;i<n;i++){
	// 	st.insert(s[i]);
	// 	sts.insert(ss[i]);
	// }
	// if(st.size()==1){
	// 	cout<<v1.size()<<"\n";
	// 	for(auto x:v1){
	// 		cout<<x<<" ";
	// 	}
	// 	return 0;
	// }
	// if(sts.size()==1){
	// 	cout<<v2.size()<<"\n";
	// 	for(auto x:v2){
	// 		cout<<x<<" ";
	// 	}
	// 	return 0;
	// }
	// cout<<-1;
	// string s,t;
	// cin>>s>>t;
	// vector<int> ans=KMP(s,t);
	
	// int n;
	// cin>>n;
	// int a[n];
	// for(int i=0;i<n;i++){
	// 	cin>>a[i];
	// }
	// cout<<max_diff(a,n);
	// int t;
	// cin>>t;
	// while(t--){
	// 	int n,r,ans=0;
	// 	cin>>n>>r;
	// 	vector<int> v;
	// 	map<int,int> hash;
	// 	for(int i=0;i<n;i++){
	// 		int x;
	// 		cin>>x;
	// 		if(hash[x]==0){
	// 			v.pb(x);
	// 			hash[x]++;
	// 		}
	// 	}
	// 	n=v.size();
	// 	sort(all(v));
		
	// 	for(int i=0;i<n;i++){
	// 		v.at(n-1-i)-=(r*i);
	// 		if(v.at(n-1-i)>0){
	// 			ans++;
	// 		}
	// 	}
	// 	cout<<ans<<"\n";
	// }
	// int n;
	// cin>>n;
	// vector<pair<int,int> > v(n);
	// for(int i=0;i<n;i++){
	// 	cin>>v[i].FF;
	// 	v[i].SS=-i;
	// }
	// sort(all(v));
	// int m;
	// cin>>m;
	// while(m--){
	// 	int k,p;
	// 	cin>>k>>p;
	// 	vector<pair<int,int> > ans;
	// 	for(int i=n-1;i>=n-k;i--){
	// 		ans.pb(mp(-v[i].SS,v[i].FF));
	// 	}
	// 	sort(all(ans));
	// 	cout<<ans[p-1].SS<<"\n";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	int n;
	// 	cin>>n;
	// 	vector<int> v(n);
	// 	for(int i=0;i<n;i++){
	// 		cin>>v[i];
	// 	}
	// 	vector<bool> p(n+1,false);
	// 	int pos=1;
	// 	bool say=true;
	// 	vector<int> ans;
	// 	for(int i=0;i<n;i++){
	// 		if(i==0){
	// 			ans.pb(v[i]);
	// 			p[v[i]]=true;
	// 		}else{
	// 			if(p[v[i]]==false){
	// 				ans.pb(v[i]);
	// 				p[v[i]]=true;
	// 				continue;
	// 			}
	// 			while(p[pos]==true){
	// 				pos++;
	// 			}
	// 			if(pos>v[i]){
	// 				say=false;
	// 				break;
	// 			}else{
	// 				ans.pb(pos);
	// 				p[pos]=true;
	// 			}
	// 		}
	// 	}
	// 	if(say==false){
	// 		cout<<-1<<"\n";
	// 		continue;
	// 	}
	// 	for(auto x:ans){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// int n,m,d;
	// cin>>n>>m>>d;
	// vector<int> v(m+1);
	// int sum=0;
	// for(int i=0;i<m;i++){
	// 	cin>>v[i+1];
	// 	sum+=v[i+1];
	// }
	// int dd=((m+1)*(d-1))+sum;
	// if(dd<n){
	// 	cout<<"NO\n";
	// 	// cout<<-1<<"\n";
	// 	return 0;
	// }
	// int extra=n-sum;
	// vector<int> ans(n);
	// int idx=0,pos=1;
	// while(extra>0){
	// 	int x=min(extra,d-1);
	// 	for(int i=idx+x,cnt=0;cnt<v[pos];cnt++,i++){
	// 		ans[i]=pos;
	// 		idx=i;
	// 	}
	// 	idx++;
	// 	pos++;
	// 	// cout<<pos<<" POS\n";
	// 	extra-=min(extra,d-1);
	// }
	// // cout<<pos<<" pos\n";
	// for(int i=pos;i<=m;i++){
	// 	for(int j=idx,cnt=0;cnt<v[pos]&&j<n;cnt++,j++){
	// 		ans[i]=i;
	// 	}
	// }
	// cout<<"YES\n";
	// for(int i=0;i<n;i++){
	// 	cout<<ans[i]<<" ";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll n,k;
	// 	cin>>n>>k;
	// 	char s[MAX];
	// 	for(ll i=0;i<n;i++){
	// 		cin>>s[i];
	// 	}
	// 	ll zidx=-1,oidx=-1;
	// 	for(ll i=0;i<n;i++){
	// 		if(s[i]=='1'){
	// 			oidx=i;
	// 			break;
	// 		}
	// 	}
	// 	for(ll i=max((ll)0,oidx);i<n;i++){
	// 		if(s[i]=='0'){
	// 			zidx=i;
	// 			break;
	// 		}
	// 	}
	// 	while(k>0){
	// 		if(zidx==-1||oidx==-1){
	// 			break;
	// 		}
	// 		if(zidx-oidx<=k){
	// 			s[zidx]='1';
	// 			s[oidx]='0';
	// 			k=k-(zidx-oidx);
	// 			oidx++;
	// 			if(oidx==(n-1)){
	// 				break;
	// 			}
	// 		}

	// 		else{
	// 			ll idx=zidx;
	// 			for(ll i=zidx-1,cnt=0;i>=0&&cnt<k;i--,cnt++){
	// 				if(s[i]=='1'){
	// 					idx=i;
	// 				}
	// 			}
	// 			s[idx]='0';
	// 			s[zidx]='1';
	// 			break;
	// 		}
	// 		if(zidx==(n-1)){
	// 			break;
	// 		}
	// 		bool say=false;
	// 		for(ll i=zidx;i<n;i++){
	// 			if(s[i]=='0'){
	// 				say=true;
	// 				zidx=i;
	// 				break;
	// 			}
	// 		}
	// 		if(say==false){
	// 			break;
	// 		}
	// 	}
	// 	for(ll i=0;i<n;i++){
	// 		cout<<s[i];
	// 	}
	// 	cout<<"\n";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	int n;
	// 	cin>>n;
	// 	vector<int> v(n+1);
	// 	for(int i=1;i<=n;i++){
	// 		cin>>v[i];
	// 	}
	// 	vector<int> arr(n+1,0);
	// 	int m;
	// 	cin>>m;
	// 	for(int i=0;i<m;i++){
	// 		int p,s;
	// 		cin>>p>>s;
	// 		arr[s]=max(p,arr[s]);
	// 	}
	// 	for(int i=n-1;i>=1;i--){
	// 		arr[i]=max(arr[i],arr[i+1]);
	// 	}
	// 	int idx=0,ans=1,bada=0;
	// 	bool say=true;
	// 	for(int i=1;i<=n;i++){
	// 		bada=max(bada,v[i]);
	// 		if(bada>arr[1]){
	// 			// cout<<bada<<" bada\n";
	// 			cout<<-1<<"\n";
	// 			say=false;
	// 			break;
	// 		}
	// 		if(bada>arr[i-idx]){
	// 			ans++;
	// 			idx=i-1;
	// 			bada=v[i];
	// 		}
	// 	}
	// 	if(say){
	// 		cout<<ans<<"\n";
	// 	}
	// }
	// int n1,n2,n3,x;
	// cin>>n1>>n2>>n3;
	// int n=n1+n2+n3;
	// vector<int> v(n+1);
	// fl(i,0,n1-1,1){
	// 	cin>>x;
	// 	v[x]=1;
	// }
	// fl(i,0,n2-1,1){
	// 	cin>>x;
	// 	v[x]=2;
	// }
	// fl(i,0,n3-1,1){
	// 	cin>>x;
	// 	v[x]=3;
	// }
	// int dp[4][n+1];
	// memset(dp,0,sizeof(dp));
	// for(int i=1;i<=n;i++){
	// 	dp[1][i]=dp[1][i-1]+(v[i]==1?0:1);
	// 	dp[2][i]=min(dp[2][i-1],dp[1][i-1])+(v[i]==2?0:1);
	// 	dp[3][i]=min(dp[3][i-1],min(dp[2][i-1],dp[1][i-1]))+(v[i]==3?0:1);
	// }
	// // for(int i=1;i<=3;i++){
	// // 	for(int j=1;j<=n;j++){
	// // 		cout<<dp[i][j]<<" ";
	// // 	}
	// // 	cout<<"\n";
	// // }
	// cout<<min(dp[1][n],min(dp[2][n],dp[3][n]));
	// int n,m;
	// cin>>n>>m;
	// int a[n][m];
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		cin>>a[i][j];
	// 	}
	// }
	// int dp[n][m];
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		dp[i][j]=INT_MAX;
	// 	}
	// }
	// dp[0][0]=a[0][0];
	// set<pair<int,pair<int,int> > > s;
	// s.insert(mp(a[0][0],mp(0,0)));
	// while(s.empty()==0){
	// 	auto it=s.begin();
	// 	int w=(*it).FF,x=(*it).SS.FF,y=(*it).SS.SS;
	// 	s.erase(s.begin());
	// 	if(x-1>=0&&dp[x-1][y]>w+a[x-1][y]){
	// 		dp[x-1][y]=w+a[x-1][y];
	// 		s.insert(mp(dp[x-1][y],mp(x-1,y)));
	// 	}
	// 	if(y-1>=0&&dp[x][y-1]>w+a[x][y-1]){
	// 		dp[x][y-1]=w+a[x][y-1];
	// 		s.insert(mp(dp[x][y-1],mp(x,y-1)));
	// 	}
	// 	if(x+1<n&&dp[x+1][y]>w+a[x+1][y]){
	// 		dp[x+1][y]=w+a[x+1][y];
	// 		s.insert(mp(dp[x+1][y],mp(x+1,y)));
	// 	}
	// 	if(y+1<m&&dp[x][y+1]>w+a[x][y+1]){
	// 		dp[x][y+1]=w+a[x][y+1];
	// 		s.insert(mp(dp[x][y+1],mp(x,y+1)));
	// 	}
	// }
	// cout<<dp[n-1][m-1];
	// int t;
	// cin>>t;
	// while(t--){
	// 	int n;
	// 	cin>>n;
	// 	int ans=INT_MAX;
	// 	vector<int> v(n),hash(n+1,-1);
	// 	for(int i=0;i<n;i++){
	// 		cin>>v[i];
	// 		if(hash[v[i]]==-1){
	// 			hash[v[i]]=i;
	// 		}else{
	// 			ans=min(ans,i-hash[v[i]]+1);
	// 			hash[v[i]]=i;
	// 		}
	// 	}
	// 	if(ans==INT_MAX){
	// 		cout<<-1;
	// 	}else{
	// 		cout<<ans;
	// 	}
	// 	cout<<"\n";
	// }
	       //Ways of coins change
	// memset(dp2d,-1,sizeof(dp2d));
	// int n;
	// cin>>n;
	// int sum;
	// cin>>sum;
	// vector<int> v(n);
	// fl(i,0,n-1,1){
	// 	cin>>v[i];
	// }
	
	// int ans=coinsways_recursion(v,n,sum);
	// for(int i=0;i<=n;i++){
	// 	for(int j=0;j<=sum;j++){
	// 		cout<<dp2d[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
		//binary strings of length n with no 1 tog
	// int n;
	// cin>>n;
	// string s="";
	// number_of_binary_strings(n,s);
	// for(int i=0;i<(int)v.size();i++){
	// 	cout<<v[i]<<" ";
	// }
	// int n;
	// cin>>n;
	// genbrackets(0,0,0,n);
	// int t;
	// cin>>t;
	// while(t--){
	// 	int n,m;
	// 	cin>>n>>m;
	// 	vector<int> v(n);
	// 	vector<pair<int,int> > ans(n);
	// 	fl(i,0,n-1,1){
	// 		cin>>v[i];
	// 		ans[i].FF=v[i];
	// 	}
		

	// 	for(int i=0;i<m;i++){
	// 		for(int j=i;j<n;j+=m){
	// 			ans[j].SS=i;
	// 		}
	// 	}
	// 	sort(all(ans));
	// 	int out = 1e18;
 //        int j = 0;
 //        int unique = 0;
 //        map<int,int> mapp;
 //        for(int i=0;i<ans.size();i++){
 //            while(j < ans.size() && unique < m){
 //                mapp[ans[j].second]++;
 //                if(mapp[ans[j].second] == 1){
 //                    unique++;
 //                }
 //                j++;
 //            }
 //            if(unique == m){
 //                //cerr<<i<<" "<<j<<endl;
 //                out = min(out,ans[j-1].first - ans[i].first);
 //            }
 //            mapp[ans[i].second]--;
 //            if(mapp[ans[i].second] == 0){
 //                unique--;
 //            }
 //        }
 //        cout<<out<<"\n";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	string s;
	// 	memset(dp2d,-1,sizeof(dp2d));
	// 	int n;
	// 	cin>>s;
	// 	tt=s;
	// 	cin>>n;
	// 	solve(s,n);
	// 	if(dp2d[change(tt)][n]){
	// 		cout<<"Ada\n";
	// 	}else{
	// 		cout<<"Vinit\n";
	// 	}
	// }
	//~ struct node* root=newNode(49);
	//~ int a[11]={37,89,13,41,53,7,19,71,25,60,82};
	//~ for(int i=0;i<11;i++){
		//~ insert(a[i],root);
	//~ }
	//~ cout<<"\nInOrder Traversal : ";
	//~ inOrder(root);
	//~ cout<<"\nPreOrder Traversal : ";
	//~ preOrder(root);
	//~ cout<<"\nPostOrder Traversal : ";
	//~ postOrder(root);
	//~ treeSum(root);
	//~ cout<<"\nInOrder Traversal tree sum : ";
	//~ inOrder(root);
	//~ cout<<"\nPreOrder Traversal tree sum : ";
	//~ preOrder(root);
	//~ cout<<"\nPostOrder Traversal tree sum : ";
	//~ postOrder(root);
	//~ cout<<"\n"<<heightTree(root);
	//~ cout<<"\n Maximum Path sum : "<<maximumSumPath(root);
	
	//~ cout<<"\nDiameter of a tree : "<<diameterTree(root);
	//~ cout<<"\nHas Path with Sum : "<<hasPathWithGivenSum(root,143);	
	//~ cout<<"\nLCA of 25 and 60 is : "<<lca(root,25,60);
	
	//~ verticalSum(root,0);
	//~ for(auto it=m.begin();it!=m.end();++it){
		//~ cout<<it->FF<<" "<<it->SS<<"\n";
	//~ }
	// ll n,k;
	// cin>>n>>k;
	// ll a[n];
	// for(ll i=0;i<n;i++){
	// 	cin>>a[i];
	// }
	// sort(a,a+n);
	// ll low=a[n/2],ans=a[n/2],high=1e10+1;
	// while(low<=high){
	// 	ll mid=(low+high)/2;
	// 	if(check(mid,a,n,k)){
	// 		ans=mid;
	// 		low=mid+1;
	// 	}else{
	// 		high=mid-1;
	// 	}
	// }
	// cout<<ans<<"\n";
	// fl(i,0,100,1){
	// 	cout<<i<<" ";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll n;
	// 	cin>>n;
	// 	ll sum=0;
	// 	fl(i,1,n,1){
	// 		sum+=(n-i);
	// 	}
	// 	ll mul=1;
	// 	fl(i,1,n,1){
	// 		mul=mul*i;
	// 	}
	// 	cout<<mul*sum<<"\n";
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll a,b,n;
	// 	cin>>a>>b>>n;
	// 	ll x=a^b;
	// 	ll xn=xnor(a,b);
	// 	ll ar[3]={a,b};
	// 	if(n%3!=0){
	// 		cout<<ar[n%3-1]<<"\n";
	// 	}else{
	// 		cout<<max(x,xn)<<"\n";
	// 	}
	// }
	// ll n;
	// cin>>n;
	// vector<int> v(n);
	// fl(i,0,n-1,1){
	// 	cin>>v[i];
	// }
	// sort(all(v));
	// ll i=0,j=n-1;
	// ll vv=0,h=0;
	// while(1){
	// 	vv+=v[j];
	// 	if(i==j){
	// 		break;
	// 	}
	// 	if(i+1==j){
	// 		h+=v[i];
	// 		break;
	// 	}
	// 	h+=v[i];
	// 	i++;j--;
	// }
	// cout<<h*h+vv*vv;
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll n;
	// 	cin>>n;
	// 	ll p[n];
	// 	int pe=0,po=0;
	// 	for(ll i=0;i<n;i++){
	// 		cin>>p[i];
	// 		if(p[i]%2==0){
	// 			pe++;
	// 		}else{
	// 			po++;
	// 		}
	// 	}
	// 	ll m;
	// 	cin>>m;
	// 	ll q[m];
	// 	ll ans=0;
	// 	for(ll i=0;i<m;i++){
	// 		cin>>q[i];
	// 		if(q[i]%2==0){
	// 			ans+=pe;
	// 		}else{
	// 			ans+=po;
	// 		}
	// 	}
	// 	cout<<ans<<"\n";
	// }
	// ll dp[100000001];
	// dp[2]=1;
	// for(ll i=3;i<100000001;i++){
	// 	dp[i]=(dp[i-1]*(i-1))%i;
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll n;
	// 	cin>>n;
	// 	int cnt=0;
	// 	fl(i,0,n-1,1){
	// 		int x;
	// 		cin>>x;
	// 		if(dp[x]==(x-1)){
	// 			cnt++;
	// 		}
	// 	}
	// 	cout<<cnt<<"\n";
	// }
	// int n,q;
	// cin>>n>>q;
	// vector<int> v(n);
	// fl(i,0,n-1,1){
	// 	cin>>v[i];
	// }
	// vector<int> diff;
	// for(int i=0;i<n-1;i++){
	// 	diff.pb(v[i+1]-v[i]);
	// 	// cout<<v[i+1]-v[i]<<" ";
	// }
	// // cout<<"\n";
	// vector<vector<pair<int,int> > >neg(200001),pos(200001);
	// int prev=0,curr=0;
	// for(int i=0;i<(int)diff.size();i++){
	// 	curr=i;
	// 	if(diff[curr]==diff[prev]){
	// 		continue;
	// 	}else{
	// 		if(diff[curr-1]<0){
	// 			neg[abs(diff[curr-1])].pb(mp(prev,curr));
	// 			// cout<<"neg -> "<<prev<<" "<<curr<<"\n";
	// 			// i=curr-1;
	// 			prev=curr;
	// 		}else{
	// 			pos[abs(diff[curr-1])].pb(mp(prev,curr));
	// 			// cout<<"pos -> "<<prev<<" "<<curr<<"\n";
	// 			// i=curr-1;
	// 			prev=curr;
	// 		}
	// 	}
	// }
	// if(diff[curr]<0){
	// 	neg[abs(diff[curr-1])].pb(mp(prev,curr+1));
	// 	// cout<<"neg -> "<<prev<<" "<<curr+1<<"\n";
	// }else{
	// 	pos[abs(diff[curr-1])].pb(mp(prev,curr+1));
	// 	// cout<<"pos -> "<<prev<<" "<<curr+1<<"\n";
	// }
	// // for(int i=0;i<200000;i++){
	// // 	if(pos[i].size()>0){
	// // 		cout<<"Diff = "<<i<<" -> ";
	// // 		for(int j=0;j<(int)pos[i].size();j++){
	// // 			cout<<pos[i][j].FF<<" "<<pos[i][j].SS<<" | ";
	// // 		}
	// // 		cout<<"\n\n";
	// // 	}
	// // }
	// // for(int i=0;i<200000;i++){
	// // 	if(neg[i].size()>0){
	// // 		cout<<"Diff = "<<-i<<" -> ";
	// // 		for(int j=0;j<(int)neg[i].size();j++){
	// // 			cout<<neg[i][j].FF<<" "<<neg[i][j].SS<<" | ";
	// // 		}
	// // 		cout<<"\n\n";
	// // 	}
	// // }
	// while(q--){
	// 	int l,r,d;
	// 	cin>>l>>r>>d;
	// 	l--;r--;
	// 	if(d>=0){
	// 		if(pos[d].size()>0){
	// 			// int low=0,high=pos[d].size()-1,ans=pos[d].size();
	// 			// while(low<=high){
	// 			// 	int mid=(low+high)/2;
	// 			// 	if(pos[d][mid].SS>=l){
	// 			// 		ans=mid;
	// 			// 		high=mid-1;
	// 			// 	}else{
	// 			// 		low=mid+1;
	// 			// 	}
	// 			// }
	// 			// cout<<ans<<" ans\n";
	// 			int out=0;
	// 			// for(int i=ans;i<(int)pos[d].size()&&pos[d][i].FF<=r;i++){
	// 			// 	// cout<<"AYA\n";
	// 			// 	out=max(out,(min(pos[d][i].SS,r)-max(pos[d][i].FF,l)));
	// 			// }
	// 			for(int i=0;i<(int)pos[d].size();i++){
	// 				if(pos[d][i].FF<=r){
	// 					int st=max(pos[d][i].FF,l);
	// 					int en=min(pos[d][i].SS,r);
	// 					out=max(out,(en-st));
	// 				}
	// 			}
	// 			cout<<out+1<<"\n";
	// 		}else{
	// 			cout<<1<<"\n";
	// 		}
	// 	}else{
	// 		d=abs(d);
	// 		if(neg[d].size()>0){
	// 			// int low=0,high=neg[d].size()-1,ans=neg[d].size();
	// 			// while(low<=high){
	// 			// 	int mid=(low+high)/2;
	// 			// 	if(neg[d][mid].SS>=l){
	// 			// 		ans=mid;
	// 			// 		high=mid-1;
	// 			// 	}else{
	// 			// 		low=mid+1;
	// 			// 	}
	// 			// }
	// 			// cout<<ans<<" ans\n";
	// 			int out=0;
	// 			// for(int i=ans;i<(int)neg[d].size()&&neg[d][i].FF<=r;i++){
	// 			// 	// cout<<"AYA\n";
	// 			// 	out=max(out,(min(neg[d][i].SS,r)-max(neg[d][i].FF,l)));
	// 			// }
	// 			for(int i=0;i<(int)neg[d].size();i++){
	// 				if(neg[d][i].FF<=r){
	// 					int st=max(neg[d][i].FF,l);
	// 					int en=min(neg[d][i].SS,r);
	// 					out=max(out,(en-st));
	// 				}
	// 			}
	// 			cout<<out+1<<"\n";
	// 		}else{
	// 			cout<<1<<"\n";
	// 		}
	// 	}
	// }
	// int t;
	// cin>>t;
	// while(t--){
		// int n;
		// cin>>n;
		// vector<int> v(n+1),dp(n+1,1),reached(n+1,0);
		// fl(i,0,n-1,1){
		// 	cin>>v[i+1];
		// }
		// for(int i=1;i<=n;i++){
		// 	if(v[i]==i){
		// 		dp[i]=1;
		// 	}else{
		// 		if(reached[i]==1){
		// 			continue;
		// 		}
		// 		int cnt=1;
		// 		int j=i;
		// 		j=v[i];
		// 		while(j!=i){
		// 			j=v[j];
		// 			cnt++;
		// 		}
		// 		j=v[i];
		// 		while(j!=i){
		// 			j=v[j];
		// 			dp[j]=cnt;
		// 			reached[j]=1;
		// 		}
		// 		// cout<<cnt<<"\n";
		// 	}
		// }
		// for(int i=1;i<=n;i++){
		// 	cout<<dp[i]<<" ";
		// }
		// cout<<"\n";
		// fl(i,0,n-1,1){
		// 	cin>>v[i];
		// }
		// sort(all(v));
		// bool say=false;
		// for(int i=1;i<n;i++){
		// 	if(v[i]-v[i-1]==1){
		// 		say=true;
		// 		break;
		// 	}
		// }
		// if(say){
		// 	cout<<2<<"\n";
		// }else{
		// 	cout<<1<<"\n";
		// }
	// }
	// int t;
	// cin>>t;
	// while(t--){
	// 	ll n;
	// 	cin>>n;
	// 	deque<ll> d;
	// 	ll ans=n;
	// 	while(n){
	// 		d.pf(n%3);
	// 		n=n/3;
	// 	}
	// 	bool twohai=false;
	// 	for(auto x:d){
	// 		if(x==2){
	// 			twohai=true;
	// 			break;
	// 		}
	// 	}
	// 	if(twohai==false){
	// 		cout<<ans<<"\n";
	// 		continue;
	// 	}
	// 	ll tc=0,idx=-1;
	// 	for(int i=(ll)d.size()-1;i>=0;i--){
	// 		if(d[i]==2){
	// 			tc++;
	// 			idx=-1;
	// 		}else if(d[i]==0){
	// 			if(tc>0){
	// 				idx=i;
	// 				tc=0;
	// 			}
	// 		}
	// 	}
	// 	if(idx==-1){
	// 		cout<<power(3,(ll)d.size())<<"\n";
	// 	}else{
	// 		d[idx]=1;
	// 		for(ll i=idx+1;i<(ll)d.size();i++){
	// 			d[i]=0;
	// 		}
	// 		ans=0;
	// 		ll k=(ll)d.size();
	// 		for(ll i=(ll)d.size()-1;i>=0;i--){
	// 			ans=ans+d[i]*power(3,k-1-i);
	// 		}
	// 		cout<<ans<<"\n";
	// 	}
	// }
	// int n,p;
	// cin>>n>>p;
	// vector<int> st(n),ele(n);
	// for(int i=0;i<n-1;i++){
	// 	cin>>st[i];
	// }
	// for(int i=0;i<n-1;i++){
	// 	cin>>ele[i];
	// }
	// vector<int> dp1(n,mod),dp2(n,mod);
	// dp1[0]=0;
	// dp2[0]=p;
	// for(int i=0;i<n-1;i++){
	// 	dp1[i+1]=min(dp1[i+1],dp1[i]+st[i]);
	// 	dp1[i+1]=min(dp1[i+1],dp2[i]+st[i]);
	// 	dp2[i+1]=min(dp2[i+1],dp2[i]+ele[i]);
	// 	dp2[i+1]=min(dp2[i+1],dp1[i]+ele[i]+p);
	// }
	// fl(i,0,n-1,1){
	// 	cout<<min(dp1[i],dp2[i])<<" ";
	// }
	// cout<<"\n";
// 	int n,k,nn;
// 	cin>>n>>k;
// 	nn=n;
// 	if(n==k){
// 		cout<<"Yes\n";
// 		for(int i=1;i<=n;i++){
// 			cout<<i<<" ";
// 		}
// 		return 0;
// 	}
// 	if(k==1){
// 		if(n==1){
// 			cout<<"Yes\n1";
// 			return 0;
// 		}else{
// 			cout<<"No\n";
// 			return 0;
// 		}
// 	}
// 	if(k>2){
// 		n=n-k+1;
// 	}
// 	deque<deque<int> > v1,v2;
// 	deque<int> a;
// 	for(int i=0;i<n;i+=2){
// 		a.pb(i+1);
// 	}
// 	deque<int> tmp;
// 	for(int i=0;i<(int)a.size();i+=1){
// 		tmp.pb(a[i]);
// 	}
// 	v1.pb(tmp);
// 	while(1){
// 		if(v1[0].size()>2){
// 			deque<int> t1,t2;
// 			for(int i=0;i<(int)v1[0].size();i+=2){
// 				t1.pb(v1[0][i]);
// 			}
// 			for(int i=1;i<(int)v1[0].size();i+=2){
// 				t2.pb(v1[0][i]);
// 			}
// 			v1.popf();
// 			v1.pb(t1);
// 			v1.pb(t2);
// 		}else{
// 			if(v1[0][0]!=1){
// 				v1.pb(v1[0]);
// 				v1.popf();
// 			}else{
// 				break;
// 			}
// 		}
// 	}
// 	a.clear();
// 	for(int i=1;i<n;i+=2){
// 		a.pb(i+1);
// 	}
// 	tmp.clear();
// 	for(int i=0;i<(int)a.size();i+=1){
// 		tmp.pb(a[i]);
// 	}
// 	v2.pb(tmp);
// 	cout<<"Yes\n";
// 	if(nn%2!=k%2&&k!=2){
// 		for(int i=nn,cnt=0;cnt<k-1;cnt++,i--){
// 			cout<<i<<" ";
// 		}
// 	}
// 	while(1){
// 		if(v2[0].size()>2){
// 			deque<int> t1,t2;
// 			for(int i=0;i<(int)v2[0].size();i+=2){
// 				t1.pb(v2[0][i]);
// 			}
// 			for(int i=1;i<(int)v2[0].size();i+=2){
// 				t2.pb(v2[0][i]);
// 			}
// 			v2.popf();
// 			v2.pb(t1);
// 			v2.pb(t2);
// 		}else{
// 			if(v2[0][0]!=2){
// 				v2.pb(v2[0]);
// 				v2.popf();
// 			}else{
// 				break;
// 			}
// 		}
// 	}
// 	for(int i=0;i<(int)v1.size();i++){
// 		for(int j=0;j<(int)v1[i].size();j++){
// 			cout<<v1[i][j]<<" ";
// 		}
// 	}
// 	for(int i=0;i<(int)v2.size();i++){
// 		for(int j=0;j<(int)v2[i].size();j++){
// 			cout<<v2[i][j]<<" ";
// 		}
// 	}
// 	if(nn%2==k%2&&k!=2){
// 		for(int i=nn-k+2,cnt=0;cnt<k-1;cnt++,i++){
// 			cout<<i<<" ";
// 		}
// 	}
	// int t;
	// cin>>t;
	// while(t--){
	// 	string s;
	// 	cin>>s;
	// 	int hash[26];
	// 	for(int i=0;i<26;i++){
	// 		hash[i]=0;
	// 	}
	// 	int n=s.size();
		
	// 	vector<char> st;
	// 	int cnt=0;
	// 	int i=0;

	// 	string ans="";
	// 	while(1){
	// 		if(st.empty()==1){
	// 			st.pb(s[i]);
	// 		}
	// 		else{
	// 			if(s[i]==st.back()){
	// 				st.pb(s[i]);
	// 			}else{
	// 				int cnt=st.size();
	// 				// if(cnt%2==0&&hash[st.back()-'a']==0){
	// 				// 	// hash[st.back()-'a']=0;
	// 				// 	continue;
	// 				// }else{
	// 				// cout<<cnt<<"\n";
	// 				if(cnt%2==1){
	// 					if(hash[st.back()-'a']==0){
	// 						ans+=st.back();
	// 					}
	// 					// cout<<"aaya\n";
	// 					hash[st.back()-'a']=1;
	// 				// }
	// 				}
	// 				st.clear();
	// 				st.pb(s[i]);
	// 			}
				
	// 		}
	// 		i++;
	// 		if(i==n){
	// 			cnt=st.size();
	// 			// cout<<"last "<<st.size()<<"\n";
	// 			if(cnt%2==1){
	// 				if(hash[st.back()-'a']==0){
	// 					ans+=st.back();
	// 				}
	// 				// cout<<"aaya\n";
	// 				hash[st.back()-'a']=1;
	// 			// }
	// 			}
	// 			break;
	// 		}

	// 	}
	// 	sort(all(ans));
		
	// 	cout<<ans<<"\n";
	// }
	// fl(i,0,n,1){
	// 	cout<<"Parent of "<<i<<" is "<<p[i]<<"\n";
	// }
	// fl(i,0,n-1,1)
	// {
	// 	cout<<dis[i]<<" ";
	// }
	// sieve();
	// ll n;
	// cin>>n;
	// bool say=true;
	// for(ll i=2;i*i<=n;i++){
	// 	if(n%i==0){
	// 		say=false;
	// 		break;
	// 	}
	// }
	// if(say){
	// 	cout<<n;
	// 	return 0;
	// }
	// ll ans=0;
	// for(ll i=2;i*i<=n;i++){
	// 	if(n%i==0){
	// 		ans=__gcd(ans,i);
	// 		ans=__gcd(ans,n/i);
	// 		if(ans==1){
	// 			break;
	// 		}
			
	// 	}
	// }
	// cout<<ans;
	// int tt;
	// cin>>tt;
	// while(tt--){
	// 	int n,cnt=0;
	// 	cin>>n;
	// 	string s,t;
	// 	cin>>s>>t;
	// 	vector<pair<int,int> > v;
	// 	fl(i,0,n-1,1){
	// 		if(s[i]!=t[i]){
	// 			cnt++;
	// 			v.pb(mp(s[i],t[i]));
	// 		}
	// 	}
	// 	if(cnt!=2){
	// 		cout<<"No\n";
	// 	}else{
	// 		if(v[0].FF==v[1].FF&&v[0].SS==v[1].SS){
	// 			cout<<"Yes\n";
	// 		}else{
	// 			cout<<"No\n";
	// 		}
	// 	}
	// }
	// int n,m;
	// cin>>n>>m;
	// char a[n][m];
	// fl(i,0,n-1,1){
	// 	for(int j=0;j<m;j++){
	// 		cin>>a[i][j];
	// 	}
	// }
	// int dp[n][m],vis[n][m];
	// memset(dp,MAX,sizeof(dp));
	// memset(vis,0,sizeof(vis));
	// queue<pair<int,int> > q;
	// fl(i,0,n-1,1){
	// 	for(int j=0;j<m;j++){
	// 		if(a[i][j]!='x'){
	// 			continue;
	// 		}
	// 		q.push(mp(i,j));
	// 		dp[i][j]=0;
	// 	}
	// }

	// fl(i,0,n-1,1){
	// 	for(int j=0;j<m;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"\n";

	// while(!q.empty()){
	// 	int f=q.front().FF;
	// 	int s=q.front().SS;
	// 	q.pop();
	// 	if(s-1>=0&&vis[f][s-1]==0){
	// 		dp[f][s-1]=min(dp[f][s-1],dp[f][s]+1);
	// 		q.push(mp(f,s-1));
	// 		vis[f][s-1]=1;
	// 	}
	// 	if(f-1>=0&&vis[f-1][s]==0){
	// 		dp[f-1][s]=min(dp[f-1][s],dp[f][s]+1);
	// 		q.push(mp(f-1,s));
	// 		vis[f-1][s]=1;
	// 	}
	// 	if(s+1<m&&vis[f][s+1]==0){
	// 		dp[f][s+1]=min(dp[f][s+1],dp[f][s]+1);
	// 		q.push(mp(f,s+1));
	// 		vis[f][s+1]=1;
	// 	}
	// 	if(f+1<n&&vis[f+1][s]==0){
	// 		dp[f+1][s]=min(dp[f+1][s],dp[f][s]+1);
	// 		q.push(mp(f+1,s));
	// 		vis[f+1][s]=1;
	// 	}
	// }
	// int ans=INT_MAX;
	// fl(i,0,n-1,1){
	// 	for(int j=0;j<m;j++){
	// 		if(a[i][j]=='y'){
	// 			ans=min(ans,dp[i][j]);
	// 		}
	// 	}
	// }
	// cout<<ans;
	// fl(i,0,n-1,1){
	// 	for(int j=0;j<m;j++){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}
// 1 65 33 97 17 81 49 9 73 41 25 89 57 5 69 37 21 85 53 13 77 45 29 93 61 3 67 35 99 19 83 51 11 75 43 27 91 59 7 71 39 23 87 55 15 79 47 31 95 63 2 66 34 98 18 82 50 10 74 42 26 90 58 6 70 38 22 86 54 14 78 46 30 94 62 4 68 36 100 20 84 52 12 76 44 28 92 60 8 72 40 24 88 56 16 80 48 32 96 64
// 1 65 33 97 17 81 49 9 73 41 25 89 57 5 69 37 21 85 53 13 77 45 29 93 61 3 67 35 99 19 83 51 11 75 43 27 91 59 7 71 39 23 87 55 15 79 47 31 95 63 2 66 34 98 18 82 50 10 74 42 26 90 58 6 70 38 22 86 54 14 78 46 30 94 62 4 68 36 100 20 84 52 12 76 44 28 92 60 8 72 40 24 88 56 16 80 48 32 96 64
// 10 5
// 5 3 2 1 4 8 9 6 54 5
// 1 5 3
// 1 10 4
// 1 6 -2
// 7 10 51
// 1 10 -51
// 7 -1469348094 1036140795 2040651434 -317097467 1376710097 1330573317 1687926652
// 4 4
// x 0 y 0
// 0 y 0 x
// x x x x
// y 0 0 y
// 4 4
// x 0 0 0
// 0 0 0 0
// 0 0 0 0
// 0 0 0 y

// Jupiter Start :
// 	jupyter notebook --allow-root
	// jupyter notebook --ip=' *'
// 8 4 1 2 9

// #include <bits/stdc++.h>
 
// using namespace std;
 
// static int tree[400005];
// int n;
 
// void update(int l, int r){
// 	for(l += n, r += n;l < r;l >>= 1, r>>= 1){
// 		if(l&1){
// 			tree[l]++;
// 			l++;
// 		}
// 		if(r&1){
// 			r--;
// 			tree[r]++;
// 		}
// 	}
// }
 
// int get(int i){
// 	int ans = 0;
// 	i += n;
// 	while(i > 0){
// 		ans += tree[i];
// 		i >>= 1;
// 	}
// 	return ans;
// }
// int main(){
// 	//freopen("i.txt","r",stdin);
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(0);
	
	
	
// 	cin >> n;
// 	int arr[n];
// 	for(int i = 0;i < n;i++) cin >> arr[i];
// 	typedef pair<int,int> ii;
// 	priority_queue<ii> pq;
// 	for(int i = 0;i < n;i++){
// 		pq.push(ii(arr[i],-1*i));
// 	}
	
// 	int q;
// 	cin >> q;
// 	vector<ii> query[n];
// 	int answer[q];
// 	for(int i = 0;i < q;i++){
// 		int a, b;
// 		cin >> a >> b;
// 		query[a-1].push_back(ii(b,i));
// 	}
// 	for(int i = 0;i < n;i++){
// 		int p = pq.top().second;
// 		pq.pop();
// 		p *= -1;
		
// 		update(p,n);
		
		
// 		for(ii x : query[i]){
// 			int look = x.first;
			
// 			int low = -1;
// 			int high = n-1;
// 			while(true){
// 				if(low == high - 1) break;
// 				int s = (low + high) / 2;
				
// 				if(get(s) >= look) high = s;
// 				else low = s;
// 			}
			
// 			answer[x.second] = high;
// 		}
// 		/*
// 		for(int j = 0;j < n;j++){
// 			cout << get(j) << " ";
// 		}
// 		cout << "\n";
// 		*/
// 	}
	
// 	for(int i = 0;i < q;i++){
// 		cout << arr[answer[i]] << "\n";
// 	}
// }