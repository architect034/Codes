#include "bits/stdc++.h"
#define ll long long
using namespace std;
int main(){
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> ans;
        for(ll i=2; i*i<n; ++i) {
            if(n%i == 0) {
                ans.push_back(i);
                n /= i;
                break;
            }
        }
        if(ans.size() > 0) {
            for(ll i=2; i*i<n; ++i) {
                if(i != ans[0] && n%i == 0 && n/i != i) {
                    ans.push_back(i);
                    ans.push_back(n/i);
                    n = 1;
                    break;
                }
            }
        }
        if(ans.size() == 3) {
            cout << "YES" << endl;
            cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}