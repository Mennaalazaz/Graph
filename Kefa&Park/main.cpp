#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int N=1e5+5;
int n,m,ans; vector<int> adj[N]; bool vis[N],cat[N];

// The problem is asking: how many valid leaf nodes can you reach from the root. (within the cat limit)
void dfs(int node,int cats) {
    vis[node]=true;
    if(cats>m) return; // If the current path exceeds the max allowed consecutive cats, stop going deeper
    if(!cat[node]) cats=0; // If you reach a node without a cat, then the consecutive streak breaks.
    bool leaf=1;
    for(auto it:adj[node]) {
        if(!vis[it]) {
            dfs(it,cats+cat[it]);
            leaf=0; //  if the node has at least one unvisited child, it's not a leaf → set leaf = 0.
        }
    }
    ans+=leaf; // If leaf == 1, this node is a valid leaf node and I’ve reached it on a valid path (within the cat limit). So I count it.
}

int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>cat[i];
    for(int i=1;i<n;i++) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,cat[1]);
    cout<<ans;
}










