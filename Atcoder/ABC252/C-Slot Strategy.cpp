#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
const int N = 20;
int cnt[N][N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<string> s(n);
    for(auto &e:s) cin >> e;
    for(int i=0;i<n;i++){
        for(int j=0;j<10;j++){
            cnt[s[i][j]-'0'][j]++;
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<10;i++){
        int mx=0;
        for(int j=0;j<10;j++){
            mx = max(mx,(cnt[i][j]-1)*10+j);
        }
        ans = min(mx,ans);
    }
    cout << ans ;
    return 0;
}
