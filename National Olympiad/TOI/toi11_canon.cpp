#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k,li;cin >> n >> m >> k >> li;
    vector<int> a(n);
    int b[m];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    for(int i=0;i<k;i++){
        int ans=0,now=0;
        for(int j=0;j<m;j++){
            cin >> b[j];
            int it1 = upper_bound(a.begin()+now,a.end(),b[j]+li)-a.begin();
            int it2 = lower_bound(a.begin()+now,a.end(),b[j]-li)-a.begin();
            ans+=(it1-it2);
            now = it1;
        }
        cout << ans << '\n';
    }    
    return 0;
}
