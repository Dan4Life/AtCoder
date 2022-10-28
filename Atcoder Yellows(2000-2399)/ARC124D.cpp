/*
Solved with editorial
There is almost 0 chance i could have gotten this myself wtf
*/

#include <bits/stdc++.h>
using namespace std;

const int maxn=(int)2e5+10;

int a[maxn];
bool vis[maxn];
vector<int> adj[maxn];
int n, m, r, b, ans, ok; 

void dfs(int s, int type=3){
    vis[s]=1;
    for(auto u : adj[s]){
        if(type!=3){
            if(!type and u>n) ok=0;
            if(type and u<=n) ok=0;
        }
        if(!vis[u]) dfs(u,type);
    }
}

int main()
{
    cin >> n >> m; ans = n+m;
    for(int i = 1; i <= n+m; i++) cin >> a[i];
    for(int i = 1; i <= n+m; i++)
        adj[i].push_back(a[i]);
    for(int i = 1; i <= n+m; i++)
        if(!vis[i]) ans--, dfs(i);
    fill(vis, vis+maxn,0);
    for(int i = 1; i <= n+m; i++){
        if(vis[i]) continue; 
        ok=1; dfs(i,(i>n));
        if(a[i]==i or !ok) continue;
        if(i<=n) r++; 
        else b++;
    }
    cout << ans+2*max(r,b);
}
