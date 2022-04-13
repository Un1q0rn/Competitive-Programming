#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
        a[i]+=a[i-1];
    }
    int ab=INT_MAX,ans1,ans2,sec1,sec2,sec3,mn,mx;
    for(int i=2;i<=n;i++){
        for(int j=i+1;j<n;j++){
            sec1 = a[i];
            sec2 = a[j]-a[i];
            sec3 = a[n]-a[j];
            mx = max({sec1,sec2,sec3});
            mn = min({sec1,sec2,sec3});
            if(mx-mn < ab){
                ans1 = i+1;
                ans2 = j+1;
                ab = mx-mn;
            }
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
