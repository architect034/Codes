#include<bits/stdc++.h>
#include <cstdlib> 
#define fio   ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define test() ll t; cin>>t; while(t--)
#define speed ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define nax 1000005
#define pb push_back
#define mp make_pair
#define in insert
#define lpi(i,a,b) for(ll i=a;i<b;i++)
#define lpd(i,a,b) for(ll i=a;i>b;i--)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned int ui;
typedef long double ld;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    int n ;
    cin>>n;
    char a[n][n];

    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int> v;
    for(int i =0;i<n;i++)
    {
        int c =0;
        for(int j=0;j<n;j++)
        {
            if(a[i][j] !='.')
                {
                    c++;
                }
        }
        // cout<<c<<" ";
        v.pb(c);
    }
    // cout<<"\n";
    for(int i =0;i<n;i++)
    {
        int c =0;
        for(int j=0;j<n;j++)
        {
            if(a[j][i] !='.')
                {
                    c++;
                }
        }
        // cout<<c<<" ";
        v.pb(c);
    }
    // cout<<"\n";
    int arr[2*n];
    memset(arr,0,sizeof arr);
    for(int i = 0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(a[i][j]!='.'){
                arr[i+j]++;
            }
        }
    }
    for(int i=0;i<2*n;i++){
        if(arr[i]>=3){
            v.pb(arr[i]);
            cout<<arr[i]<<" ";
        }
    }
    cout<<"\n";
    for(int i=0;i<n;i++){
        int c =0;
        int k =i;
        for(int j=0;j<n-i;j++,k++){
            if(a[k][j]!='.')c++;
        }
        cout<<c<<" ";
        v.pb(c);
    }
    cout<<"\n";

    for(int j=1;j<n;j++){
        int c =0;
        int k = j;
        for(int i =0;i<n-j;i++,k++){
            if(a[i][k]!='.')c++;
        }
        cout<<c<<" ";
        v.pb(c);
    }
    cout<<"\n";
    int ans=0;
    vector<int> m;
    for(int i=0;i<v.size();i++){
        if(v[i]<3)continue;
        else{
            cout<<v[i]<<" ";
            int x=v[i];
            int tmp=(x*(x-1)*(x-2))/6;
            m.pb(tmp);
            ans+=tmp;
        }
    }
    // sort(m.begin(),m.end());
    // for(auto x:m){
    //     cout<<x<<" ";
    // }
    cout<<"\n";
    cout<<ans<<"\n";

   }
}