#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	stack<char> st;
	for(int i=0;i<n;i++){
		if(st.empty()){
			st.push(s[i]);
		}else{
			if(s[i]=='a')st.push('a');
			else{
				if(st.top()=='a')st.pop();
				else st.push(s[i]);
			}
		}
	}
	cout<<st.size();
}