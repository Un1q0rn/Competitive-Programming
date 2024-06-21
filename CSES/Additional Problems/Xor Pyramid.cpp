#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define pi pair<int,int>
#define sz(x) (int)x.size()

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;cin >> n;
    vector<int> pref(n+1),a(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=2;i<=n;i++){
        int num = i;
        while(num%2==0){
            pref[i]++;
            num/=2;
        }
        pref[i] += pref[i-1];
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        if(pref[n-1]-pref[i]-pref[n-i-1] != 0) continue;
        ans ^= a[i];
    }
    cout << ans;
    return 0;
}
