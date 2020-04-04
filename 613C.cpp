#include<bits/stdc++.h>
using namespace std;

vector<bool> p(10000001,true);
vector<long long> primes;
vector<long long> spf(10000001,0);
void sieve(){
    spf[2]=2;
    for(long long i=4;i<10000001;i+=2){
        p[i]=false;
        spf[i]=2;
    }
    spf[2]=2;
    primes.push_back(2);
    for(long long i=3;i<10000001;i+=2){
        if(p[i]==true){
            spf[i]=i;
            primes.push_back(i);
            for(long long j=i*i;j<10000001;j+=i){
                if(p[j]==false)continue;
                p[j]=false;
                spf[j]=i;
            }
        }
    }
}

long long compute(long long i,long long prev,vector<long long> &val,vector<vector<long long> > &gr,vector<long long> &xor_val){
    long long x=val[i];
    for(long long j=0;j<(long long)gr[i].size();j++){
        if(gr[i][j]!=prev){
            x^=compute(gr[i][j],i,val,gr,xor_val);   
        }
    }
    xor_val[i]=x;
    return x;
}

int main(){
    for(long long i=0;i<10000001;i++){
        p[i]=true;
    }
    p[0]=p[1]=false;
    sieve();
    long long n,xx=0;
    cin>>n;
    vector<long long> v(n),xor_val(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
        if(p[v[i]]==0){
            v[i]=0;
        }
        xx^=v[i];
    }
    vector<vector<long long> > graph(n);
    for(long long i=1;i<n;i++){
        long long x;
        cin>>x;
        x--;
        graph[x].push_back(i);
    }
    compute(0,-1,v,graph,xor_val);
    for(long long i=0;i<n;i++){
        long long ans=xor_val[i]^xx;
        long long out=1;
        if(ans==0){
            cout<<0<<" ";
            continue;
        }
        map<long long,long long> m;
        while(ans!=1){
            
            m[spf[ans]]++;
            if(spf[ans]==0){
                break;
            }
            ans=ans/spf[ans];
        }
        for(auto it=m.begin();it!=m.end();++it){
            out=out*(it->second+1);
        }
        cout<<out<<" ";
    }
}