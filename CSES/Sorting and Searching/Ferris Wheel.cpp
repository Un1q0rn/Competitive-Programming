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
    int n,x;cin >> n >> x;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(all(a));
    int l=0,r=n-1,ans=0;
    while(l < r){
        if(a[r]+a[l] <= x){
            l++;
            r--;
        }
        else{
            r--;
        }
        ans++;
    }
    cout << ans+(l==r);
    return 0;
}
