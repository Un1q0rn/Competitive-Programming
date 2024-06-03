#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define sz(x) (int)x.size()
 
const int N = 1e6;
vector<int> g[N+10];
int n,m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    while(cin >> n >> m){
        for(int i=0;i<n;i++){
            int x;cin >> x;
            x--;
            g[x].push_back(i+1);
        }
        while(m--){
            int k,v;cin >> k >> v;
            v--;
            if(sz(g[v]) < k){
                cout << 0 << '\n';
            }
            else{
                k--;
                cout << g[v][k] << '\n';
            }
        }
        for(int i=0;i<n;i++){
            g[i].clear();
        }
    }
    return 0;
}
