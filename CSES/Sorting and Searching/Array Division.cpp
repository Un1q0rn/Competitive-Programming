#include <bits/stdc++.h> 
using namespace std; 
 
#define ll long long int 
#define ld long double
#define vi(x)  vector<x>
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

int main()
{
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);
    int n,k;cin >> n >> k;
    vi(int) a(n);
    for(auto &e:a) cin >> e;
    ll l = 1,r = 1e18;
    while(l < r){
        ll mid = l+((r-l)>>1);
        ll sum = 0,cnt = 1;
        for(int i=0;i<n;i++){
            if(a[i] > mid){
                cnt = k+1;
                break;
            }
            if(a[i]+sum > mid){
                cnt++;
                sum = 0;
            }
            sum += a[i];
        }
        if(cnt > k){
            l = mid+1;
        }
        else r = mid;
    }
    cout << r;
    return 0;
}
