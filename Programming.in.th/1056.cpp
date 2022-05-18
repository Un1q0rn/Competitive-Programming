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
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,k;cin >> n >> k;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(all(a),greater<int>());
    int ans = 0;
    for(int i=0;i<n;i+=k){
        ans+=a[i];
    }
    cout << ans ;
    return 0;
}
