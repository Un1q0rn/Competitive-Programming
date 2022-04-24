#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q;cin >> n >> q;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    while(q--){
        int l,r,k;cin >> l >> r >> k;
        int it1 = lower_bound(a.begin(),a.end(),pair<int,int>(k,l))-a.begin();
        int it2 = upper_bound(a.begin(),a.end(),pair<int,int>(k,r))-a.begin();
        cout << it2-it1 << '\n';
    }
    return 0;
}
