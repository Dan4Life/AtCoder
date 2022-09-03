// This solution ACs but I think it might be wrong...
// I'll update this to the correct dp solution soon
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int maxn = (int)2e5+10;
vector<int> adj[maxn];
bool isStraight[maxn];

void recur(int s, int p){
	if(adj[s].size()>2) isStraight[s]=0;
	for(auto u : adj[s]){
		if(u==p) continue;
		recur(u,s); isStraight[s]&=isStraight[u];
	}
}

int dfs(int s, int p){
	if(isStraight[s]) return 1;
	int ans = 0, cnt = 0;
	for(auto u : adj[s]){
		if(u==p) continue;
		if(isStraight[u]) cnt++;
		else ans+=dfs(u,s);
	}
	return ans+cnt-(cnt>0);
}

int main() {
	int n, a, b; cin >> n;
	fill(isStraight, isStraight+maxn, true);
	for(int i = 0; i < n-1; i++) 
		cin >> a >> b, adj[a].pb(b), adj[b].pb(a);
		int p = 0, mx = 0;
	for(int i = 0; i < n; i++)
		if(mx<(int)adj[i].size()) mx=(int)adj[i].size(), p=i;
	recur(p,-1); cout << dfs(p,-1);
}