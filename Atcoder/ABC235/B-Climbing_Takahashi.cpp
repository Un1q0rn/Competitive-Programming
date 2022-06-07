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
    ll n;cin >> n;
    vector<int> a(n);
    for(auto &e:a){
        cin >> e;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        if(a[i] > ans) ans = a[i];
        else break;
    }
    cout << ans << endl;    
    return 0;
}

