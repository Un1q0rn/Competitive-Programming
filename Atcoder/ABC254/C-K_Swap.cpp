#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) (int)x.size()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    vector<vector<int>> b(k);
    for(int i=0;i<n;i++){
        b[i%k].pb(a[i]);
    }
    for(int i=0;i<k;i++){
        sort(rall(b[i]));
    }
    sort(all(a));
    vector<int> ans;
    for(int i=0;i<n;i++){
        ans.pb(b[i%k].back());
        b[i%k].pop_back();
    }
    if(ans == a) cout << "Yes";
    else cout << "No";
    return 0;
}

