#include<bits/stdc++.h>
using namespace std;
int level[1000010],vis[1000010];
int pos,ran;
int n,r,m;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d %d %d",&n,&r,&m);
		vector<vector<int> > graph(n+1);
		for(int i=0;i<r;i++){
			int x,y;
			scanf("%d %d",&x,&y);
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		vector<int> hogya(n+1,0);
		bool say=1;
		for(int i=0;i<m;i++){
			
			memset(level,0,sizeof(level));
			memset(vis,0,sizeof(vis));
			
			scanf("%d %d",&pos,&ran);
			queue<int> q;
			q.push(pos);
			vis[pos]=1;
			while(!q.empty()){
				int x=q.front();
				if(level[x]>ran){
					break;
				}
				if(hogya[x]==1){
					say=0;
					break;
				}
				
				q.pop();
				for(int j=0;j<(int)graph[x].size();j++){
					if(!vis[graph[x][j]]){
						q.push(graph[x][j]);
						vis[graph[x][j]]=1;
						level[graph[x][j]]=level[x]+1;
					}
				}
				hogya[x]=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(hogya[i]==0){
				say=0;
				break;
			}
		}
		if(say){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}