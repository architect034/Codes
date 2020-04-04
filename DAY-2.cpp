#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    int n;
    cin>>n;
    int a[n+1][n+1];
    vector<int> tmp;
    tmp.push_back(0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(i==j){
                tmp.push_back(a[i][j]);
            }
        }
    }
    int q;
    cin>>q;
    int dp[n+2]={0};
    while(q--){
        int t,a,b,c;
        cin>>t>>a>>b>>c;
        if(t==1){
            dp[a]^=c;
            dp[b+1]^=c;
        }else{
            dp[a]^=c;
            dp[b+1]^=c;
        }
    }
    int ans=0;
    for(int i=1;i<=n+1;i++){
        dp[i]^=dp[i-1];
        tmp[i]^=dp[i];
        ans+=tmp[i];
    }
    cout<<ans;
}