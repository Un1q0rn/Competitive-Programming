#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()
map<int,int> id;
map<pi,int> m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        id[x]++;
        m[{x,id[x]}] = i+1;
    }
    while(q--){
        int x,k;cin >> x >> k;
        if(m[{x,k}]){
            cout << m[{x,k}] << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}


