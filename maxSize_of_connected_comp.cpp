#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int
const int mod=1000000007;

int val=0;
void dfs(set<int> adj[], bool visited[], int source){
	val++;
	visited[source]=true;
	set<int>::iterator i;
	for (i = adj[source].begin(); i != adj[source].end(); ++i) 
        if (!visited[*i]) 
            dfs(adj, visited, *i); 
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,e;
	cin>>n>>e;
	set<int> adj[n];
	for(int i=0;i<e;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		//if(find(adj[a].begin(),adj[a].end(),b)==adj[a].end())
			adj[a].insert(b);
		//if(find(adj[b].begin(),adj[b].end(),a)==adj[b].end())
			adj[b].insert(a);
	}
	
	bool visited[n];
	memset(visited,false,sizeof(visited));
	
	int ans=0;
	for(int i=0;i<n;i++){
		val=0;
		//TODO: for every node do DFS 
		if(!visited[i]){
			dfs(adj,visited,i);
			ans=max(ans,val);
		}
	}
	cout<<ans;
	return 0;
}


//1
//7 2
//3 5 4 5 1 1 1

