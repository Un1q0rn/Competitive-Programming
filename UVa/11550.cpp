#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define sz(x) (int)x.size()

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> g(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;cin >> x;
            if(x) g[j].push_back(i);
        }
    }
    for(int i=0;i<m;i++){
        if(sz(g[i]) != 2){
            cout << "No\n";
            return ;
        }
    }
    set<pair<int,int>> ver;
    for(int i=0;i<m;i++){
        ver.insert({g[i][0],g[i][1]});
    }
    if(sz(ver) == m) cout << "Yes\n";
    else cout << "No\n";
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
