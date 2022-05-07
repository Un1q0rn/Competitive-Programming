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
    int n,k;cin >> n >> k;
    vector<int> a(n+2,0),ans;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n+1;i++){
        if(a[i] > a[i-1] && a[i] > a[i+1]) ans.pb(a[i]);
    }
    sort(all(ans));
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    int s = ans.size();
    if(s == 0) cout << -1;
    else if(s < k){
        for(auto x:ans) cout << x << '\n';
    }
    else{
        reverse(all(ans));
        for(int i=0;i<k;i++){
            cout << ans[i] << '\n';
        }
    }
    return 0;
}
