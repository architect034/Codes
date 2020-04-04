#include<bits/stdc++.h>
using namespace std;
int main(){
   int _;
   cin>>_;
   while(_--){
      int x=1,y=1;
      x=2;y=2;
      long long a,b,n,s;
      cin>>a>>b>>n>>s;
      long long c=s/n;
      c=min(c,a)*n;
      if(s-c<=b){
         cout<<"yes\n";
      }else{
         cout<<"no\n";
      }
   }
}