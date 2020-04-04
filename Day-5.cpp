#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll a,ll b){
    ll ans=1;
    while(b!=0){
        if(b%2){
            ans=ans*a;
        }
        a=a*a;
        b=b>>1;
    }
    return ans;
}
int main(){
    int t;
    cin>>t;
    bool say[16];
    say[0]=say[1]=say[3]=say[6]=say[7]=say[12]=say[13]=say[15]=false;
    say[2]=say[4]=say[8]=say[5]=say[9]=say[10]=say[11]=say[14]=true;
    while(t--){
        ll n;
        cin>>n;
        if(n<16){
            if(say[n]){
                cout<<"Jatin\n";
                continue;
            }
            cout<<"Pranshu\n";
            continue;
        }
        if(ceil(log2(n*1.0))==log2(n)){
            cout<<"Jatin\n";
            continue;
        }
        if(ceil(log2((n+1)*1.0))==log2(n+1)){
            cout<<"Pranshu\n";
            continue;
        }
        while(1){
            if(n<16){
                    if(say[n]){
                    cout<<"Jatin\n";
                    break;
                }
                cout<<"Pranshu\n";
                break;
            }
            if(ceil(log2(n*1.0))==log2(n)){
                cout<<"Jatin\n";
                continue;
            }
            if(ceil(log2((n+1)*1.0))==log2(n+1)){
                cout<<"Pranshu\n";
                continue;
            }
            ll x=ceil(log2(n*1.0));
            ll ran=power(2,x-2);
            ll upto=power(2,x-1)+ran;
            if(n<=upto){
                cout<<"Jatin\n";
                break;
            }
            if(upto+1==n){
                cout<<"Pranshu\n";
                break;
            }else{
                ll last=power(2,x);
                ll extra=last-n;
                n=power(2,x-2)-last;
            }
        }
    }
}