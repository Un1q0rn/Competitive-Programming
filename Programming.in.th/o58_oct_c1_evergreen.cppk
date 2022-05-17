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

const int N = 1e3+100;
ll n,k,a[N];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a,a+n);
    ll l = 0,r = 1e9,mid;
    while(l<r){
        mid = (l+r)/2;
        ll sum = (mid+1)*(mid+1)*n;
        for(int i=1;i<n;i++){
            if(a[i] == a[i-1]){
                sum -= (mid+1)*(mid+1);
                continue;
            }
            ll diff = a[i]-a[i-1]-1;
            if(diff%2 == 0){
                diff/=2;
                if(diff >= mid) continue;
                diff = mid - diff;
                sum -= diff*(diff+1);

            }
            else {
                diff/=2;
                if(diff >= mid) continue;
                diff = mid - diff;
                sum -= diff*diff;
            }
        }
        if(sum >= k) r = mid;
        else l = mid+1;
    }
    cout << l << '\n';
    return 0;
}
