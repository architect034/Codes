#include<bits/stdc++.h>
using namespace std;
const int me = 100025;
const int mod = 100000000;
void add(int &a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
}
int n;
int dp[me];
pair<int, int> a[me];
 
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}
int main(int argc, const char * argv[]) {
    while(scanf("%d", &n)){
        if(n == -1)
            break;
        for(int i = 1; i <= n; i ++)
            scanf("%d%d",&a[i].first,&a[i].second);
        sort(a+1,a+n+1,cmp);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            auto next_pos=upper_bound(a,a+n+1,make_pair(0,a[i].first),cmp)-a-1;
            add(dp[i],dp[next_pos]);
        }
        add(dp[n],mod-1);
        cout<<setfill('0')<<setw(8)<<dp[n]<<endl;
    }
    return 0;
}