#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define sz(x) (int)x.size()

void dfs(vector<vector<int>> &g,vector<int> &vis,int u){
    vis[u] = 1;
    for(auto v:g[u]){
        if(vis[v]) continue;
        dfs(g,vis,v);
    }
    return ;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        char c;cin >> c;
        int n = (c-'A')+1;
        cin.ignore();
        vector<vector<int>> g(n);
        vector<int> vis(n);
        string s;
        while(getline(cin,s) && s != ""){
            int u = (s[0]-'A');
            int v = (s[1]-'A');
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                dfs(g,vis,i);
            }
        }
        cout << ans << '\n';
        if(t) cout << '\n';
    }
    return 0;
}
