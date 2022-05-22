#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
map<int,int> m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    int mx=0;
    vector<int> a(n);
    for(auto &e:a) {
        cin >> e;
        mx = max(mx,e);
    }
    while(k--){
        int x;cin >> x;
        if(a[--x] == mx){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No" ;
    return 0;
}
