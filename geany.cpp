#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<pair<int,int> > dq;
    int n;
    cin>>n;
    vector<pair<int,int> > v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++){
        if(dq.empty()){
            dq.push_back(make_pair(v[i].first,v[i].second));
            ans=max(ans,(int)dq.size());
        }else{
            while(dq.size()>0&&dq.front().second<v[i].first){
                //~ cout<<dq.front().second<<" "<<v[i].first<<" i = "<<i+1<<"\n";
                dq.pop_front();
            }
            dq.push_back(make_pair(v[i].first,v[i].second));
        }
        ans=max(ans,(int)dq.size());
    }
    cout<<ans;
}
