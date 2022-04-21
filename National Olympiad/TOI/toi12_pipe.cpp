#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pb push_back
struct A{
    int x,y,dist;
};
int n,k;
vector<A> a;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].dist = INT_MAX;
    }
    a[0].dist=-1;
    int j = 0;
    vector<int> ans;
    while(1){
        int mn = INT_MAX;
        int idx = -1;
        for(int i=1;i<n;i++){
            if(a[i].dist == -1) continue;
            a[i].dist =min(a[i].dist,abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            if(mn > a[i].dist){
                mn = a[i].dist;
                idx = i;
            }
        }
        if(idx == -1) break;
        a[idx].dist = -1;
        ans.pb(mn);
        j = idx;
    }
    int cnt=0;
    sort(ans.begin(),ans.end(),greater<int>());
    for(int i=k-1;i<n-1;i++) cnt+=ans[i];
    cout << cnt;
    return 0;
}
