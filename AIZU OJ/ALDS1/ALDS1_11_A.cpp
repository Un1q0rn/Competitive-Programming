#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<vector<int>> graph(n,vector<int>(n));
    for(int i=0;i<n;i++){
        int u,k;cin >> u >> k;
        u--;
        while(k--){
            int v;cin >> v;
            v--;
            graph[u][v] = 1;
        }
    }
    for(auto u:graph){
        for(int i=0;i<n-1;i++){
            cout << u[i] << ' ';
        }
        cout << u[n-1] << '\n';
    }
    return 0;
}
