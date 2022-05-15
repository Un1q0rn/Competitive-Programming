#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ui unsigned int 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 
#define sz(x) (int)x.size()

map<vector<pi>,int> m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t,q;cin >> t >> q;
    while(t--){
        int n;cin >> n;
        vector<pi> t;
        for(int i=0;i<n-1;i++){
            int u,v;cin >> u >> v;
            t.pb({min(u,v),max(u,v)});
        }
        sort(all(t));
        m[t]++;
    }
    while(q--){
        int n;cin >> n;
        vector<pi> t;
        for(int i=0;i<n-1;i++){
            int u,v;cin >> u >> v;
            t.pb({min(u,v),max(u,v)});
        }
        sort(all(t));
        cout << m[t] << '\n';
    }
    return 0;
}
