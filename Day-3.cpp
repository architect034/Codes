//Surprise motherfuckers
#include<bits/stdc++.h>
#define lld long long
using namespace std;
const lld r= 1e9+7;
lld DP[14][100010],n,m,l;
vector<lld> cnt(14,0);
lld calculate(lld abtak,lld len){
    if(len<=0){
        if(abtak==0)return 1;
        return 0;
    }
    if(DP[abtak][len]!=-1)return DP[abtak][len];
    lld ans=0;
    for(lld j=0;j<m;j++){
        ans+=(cnt[j]*calculate((abtak+j)%m,len-1))%r;
        ans=ans%r;
    }
    return DP[abtak][len]=ans;
}
int main(){
    cin>>n>>m>>l;
    memset(DP,-1,sizeof DP);
    for(lld i=0;i<l;i++){
        lld x;
        cin>>x;
        cnt[x%m]++;
    }
    printf("%lld",calculate(0,n));
}