#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define f first
#define s second 

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 5;
    while(t--){
        int n;cin >> n;
        vector<pi> t1,t2;
        for(int i=0;i<n-1;i++){
            int u,v;cin >> u >> v;
            t1.pb({max(u,v),min(u,v)});
        }
        for(int i=0;i<n-1;i++){
            int u,v;cin >> u >> v;
            t2.pb({max(u,v),min(u,v)});
        }
        sort(all(t1));
        sort(all(t2));
        if(t1 == t2) cout << 'Y';
        else cout << 'N';
    }
    return 0;
}
